/*
 *  GameLayer.h
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include "cocos2d.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"

class GameLayer: public cocos2d::CCLayer {
public:
	GameLayer();
	virtual ~GameLayer();
	CREATE_FUNC(GameLayer);
	virtual bool init();
	void backgroundMove();

public:
	// 实现滚动背景的两个成员变量
	cocos2d::CCSprite* background_one;
	cocos2d::CCSprite* background_two;
	PlaneLayer* _planeLayer;
	BulletLayer* _bulletLayer;
};

#endif /* GAMELAYER_H_ */
