//
//  RunningWolf.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/29/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_RunningWolf_cpp
#define SheepGame_RunningWolf_cpp

#include "Actor.h"

USING_NS_CC;

class RunningWolf : public CCSprite {
private:
    CCSpriteBatchNode * m_batch;
    
    CCAction * m_runAction;
    CCAction * m_jumpAction;   
    CCAction * m_jumpHeightAction;
    bool m_isJumping;
    
private:
    virtual bool init(CCSpriteBatchNode * batch);
    void finishJumping();
    
public:
    static RunningWolf * wolfWithStage(Stage * stage);
    
    bool isJumping();
    bool jump();    
    bool run();
    
    virtual ~RunningWolf();

};

#endif
