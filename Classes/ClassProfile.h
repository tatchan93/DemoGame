#ifndef __CLASS_PROFILE_H__
#define __CLASS_PROFILE_H__

#include "cocos2d.h"
void hienthongtin(class Profile *profile);
class Profile
{
public: 
	char name[50];
	int ID;
	int level;
	int tinnhiem;
	int cash;
	int gold;
	int totalmatch;
	int totalwin;
	int totallose;
};
int scene()
{
	Profile avatar1;
	Profile avatar2;
	////////////////////////
	strcpy(avatar1.name, "Tran Ngoc Ha");
	avatar1.level = 1;
	avatar1.tinnhiem = 2;
	avatar1.cash = 1000;
	avatar1.gold = 2000;
	avatar1.totalmatch = 10;
	avatar1.totalwin = 5;
	avatar1.totallose = 5;
	avatar1.ID = 1000;
	//////////////////
	strcpy(avatar2.name, "Ngan Nguyen");
	avatar2.level = 5;
	avatar2.tinnhiem = 5;
	avatar2.cash = 10000;
	avatar2.gold = 25000;
	avatar2.totalmatch = 40;
	avatar2.totalwin = 30;
	avatar2.totallose = 10;
	avatar2.ID = 1001;
	/////////////////
	hienthongtin(&avatar1);
	hienthongtin(&avatar2);
	return 0;
}

#endif // __CLASS_PROFILE_H__
