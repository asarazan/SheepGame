//
//  RepeatableLayer.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/28/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_RepeatableLayer_cpp
#define SheepGame_RepeatableLayer_cpp

USING_NS_CC;

class RepeatableLayer : public CCSprite {
private:
    CCPoint texOffset;
    CCPoint firstOffset;
    
public:
    static RepeatableLayer * layerWithFile(const char * file);
    void scrollTest();
    void scroll(float offset);    
    
    virtual void draw();
};

#endif
