//
//  ChaseStage.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/28/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include <iostream>

#include "ChaseStage.h"
#include "Actor.h"
#include "Boy.h"

bool ChaseStage::init() {
    if (!Stage::init()) {
        return false;
    }
    
    m_bgs = CCArray::array();
    m_bgs->retain();
    
    m_clouds = CCArray::array();
    m_clouds->retain();
    
    m_mountains = CCArray::array();
    m_mountains->retain();
    
    m_bgNode = CCParallaxNodeExtras::node();
    m_bgNode->retain();
    this->addChild(m_bgNode);
    
    CCPoint offset = ccp(128,100);
    
    const char * bgName = "shinybg.png";
    
    Sprite * sky = Sprite::spriteWithFile("sky.png");
    m_bgNode->addChild(sky, -1, ccp(0.0,0.0), ccp(240,160));
    
    CCPoint cloudRatio = ccp(0.25,0.25);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float yCloudStart = (winSize.height * 2) / 3;
    float yCloudHeight = winSize.height / 3;
    
    CCRect cloudSpawnRect = CCRectMake(0, yCloudStart, winSize.width, yCloudHeight);
    
    for (int i = 0; i < 5; ++i) {
        
        float x = (rand() % (int)cloudSpawnRect.size.width) + cloudSpawnRect.origin.x;        
        float y = (rand() % (int)cloudSpawnRect.size.height) + cloudSpawnRect.origin.y;
        
        CCPoint cloudOffset = ccp(x,y);        
        Sprite * cloud = Sprite::spriteWithFile("cloud.png");
        m_bgNode->addChild(cloud, 0, cloudRatio, cloudOffset);
        m_clouds->addObject(cloud);
    }
    
    CCPoint mountainOffset = ccp(128,128);
    
    Sprite * mountains = Sprite::spriteWithFile("mountains.png");
    m_bgNode->addChild(mountains, -1, ccp(0.1,0.1), mountainOffset);
    m_mountains->addObject(mountains);
    
    mountainOffset.x+=318;
    mountains = Sprite::spriteWithFile("mountains.png");
    m_bgNode->addChild(mountains, -1, ccp(0.1,0.1), mountainOffset);
    m_mountains->addObject(mountains);
    
    Sprite * sprite = Sprite::spriteWithFile(bgName);
    m_bgNode->addChild(sprite, -1, ccp(0.5,0.5), offset);
    m_bgs->addObject(sprite);
    
    offset.x += 256;
    
    sprite = Sprite::spriteWithFile(bgName);
    m_bgNode->addChild(sprite, -1, ccp(0.5,0.5), offset);
    m_bgs->addObject(sprite);
    
    offset.x += 256;
    
    sprite = Sprite::spriteWithFile(bgName);
    m_bgNode->addChild(sprite, -1, ccp(0.5,0.5), offset);
    m_bgs->addObject(sprite);
    
    offset.x += 256;
    
    sprite = Sprite::spriteWithFile(bgName);
    m_bgNode->addChild(sprite, -1, ccp(0.5,0.5), offset);
    m_bgs->addObject(sprite);
    
    Sprite * boy = Sprite::spriteWithFile("boy.png");
    this->addChild(boy);
    boy->setPosition(ccp(50,50));
        
    this->scheduleUpdate();
    
    return true;
}

void ChaseStage::update(ccTime dt) {    
    CCPoint backgroundScrollVert = ccp(-500,0) ;
    m_bgNode->setPosition(ccpAdd(m_bgNode->getPosition(),ccpMult(backgroundScrollVert,dt)));
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float winWidth = winSize.width;
    
    CCObject * obj = NULL;
    CCARRAY_FOREACH(m_bgs, obj) {
        CCSprite * sprite = (CCSprite*)obj;
        float xPosition = m_bgNode->convertToWorldSpace(sprite->getPosition()).x;
        float size = sprite->getContentSize().width;
        if ( xPosition < -size ) {
            float offset = winWidth * 2;
            m_bgNode->incrementOffset(ccp(offset,0),sprite); 
        }            
    }    
    
    CCARRAY_FOREACH(m_clouds, obj) {
        CCSprite * sprite = (CCSprite*)obj;
        float xPosition = m_bgNode->convertToWorldSpace(sprite->getPosition()).x;
        float size = sprite->getContentSize().width;
        if ( xPosition < -size ) {
            float offset = size + winWidth;
            m_bgNode->incrementOffset(ccp(offset,0),sprite); 
        }    
    }
    
    CCARRAY_FOREACH(m_mountains, obj) {
        CCSprite * sprite = (CCSprite*)obj;
        float xPosition = m_bgNode->convertToWorldSpace(sprite->getPosition()).x;
        float size = sprite->getContentSize().width;
        if ( xPosition < -(size / 2) ) {
            float offset = winWidth + size;
            m_bgNode->incrementOffset(ccp(offset,0),sprite); 
        }            
    }
}

Scene * ChaseStage::scene() {
    
    Scene * scene = Scene::node();
    
    ChaseStage * layer = ChaseStage::node();
    
    scene->addChild(layer);
    
    return scene;
}