//
//  CustomParallaxNode.h
//  SheepGame
//
//  Created by Aaron Sarazan on 4/28/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#ifndef SheepGame_CustomParallaxNode_cpp
#define SheepGame_CustomParallaxNode_cpp

USING_NS_CC;

#define MAX_PARALLAX_CHILDREN 25

class CustomParallaxNode : public CCNode {

private:    
	float ratios[MAX_PARALLAX_CHILDREN];
	int childrenNo;
    CustomParallaxNode(void);
    
public:
    
    static CustomParallaxNode * node(void);
    
    void addChild(CCNode * child, int z, float ratio);
    void scroll(float offset);
};

#endif
