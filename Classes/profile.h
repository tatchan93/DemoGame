#ifndef __Profile_SCENE_H__
#define __Profile_SCENE_H__

#include "cocos2d.h"

class profile : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
	CREATE_FUNC(profile);
};

#endif
