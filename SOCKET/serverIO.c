


int main(){

	de_set readset;
	fd = socket();

	bind(fd,);
	
	listen(fd,....);

	FD_ZERO(&readset);
	FD_SET(fd,&readset);
	// puts fd that have established the connection to de_set in turn
	//
#if 0
	select(maxfd+1,&readset,NULL,NULL,NULL);
#else
	struct timeval tout;
	tout.tv_sec = 5;
	tout.tv_usec= 0;
	select(maxfd+1,&readset,NULL,NULL,&tout);
#endif
	if(FD_ISSET(fd,&readset)){
		newfd = accept(fd,...);
	}

	// determines if the client that has established a connection has data in turn
	// 
	return 0;
}
