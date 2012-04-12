//
//  SGScene.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_SGScene_cpp
#define SheepGame_SGScene_cpp

#include "cocos2d.h"
#include "SheepGame.h"

class Actor;
typedef cocos2d::CCMutableArray<Actor*> ActorArray;

class SGScene : public Scene, public cocos2d::CCTouchDelegate {
    
private:
    ActorArray m_actors;
    Layer * m_layer;
    
    void touch();

public:
    SGScene();
    virtual ~SGScene();
    
    void addActor(Actor * actor);
    void removeActor(Actor * actor);
    ActorArray * getActors();
    
protected:
    virtual bool init();    
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
};

#endif
