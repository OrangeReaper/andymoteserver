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
 * File:   clReadMessage.h
 * Author: andy
 *
 * Created on 09 July 2018, 10:01
 */

#ifndef CLREADMESSAGE_H
#define CLREADMESSAGE_H

#include <string>

class clReadMessage {
public:
    clReadMessage();
    clReadMessage(const clReadMessage& orig);
    virtual ~clReadMessage();
    std::string readMessage(int connectionfd);

    enum ERRORCODE {
        NO_ERRORS, SOCKET_READ_FAIL, HEADER_READ_FAIL
    };
    
    ERRORCODE getLastError() { return error; }

private:
    int readPayloadLength(int connectionfd);
    std::string readFromSocket(int connectionfd, int size);
    
    
    
    ERRORCODE error = NO_ERRORS;

};

#endif /* CLREADMESSAGE_H */

