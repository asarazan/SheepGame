//
//  RunningWolf.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/29/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "RunningWolf.h"
#include "Stage.h"

bool RunningWolf::init(CCSpriteBatchNode * batch) {
    if (!CCSprite::initWithSpriteFrameName("wolf_0.png")) {
        return false;
    }
    
    m_speed = 50;
    
    m_batch = batch;
    m_batch->retain();
    m_batch->addChild(this);
    
    // Set up running animation
    CCMutableArray<CCSpriteFrame*> runFrames;
    for (int i = 0; i < 5; ++i) {
        char name[11];
        sprintf(name, "wolf_%i.png",i);
        name[10] = '\0';
        runFrames.addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));
    }
        
    CCAnimation * runAnim = CCAnimation::animationWithFrames(&runFrames, 0.1f);
    m_runAction = CCRepeatForever::actionWithAction(CCAnimate::actionWithAnimation(runAnim, true));
    m_runAction->retain();
    
    // Set up jumping animation
    CCMutableArray<CCSpriteFrame*> jumpFrames;
    jumpFrames.addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("wolf_0.png"));
    jumpFrames.addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("wolf_1.png"));
    
    CCAnimation * jumpAnim = CCAnimation::animationWithFrames(&jumpFrames, 0.5f);
    m_jumpAction =     
    CCSequence::actionOneTwo(
                             CCAnimate::actionWithDuration(1.0f, jumpAnim, false),
                             CCCallFunc::actionWithTarget(this, callfunc_selector(RunningWolf::finishJumping)));
    m_jumpAction->retain();
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
  
    m_batch->getTexture()->setAliasTexParameters();
    getTexture()->setAliasTexParameters();
    
    run();
    scheduleUpdate();
                    
    return true;
}

RunningWolf * RunningWolf::wolfWithStage(Stage *stage) {
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Chase.plist");
    CCSpriteBatchNode * batch = CCSpriteBatchNode::batchNodeWithFile("Chase.png");
    
    RunningWolf * pRet = new RunningWolf();
    pRet->init(batch);
    stage->cocos2d::CCNode::addChild(pRet->m_batch);
    pRet->autorelease();
    
    return pRet;
}

void RunningWolf::finishJumping() {
    m_isJumping = false;
}

bool RunningWolf::isJumping() {
    return m_isJumping;
}

CCPoint RunningWolf::destWithDest(const CCPoint & dest, ccTime dt) {   

    bool backward = dest.x < getPosition().x;
    float d = m_speed * dt * (backward ? -1 : 1);    
    
    CCPoint pos = getPosition();
    pos.x += d;
    
    if ((!backward && pos.x > dest.x) || 
        (backward && pos.x < dest.x)) {
        pos.x = dest.x;
    }
    
    return pos;
}

bool RunningWolf::jump(const CCPoint & dest) {
    if (isJumping()) {
        return false;
    }
    
    m_isJumping = true;
    runAction(m_jumpAction);  
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCPoint pos = getPosition();
    CCPoint finalDest = destWithDest(dest, 1);
    
    CCAction * jumpHeightAction = 
    CCJumpTo::actionWithDuration(1.0f, finalDest, winSize.height * 0.1f, 1);
    runAction(jumpHeightAction);
    return true;
}

bool RunningWolf::run() {
    if (isJumping()) {
        return false;
    }
    
    runAction(m_runAction);
    return true;
}

void RunningWolf::moveTowardPoint(const CCPoint &point) {
    m_pursueDest = !CCPoint::CCPointEqualToPoint(point,CCPointZero);
    m_dest = point;
}

void RunningWolf::update(ccTime dt) {
    if (!m_pursueDest) {
        return;
    }
    
    if (fabsf(m_dest.x - getPosition().x) < 5) {
        return;
    }
    
    CCPoint dest = destWithDest(m_dest, dt);
    setPosition(dest);
}

RunningWolf::~RunningWolf() {
    m_jumpAction->release();
    m_runAction->release();
    m_batch->release();
}