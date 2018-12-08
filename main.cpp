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
 * File:   main.cpp
 * Author: andy
 *
 * Created on 25 June 2018, 15:56
 */



#include <cstdlib>
#include <iostream> //for cout
//#include "TCPServer.h"
//#include "lirc/lirc_client.h"
#include "clServer.h"
#include "utils.h"

//TCPServer server;





/*
 * 
 */
int main(int argc, char** argv) {

//    int fd;//File descriptor for lircd socket'
//    fd = lirc_get_local_socket(NULL, 0);
    lirc_init();
   if (fd < 0) {
        // Process error
        std::cout << "Error occurred getting LIRC local socket"<< std::endl;
        return 1;
    } else {
//        //lirc_send_one(, "name of remote", "Key symbol") 
////was        if (lirc_send_one(fd, "LGBP630", "KEY_POWER") == -1) {
//        if (mylirc_send_one(fd, "LGBP630", "KEY_POWER") == -1) {
//            // Process errors
//            std::cout << "Attempt to transmit failed"<< std::endl;
//            return 1;
//        }
    }
    std::cout << "LIRC Subsystem Connected OK"<< std::endl;
    
//    if (lirc_send_start(fd, "LGBP630", "KEY_POWER") == -1) {
//            // Process errors
//            std::cout << "Attempt to start sending failed"<< std::endl;
//            return 1;
//        }
//    
//    if (lirc_send_stop(fd, "LGBP630", "KEY_POWER") == -1) {
//        // Process errors
//        std::cout << "Attempt to stop sending failed"<< std::endl;
//        return 1;
//    }
    
    clServer server =  clServer();
    server.runServer(12123);
    
    
    
  
    return 0;
}



