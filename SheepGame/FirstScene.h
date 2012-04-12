//
//  FirstScene.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/11/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_FirstScene_cpp
#define SheepGame_FirstScene_cpp

#include "SGScene.h"

class Boy;
class Sheep;

typedef cocos2d::CCMutableArray<Sheep*> SheepArray;

class FirstScene : public SGScene {

private:
    Boy * m_boy;
    SheepArray * m_sheepArray;
        
protected:
    virtual bool init();
    
public:
    virtual ~FirstScene();
    static FirstScene * scene();
};

#endif
