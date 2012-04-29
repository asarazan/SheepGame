//
//  CustomParallaxNode.cpp
//  SheepGame
//
//  Created by Aaron Sarazan on 4/28/12.
//  Copyright (c) 2012 Greplin, Inc. All rights reserved.
//

#include "CustomParallaxNode.h"
#include "RepeatableLayer.h"

CustomParallaxNode::CustomParallaxNode() :
CCNode(), childrenNo(0) 
{}

CustomParallaxNode * CustomParallaxNode::node(void) {
	CustomParallaxNode * pRet = new CustomParallaxNode();
	pRet->autorelease();
	return pRet;
}

void CustomParallaxNode::addChild(cocos2d::CCNode *child, int z, float ratio) {
	assert(childrenNo < MAX_PARALLAX_CHILDREN);
	ratios[childrenNo++] = ratio;    
    CCNode::addChild(child, z);
}

void CustomParallaxNode::scroll(float offset) {
	int idx = 0;
    
    CCObject * child = NULL;
    CCARRAY_FOREACH(getChildren(), child) {
        RepeatableLayer * layer = (RepeatableLayer*)child;
        layer->scroll(offset * ratios[idx++]);
	}
}