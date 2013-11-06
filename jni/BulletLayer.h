/*
 *  BulletLayer.h
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */

#ifndef BULLETLAYER_H_
#define BULLETLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class BulletLayer: public cocos2d::CCLayer {
public:
	BulletLayer();
	virtual ~BulletLayer();
	virtual bool init();
	CREATE_FUNC(BulletLayer);
	void addBullet();
	void startShoot(float delay=0.0f);

public:
	CCSpriteBatchNode* _bulletBatchNode;
};

#endif /* BULLETLAYER_H_ */
