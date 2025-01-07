#ifndef SERV_HPP
# define SERV_HPP

#include <cstring>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>
#include "../config/ServConf.hpp"

class Serv
{
private:
	int _kq; // kq fd
	struct addrinfo _hints; // 서버 소켓 정보 구조체
	vector<int> _sockfd; // 서버 소켓 fd들
	vector<struct kevent> _evList; // kevent list
	

	void setAddrInfo();
	void setSocket(const vector<ServBlock>& serv);
	void setKqueue();
public:
	Serv(ServConf& servConf);
	~Serv();

	bool checkSockfd(int fd);

	int getKq() const;
	vector<int>& getSockfd();
	vector<struct kevent>& getEvList();
};

#endif
