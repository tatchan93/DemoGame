#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <ctime>
#include "TLMNConfig.hpp"
#include "LocalString.h"
#include "cocos2d.h"
#include "network/HttpClient.h"

using namespace std;

class Common {
public:
    static Common* getInstance();
    Common(string = "", string = "", string = "", string = "", string = "",
        string = "", string = "", int = 0, int = 0, string = "-1", int = -1);
    ~Common();

    string getDeviceId() const;
	int getVersionCode() const;
    /*string getUserIdFacebook() const;
    string getUserLastNameFacebook() const;
    string getUserFirstNameFacebook() const;
    string getTokenFacebook() const;*/
    string getDeviceInfo() const;
    string getAppVersion() const;
    string getCp() const;
    string getLanguage() const;
    string getCountry() const;
    string getIpaddress() const;
    string getSessionId();
    string convertIntToString(int var);
	std::string convertLongToMoneyView(long long var);
    string convertIntToMoneyView(int var);
    string convertIntToMoneyView100k(int var);

	bool isForceUpdate() const; 
	
	void setForceUpdate(bool _forceUpdate);
	void loginFacebook();
    void callPhone(string myPhone);
	void viewMessageSms(string target_number, string syntax);
	void openUrl(string url);
    std::string getPackageName();
    long long getCurrentTime() const;
    void setSessionId(string sessionId);
    void setIpadress(string address);
    google::protobuf::Message* checkEvent(int);
    void pickIpaddress();
    void onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *data);

    string distanceRemainTime(long long fromTime, long long toTime);

    int getOS();

    int getZoneId();
    void setZoneId(int zoneId);
    void setGameState(GAME_STATE state);
    GAME_STATE getGameState() const; 
	void setEnableGameIds(vector<int> gameids);
	vector<int> getEnableGameIds() const; 

    int getChannelId();
    int getRoomIndex();
    int getUserId();
    void closeApp();
    void swap(int &x, int &y);
    void shareContentFace(const std::string& filePath);

    char* getScreenShotPath();

    char* getNetworkStrength();
    
    void setGameTag(int gameTag);
    int getGameTag();
    
    /* userInfo */
    void setUserName(std::string userName);
    std::string getUserName();
    
    void setDisplayName(std::string displayName);
    std::string getDisplayName();

	void setEnableCashTranfer(bool enableCashTransfer);

	bool getEnableCashTransfer() const;
    
    void setCash(long long cash);
    long long getCash();
    void setNewPhone(string phone);
    string getNewPhone();
    void setGold(long long gold);
    long long getGold();
    
    void setAvatarId(int avatarId);
    int getAvatarId();
    
    void setLevel(int level);
    int getLevel();
    
    void setAutoReady(bool autoReady);
    bool isAutoRead();
    
    void setAutoDenyInvitation(bool autoDenyInvitation);
    bool isAutoDenyInvitation();

    void setPhoneNunber(std::string phoneNumber);
    std::string getPhoneNumber();
    
    /*void setCashRoomList(vector<BINRoomConfig> cashRoomList);
    vector<BINRoomConfig> getCashRoomList();
    
    void setGoldRoomList(vector<BINRoomConfig> goldRoomList);
    vector<BINRoomConfig> getGoldRoomList();*/

    void setFanpageUrl(std::string fanpageUrl);
    std::string getFanpageUrl();

    void setWebsiteUrl(std::string websiteUrl);
    std::string getWebsiteUrl();

    void setHotLines(vector<string> hotlines);
    vector<string> getHotLines();

    void setRequestRoomType(int requestRoomType);
    int getRequestRoomType();

    /*Common Function */
    string convertListCardToString(vector<int> _card_values);
    vector<string> split(string str, char delimiter);
    vector<int> convertStringsToInt(vector<string> str);
    int convertStringToInt(string str);
    
    bool to_bool(std::string str);
    std::string boolToString(bool value);
    string convertMillisecondToTime(long long milliseconds);
    string convertMillisecondToTime(long long milliseconds, string fomat);
    void setIdle(bool _idle);
    bool isIdle() const;
    void sleep(int milliseconds);
    bool isIntro() const;
    void setIntro(bool _intro); 
    
    void removeElement(vector<int> &vector, int a);

    vector<char> decompress_gzip2(const char* byte_arr, int length);

    std::string convertLongToCurrency(long money);
    std::string numberFormatWithCommas(long long value);
    std::string numberFormat(long long value);

    /*Common Constant*/
    std::string getTitleGame();
    
    int getOwnerUserId() const;
    void setOwnerUserId(const int ownerUserId);
    void setRoomIndex(int roomIndex);
    vector<pair<int, int>> parseBetMoney(int money);

    bool isEnabledPurchaseCash() const; 
    bool isEnabledTopup() const; 
    void setEnablePurchaseCash(bool _enablePurchaseCash);
    void setEnableTopup(bool _enableTopup);

    void setEnableCashToGold(bool enableCashToGold);
    bool getEnableCashToGold();
    void setCashToGoldRatio(int cashToGoldRatio);
    int getCashToGoldRatio();

    void setEnableQuickPlay(bool enableQuickPlay);
    bool getEnableQuickPlay();

	void setAccountVerify(bool accountVerify);
	bool getAccountVerify();

	void setDisableCashTransaction(bool disableCashTransaction);
	bool getDisableCashTransaction();

	void setSecurityKeySeted(bool securityKeySeted);
	bool getSecurityKeySeted();

	void setFirstLogin(bool firstLogin);
	bool isFirstLogin();

	void setEnableGiftCode(bool enableGiftCode);
	bool isEnableGiftCode();

	void setResetPwSmsSyntax(string resetPwSmsSyntax);
	string getResetPwSmsSyntax();

	/*void setHeadLineNotify(vector<BINNews> headline_notify);
	vector<BINNews> getHeadLineNotify();*/

	void setPosNotiEmergency(float pos_noti_emergency);
	float getPosNotiEmergency();

	void setNotifycationEmergency(string notifycation_emergency);
	string getNotifycationEmergency();

	string getDisplayNameSubText(string displayName);

	void utf8substr(std::string originalString, int SubStrLength, std::string& csSubstring);
    
    bool getSendPing();
    void setSendPing(bool isSendPing);

    static char* KEY_SESSION_ID;
    static char* KEY_USER_ID; 
    static const int FREE_ROOM_GROUP_ID = 5003;
    static const int VIP_ROOM_GROUP_ID = 5002;
    static char* NO_DEVICE;

    static int FACEBOOK_CHANNEL;
    static int GOOGLE_CHANNEL;
    static int TIENLENMIENNAM_ZONE;
    static int BACAY_ZONE;
    static int XITO_ZONE;
    static int POKER_ZONE;
    static int PHOM_ZONE;
	static int TLMN_SOLO_ZONE;
    static int CARO_ZONE;
    static int BAUCUA_ZONE;
    static int CHAN_ZONE;
    static int SAM_ZONE;
    static int LIENG_ZONE;
    static int MAUBINH_ZONE;
    static int XENG_ZONE;
    static int XOCDIA_ZONE;
	static int WHEEL_ZONE;
