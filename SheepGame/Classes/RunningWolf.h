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
    bool m_isJumping;

    CCPoint m_dest;
    bool m_pursueDest;
    float m_speed;
    
private:
    virtual bool init(CCSpriteBatchNode * batch);
    void finishJumping();
    void update(ccTime dt);
    CCPoint destWithDest(const CCPoint & dest, ccTime dt);
    
public:
    static RunningWolf * wolfWithStage(Stage * stage);
    
    bool isJumping();
    bool jump(const CCPoint & dest);    
    bool run();
    
    void moveTowardPoint(const CCPoint & point);
    
    virtual ~RunningWolf();

};

#endif
