//
//  Beginning.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/12/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_Beginning_cpp
#define SheepGame_Beginning_cpp

#include "Stage.h"

class Sheep;
class Boy;

typedef cocos2d::CCMutableArray<Sheep*> SheepArray;

class Beginning : public Stage {

private:
    Boy * m_boy;
    SheepArray * m_sheepArray;
    
public:    
    virtual ~Beginning();
    
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static Scene * scene();
    
	// implement the "static node()" method manually
	LAYER_NODE_FUNC(Beginning);
};

#endif
