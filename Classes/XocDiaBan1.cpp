#include "XocDiaBan1.h"
#include "profile.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
Scene* XocDiaBan1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = XocDiaBan1::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
// on "init" you need to initialize your instance
bool XocDiaBan1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
		BACKGROUND_BLUE;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	PopupAvatar *popupAvatar = PopupAvatar::create();
	this->addChild(popupAvatar);

	auto avatar1 = Button::create("khungavataa.png");
	avatar1->setPosition(Vec2(origin.x +avatar1->getContentSize().width/2, origin.y+avatar1->getContentSize().height/2));
	avatar1->addTouchEventListener([=](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			popupAvatar->appear();
			break;
		}
	});
	this->addChild(avatar1, 100);
	////////////////
	auto avatar2 = Button::create("khungavataa.png");
	avatar2->setPosition(Vec2(origin.x + visibleSize.width - avatar2->getContentSize().width / 2,
		origin.y + avatar2->getContentSize().height / 2));
	avatar2->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar2, 100);
	////////////////
	auto avatar3 = Button::create("khungavataa.png");
	avatar3->setPosition(Vec2(origin.x + visibleSize.width - avatar3->getContentSize().width / 2,
		origin.y + avatar3->getContentSize().height / 2));
	avatar3->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar3, 100);
	////////////////
	auto avatar4 = Button::create("khungavataa.png");
	avatar4->setPosition(Vec2(origin.x + visibleSize.width - avatar4->getContentSize().width / 2,
		origin.y + avatar4->getContentSize().height / 2));
	avatar4->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar4, 100);
	////////////////
	auto avatar5 = Button::create("khungavataa.png");
	avatar5->setPosition(Vec2(origin.x + visibleSize.width - avatar5->getContentSize().width / 2,
		origin.y + avatar5->getContentSize().height / 2));
	avatar5->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar5, 100);
	////////////////
	auto avatar6 = Button::create("khungavataa.png");
	avatar6->setPosition(Vec2(origin.x + visibleSize.width - avatar6->getContentSize().width / 2,
		origin.y + avatar6->getContentSize().height / 2));
	avatar6->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar6, 100);
	////////////////
	auto avatar7 = Button::create("khungavataa.png");
	avatar7->setPosition(Vec2(origin.x + visibleSize.width - avatar7->getContentSize().width / 2,
		origin.y + avatar7->getContentSize().height / 2));
	avatar7->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar7, 100);
	////////////////
	auto avatar8 = Button::create("khungavataa.png");
	avatar8->setPosition(Vec2(origin.x + visibleSize.width - avatar8->getContentSize().width / 2,
		origin.y + avatar8->getContentSize().height / 2));
	avatar8->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar8, 100);
	////////////////
	auto avatar9 = Button::create("khungavataa.png");
	avatar9->setPosition(Vec2(origin.x + visibleSize.width - avatar9->getContentSize().width / 2,
		origin.y + avatar9->getContentSize().height / 2));
	avatar9->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar9, 100);
	////////////////
	auto avatar10 = Button::create("khungavataa.png");
	avatar10->setPosition(Vec2(origin.x + visibleSize.width - avatar10->getContentSize().width / 2,
		origin.y + avatar10->getContentSize().height / 2));
	avatar10->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		}
	});
	this->addChild(avatar10, 100);
	////////////////
	// connect to server
	_client = SocketIO::connect("http://127.0.0.1:8888", *this);
	_client->on("message", CC_CALLBACK_2(XocDiaBan1::onReceiveEvent, this));
	_client->emit("message", "tin nhan toi server");

	return true;
}

void XocDiaBan1::onConnect(SIOClient* client) {
	// SocketIO::connect success
}
void XocDiaBan1::onMessage(SIOClient* client, const std::string& data) {
	// SocketIO::send receive
}
void XocDiaBan1::onClose(SIOClient* client) {
	// SocketIO::disconnect success
}
void XocDiaBan1::onError(SIOClient* client, const std::string& data) {
	// SocketIO::failed
}

void XocDiaBan1::onReceiveEvent(SIOClient* client, const std::string& data) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto lbl = Label::createWithTTF(data, "fonts/Marker Felt.ttf", 24);
	lbl->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	this->addChild(lbl, 1000);
}