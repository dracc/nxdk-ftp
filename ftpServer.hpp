#ifndef __FTPSERVER_H
#define __FTPSERVER_H

#include <map>
#include <string>
#include <thread>
#include "ftpConnection.hpp"
#include "ftp.h"
#ifdef NXDK
#include <lwip/netdb.h>
#include <lwip/sockets.h>
#else
#include <netdb.h>
#endif

struct ftpServer {};

class FtpConfig {
  bool enable;
  std::string username;
  std::string password;
  int port;

public:
  FtpConfig();
  FtpConfig(ftpConfig* f);

  bool getEnabled() const { return enable; }
  const std::string& getUser() const { return username; }
  const std::string& getPassword() const { return password; }
  int getPort() const { return port; }

  void setEnabled(bool val);
  void setUser(std::string const& username);
  void setPassword(std::string const& password);
  void setPort(int port);
};

class FtpServer : public ftpServer {
  fd_set master;
  fd_set readFds;
  int fdmax;

  std::map<int, ftpConnection*> clients;

  int listener;
  int newfd;
  int i;

  struct sockaddr_storage raddr;
  socklen_t addrlen;
  struct addrinfo hints, *ai, *p;

  std::thread serverThread;

  void* getInAddr(struct sockaddr* sa);
  static int thread_runner(FtpServer* server);

public:
  FtpServer(FtpConfig const* conf);
  int init();
  int run();
  void runAsync();
  void forgetConnection(int fd);
  int openConnection(std::string const& addr, std::string const& port);

  const FtpConfig* conf;
};

#endif
