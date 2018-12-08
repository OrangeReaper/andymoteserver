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
 * File:   clListKeysResponder.cpp
 * Author: andy
 * 
 * Created on 24 July 2018, 14:58
 */

#include "clListKeysResponder.h"

std::string line;
static const std::string whitespace = " \t\f\v\n\r";

clListKeysResponder::clListKeysResponder() {
}

clListKeysResponder::clListKeysResponder(const clListKeysResponder& orig) {
}

clListKeysResponder::~clListKeysResponder() {
}
void clListKeysResponder::getResponse(nlohmann::json &jReply, std::string remoteName){   

    nlohmann::json jKeys;
    bool fault=true;
    std::string path = lircDir + remoteName + ".lircd.conf";
    //std::ifstream infile(path);
    std::fstream infile;
    //std::cout << "Path: " << path << std::endl;
    infile.open (path, std::fstream::in);
    
    if (readUntilLineContains(infile,"begin remote")){
        if (readUntilLineContains(infile,"flags")){
            if (stringContains(line, "RAW_CODES")){
                if (readUntilLineContains(infile,"begin raw_codes")){
                    fault= !readRawKeys(infile, jKeys)>0;
                }
            } else {
                if (readUntilLineContains(infile,"begin codes")){
                    fault=!readKeys(infile, jKeys)>0;
                }
            }
        }
    } 
    if (fault) {
        onError(jReply, "Error in conf file"); 
    } else {
        jReply["keys"]=jKeys;
    }
    infile.close();
       

}
bool clListKeysResponder::readUntilLineContains(std::fstream &stream, const std::string &searchFor){
    bool found=false;
    while (getLine(stream)){
        
        if (stringContains(line, searchFor)) {
            found=true;
            break;
        }
    }
    return found;
}

int clListKeysResponder::readKeys(std::fstream &stream, nlohmann::json &jKeys){
    int keysFound=0;
    while (getLine(stream)){
        if (stringContains(line, "end codes")) {
            break;
        } else {
            std::string keyName=getKeyName();
            if (keyName.length() != 0){
                jKeys.push_back(keyName);
                keysFound++;
            }
        }
    }
    return keysFound;
}
int clListKeysResponder::readRawKeys(std::fstream &stream, nlohmann::json &jKeys){
    int keysFound=0;
    while (getLine(stream)){
        if (stringContains(line, "end raw_codes")) {
            break;
        } else {
            if (stringContains(line, "name ")){
                std::string keyName=getRawKeyName();
           
                if (keyName.length() != 0){
                    jKeys.push_back(keyName);
                    keysFound++;
                }
            }
        }
    }
    return keysFound;
}
bool clListKeysResponder::getLine(std::fstream &stream){
    do {
        std::getline(stream, line);
    } while ((line.length()==0 || lineIsComment()) && (!stream.eof()));
    //std::cout << "Line: " << line << std::endl;
    return (!stream.eof());
}
bool clListKeysResponder::lineIsComment() {
    int start = line.find_first_not_of(whitespace);
    //std::cout << "Start: " << start << std::endl;
    if (start == std::string::npos) return true; // blank line is considered a comment
    char c = line[start];//.at(start);
    return ( c == '#');    
}
std::string clListKeysResponder::getKeyName(){
    
    int start = line.find_first_not_of(whitespace);
    //std::cout << "Start: " << start << std::endl;
    if (start == std::string::npos) return "";
    int end = line.find_first_of(whitespace, start);
    //std::cout << "end: " << end << std::endl;
    if (end == std::string::npos) return "";
    //std::cout << "Key: '" << line.substr(start, end-start) << "'" <<std::endl;
    if (end > start) return line.substr(start, end-start);
    return "";
    
}
std::string clListKeysResponder::getRawKeyName(){
    int ptr=line.find("name");
    if (ptr== std::string::npos) return ""; //not found
    
    ptr=ptr+5;
    return line.substr(ptr);
    
}
