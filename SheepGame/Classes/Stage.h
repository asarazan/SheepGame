//
//  Stage.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/12/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_Stage_cpp
#define SheepGame_Stage_cpp

#include "SheepGame.h"

USING_NS_CC;

class Actor;
typedef cocos2d::CCMutableArray<Actor*> ActorArray;

class Stage : public Layer {
    
private:
    ActorArray m_actors;
    
public:
    
    void addActor(Actor * actor);
    void removeActor(Actor * actor);
    ActorArray * getActors();   
    
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    virtual bool init();
        
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static Scene * scene();
    
	// implement the "static node()" method manually
	LAYER_NODE_FUNC(Stage);
};



#endif
