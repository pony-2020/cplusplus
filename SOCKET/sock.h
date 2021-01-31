
#ifndef		_SOCK_H_
#define		_SOCK_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <strings.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/time.h>
#include <sys/time.h>

#define 	BUFSIZE		64
#define 	SERV_PORT	5001
#define		SERV_IP_ADDR	"192.168.5.137"
#define 	BACKLOG 	5
#define 	QUIT_STR 	"quit"
#define 	SERV_RESP_STR	"Server"

#define 	UNIX_DOMAIN_FILE "/tmp/my_domain_file.h"
#endif
