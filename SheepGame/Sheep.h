//
//  Sheep.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_Sheep_cpp
#define SheepGame_Sheep_cpp

#include "Actor.h"

class SGScene;
class Boy;

class Sheep : public Actor {
    
private:
    Boy * m_boy;
    void moveToBoy();
    
public:
    virtual bool init(SGScene * scene, Boy * boy);
    
protected:
    virtual void tick(cocos2d::ccTime dt);
    virtual const String getImageName();
    virtual void touch();
    virtual ~Sheep();
};

#endif
