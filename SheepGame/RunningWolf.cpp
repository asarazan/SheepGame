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
    m_jumpHeightAction = CCJumpBy::actionWithDuration(1.0f, getPosition(), winSize.height * 0.1f, 1);
    m_jumpHeightAction->retain();
    
    run();
                    
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

bool RunningWolf::jump() {
    if (isJumping()) {
        return false;
    }
    
    m_isJumping = true;
    runAction(m_jumpAction);  
    runAction(m_jumpHeightAction);
    return true;
}

bool RunningWolf::run() {
    if (isJumping()) {
        return false;
    }
    
    runAction(m_runAction);
    return true;
}

RunningWolf::~RunningWolf() {
    m_jumpAction->release();
    m_runAction->release();
    m_batch->release();
}