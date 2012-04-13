//
//  Boy.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_Boy_cpp
#define SheepGame_Boy_cpp

#include "Actor.h"

class Boy : public Actor {

public:
    virtual ~Boy();
    
protected:
    virtual void tick(cocos2d::ccTime dt);
    virtual const String getImageName();
};

#endif
