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
 * File:   clReadMessage.cpp
 * Author: andy
 * 
 * Created on 09 July 2018, 10:01
 */

#include "clReadMessage.h"

#include <unistd.h>

clReadMessage::clReadMessage() {
}

clReadMessage::clReadMessage(const clReadMessage& orig) {
}

clReadMessage::~clReadMessage() {
}
std::string clReadMessage::readMessage(int connectionfd){
    // Protocol -- 
    //      8byte header containing length of message (lm)
    //      lm payload
    return readFromSocket(connectionfd, readPayloadLength(connectionfd));
    
}
int clReadMessage::readPayloadLength(int connectionfd){
    std::string hexSize=readFromSocket(connectionfd, 8);
    if (hexSize.length() == 0) return 0;
    
    const char *hexstring = hexSize.c_str() ;
    int result = (int)strtol(hexstring, NULL, 16);
    return result;

}
std::string clReadMessage::readFromSocket(int connectionfd, int size){    
    std::string result="";
    if (size > 0) {
        char data[size];
        if(read(connectionfd, data, size) < 0){
            error = SOCKET_READ_FAIL;
        } else {
            std::string s(data, sizeof(data));
            result=s;
        }
    }    
    return result;
} 
   

