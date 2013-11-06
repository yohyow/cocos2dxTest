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
	CCPoint bulletPoint = ccp(planePoint.x + 2, planePoint.y + 2 + PlaneLayer::sharedPlane->getChildByTag(747)->getContentSize().height/2);
	bullet->setPosition(bulletPoint);

	float length = CCDirector::sharedDirector()->getWinSize().height + bullet->getContentSize().height/2 - bulletPoint.y;
	float velocity = 420/1;
	float realMoveDuration = length / velocity;
	CCFiniteTimeAction* actionMove=CCMoveTo::create(realMoveDuration,ccp(bulletPoint.x,CCDirector::sharedDirector()->getWinSize().height+bullet->getContentSize().height/2));
	CCFiniteTimeAction* actionDone=CCCallFuncN::create(this,callfuncN_selector(BulletLayer::bulletMoveFinished));//回调一个子弹结束处理函数
	CCSequence* sequence = CCSequence::create(actionMove,actionDone, NULL);
	bullet->runAction(sequence);


	this->_bulletBatchNode->addChild(bullet);
}

void BulletLayer::startShoot(float delay) {
	this->schedule(schedule_selector(BulletLayer::addBullet),0.15f,kCCRepeatForever,delay);
}

void BulletLayer::bulletMoveFinished() {

}

BulletLayer::~BulletLayer() {
	// TODO Auto-generated destructor stub
}

