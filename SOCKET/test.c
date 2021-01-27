#include "sock.h"

int main(){

	uint32_t addr;
	inet_pton(AF_INET,SERV_IP_ADDR,(void*)&addr);
	printf("%x ",addr);

	return 0;
}
