//
//  ViewController.m
//  LeetCodeGraphically
//
//  Created by wsy on 2019/4/30.
//  Copyright © 2019 WSY. All rights reserved.
//

#import "ViewController.h"
#import "LEFListSubject.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    LEFListSubject::Soulation s;
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(int);
    LEFListSubject::ListNode *head = s.createLinkedList(arr, n);
    s.printLinkedList(head);
//    s.reverseBetween2(head, 1, 2);
    LEFListSubject::ListNode *ret = s.swapPairs(head);
    s.printLinkedList(ret);

}


@end
