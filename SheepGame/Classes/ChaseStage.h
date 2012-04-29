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

class ChaseStage : public Stage {        

private:
    CCParallaxNodeExtras * m_bgNode;
    CCArray * m_bgs;
    CCArray * m_clouds;
    CCArray * m_mountains;

public:
	LAYER_NODE_FUNC(ChaseStage);
	static Scene * scene();
    virtual bool init();
    
    virtual void update(ccTime dt);
};

#endif
