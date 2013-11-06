/*
 *  BulletLayer.cpp
 *
 *  Created on: 2013-11-6
 *
 *  Author: HHP
 */

#include "BulletLayer.h"
#include "PlaneLayer.h"

USING_NS_CC;

BulletLayer::BulletLayer() {
	// TODO Auto-generated constructor stub
}

bool BulletLayer::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!(CCLayer::init()));
		CCTexture2D* _texture = CCTextureCache::sharedTextureCache()->textureForKey("ui/shoot.png");
		this->_bulletBatchNode = CCSpriteBatchNode::createWithTexture(_texture);
		this->addChild(this->_bulletBatchNode);
		bRet = true;
	}while(0);
	return bRet;
}

void BulletLayer::addBullet() {
	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	CCSprite* bullet = CCSprite::createWithSpriteFrame(cache->spriteFrameByName("bullet1.png"));
	CCPoint planePoint = PlaneLayer::sharedPlane->getChildByTag(747)->getPosition();
	CCPoint bulletPoint = ccp(planePoint.x, planePoint.y + PlaneLayer::sharedPlane->getChildByTag(747)->getContentSize().height/2);
	bullet->setPosition(bulletPoint);
	this->_bulletBatchNode->addChild(bullet);
}

void BulletLayer::startShoot(float delay) {
	this->schedule(schedule_selector(BulletLayer::addBullet),0.01f,kCCRepeatForever,delay);
}

BulletLayer::~BulletLayer() {
	// TODO Auto-generated destructor stub
}

