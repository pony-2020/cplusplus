#ifndef _SOCKET_HEADER_H_
#define _SOCKET_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <pthread.h>
#include <arpa/inet.h>

#define 	BACKLOG		5
#define 	SOCK_ADDR  	"192.168.5.140"
#define 	SOCK_PORT 	5001
#define 	QUIT_STR	"quit"
#define 	BUFSIZE		64

#endif
