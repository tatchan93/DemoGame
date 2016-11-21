///@ Popup.cpp


#include "Popup.hpp"

bool Popup::init() {
    if (!Node::init())
        return false;
    this->setAnchorPoint(Point::ZERO);
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    background = LayerColor::create(Color4B(0,0,0,160));
    background->setContentSize(Size(960, 600));
    background->setPosition(Vec2(origin.x + background->getContentSize().width / 5
		,origin.y + background->getContentSize().height / 6));
    background->setOpacity(0);

    this->addChild(background);
    
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, background);

    m_popupLayer = Layer::create();
    m_popupLayer->setPosition(Vec2(origin.x,origin.y - visibleSize.height*1.5));
    addChild(m_popupLayer);

	backgroundPopup = Sprite::create("backgruondPopup.png");
	backgroundPopup->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2.5));
	backgroundPopup->setScaleY(0.8f);
	m_popupLayer->addChild(backgroundPopup, 100);

    disablePopup = true;
    return true;
}

void Popup::disappear() {
    
    auto callDisappear = CallFunc::create([this](){
        background->runAction(FadeTo::create(0.15f, 0));
        disablePopup = true;
        this->removeFromParentAndCleanup(true);
    });
    m_popupLayer->runAction(Sequence::create(MoveTo::create(0.15f,Vec2(origin.x, origin.y - visibleSize.height)),
                                             callDisappear, NULL));
}

void Popup::appear() {
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    
    touchListener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (!rect.containsPoint(locationInNode)){
            this->disappear();
            return true;
        }
        return false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, backgroundPopup);
    
    auto callAppear = CallFunc::create([this](){
        background->runAction(FadeTo::create(0.15f, 200));
        disablePopup = false;
    });
    
    m_popupLayer->runAction(Sequence::create(MoveTo::create(0.15f,Vec2(origin.x, origin.y + background->getContentSize().height / 7)),
                                             callAppear, nullptr));
    
}

void Popup::onExit() {
    
    Node::onExit();
}
