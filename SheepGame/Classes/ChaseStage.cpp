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
#include "RunningWolf.h"

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
        
    static const float designWith = 480;
    static const float designHeight = 320;    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float scale = min((winSize.width / designWith), (winSize.height / designHeight));
    CCPoint center = ccp(winSize.width*0.5,winSize.height*0.5);
    
    {
        Sprite * sky = Sprite::spriteWithFile("sky.png");
        sky->setScale(scale);        
        m_bgNode->addChild(sky, -1, ccp(0.0,0.0), center);
    }
    
    {
        float cloudRatio = 0.05f;
        float yCloudStart = (winSize.height * 2) / 3;
        float yCloudHeight = winSize.height / 3;
        
        CCRect cloudSpawnRect = CCRectMake(0, yCloudStart, winSize.width, yCloudHeight);
        
        for (int i = 0; i < 7; ++i) {
            
            float x = (rand() % (int)cloudSpawnRect.size.width) + cloudSpawnRect.origin.x;        
            float y = (rand() % (int)cloudSpawnRect.size.height) + cloudSpawnRect.origin.y;
            
            float cloudRatioNoise = ((float)rand() / INT_MAX) * 0.01;
            cloudRatio += cloudRatioNoise;
            
            CCPoint cloudOffset = ccp(x,y);        
            Sprite * cloud = Sprite::spriteWithFile("cloud.png");
            cloud->setScale(scale);
            m_bgNode->addChild(cloud, 0, ccp(cloudRatio,cloudRatio), cloudOffset);
            m_clouds->addObject(cloud);
        }        
    }
    
    {
        CCPoint mountainOffset = ccp(128 * scale, 128 * scale * 0.7);
        
        Sprite * mountains = Sprite::spriteWithFile("mountains.png");
        mountains->setScale(scale);
        m_bgNode->addChild(mountains, -1, ccp(0.1,0.1), mountainOffset);
        m_mountains->addObject(mountains);
        
        mountainOffset.x+=mountains->getContentSize().width + winSize.width * 0.1;
        mountains = Sprite::spriteWithFile("mountains.png");
        mountains->setScale(scale);
        m_bgNode->addChild(mountains, -1, ccp(0.1,0.1), mountainOffset);
        m_mountains->addObject(mountains);        
    }
     
    {
        const char * bgName = "shinybg.png";
        Sprite * sprite = Sprite::spriteWithFile(bgName);
        sprite->setScale(scale);
        
        CCPoint offset = ccp((sprite->getContentSize().width / 2), (sprite->getContentSize().height * 0.2));
        
        do {
            sprite->setScale(scale);
            m_bgNode->addChild(sprite, -1, ccp(0.5,0.5), offset);
            m_bgs->addObject(sprite);            
            offset.x += sprite->getContentSize().width;
            sprite = Sprite::spriteWithFile(bgName);
        } while (offset.x < (winSize.width + (sprite->getContentSize().width * 2)));
    }
    
    m_wolf = RunningWolf::wolfWithStage(this);
    m_wolf->setScale(scale * 2);
    m_wolf->retain();
    
    float xWolf = winSize.width * 0.1 + m_wolf->getContentSize().width * 0.5;
    float yWolf = (winSize.height * 0.1) + m_wolf->getContentSize().height * 0.5;    
    m_wolf->setPosition(ccp(xWolf, yWolf));       
       
    this->scheduleUpdate();
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
    
    return true;
}

bool ChaseStage::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    Stage::ccTouchBegan(pTouch, pEvent);    
    m_wolf->jump();
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

ChaseStage::~ChaseStage() {
    m_bgNode->release();
    m_bgs->release();
    m_clouds->release();
    m_mountains->release();
    m_wolf->release();
}
