#include "Popup.h"

bool Popup::init()
{
	if (!Node::init()) return false;

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	popupLayer = Layer::create();
	popupLayer->setAnchorPoint(Vec2::ZERO);
	popupLayer->setPosition(Vec2(visibleSize.width + origin.x, origin.y));
	addChild(popupLayer);

	auto _background = Sprite::create("backgruond.png");
	_background->setAnchorPoint(Vec2::ZERO);
	_background->setPosition(Point::ZERO);
	popupLayer->addChild(_background);

	backgroundContentSize = _background->getContentSize();

		appearAction = TargetedAction::create(popupLayer,
		MoveTo::create(1, Vec2(visibleSize.width - backgroundContentSize.width + origin.x, origin.y)));

	disappearAction = TargetedAction::create(popupLayer,
		MoveTo::create(1, Vec2(visibleSize.width + origin.x, origin.y)));

	appearAction->retain();
	disappearAction->retain();

	return true;
}

void Popup::disappear()
{
	this->runAction(disappearAction->clone());
}

void Popup::appear()
{
	this->runAction(appearAction->clone());
}

void Popup::setTitlePopup(std::string _titlePopup)
{
	auto _title = Label::createWithTTF("Popup",	"fonts/Marker Felt.ttf", 25);

	_title->setAdditionalKerning(7.0f);
	_title->setPosition(Point(backgroundContentSize.width / 2 + origin.x,
		backgroundContentSize.height * 8 / 10 + origin.y));

	_title->setColor(Color3B::YELLOW);
	_title->setScale(1.5f);

	popupLayer->addChild(_title);
}

void Popup::onExit()
{
	appearAction->release();
	disappearAction->release();

	Node::onExit();
}