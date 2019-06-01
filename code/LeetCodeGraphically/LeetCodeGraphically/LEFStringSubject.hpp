//
//  LEFStringSubject.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/6/1.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFStringSubject_hpp
#define LEFStringSubject_hpp

#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    // ipv6 包含的字符
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    // 是否为 ipv4 的块
    bool isValidIPv4Block(string& block) {
        int num = 0;
        // 最大长度为 3
        if (block.size() > 0 && block.size() <= 3) {
            for (int i = 0; i < block.size(); i++) {
                char c = block[i];
                // 如果不是数字，或者第一个为 0，不合法
                if (!isalnum(c) || (i == 0 && c == '0' && block.size() > 1))
                    return false;
                else {
                    num *= 10;
                    num += c - '0';
                }
            }
            // ipv4 要小于 255
            return num <= 255;
        }
        return false;
    }
    // 是否为 ipv6 的块
    bool isValidIPv6Block(string& block) {
        // 最大长度为 4
        if (block.size() > 0 && block.size() <= 4) {
            for (int i = 0; i < block.size(); i++) {
                char c = block[i];
                // 是否为特定的字符
                if (validIPv6Chars.find(c) == string::npos)
                    return false;
            }
            return true;
        }
        return false;
    }
    
    string validIPAddress(string IP) {
        string ans[3] = {"IPv4", "IPv6", "Neither"};
        stringstream ss(IP);
        string block;
        // ipv4 判断，string::npos 表示未找到
        if (IP.substr(0, 4).find('.') != string::npos) {
            for (int i = 0; i < 4; i++) {
                if (!getline(ss, block, '.') || !isValidIPv4Block(block))
                    return ans[2];
            }
            // ss.eof() 表示输入是否截止
            return ss.eof() ? ans[0] : ans[2];
        }
        // ipv6 判断
        else if (IP.substr(0, 5).find(':') != string::npos) {
            for (int i = 0; i < 8; i++) {
                if (!getline(ss, block, ':') || !isValidIPv6Block(block))
                    return ans[2];
            }
            return ss.eof() ? ans[1] : ans[2];
        }
        
        return ans[2];
    }
};

#endif /* LEFStringSubject_hpp */
