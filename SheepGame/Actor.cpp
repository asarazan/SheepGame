//
//  Actor.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "Actor.h"
#include "SGScene.h"
#include "cocos2d.h"

using namespace cocos2d;

bool Actor::init(SGScene * scene) {
    String imageName = getImageName();    
    if (!cocos2d::CCSprite::initWithFile(imageName.c_str())) {
        return false;
    }
    
    scene->addActor(this);    
    schedule(schedule_selector(Actor::tick), 0);
    
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
    
    return true;
}

void Actor::tick(cocos2d::ccTime dt) {
    
}

void Actor::touch() {
    
}

void Actor::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent) {
    touch();
}