#include "string"
#include "VisibleRect.h"
#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "cocos2d.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/1.5 ,
                                origin.y + pCloseItem->getContentSize().height/1.5));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
//    pMenu->runAction(CCMoveTo::create(0.5f, ccp(winSize.width/2.0f, winSize.height)));

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "随便抓,不要钱"
    // create and initialize a label
    CCDictionary *strings = CCDictionary::createWithContentsOfFile("font/chinese-simple.xml");
    const char *charTitle = ((CCString*) strings->objectForKey("title"))->m_sString.c_str();

    CCLabelTTF* pLabel = CCLabelTTF::create(charTitle, "Arial", TITLE_FONT_SIZE);

    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    cocos2d::CCLog("visibleSize.height = %2f\n origin.y = %2f", visibleSize.height, origin.y);
    cocos2d::CCLog("visibleSize.width = %2f\n origin.x = %2f",visibleSize.width, origin.x);
    // add the label as a child to this layer
//    this->addChild(pLabel, 1);

    CCSprite *pSprite_logo = CCSprite::create("ui_logo_001-hd.png");
    pSprite_logo->setPosition(ccp(origin.x + visibleSize.width/2, origin.y + visibleSize.height - pSprite_logo->getContentSize().height/1.5));
    this->addChild(pSprite_logo, 1);

    CCMenuItemImage *pMenu_item_start = CCMenuItemImage::create("starMenuButton02.png", "starMenuButton01.png", this, menu_selector(HelloWorld::replaceScenes));
    pMenu_item_start->setPosition(ccp(origin.x + visibleSize.width/2, origin.y + pMenu_item_start->getContentSize().height));

    CCMenu *pMenu_start = CCMenu::create(pMenu_item_start, NULL);
    pMenu_start->setPosition(CCPointZero);
    this->addChild(pMenu_start, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("startMenuBG.png");
    // position the sprite on the center of the screen
//    pSprite->setPosition(ccp(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
//    pSprite->setContentSize(cocos2d::CCSizeMake(visibleSize.width, visibleSize.height));
    pSprite->setPosition(ccp(origin.x + winSize.width/2,origin.y + winSize.height/2));
//    pSprite->setScale(1.0/CCEGLView::sharedOpenGLView()->getScaleX());
    cocos2d::CCLog("winSize.height = %2f\n", winSize.height);
    cocos2d::CCLog("winSize.width = %2f\n",winSize.width);
    cocos2d::CCLog("pSprite->getContentSize().width = %2f",pSprite->getContentSize().width);
    cocos2d::CCLog("pSprite->getContentSize().height = %2f",pSprite->getContentSize().height);

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::replaceScenes() {
	CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(2.0f, HelloWorld::scene()));
}
