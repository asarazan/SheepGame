//
//  Actor.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_Actor_cpp
#define SheepGame_Actor_cpp

#include "SheepGame.h"

class SGScene;

class Actor : public Sprite, public cocos2d::CCTouchDelegate {
    
public:
    virtual bool init(SGScene * scene);
    
protected:
    virtual void tick(cocos2d::ccTime dt);
    virtual void touch();
    virtual const String getImageName() = 0;
    
private:    
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
};

#endif
