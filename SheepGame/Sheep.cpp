//
//  Sheep.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "Sheep.h"
#include "Boy.h"

using namespace cocos2d;

bool Sheep::init(SGScene * scene, Boy * boy) {
    if (!Actor::init(scene)) {
        return false;
    }
    
    m_boy = boy;
    m_boy->retain();
    
    return true;
}

const String Sheep::getImageName() {
    return String("sheep.png");
}

void Sheep::tick(cocos2d::ccTime dt) {
    
}

void Sheep::moveToBoy() {
    CCPoint location = m_boy->getPosition();
    runAction(CCMoveTo::actionWithDuration(1.0f, location));
}

void Sheep::touch() {
    moveToBoy();
}

Sheep::~Sheep() {
    m_boy->release();
    m_boy = NULL;
}