//
//  TLMNConfig.cpp
//  MyCards
//
//  Created by Black3rry on 4/9/16.
//
//

#include "TLMNConfig.hpp"

using namespace std;

const int		SCREEN_WIDTH			 = 1280;
const int		SCREEN_HEIGHT			 = 720;

//anh Linh
//const char*  SERVER_NAME = "192.168.100.200";

//stagging server
//const char*  SERVER_NAME = "192.168.100.250";

// anh Hai
//const char*  SERVER_NAME = "192.168.100.32";
//const char*  SERVER_NAME = "192.168.1.100";

//real server
//ip address
//const char* SERVER_NAME = "124.158.6.205";

//domain
const char* SERVER_NAME = "bigken.net";
const char* SERVER_PORT = "1240";

// TLMN

const char* TurnResponseKey[] = { "turnCards", "newTurn", "passUp"};
vector<const char *> soundTLMN = {
    "sounds/tienlen/boqua1.mp3","sounds/tienlen/boqua2.mp3","sounds/tienlen/boqua3.mp3","sounds/tienlen/boqua4.mp3","sounds/tienlen/boqua5.mp3","sounds/tienlen/boqua6.mp3", //0->5
    "sounds/tienlen/chat1.mp3","sounds/tienlen/chat2.mp3","sounds/tienlen/chat3.mp3","sounds/tienlen/chat4.mp3", //6->9
    "sounds/tienlen/danhbo1.mp3","sounds/tienlen/danhbo2.mp3","sounds/tienlen/danhbo3.mp3","sounds/tienlen/danhbo4.mp3","sounds/tienlen/danhbo5.mp3","sounds/tienlen/danhbo6.mp3", //10->15
    "sounds/tienlen/danhdoi1.mp3","sounds/tienlen/danhdoi2.mp3","sounds/tienlen/danhdoi3.mp3","sounds/tienlen/danhdoi4.mp3","sounds/tienlen/danhdoi5.mp3","sounds/tienlen/danhdoi6.mp3", // 16->21
    "sounds/tienlen/danhle1.mp3","sounds/tienlen/danhle2.mp3","sounds/tienlen/danhle3.mp3","sounds/tienlen/danhle4.mp3","sounds/tienlen/danhle5.mp3","sounds/tienlen/danhle6.mp3", // 22->27
    "sounds/tienlen/haine1.mp3","sounds/tienlen/haine2.mp3","sounds/tienlen/haine3.mp3","sounds/tienlen/haine4.mp3", //28->31
    "sounds/tienlen/doihai1.mp3","sounds/tienlen/doihai2.mp3", // 32->33
    "sounds/tienlen/end_game1.mp3","sounds/tienlen/end_game2.mp3", // 34->35
    "sounds/click_card.mp3", //36
    "sounds/chiabai.mp3" }; // 37

vector<const char *> soundPhom = {
    "sounds/phom/anquan1.mp3","sounds/phom/anquan2.mp3","sounds/phom/anquan3.mp3","sounds/phom/anquan4.mp3", // 0 ->3
    "sounds/phom/an2quan1.mp3","sounds/phom/an2quan2.mp3","sounds/phom/an2quan3.mp3","sounds/phom/an2quan4.mp3", // 4 ->7
    "sounds/phom/anchot1.mp3","sounds/phom/anchot2.mp3","sounds/phom/anchot3.mp3","sounds/phom/anchot4.mp3", // 8->11
    "sounds/phom/u1.mp3","sounds/phom/u2.mp3","sounds/phom/u3.mp3","sounds/phom/u4.mp3", // 12-> 15
    "sounds/phom/uden1.mp3","sounds/phom/uden2.mp3","sounds/phom/uden3.mp3" // 16->18
};

vector<const char *> soundMauBinh = {
    "sounds/maubinh/sanhrongcuon.mp3",
    "sounds/maubinh/sanhrong.mp3",
    "sound_null.mp3", //13 lá đồng màu
    "sound_null.mp3",  //12 lá đồng màu
    "sound_null.mp3",  // 5 đôi một sám
    "sounds/maubinh/lucphebon.mp3",
    "sounds/maubinh/bacaithung.mp3",
    "sounds/maubinh/bacaisanh.mp3",
    "sounds/maubinh/thung.mp3",
    "sounds/maubinh/thungchi2.mp3",
    "sounds/maubinh/tyquy.mp3",
    "sounds/maubinh/tuquychi2.mp3",
    "sounds/maubinh/culu.mp3",
    "sounds/maubinh/culuchi2.mp3",
    "sounds/maubinh/thung.mp3",
    "sounds/maubinh/sanh.mp3",
    "sounds/maubinh/xamchi.mp3",
    "sounds/maubinh/xamchi3.mp3",
    "sounds/maubinh/thu.mp3",
    "sounds/maubinh/doi.mp3",
    "sound_null.mp3", //mậu thầu
    "sound_null.mp3",  // binh lung
    "sound_null.mp3",  // thắng sập hầm
    "sound_null.mp3" // thua sập hầm //23 am thanh
};

vector<const char *> soundBaCay = {
};

vector<const char*> soundSocdia = {
	"sounds/socdia/socdia.mp3"
};

vector<const char *> soundOther = {
    "sounds/latbai.mp3","sounds/chiabai.mp3","sounds/click_card.mp3",
    "sounds/bom.mp3","sounds/dep.mp3","sounds/beer.mp3","sounds/hoahong.mp3",
    "sounds/cachua.mp3","sounds/egg.mp3","sounds/nohu.mp3","sounds/thang.mp3",
	"sounds/nemxu.mp3", "sounds/xunhanve.mp3","sounds/clockTick.mp3","sounds/quatanghangngay.mp3"
};

vector<int> moneyType = {50, 100, 500, 2000, 5000, 20000};

//COMMON
char* screenshot_path_ios = "";
char* screenshot_path_android = "/sdcard/snapshot.jpg";
