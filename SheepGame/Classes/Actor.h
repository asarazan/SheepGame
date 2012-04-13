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

class Stage;

class Actor : public Sprite, public cocos2d::CCTouchDelegate {
    
public:
    virtual bool init(Stage * stage);
    virtual void touch();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
protected:
    virtual void tick(cocos2d::ccTime dt);
    virtual const String getImageName() = 0;
    
private:    
};

#endif
