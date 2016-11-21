#ifndef __XocDiaBan1__H__
#define __XocDiaBan1__H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"
#include <network/SocketIO.h>
#include "PopupAvatar.h"

using namespace cocos2d::network;
using namespace cocos2d::ui;

class XocDiaBan1 : public cocos2d::Layer, public SocketIO::SIODelegate
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually

	// socket.io even\vent listener
	void onReceiveEvent(SIOClient* client, const std::string& data);
	// SIODelegate
	virtual void onConnect(SIOClient* client);
	virtual void onMessage(SIOClient* client, const std::string& data);
	virtual void onClose(SIOClient* client);
	virtual void onError(SIOClient* client, const std::string& data);

	CREATE_FUNC(XocDiaBan1);

protected:
private:
	int index;
	SIOClient* _client;
	TextField* editBox;
};

#endif // __XocDiaBan1_SCENE_H__
