/*
 *  PlaneLayer.cpp
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */
#include "PlaneLayer.h"

USING_NS_CC;

PlaneLayer* PlaneLayer::sharedPlane = NULL;//静态变量要在cpp里初始化
PlaneLayer::PlaneLayer() {
	// TODO Auto-generated constructor stub
}

PlaneLayer* PlaneLayer::create() {
	PlaneLayer* pRet = new PlaneLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedPlane = pRet;
		return pRet;
	}else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool PlaneLayer::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("ui/shoot.plist");

		CCSprite* hero = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("hero1.png"));
		hero->setPosition(ccp(size.width/2, hero->getContentSize().height/2));
		this->addChild(hero, 0, AIRPLANE);

		CCBlink* blink = CCBlink::create(1, 3);// 闪烁动画

		CCAnimation* animation = CCAnimation::create();// 帧动画
		animation->setDelayPerUnit(0.1f);
		animation->addSpriteFrame(cache->spriteFrameByName("hero1.png"));
		animation->addSpriteFrame(cache->spriteFrameByName("hero2.png"));

		CCAnimate* animate = CCAnimate::create(animation);

		hero->runAction(blink);
		hero->runAction(CCRepeatForever::create(animate));
		bRet = true;
	}while(0);
	return bRet;
}

PlaneLayer::~PlaneLayer() {
	// TODO Auto-generated destructor stub
}

