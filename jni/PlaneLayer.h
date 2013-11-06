/*
 *  PlaneLayer.h
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */

#ifndef PLANELAYER_H_
#define PLANELAYER_H_

#include "cocos2d.h"

const int AIRPLANE=747;

class PlaneLayer: public cocos2d::CCLayer {
public:
	PlaneLayer();
	virtual ~PlaneLayer();
	virtual bool init();
	static PlaneLayer* create();
public:
	static PlaneLayer* sharedPlane;
};

#endif /* PLANELAYER_H_ */
