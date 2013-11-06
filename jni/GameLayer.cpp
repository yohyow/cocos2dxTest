/*
 *  GameLayer.cpp
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */
#include "GameLayer.h"

USING_NS_CC;

GameLayer::GameLayer() {
}

bool GameLayer::init() {
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		// 把背景缓存起来 全局性的
		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("ui/shoot_background.plist");
		// 加载两个背景精灵
		this->background_one = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("background.png"));
		this->background_one->setAnchorPoint(ccp(0, 0));
		this->background_one->setPosition(ccp(0, 0));
		cocos2d::CCLog("background_one = width: %2f, height:%f", background_one->getContentSize().width, background_one->getContentSize().height);
		this->addChild(this->background_one);

		this->background_two = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("background.png"));
		this->background_two->setAnchorPoint(ccp(0, 0));
		this->background_two->setPosition(ccp(0, this->background_two->getContentSize().height - 2));// -2 让两个精灵重叠2像素 可以防止交接黑边的出现
		cocos2d::CCLog("background_two = width: %2f, height:%f", background_two->getContentSize().width, background_two->getContentSize().height);
		this->addChild(this->background_two);

		// 添加hero层
		this->_planeLayer = PlaneLayer::create();
		this->addChild(this->_planeLayer);

		this->_bulletLayer = BulletLayer::create();
		this->addChild(this->_bulletLayer);
		this->_bulletLayer->startShoot(0.15f);

		// 定义任务计划 执行背景滚动函数

		this->schedule(schedule_selector(GameLayer::backgroundMove), 0.01f);

		bRet = true;
	}while(0);
	return bRet;
}
//背景滚动函数
void GameLayer::backgroundMove() {
	this->background_one->setPositionY(this->background_one->getPositionY() - 2);
	this->background_two->setPositionY(this->background_one->getPositionY() + this->background_one->getContentSize().height - 2);
	// 当背景1彻底滚出屏幕时 这时背景2正好位于0,0坐标
	//而且跟背景1刚开始滚动时位置相同 又由于背景1和背景2 是同一张图片
	// 所以直接替换背景2为背景1
	if (this->background_two->getPositionY() == 0) {
		this->background_one->setPositionY(0);//注意: 背景2的高度为842, 所以每次-2, 至终会变为0, 否则永远不会是0 条件不成立 滚动失败
	}

}

GameLayer::~GameLayer() {
}

