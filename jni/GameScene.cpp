/*
 *  GameScene.cpp
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */

#include "GameScene.h"

GameScene::GameScene() {
	this->_gameLayer = NULL;
}

bool GameScene::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!CCScene::init());
		this->_gameLayer = GameLayer::create();
		CC_BREAK_IF(!this->_gameLayer);
		this->addChild(this->_gameLayer);
		bRet = true;
	}while(0);
	return bRet;
}

GameScene::~GameScene() {
}

