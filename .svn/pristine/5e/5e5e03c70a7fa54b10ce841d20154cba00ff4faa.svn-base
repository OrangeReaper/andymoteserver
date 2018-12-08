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
 * File:   clKeySeqResponder.cpp
 * Author: andy
 * 
 * Created on 08 August 2018, 14:35
 */

#include "clKeySeqResponder.h"
#include "json.hpp"
#include <thread>
#include <chrono>

clKeySeqResponder::clKeySeqResponder() {
}

clKeySeqResponder::clKeySeqResponder(const clKeySeqResponder& orig) {
}

clKeySeqResponder::~clKeySeqResponder() {
}

void clKeySeqResponder::getResponse(nlohmann::json &jReply, nlohmann::json &jKeySeq){   

    //nlohmann::json jArray=jKeySeq.at("keySeqArray"); 
    if (jKeySeq.is_array()){
//        std::cout << "Array: " << jArray.dump() << std::endl;
        // iterate the array
        //for (nlohmann::json::iterator it = jArray.begin(); it != jArray.end(); ++it) {
        bool firstTime=true;
        for (nlohmann::json& x : jKeySeq){
            //wait 50ms between keys...
            if (!firstTime) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                firstTime=false;
            }
            //std::cout << "Iterator: " << *it << '\n';
 //           std::cout << "Item: " << x << '\n';
            std::string device = x.at("lircName");
            std::string function = x.at("transmitCode");
            int delay = x.at("duration");
//            std::cout << "Device: " << device << '\n';
//            std::cout << "transmitCode: " << function << '\n';
//            std::cout << "duration: " << delay << '\n';
            if (function.compare("WAIT") == 0){
                //std::cout << str1 << " is  " << str2 << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            } else {
                if (delay==0) {delay=50;}
                if (delay==-1){
                    if (!lirc_send_key(device.c_str(), function.c_str())){
                        onError(jReply, "KeySeq Send One Failed");
                        break;
                    }
                } else {   
                    if (!lirc_start_sending(device, function)){
                        onError(jReply, "KeySeq Start Sending Failed");
                        break;
                    } else {
                        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                        if (!lirc_stop_sending(device, function)){
                           onError(jReply, "KeySeq Stop Sending Failed");
                            break;  
                        }
                    }
                }
            }
        }
    } else {
        onError(jReply, "Invalid KeySeq Request");
    }
}

       



