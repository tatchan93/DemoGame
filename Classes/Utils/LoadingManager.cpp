//
//  LoadingManager.cpp
//  MyCards
//
//  Created by hungle on 6/20/16.
//
//

#include "LoadingManager.hpp"
#include "TLMNConfig.hpp"

LoadingManager::LoadingManager(){
}

LoadingManager::~LoadingManager(){
}

bool LoadingManager::init(){
    if(Node::init()){
        Size _visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 _origin = Director::getInstance()->getVisibleOrigin();
        auto darkSprite = LayerColor::create(Color4B(255, 255, 255, 0));
        darkSprite->setContentSize(_visibleSize);
        darkSprite->setOpacity(0);
        darkSprite->setPosition(_origin);
        this->addChild(darkSprite);
        
        auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
            return true;
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, darkSprite);
        
        auto progressbar = Sprite::createWithSpriteFrameName("loading.png");
        progressbar->setTag(TAG_SPRITE_LOADING);
        progressbar->setPosition(Vec2(_origin.x + _visibleSize.width/2,
                                      _origin.y+ _visibleSize.height/2));
        this->addChild(progressbar);
        
        this->setTag(TAG_POPUP_LOADING);
        return true;
    }
    return false;
}

void LoadingManager::showLoading() {
    if (this->getChildByTag(TAG_SPRITE_LOADING) != nullptr){
        auto sprite = (Sprite*)this->getChildByTag(TAG_SPRITE_LOADING);
        sprite->runAction(RepeatForever::create(RotateBy::create(0.1f, 30)));
    }
}

void LoadingManager::hideLoading() {
    auto scene = cocos2d::Director::getInstance()->getRunningScene();
    if(scene->getChildByTag(TAG_POPUP_LOADING) != nullptr){
        scene->removeChildByTag(TAG_POPUP_LOADING);
    }
}
