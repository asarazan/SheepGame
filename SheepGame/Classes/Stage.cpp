//
//  Stage.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/12/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "Stage.h"
#include "Actor.h"

using namespace cocos2d;

bool Stage::init() {
    if (!Layer::init()) {
        return false;
    }
    
    return true;
}

bool Stage::ccTouchBegan(cocos2d::CCTouch *pTouch, CCEvent *pEvent) {
    CCPoint location = convertToWorldSpace(pTouch->locationInView());
    
    for (ActorArray::CCMutableArrayIterator i =  m_actors.begin(); i != m_actors.end(); ++i) {
        Actor * actor = (*i);
        CCPoint position = actor->convertToWorldSpace(actor->getPosition());
        CCRect box = actor->boundingBox();
        CCPoint local = actor->convertToNodeSpace(location);
        if (CCRect::CCRectContainsPoint(box, local)) {
            actor->touch();
        }
    }
    
    return true;
}

void Stage::addActor(Actor * actor) {
    m_actors.addObject(actor);
    addChild(actor);
}

void Stage::removeActor(Actor * actor) {
    m_actors.removeObject(actor);
    removeChild(actor, true);
}

ActorArray * Stage::getActors() {
    return &m_actors;
}
