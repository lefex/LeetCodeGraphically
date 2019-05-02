//
//  LEFListSubject.cpp
//  DSACode
//
//  Created by wsy on 2019/4/22.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#include "LEFListSubject.hpp"

/**
 ListNode* reverseBetween2(ListNode* head, int m, int n) {
 printLinkedList(head);
 if (head == NULL || head->next == NULL || m == n) {
 return head;
 }
 
 if (m > n || m < 0 || n < 0) {
 return head;
 }
 
 //
 ListNode *mNode = NULL;
 ListNode *mPreNode = NULL;
 ListNode *nNode = NULL;
 ListNode *nNextNode = NULL;
 ListNode *p = head;
 ListNode *last = NULL;
 int count = 1;
 while (p) {
 if (count == m) {
 mNode = p;
 if (last) {
 mPreNode = last;
 }
 } else if (count == n) {
 nNode = p;
 if (nNode->next) {
 nNextNode = nNode->next;
 }
 break;
 }
 last = p;
 p = p->next;
 count += 1;
 }
 
 // 找到了第 m 个 节点和第 n 个节点
 ListNode *cur = mNode;
 ListNode *pre = NULL;
 while (cur != NULL) {
 ListNode *tempNext = cur->next;
 cur->next = pre;
 pre = cur;
 cur = tempNext;
 if (cur == nNode) {
 break;
 }
 }
 printLinkedList(pre);
 printLinkedList(mPreNode);
 
 if (mPreNode) {
 mPreNode->next = mNode;
 } else {
 head = mNode;
 }
 if (nNextNode) {
 pre->next = nNextNode;
 } else {
 //
 }
 printLinkedList(head);
 
 return head;
 }
 
 */
