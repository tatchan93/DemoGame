#ifndef __TaLa_SCENE_H__
#define __TaLa_SCENE_H__

#include "cocos2d.h"

class TaLa : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(TaLa);
};

#endif // __TaLa_SCENE_H__
