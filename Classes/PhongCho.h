#ifndef __PhongCho_SCENE_H__
#define __PhongCho_SCENE_H__

#include "cocos2d.h"


class PhongCho : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	cocos2d::LayerGradient *layer;

    // implement the "static create()" method manually
    CREATE_FUNC(PhongCho);
};

#endif // __PhongCho_SCENE_H__
