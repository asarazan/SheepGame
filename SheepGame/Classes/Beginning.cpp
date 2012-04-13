//
//  Beginning.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/12/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "Beginning.h"
#include "Boy.h"
#include "Sheep.h"
#include "Actor.h"

using namespace cocos2d;

bool Beginning::init() {
    
    if (!Stage::init()) {
        return false;
    }
    
	CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    m_boy = new Boy();
    m_boy->init(this);
    m_boy->setPosition(ccp(size.width / 2, size.height / 2));
    
    m_sheepArray = new SheepArray();
    for (int i = 0; i < 1; ++i) {
        Sheep * sheep = new Sheep();
        sheep->init(this, m_boy);
        m_sheepArray->addObject(sheep);
        sheep->release();
        
        float x = rand() % (int)size.width;
        float y = rand() % (int)size.height;        
        sheep->setPosition(ccp(x, y));
    }   
    
    return  true;
}

Scene * Beginning::scene() {
    
    Scene * scene = Scene::node();
    
    Beginning * layer = Beginning::node();
    
    scene->addChild(layer);
    
    return scene;
}

Beginning::~Beginning() {
    m_boy->release();
    m_boy = NULL;
    
    m_sheepArray->release();
    m_sheepArray = NULL;
}