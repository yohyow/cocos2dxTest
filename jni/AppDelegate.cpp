#include "AppDelegate.h"

#include <map>
#include <vector>
#include <string>

#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);
	// Set the design resolution
	pEGLView->setDesignResolutionSize(designResolutionSize.width,
			designResolutionSize.height, kResolutionShowAll);
	CCSize frameSize = pEGLView->getFrameSize();

//	float ratio = frameSize.width / frameSize.height;
//	float ratio1 = largeDesignResolutionSize.width / largeDesignResolutionSize.height;
//	float ratio2 = mediumDesignResolutionSize.width / mediumDesignResolutionSize.height;
//	float ratio3 = smallDesignResolutionSize.width / smallDesignResolutionSize.height;
//	float d1 = abs(ratio - ratio1);
//	float d2 = abs(ratio - ratio2);
//	float d3 = abs(ratio - ratio3);
//	std::map<float, CCSize> designSize;
//	designSize[d1] = largeDesignResolutionSize;
//	designSize[d2] = mediumDesignResolutionSize;
//	designSize[d3] = smallDesignResolutionSize;
//	std::map<float, CCSize>::reverse_iterator iter = designSize.rbegin();

	//得到key最大的，因此我这里是横屏，所以以高度为基准，为了确保缩放后宽度能全屏，所以选取宽高比最大的为设计方案
//	CCSize designResolutionSize = iter->second;

	//pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
//	pEGLView->setDesignResolutionSize(designResolutionSize.width,
//			designResolutionSize.height, kResolutionShowAll);

	//pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionExactFit);

//	if (frameSize.height > mediumResource.size.height) {
//		CCFileUtils::sharedFileUtils()->setResourceDirectory(
//				largeResource.directory);
//		pDirector->setContentScaleFactor(
//				largeResource.size.height / designResolutionSize.height);
//	} else if (frameSize.height > smallResource.size.height) {
//		CCFileUtils::sharedFileUtils()->setResourceDirectory(
//				mediumResource.directory);
//		pDirector->setContentScaleFactor(
//				mediumResource.size.height / designResolutionSize.height);
//	} else {
//		CCFileUtils::sharedFileUtils()->setResourceDirectory(
//				smallResource.directory);
//		pDirector->setContentScaleFactor(
//				smallResource.size.height / designResolutionSize.height);
//	}

	vector<string> searchPath;

	// In this demo, we select resource according to the frame's height.
	// If the resource size is different from design resolution size, you need to set contentScaleFactor.
	// We use the ratio of resource's height to the height of design resolution,
	// this can make sure that the resource's height could fit for the height of design resolution.

	// if the frame's height is larger than the height of medium resource size, select large resource.
	if (frameSize.height > mediumResource.size.height) {
		searchPath.push_back(largeResource.directory);

		pDirector->setContentScaleFactor(
				MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
	// if the frame's height is larger than the height of small resource size, select medium resource.
	else if (frameSize.height > smallResource.size.height) {
		searchPath.push_back(mediumResource.directory);

		pDirector->setContentScaleFactor(
				MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
	}
	// if the frame's height is smaller than the height of medium resource size, select small resource.
	else {
		searchPath.push_back(smallResource.directory);

		pDirector->setContentScaleFactor(
				MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
	}

	// set searching path
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

	// turn on display FPS
	pDirector->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	// TODO Ӧ���������
	CCScene *pScene = HelloWorld::scene();

	// run
	pDirector->runWithScene(pScene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	CCDirector::sharedDirector()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	CCDirector::sharedDirector()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
