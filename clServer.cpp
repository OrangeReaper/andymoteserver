/*
 * Copyright (C) 2018 Andy Bond
 *
 * This file is part of AndyMOTE Server
 *
 * AndyMOTE Server is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 3.0 as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/* 
 * File:   TCPServer.cpp
 * Author: andy
 * 
 * Created on 08 July 2018, 15:50
 */

#include "clServer.h"
#include "clReadMessage.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include <iostream>
#include <vector> //for cout
clServer::clServer() {
}

clServer::clServer(const clServer& orig) {
}

clServer::~clServer() {
}

int clServer::runServer(int port)
{
    clReadMessage messageReader;
    clServerResponder responder;;
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    

    
    
    
    //char sendBuff[1025];
    //time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Set socket timeout to 5 seconds
//    struct timeval tv;
//    tv.tv_sec = 5;
//    tv.tv_usec = 0;
//    setsockopt(listenfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    
    
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    //memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 
    //std::cout << "Server started... Waiting for first request" << std::endl;

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        
        
        std::string request = messageReader.readMessage(connfd);
        if (request.length() > 0) {
            std::cout << "Request Received: " << request << std::endl;

            std::string response=responder.getResponse(request);
            const char *reply;
            reply = response.c_str();

            int sent=send(connfd , reply , strlen(reply) , 0 );
            std::cout << "Reply Sent: " << response << std::endl;
//            std::cout << "---------------------------- " << std::endl;
//            std::cout << "Waiting for next request..." << std::endl;
            close(connfd);
            sleep(1);
        }
     }
}


