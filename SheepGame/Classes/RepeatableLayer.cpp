//
//  RepeatableLayer.cpp
//
//  Created by Rolando Abarca on 12/13/09.
//

#import "RepeatableLayer.h"

USING_NS_CC;

RepeatableLayer * RepeatableLayer::layerWithFile(const char *file) {
	RepeatableLayer * layer = new RepeatableLayer();
    layer->initWithFile(file);
    layer->autorelease();
    
	layer->setAnchorPoint(CCPointZero);
	ccTexParams params = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
    layer->getTexture()->setTexParameters(&params);
    
	return layer;
}

void RepeatableLayer::draw() {
	glEnableClientState( GL_VERTEX_ARRAY); 
	glEnableClientState( GL_TEXTURE_COORD_ARRAY ); 
	glEnable( GL_TEXTURE_2D); 
    
    ccColor3B color = this->getColor();
	glColor4ub( color.r, color.g, color.b, this->getOpacity()); 
	//Adjust the texture matrix 
	glMatrixMode(GL_TEXTURE); 
	glPushMatrix(); 
	glLoadIdentity(); 
	//We are just doing horizontal scrolling here so only adjusting x 
	glTranslatef(texOffset.x/this->getContentSize().width, 0, 0); 
	//Draw the texture 
    getTexture()->drawAtPoint(CCPointZero);
	//Restore texture matrix and switch back to modelview matrix 
	glPopMatrix(); 
	glMatrixMode(GL_MODELVIEW); 
	glColor4ub( 255, 255, 255, 255); 
	glDisable( GL_TEXTURE_2D); 
	glDisableClientState(GL_VERTEX_ARRAY ); 
	glDisableClientState( GL_TEXTURE_COORD_ARRAY ); 
}

//
// adapted from
// http://www.codza.com/making-seamless-repeating-backgrounds-photoshop-cocos2d-iphone
// 
// it only scrolls on x-axis
//
void RepeatableLayer::scroll(float offset) {
	texOffset = ccpAdd(texOffset, CCPointMake(offset, 0.0f));
	CCSize contentSize = getTexture()->getContentSize();
	if (texOffset.x > contentSize.width) texOffset.x -= contentSize.width;
    if (texOffset.y > contentSize.height) texOffset.y -= contentSize.height;
    if (texOffset.x < 0) texOffset.x += contentSize.width;
    if (texOffset.y < 0) texOffset.y += contentSize.height;
}

void RepeatableLayer::scrollTest() {
    this->scroll(0.3f);
}