// filed update
    static int UPDATE_DISPLAY_NAME;
    static int UPDATE_EMAIL;
    static int UPDATE_PHONE;
    static int UPDATE_IDENTIFY;
    static int UPDATE_AVATAR;
    static int UPDATE_PASSWORD;
//    static int XITO_ZONE;
private:
    static Common* instance; 
    std::string device_id; 
    std::string device_info; 
    std::string app_version; 
    std::string cp; 
    std::string language; 
    std::string country; 
    std::string ipaddress; 
    std::string sessionId;
    GAME_STATE state; 
    bool _autoReady = false;
    bool _autoDenyInvitation = false;
    char* screenshot_path;
    int os;
    int channelId;
    int roomIndex;
    char* networkStrength;
    int ownerUserId;
    std::string userName;
    std::string displayName;
    bool _idle;
    long long cash;
    long long gold;
    string new_phone;
    int avatarId;
    int level;
    int gameTag;
    long long lag_time;
    bool isLagged; 
    int _zoneId = -1;
    std::string phoneNumber;
    bool _enablePurChaseCash;
    bool _enableTopup; 
	bool _enableCashTransfer; 
    bool _intro; 
    string _fanpageUrl;
    string _websiteUrl;
    vector<string> _hotlines;
    int _requestRoomType = -1;  //loai room de cau hinh load lan dau trong ban choi (load danh sach phong cho, free, vip)
    bool _enableCashToGold = false; //bat tat chuc nang doi xu sang ken
    int _cashToGoldRatio;        //ti le doi xu sang ken
    bool _enableQuickPlay;
	bool accountVerify;  //tai khoan da kich hoat chua
	bool disableCashTransaction; //disable chuc nang doi thuong, nap the
	bool securityKeySeted;  //da thiet lap ma xac thuc
	bool enableGiftCode;
	string resetPwSmsSyntax;
	bool _forceUpdate;
    
   /* vector<BINRoomConfig> cashRoomList;
    vector<BINRoomConfig> goldRoomList;*/
	vector<int> enableGameIds;
    bool isSendPing = true;
    
	//vector<BINNews> headline_nofify;  //bien luu thong bao trong showgame
	float pos_noti_emergency = 0.0f; //luu vi tri cua thong bao khan cap
	string notifycation_emergency = ""; //luu thong bao khan cap trong toan bo man hinh game
};

#endif // __COMMON_H__
