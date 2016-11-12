#ifndef __XiTo_SCENE_H__
#define __XiTo_SCENE_H__

#include "cocos2d.h"

class XiTo : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(XiTo);
};

#endif // __XiTo_SCENE_H__
