//
//  ViewController.m
//  LeetCodeGraphically
//
//  Created by wsy on 2019/4/30.
//  Copyright © 2019 WSY. All rights reserved.
//

#import "ViewController.h"
#import "LEFListSubject.hpp"
#import "LEFLRUCache.hpp"
#import "LEFLFUCache.cpp"
#import "LEFHash.hpp"
#import "LEFRecursion.hpp"
#import "DataStructer.hpp"
#import "MaxHeap.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    HeapSolution hs;
    vector<int> v {1,1,2,2,2,3};
    hs.topKFrequent(v, 2);
    
    return;

    
    int harr[] = {10,20,30,100};
    MaxHeap h2 = MaxHeap(harr, 4);
    h2.printHeap();
    
    
    MaxHeap heap;
    heap.add(10);
    heap.add(20);
    heap.add(30);
    heap.add(28);
    heap.add(40);
    heap.add(4);
    heap.add(100);
    heap.printHeap();
    

    
    NSLog(@"max: %@", @(heap.pop_max()));
    heap.printHeap();
    NSLog(@"max: %@", @(heap.pop_max()));
    heap.printHeap();
    NSLog(@"max: %@", @(heap.pop_max()));
    heap.printHeap();
    NSLog(@"max: %@", @(heap.pop_max()));
    heap.printHeap();
    NSLog(@"max: %@", @(heap.pop_max()));
    heap.printHeap();
    


    
    return;
    DataStructer ds;
    ds.testSet();
    
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
    

    
//    LEFListSubject::ListNode *l1 = s.createLinkedList(arr, n);
//    LEFListSubject::ListNode *l2 = s.createLinkedList(arr2, n2);
    
//    int isGreater = s.compareLinedList(l1, l2);
//    NSLog(@"isGreater: %@", @(isGreater));
//    LEFListSubject::ListNode *ret = s.divTwoNumbers(l1, l2);
//    s.printLinkedList(ret);
    
//    [self testSum];
//    [self testSub];
//    [self testMuti];
//    [self testDiv];
    
//    [self testHashMap];
    [self testRecursion];
}

- (void)testRecursion {
    Recursion *add = new Recursion();
    int a[6] = {1, 2, 3, 4, 5, 10};
    printf("sum: %d", add->sum(a));

}

- (void)testHashMap {
    MyHashMap *map = new MyHashMap();
    map->put(1, 10);
    map->put(2, 20);
    printf("map key - 2: %d", map->get(2));
    map->remove(2);
    printf("map key - 2: %d", map->get(2));
    printf("map key - 1: %d", map->get(1));
}

- (void)testCache  {
    LRUCache cache = LRUCache(10);
    cache.useList();
    /**
     ["LFUCache","put","put","get","put","get","get","put","get","get","get"]
     [[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
     
     */
    LFUCache lfuCache = LFUCache(3);
    int v0 = lfuCache.get(2);
    lfuCache.put(1, 1);
    lfuCache.put(2, 2);
    int v1 = lfuCache.get(1);
    lfuCache.put(3, 3);
    int v2 = lfuCache.get(2);
    int v3 = lfuCache.get(3);
    lfuCache.put(4, 4);
    int v4 = lfuCache.get(1);
    int v5 = lfuCache.get(3);
    int v6 = lfuCache.get(4);
    
    
    printf("%d - %d - %d", v1, v2, v3);
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
