//
//  SGScene.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "SGScene.h"
#include "Actor.h"

using namespace cocos2d;

SGScene::SGScene() {
}

bool SGScene::init() {
    if (!Scene::init()) {
        return false;
    }
    
    m_layer = new Layer();
    
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
    
    return true;
}

void SGScene::addActor(Actor * actor) {
    m_actors.addObject(actor);
    addChild(actor);
}

void SGScene::removeActor(Actor * actor) {
    m_actors.removeObject(actor);
    removeChild(actor, true);
}

ActorArray * SGScene::getActors() {
    return &m_actors;
}

void SGScene::touch() {
    
}

void SGScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent) {
    touch();
}

SGScene::~SGScene() {
    
}