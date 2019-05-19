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
    //
    int arr[] = {8,4,3};
    int n = sizeof(arr) / sizeof(int);
//    LEFListSubject::ListNode *head = s.createLinkedList(arr, n);
//    s.printLinkedList(head);
//    s.reverseBetween2(head, 1, 2);
//    LEFListSubject::ListNode *ret = s.swapPairs(head);
    
    int arr2[] = {4,2,1};
    int n2 = sizeof(arr2) / sizeof(int);
    

    
    LEFListSubject::ListNode *l1 = s.createLinkedList(arr, n);
    LEFListSubject::ListNode *l2 = s.createLinkedList(arr2, n2);
    
    int isGreater = s.compareLinedList(l1, l2);
    NSLog(@"isGreater: %@", @(isGreater));
    LEFListSubject::ListNode *ret = s.divTwoNumbers(l1, l2);
//    s.printLinkedList(ret);
    
//    [self testSum];
//    [self testSub];
//    [self testMuti];
    [self testDiv];

}

// 342 + 465 = 807
- (void)testSum {
    LEFListSubject::Soulation s;
    
    int arr[] = {2,4,3};
    int n = sizeof(arr) / sizeof(int);
    
    int arr2[] = {5,6,4};
    int n2 = sizeof(arr2) / sizeof(int);
    LEFListSubject::ListNode *l1 = s.createLinkedList(arr, n);
    LEFListSubject::ListNode *l2 = s.createLinkedList(arr2, n2);
    LEFListSubject::ListNode *ret = s.addTwoNumbers(l1, l2);
    
    // 7 -> 0 -> 8 -> NULL
    s.printLinkedList(ret);
}

// 465 - 382 = 83
- (void)testSub {
    LEFListSubject::Soulation s;

    int arr[] = {5,6,4};
    int n = sizeof(arr) / sizeof(int);
    
    int arr2[] = {2,8,3};
    int n2 = sizeof(arr2) / sizeof(int);
    LEFListSubject::ListNode *l1 = s.createLinkedList(arr, n);
    LEFListSubject::ListNode *l2 = s.createLinkedList(arr2, n2);
    LEFListSubject::ListNode *ret = s.subTwoNumbers(l1, l2);
    // 3 -> 8 -> 0 -> NULL
    s.printLinkedList(ret);
}

// 123 * 45 = 5535
- (void)testMuti {
    LEFListSubject::Soulation s;
    
    int arr[] = {3,2,1};
    int n = sizeof(arr) / sizeof(int);
    
    int arr2[] = {5,4};
    int n2 = sizeof(arr2) / sizeof(int);
    LEFListSubject::ListNode *l1 = s.createLinkedList(arr, n);
    LEFListSubject::ListNode *l2 = s.createLinkedList(arr2, n2);
    LEFListSubject::ListNode *ret = s.multTwoNumbers(l1, l2);
    // 5 -> 3 -> 5 -> 5 -> NULL
    s.printLinkedList(ret);
}

// 248 / 124 = 2
- (void)testDiv {
    LEFListSubject::Soulation s;
    
    int arr[] = {8,4,2};
    int n = sizeof(arr) / sizeof(int);
    
    int arr2[] = {4,2,1};
    int n2 = sizeof(arr2) / sizeof(int);
    LEFListSubject::ListNode *l1 = s.createLinkedList(arr, n);
    LEFListSubject::ListNode *l2 = s.createLinkedList(arr2, n2);
    LEFListSubject::ListNode *ret = s.divTwoNumbers(l1, l2);
    // 2 -> NULL
    s.printLinkedList(ret);
}



@end
