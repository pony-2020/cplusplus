#pragma once

#ifndef _SOCKETPROTOCOL_H
#define _SOCKETPROTOCOL_H

class socketProtocol{
	
	public:
		socketProtocol(){

			;
		}

		virtual	~socketProtocol(){

			;
		}

		// client initial
		virtual int socketInit() = 0 ;

		// client send 
		virtual int socketSend( unsigned char *buff /*in*/ , int buffLen /*in*/) = 0 ;

		// client receive 
		virtual int socketRev( unsigned char *buff /*in*/ , int *buffLen /*in*/) = 0 ;

		// client release recourse 
		virtual int socketDestrory() = 0 ;


};

#endif
