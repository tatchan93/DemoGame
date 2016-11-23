﻿#include "XocDiaBan1.h"
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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create("backgruond.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background, 0);
	auto table = Sprite::create("xocdia/tablegray.jpg");
	table->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	table->setScale(0.8);
	this->addChild(table, 1);
	auto dia = Sprite::create("xocdia/bk_dia.png");
	dia->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + dia->getContentSize().height/2-10));
	dia->setScale(0.8);
	this->addChild(dia, 3);

	auto cuocLeft = Sprite::create("xocdia/bg_cuoc.png");
	cuocLeft->setScale(0.8);
	cuocLeft->setPosition(Vec2(origin.x + visibleSize.width / 2 - cuocLeft->getContentSize().width / 2 +35,
		origin.y + visibleSize.height / 2 + cuocLeft->getContentSize().height / 2));
	this->addChild(cuocLeft, 2);

	auto cuocRight = Sprite::create("xocdia/bg_cuoc.png");
	cuocRight->setScale(0.8);
	cuocRight->setRotation(180);
	cuocRight->setPosition(Vec2(origin.x + visibleSize.width / 2 + cuocRight->getContentSize().width / 2-35,
		origin.y + visibleSize.height / 2 + cuocRight->getContentSize().height / 2));
	this->addChild(cuocRight, 2);
auto khungCuoc2 = Sprite::create("xocdia/khung_cuoc.png");
	khungCuoc2->setScale(0.8);
	khungCuoc2->setPosition(Vec2(origin.x + visibleSize.width / 2 - khungCuoc2->getContentSize().width/2 -15,
		origin.y +visibleSize.height/2 -50 - khungCuoc2->getContentSize().height/2));
	this->addChild(khungCuoc2, 2);
	auto khungCuoc1 = Sprite::create("xocdia/khung_cuoc.png");
	khungCuoc1->setScale(0.8);
	khungCuoc1->setPosition(Vec2(origin.x + visibleSize.width / 2 - khungCuoc2->getContentSize().width - khungCuoc1->getContentSize().width/2- 30, 
		origin.y + visibleSize.height / 2 - 50 - khungCuoc2->getContentSize().height / 2));
	this->addChild(khungCuoc1, 2);
	

	auto khungCuoc3 = Sprite::create("xocdia/khung_cuoc.png");
	khungCuoc3->setScale(0.8);
	khungCuoc3->setPosition(Vec2(origin.x + visibleSize.width / 2 +15 +khungCuoc3->getContentSize().width/2,
		origin.y + visibleSize.height / 2 - 50 - khungCuoc2->getContentSize().height / 2));
	this->addChild(khungCuoc3, 2);

	auto khungCuoc4 = Sprite::create("xocdia/khung_cuoc.png");
	khungCuoc4->setScale(0.8);
	khungCuoc4->setPosition(Vec2(origin.x + visibleSize.width / 2+30 +khungCuoc3->getContentSize().width+ khungCuoc4->getContentSize().width/2,
		origin.y + visibleSize.height / 2 - 50 - khungCuoc2->getContentSize().height / 2));
	this->addChild(khungCuoc4, 2);

	auto avatar1 = Button::create("khungavataa.png");
	avatar1->setPosition(Vec2(origin.x +avatar1->getContentSize().width/2, origin.y+avatar1->getContentSize().height/2));
	avatar1->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
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
	_client->emit("message", "hi, this is new emit");

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
