#include "PhongCho.h"
#include "ui/CocosGUI.h"
#include "TienLenMienNam.h"
USING_NS_CC;
using namespace ui;
Scene* PhongCho::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PhongCho::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

Scene *gameXito;
Scene *gameTala;
Scene *gameXocdia;
Scene *gameSam;
Scene *gamePhom;
// on "init" you need to initialize your instance
bool PhongCho::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundMenu = Sprite::create("backgruond.png");
	backgroundMenu->setPosition(visibleSize / 2);
	this->addChild(backgroundMenu, 0);

	auto chaomung = Sprite::create("chaomung.png");
	chaomung->setPosition(Vec2(origin.x + visibleSize.width /2,
		origin.y + visibleSize.height - chaomung->getContentSize().height));
	this->addChild(chaomung, 0);

	auto loa = Sprite::create("loa.png");
	loa->setPosition(Vec2(300, 670));
	this->addChild(loa, 0);

	auto label = Label::createWithTTF("Chào mừng bạn đã đến với Game Bài Đổi Thưởng BigKen Online",
		"fonts/Marker Felt.ttf", 25);
	label->setPosition(Vec2(330, 670));
	label->setColor(Color3B::WHITE);
	label->setZOrder(100);
	this->addChild(label);

	auto menu = Sprite::create("menu.png");
	menu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + menu->getContentSize().height / 2));
	this->addChild(menu);

	auto back = Button::create("iconback.png");
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2,
		origin.y + visibleSize.height - back->getContentSize().height / 2));
	back->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			auto dangnhap = Scene::create();
			Director::getInstance()->pushScene(dangnhap);
			break;
		}
	});
	this->addChild(back);

	auto phone = Button::create("icon-phone.png");
	phone->setPosition(Vec2(origin.x + phone->getContentSize().width*1.5,
		origin.y + visibleSize.height - phone->getContentSize().height / 2));
	phone->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			auto dienthoai = Scene::create();
			Director::getInstance()->pushScene(dienthoai);
			break;
		}
	});
	this->addChild(phone);

	auto homthu = Button::create("homthu.png");
	homthu->setPosition(Vec2(origin.x + visibleSize.width - homthu->getContentSize().width / 2,
		origin.y + visibleSize.height - homthu->getContentSize().height / 2));
	homthu->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:

			break;
		}
	});
	this->addChild(homthu);

	auto DoiThuong = Button::create("DOI-THUONG.png");
	DoiThuong->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + DoiThuong->getContentSize().height / 2));
	this->addChild(DoiThuong);

	auto caidat = Button::create("CAI-DAT.png");
	caidat->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width / 2,
		origin.y + caidat->getContentSize().height / 2));
	this->addChild(caidat);

	auto banbe = Button::create("banbe.png");
	banbe->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width,
		origin.y + banbe->getContentSize().height / 2));
	this->addChild(banbe);

	auto xephang = Button::create("XEP-HANG.png");
	xephang->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width
		- xephang->getContentSize().width*1.2, origin.y + xephang->getContentSize().height / 2));
	this->addChild(xephang);

	auto napxu = Button::create("NAP-XU.png");
	napxu->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width
		- xephang->getContentSize().width - napxu->getContentSize().width*1.7,	origin.y + napxu->getContentSize().height / 2));
	this->addChild(napxu);

	auto khungavatar= Button::create("khungavataa.png");
	khungavatar->setPosition(Vec2(origin.x + khungavatar->getContentSize().width / 2,
		origin.y + khungavatar->getContentSize().height / 2));
	this->addChild(khungavatar);

	auto label1 = Label::createWithTTF("NganNguyen", "fonts/Marker Felt.ttf", 30);
	label1->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + khungavatar->getContentSize().height - label1->getContentSize().height));
	label1->setZOrder(100);
	this->addChild(label1);

	auto label2 = Label::createWithTTF("ID: 25251325", "fonts/Marker Felt.ttf", 25);
	label2->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + label2->getContentSize().height));
	label2->setZOrder(100);
	this->addChild(label2);

	auto vip = Sprite::create("vip1.png");
	vip->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + label2->getContentSize().height*2.4));
	this->addChild(vip);

	auto tienken = Button::create("xu.png");
	tienken->setPosition(Vec2(origin.x + visibleSize.width / 2 - tienken->getContentSize().width / 1.1,
		origin.y + tienken->getContentSize().height * 2));
	tienken->setScale(0.8);
	this->addChild(tienken);

	auto tienxu = Button::create("xu.png");
	tienxu->setPosition(Vec2(origin.x + visibleSize.width / 2 - tienxu->getContentSize().width / 1.1,
		origin.y + tienxu->getContentSize().height / 1.5));
	tienxu->setScale(0.8);
	this->addChild(tienxu);

	auto gamephom = Button::create("phom.png");
	gamephom->setPosition(Vec2(origin.x + gamephom->getContentSize().width *1.3,
		origin.y + visibleSize.height - gamephom->getContentSize().height/1.4));
	gamephom->setScale(0.8);
	gamephom->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			gamePhom = Scene::create();
			Director::getInstance()->replaceScene(gamePhom);
			auto back = Button::create("iconback.png");
			back->setPosition(Vec2(origin.x + back->getContentSize().width / 2,
				origin.y + visibleSize.height - back->getContentSize().height / 2));
			back->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
				switch (type)
				{
				case cocos2d::ui::Widget::TouchEventType::BEGAN:
					break;
				case cocos2d::ui::Widget::TouchEventType::ENDED:
					Director::getInstance()->replaceScene(PhongCho::createScene());
					break;
				}
			});
			gamePhom->addChild(back);
			break;
		}
	});
	this->addChild(gamephom);

	auto gameTLMN = Button::create("tlmn.png");
	gameTLMN->setPosition(Vec2(origin.x + gamephom->getContentSize().width *1.3,
		origin.y + visibleSize.height - gamephom->getContentSize().height*1.45));
	gameTLMN->setScale(0.8);
	gameTLMN->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TienLenMienNam::createScene());
			break;
		}
	});
	this->addChild(gameTLMN);

	auto gamexocdia = Button::create("xocdia.png");
	gamexocdia->setPosition(Vec2(origin.x + gamephom->getContentSize().width * 3.5,
		origin.y + visibleSize.height - gamephom->getContentSize().height*1.45));
	gamexocdia->setScale(0.8);
	gamexocdia->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			gameXocdia = Scene::create();
			Director::getInstance()->replaceScene(gameXocdia);
			auto back = Button::create("iconback.png");
			back->setPosition(Vec2(origin.x + back->getContentSize().width / 2,
				origin.y + visibleSize.height - back->getContentSize().height / 2));
			back->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
				switch (type)
				{
				case cocos2d::ui::Widget::TouchEventType::BEGAN:
					break;
				case cocos2d::ui::Widget::TouchEventType::ENDED:
					Director::getInstance()->replaceScene(PhongCho::createScene());
					break;
				}
			});
			gameXocdia->addChild(back);
			break;
		}
	});
	this->addChild(gamexocdia);

	auto gamesam = Button::create("sam.png");
	gamesam->setPosition(Vec2(origin.x + gamephom->getContentSize().width *2.4,
		origin.y + visibleSize.height - gamephom->getContentSize().height*1.45));
	gamesam->setScale(0.82);
	gamesam->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			gameSam = Scene::create();
			Director::getInstance()->replaceScene(gameSam);
			auto back = Button::create("iconback.png");
			back->setPosition(Vec2(origin.x + back->getContentSize().width / 2,
				origin.y + visibleSize.height - back->getContentSize().height / 2));
			back->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
				switch (type)
				{
				case cocos2d::ui::Widget::TouchEventType::BEGAN:
					break;
				case cocos2d::ui::Widget::TouchEventType::ENDED:
					Director::getInstance()->replaceScene(PhongCho::createScene());
					break;
				}
			});
			gameSam->addChild(back);
			break;
		}
	});
	this->addChild(gamesam);

	auto gametala = Button::create("TA-LA.png");
	gametala->setPosition(Vec2(origin.x + gamephom->getContentSize().width * 3.5,
		origin.y + visibleSize.height - gamephom->getContentSize().height / 1.4));
	gametala->setScale(0.8);
	gametala->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			gameTala = Scene::create();
			Director::getInstance()->replaceScene(gameTala);
			auto back = Button::create("iconback.png");
			back->setPosition(Vec2(origin.x + back->getContentSize().width / 2,
				origin.y + visibleSize.height - back->getContentSize().height / 2));
			back->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
				switch (type)
				{
				case cocos2d::ui::Widget::TouchEventType::BEGAN:
					break;
				case cocos2d::ui::Widget::TouchEventType::ENDED:
					Director::getInstance()->replaceScene(PhongCho::createScene());
					break;
				}
			});
			gameTala->addChild(back);
			break;
		}
	});
	this->addChild(gametala);

	auto gamexito = Button::create("xito.png");
	gamexito->setPosition(Vec2(origin.x + gamephom->getContentSize().width *2.4,
		origin.y + visibleSize.height - gamephom->getContentSize().height / 1.4));
	gamexito->setScale(0.8);
	gamexito->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			gameXito = Scene::create();
			Director::getInstance()->replaceScene(gameXito);
			break;
		}
	});
	this->addChild(gamexito);

	auto nextleft = Button::create("next1.png");
	nextleft->setPosition(Vec2(origin.x + nextleft->getContentSize().width,
		origin.y + visibleSize.height / 2));
	this->addChild(nextleft);

	auto nextright = Button::create("next.png");
	nextright->setPosition(Vec2(origin.x + visibleSize.width - nextright->getContentSize().width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(nextright);

    return true;
}
bool CreatgameXito()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto back = Button::create("iconback.png");
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2,
		origin.y + visibleSize.height - back->getContentSize().height / 2));
	back->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(PhongCho::createScene());
			break;
		}
	});
	gameXito->addChild(back, 0);
	return (true);
}