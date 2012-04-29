//
//  ChaseStage.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/28/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_ChaseStage_cpp
#define SheepGame_ChaseStage_cpp

#include "Stage.h"
#include "CCParallaxNodeExtras.h"

USING_NS_CC;
using namespace jymc;

class RunningWolf;

class ChaseStage : public Stage {        

private:
    CCParallaxNodeExtras * m_bgNode;
    CCArray * m_bgs;
    CCArray * m_clouds;
    CCArray * m_mountains;
    RunningWolf * m_wolf;

    float m_scale;
public:
	LAYER_NODE_FUNC(ChaseStage);
	static Scene * scene(void);
    virtual bool init(void);
    
    virtual void update(ccTime dt);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual ~ChaseStage();
};

#endif
