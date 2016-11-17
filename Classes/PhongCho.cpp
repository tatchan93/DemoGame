#include "PhongCho.h"
#include "ui/CocosGUI.h"
#include "TienLenMienNam.h"
#include "Phom.h"
#include "Sam.h"
#include "TaLa.h"
#include "Xito.h"
#include "SimpleAudioEngine.h"
#include "PopupAvatar.h"
#include "XocDia.h"
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

	

	ui::ScrollView *scrollview = ui::ScrollView::create();
	scrollview->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	scrollview->setContentSize(Size(1280, 720));
	scrollview->setInnerContainerSize(Size(2560, 720));
	scrollview->setBackGroundColor(Color3B(0, 0, 0));
	scrollview->setBackGroundColorOpacity(0);
	scrollview->setBounceEnabled(true);
	scrollview->setAnchorPoint(Vec2(0.5, 0.5));
	scrollview->setPosition(visibleSize / 2);
	for (int i = 0; i < 30; i++){
		auto gamephom = Button::create("phom.png");
		gamephom->setPosition(Vec2(origin.x + gamephom->getContentSize().width *1.3,
			origin.y + visibleSize.height - gamephom->getContentSize().height / 1.4));
		gamephom->setScale(0.8f);
		gamephom->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				gamePhom = Phom::createScene();
				Director::getInstance()->replaceScene(gamePhom);
				break;
			}
		});
		scrollview->addChild(gamephom);

		auto gameTLMN = Button::create("tlmn.png");
		gameTLMN->setPosition(Vec2(origin.x + gamephom->getContentSize().width *1.3,
			origin.y + visibleSize.height - gamephom->getContentSize().height*1.45));
		gameTLMN->setScale(0.8f);
		gameTLMN->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->replaceScene(TienLenMienNam::createScene());
				break;
			}
		});
		scrollview->addChild(gameTLMN);

		auto gamexocdia = Button::create("xocdia.png");
		gamexocdia->setPosition(Vec2(origin.x + gamephom->getContentSize().width * 3.5,
			origin.y + visibleSize.height - gamephom->getContentSize().height*1.45));
		gamexocdia->setScale(0.8f);
		gamexocdia->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				gameXocdia = XocDia::createScene();
				Director::getInstance()->replaceScene(gameXocdia);
				break;
			}
		});
		scrollview->addChild(gamexocdia);

		auto gamesam = Button::create("sam.png");
		gamesam->setPosition(Vec2(origin.x + gamephom->getContentSize().width *2.4,
			origin.y + visibleSize.height - gamephom->getContentSize().height*1.45));
		gamesam->setScale(0.82f);
		gamesam->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				gameSam = Sam::createScene();
				Director::getInstance()->replaceScene(gameSam);
				break;
			}
		});
		scrollview->addChild(gamesam);

		auto gametala = Button::create("TA-LA.png");
		gametala->setPosition(Vec2(origin.x + gamephom->getContentSize().width * 3.5,
			origin.y + visibleSize.height - gamephom->getContentSize().height / 1.4));
		gametala->setScale(0.8f);
		gametala->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				gameTala = TaLa::createScene();
				Director::getInstance()->replaceScene(gameTala);
				break;
			}
		});
		scrollview->addChild(gametala);

		auto gamexito = Button::create("xito.png");
		gamexito->setPosition(Vec2(origin.x + gamephom->getContentSize().width *2.4,
			origin.y + visibleSize.height - gamephom->getContentSize().height / 1.4));
		gamexito->setScale(0.8f);
		gamexito->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				gameXito = XiTo::createScene();
				Director::getInstance()->replaceScene(gameXito);
				break;
			}
		});
		scrollview->addChild(gamexito);
	}
	this->addChild(scrollview, 2);

	auto backgroundMenu = Sprite::create("backgruond.png");
	backgroundMenu->setPosition(visibleSize / 2);
	this->addChild(backgroundMenu, 0);

	auto chaomung = Sprite::create("chaomung.png");
	chaomung->setPosition(Vec2(origin.x + visibleSize.width /2,
		origin.y + visibleSize.height - chaomung->getContentSize().height));
	this->addChild(chaomung, 2);

	auto loa = Sprite::create("loa.png");
	loa->setPosition(Vec2(300, 670));
	this->addChild(loa, 2);

	auto menu = Sprite::create("menu.png");
	menu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + menu->getContentSize().height / 2));
	this->addChild(menu, 2);

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
	this->addChild(back, 2);

	auto layer = LayerGradient::create(Color4B(255, 0, 0, 255), Color4B(255, 0, 255, 255));
	layer->setContentSize(Size(280, 80));
	layer->setPosition(Vec2(1500, 950));
	addChild(layer);

	auto phone = Button::create("icon-phone.png");
	phone->setPosition(Vec2(origin.x + phone->getContentSize().width*1.5,
		origin.y + visibleSize.height - phone->getContentSize().height / 2));
	phone->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			auto move = MoveTo::create(0.5, Point(Vec2(200, 200)));
			layer->runAction(move);
			break;
		}
	});
	this->addChild(phone, 2);

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
	this->addChild(homthu, 2);

	auto DoiThuong = Button::create("DOI-THUONG.png");
	DoiThuong->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + DoiThuong->getContentSize().height / 2));
	this->addChild(DoiThuong, 2);

	PopupAvatar  *m_PopupAvatar = PopupAvatar::create();
	m_PopupAvatar->setScaleY(0.8f);
	this->addChild(m_PopupAvatar, 2);

	auto caidat = Button::create("CAI-DAT.png");
	caidat->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width / 2,
		origin.y + caidat->getContentSize().height / 2));
	caidat->addTouchEventListener([=](Ref *sender, Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			m_PopupAvatar->appear();
			break;
		default:
			break;
		}
	});
	this->addChild(caidat, 2);

	auto banbe = Button::create("banbe.png");
	banbe->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width,
		origin.y + banbe->getContentSize().height / 2));
	this->addChild(banbe, 2);

	auto xephang = Button::create("XEP-HANG.png");
	xephang->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width
		- xephang->getContentSize().width*1.2, origin.y + xephang->getContentSize().height / 2));
	this->addChild(xephang, 2);

	auto napxu = Button::create("NAP-XU.png");
	napxu->setPosition(Vec2(origin.x + visibleSize.width - caidat->getContentSize().width - banbe->getContentSize().width
		- xephang->getContentSize().width - napxu->getContentSize().width*1.7,	origin.y + napxu->getContentSize().height / 2));
	this->addChild(napxu, 2);

	auto khungavatar= Button::create("khungavataa.png");
	khungavatar->setPosition(Vec2(origin.x + khungavatar->getContentSize().width / 2,
		origin.y + khungavatar->getContentSize().height / 2));
	this->addChild(khungavatar, 2);

	auto label1 = Label::createWithTTF("NganNguyen", "fonts/Marker Felt.ttf", 30);
	label1->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + khungavatar->getContentSize().height - label1->getContentSize().height));
	this->addChild(label1, 100);

	auto label2 = Label::createWithTTF("ID: 25251325", "fonts/Marker Felt.ttf", 25);
	label2->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + label2->getContentSize().height));
	this->addChild(label2, 100);

	auto vip = Sprite::create("vip1.png");
	vip->setPosition(Vec2(origin.x + khungavatar->getContentSize().width + label1->getContentSize().width / 1.5,
		origin.y + label2->getContentSize().height*2.4));
	this->addChild(vip, 2);

	auto tienken = Button::create("xu.png");
	tienken->setPosition(Vec2(origin.x + visibleSize.width / 2 - tienken->getContentSize().width / 1.1,
		origin.y + tienken->getContentSize().height * 2));
	tienken->setScale(0.8f);
	this->addChild(tienken, 2);

	auto tienxu = Button::create("xu.png");
	tienxu->setPosition(Vec2(origin.x + visibleSize.width / 2 - tienxu->getContentSize().width / 1.1,
		origin.y + tienxu->getContentSize().height / 1.5));
	tienxu->setScale(0.8f);
	this->addChild(tienxu, 2);


	auto nextleft = Button::create("next1.png");
	nextleft->setPosition(Vec2(origin.x + nextleft->getContentSize().width,
		origin.y + visibleSize.height / 2));
	this->addChild(nextleft, 2);

	auto nextright = Button::create("next.png");
	nextright->setPosition(Vec2(origin.x + visibleSize.width - nextright->getContentSize().width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(nextright, 2);

    return true;
}