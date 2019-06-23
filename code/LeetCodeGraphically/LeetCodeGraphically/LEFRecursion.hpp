//
//  LEFRecursion.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/6/3.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFRecursion_hpp
#define LEFRecursion_hpp

#include <stdio.h>
#include <array>

class Recursion {
    
public:
    int sum(int arr[]) {
        return sum(arr, 0);
    }

    int sum(int arr[], int len) {
        if (len == 6) {
            return 0;
        }
        int temp = arr[len] + sum(arr, len+1);
        return temp;
    }
};

#endif /* LEFRecursion_hpp */
