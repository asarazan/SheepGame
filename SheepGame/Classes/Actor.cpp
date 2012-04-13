//
//  Actor.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "Actor.h"
#include "Stage.h"
#include "cocos2d.h"

using namespace cocos2d;

bool Actor::init(Stage * stage) {
    String imageName = getImageName();    
    if (!cocos2d::CCSprite::initWithFile(imageName.c_str())) {
        return false;
    }
    
    stage->addActor(this);    
    schedule(schedule_selector(Actor::tick), 0);
        
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
    
    return true;
}

bool Actor::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    CCRect box = this->boundingBox();
    CCPoint point = pTouch->locationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    
    if (!CCRect::CCRectContainsPoint(box, point)) {
        return false;
    }
    
    this->touch();
    return true;
}

void Actor::tick(cocos2d::ccTime dt) {
    
}

void Actor::touch() {
    
}