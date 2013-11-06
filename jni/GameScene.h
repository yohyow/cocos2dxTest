/*
 *  GameScene.h
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"
#include "GameLayer.h"

class GameScene: public cocos2d::CCScene {
public:
	GameScene();
	virtual ~GameScene();
	CREATE_FUNC(GameScene);
	virtual bool init();
	GameLayer* _gameLayer;
};

#endif /* GAMESCENE_H_ */
