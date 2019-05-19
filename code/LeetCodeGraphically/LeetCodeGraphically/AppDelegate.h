//
//  AppDelegate.h
//  LeetCodeGraphically
//
//  Created by wsy on 2019/4/30.
//  Copyright © 2019 WSY. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>
ListNode *divTwoNumbers(ListNode *l1, ListNode *l2) {
    // 创建头结点
    ListNode *tempL2 = l2;
    int index = compareLinedList(l1, l2);
    if (index == 0) {
        // L1 == L2
        ListNode *node = new ListNode(1);
        return node;
    } else if (index == 0) {
        // L1 < L2
        ListNode *node = new ListNode(10);
        return node;
    }
    
    // 相解的结果
    ListNode *sub = subTwoNumbers(l1, l2);
    ListNode *front = NULL;
    int count = 1;
    while (index == 1) {
        // 到 9 后加到结果链表中
        if (count == 9) {
            ListNode *node = new ListNode(count);
            if (front == NULL) {
                front = node;
            } else {
                front = addTwoNumbers(front, node);
            }
            count = 0;
        }
        printLinkedList(sub);
        ListNode *temp_sub = sub;
        index = compareLinedList(sub, tempL2);
        if (index == 1) {
            count += 1;
            sub = subTwoNumbers(temp_sub, tempL2);
        } else if (index == 0) {
            count += 1;
            break;
        } else {
            break;
        }

    }
    
    if (count > 0) {
        // 结果用链表保存，防止溢出
        ListNode *node = new ListNode(count);
        front = addTwoNumbers(front, node);
    }
    
    return front;
}
@property (strong, nonatomic) UIWindow *window;


@end

