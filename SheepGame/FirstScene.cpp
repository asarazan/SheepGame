//
//  FirstScene.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "FirstScene.h"
#include "Boy.h"
#include "Sheep.h"

using namespace cocos2d;

FirstScene * FirstScene::scene() {
    FirstScene * retval = new FirstScene();
    retval->autorelease();
    retval->init();
    return retval;
}

bool FirstScene::init() {
    if (!SGScene::init()) {
        return false;
    }
    
	CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    m_boy = new Boy();
    m_boy->init(this);
    m_boy->setPosition(ccp(size.width / 2, size.height / 2));
    
    m_sheepArray = new SheepArray();
    for (int i = 0; i < 6; ++i) {
        Sheep * sheep = new Sheep();
        sheep->init(this, m_boy);
        m_sheepArray->addObject(sheep);
        sheep->release();
        
        float x = rand() % (int)size.width;
        float y = rand() % (int)size.height;        
        sheep->setPosition(ccp(x, y));
    }
    
    return true;
}

FirstScene::~FirstScene() {
    m_boy->release();
    m_boy = NULL;
    
    m_sheepArray->release();
    m_sheepArray = NULL;
}