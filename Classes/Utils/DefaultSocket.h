#ifndef DEFAULT_SOCKET_H_
#define DEFAULT_SOCKET_H_
#include "CommonSocket.h"
#include "Common.h"

class DefaultSocket:
	public CommonSocket
{
public:
	static DefaultSocket *getInstance();
	DefaultSocket();
	~DefaultSocket();
#if WIN32
	static bool initWinSock2_0();
	#endif
public:
	
	int peerSocket;
	int optval;
	int optlen;
	bool connectSocket(const char* serverIP, const char* serverPort);
	void closeSocket();
	int sendData(const char* data, int len);
//	int	readData(char* buffer,int len);
	int	readData(vector <char> &vectorBuffer,int len);

private:
	static DefaultSocket *_instance; 
	int hClientSocket;
};
#endif // !1
