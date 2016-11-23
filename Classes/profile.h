#ifndef __Profile_SCENE_H__
#define __Profile_SCENE_H__

#include "cocos2d.h"

class profile
{
public:
    

    virtual bool init();
public:
	static profile* getInstance();
	String getStringForKey(String key) const;
private:
	static profile* _instance;

	profile();
	virtual ~profile();

	Document _document;
	String _fileName;
    
    // implement the "static create()" method manually
	CREATE_FUNC(profile);
};

#endif
