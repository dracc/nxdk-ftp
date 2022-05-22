#ifndef __FTP_H
#define __FTP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct ftpServer ftpServer;

typedef struct ftpConfig {
  bool enable;
  char* username;
  char* password;
  int port;
} ftpConfig;

ftpServer* new_ftpServer(ftpConfig* c);
void run_ftpServer(ftpServer* f);
void delete_ftpServer(ftpServer* f);

#ifdef __cplusplus
}
#endif

#endif
