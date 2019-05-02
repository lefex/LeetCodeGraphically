//
//  LEFListSubject.hpp
//  DSACode
//
//  Created by wsy on 2019/4/22.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#ifndef LEFListSubject_hpp
#define LEFListSubject_hpp

#include <stdio.h>
#import <iostream>

using std::cout;
using std::endl;

namespace LEFListSubject {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    class Soulation {
    public:
        ListNode *createLinkedList(int arr[], int n) {
            if (n == 0) {
                return NULL;
            }
            ListNode *head = new ListNode(arr[0]);
            ListNode *cur = head;
            for(int i = 1; i < n; i++) {
                ListNode *node = new ListNode(arr[i]);
                cur->next = node;
                cur = node;
            }
            return head;
        }
        
        void printLinkedList(ListNode *head) {
            if (head == NULL) {
                cout << "NULL" << endl;
                return;
            }
            ListNode *cur = head;
            while (cur) {
                cout << cur->val << " -> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }
        
        /**
         合并两个有序的单链表
         l1 = 1-2-4
         l2 = 3-4-7
         */
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            // 如果l1为空或者l2为空，结果直接是另外一个
            if (l1 == NULL) {
                return l2;
            }
            if (l2 == NULL) {
                return l1;
            }
            // head 指向最终链表的头
            ListNode *head = NULL;
            // 找到 head 开始所指向的链表，L1 或者 L2
            if (l1->val < l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }
            // 遍历l1和l2，移动p的位置
            ListNode *p = head;
            // 两个链表均没有遍历完
            while (l1 && l2) {
                // 如果 l1的值小，那么把 l1节点作为p的下一个节点，同时移动l1的位置，反之移动l2的位置
                if (l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }
            // 遍历结束后，l1和l2总有一个会遍历完， 如果某个未遍历完，直接接到p的后面
            if (l1 != NULL) {
                p->next = l1;
            }
            if (l2 != NULL){
                p->next = l2;
            }
            
            return head;
        }
        
        /**
         删除链表中重复的元素
         Input: 1->1->2->3->3
         Output: 1->2->3
         
         [1,1,2,3,3]
         因为是排好序的单链表，遍历单链表，发现重复的接上去
         */
        ListNode* deleteDuplicates(ListNode* head) {
            // 如果为空或者只有一个节点，直接返回
            if (head == NULL || head->next == NULL) {
                return head;
            }
            // result_head 指向结果头节点
            ListNode *result_head = head;
            // p 指向结果的最后一个节点
            ListNode *p = result_head;
            
            // 无需遍历第一个节点，直接从下一个遍历
            while ((head = head->next) != NULL) {
                // p当前节点指向的节点为值 ！= head当前的值，把head接到p上
                if (p->val != head->val) {
                    p->next = head;
                    // 移动 p 的位置
                    p = p->next;
                }
            }
            // 必须斩断，否则可能是head的结尾
            p->next = NULL;
            
            return result_head;
        }
        
        /**
         移除链表中重复的元素节点
         Input: 1->2->3->3->4->4->5
         Output: 1->2->5
         */
        ListNode* deleteDuplicates2(ListNode* head) {
            // 如果为空或者只有一个节点，直接返回
            if (head == NULL || head->next == NULL) {
                return head;
            }
            // 记录结果的头节点
            ListNode *result_head = NULL;
            // 记录结果链表的尾节点
            ListNode *p = NULL;
            // 记录重复节点第一次出现的位置
            ListNode *last_repate = NULL;
            
            // 第一个已经遍历了，直接从下一个遍历
            while (head != NULL) {
                // head 有下一个节点且下一个节点与当前节点不相等，或者是尾节点
                if ((head->next && head->val != head->next->val) || head->next == NULL) {
                    // 上一个重复的节点为空，或者当前节点与上一重复的节点不相等
                    if (last_repate == NULL || last_repate->val != head->val) {
                        // 给 p 赋值
                        if (p == NULL) {
                            result_head = head;
                            p = result_head;
                        } else {
                            // 移动 p 的位置，使其永远指向结果链表的尾节点
                            p->next = head;
                            p = p->next;
                        }
                    }
                } else {
                    last_repate = head;
                }
                head = head->next;
            }
            // 必须斩断，p 可能为空，比如 [1, 1]
            if (p) {
                p->next = NULL;
            }
            
            return result_head;
        }
        
        /**
         其实这道题，开始就掉入一个陷阱了，因为链表中的数字是按照一个整数的逆序存储的，完全可以
         按照链表逐个相加，最后得出结果；这个加法正好匹配！！！
         
         2 -> 4 -> 3 -> null
         5 -> 6 -> 4 -> null
         7 -> 0 -> 7+1 -> null
         
         Runtime: 44 ms, faster than 66.16% of C++ online submissions for Add Two Numbers.
         Memory Usage: 19.2 MB, less than 44.18% of C++ online submissions for Add Two Numbers.
         
         Runtime: 40 ms, faster than 96.78% of C++ online submissions for Add Two Numbers.
         Memory Usage: 19 MB, less than 82.09% of C++ online submissions for Add Two Numbers.
         */
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            // 创建头结点
            ListNode *front = NULL;
            // 创建尾结点
            ListNode *rear = NULL;
            
            // 用来标记进位的值，如果大于等于10，则进位为1
            int num = 0;
            
            while (l1 != NULL || l2 != NULL) {
                int l1Value = 0;
                if (l1 != NULL) {
                    l1Value = l1->val;
                    l1 = l1->next;
                }
                int l2Value = 0;
                if (l2 != NULL) {
                    l2Value = l2->val;
                    l2 = l2->next;
                }
                int sum = l1Value + l2Value + num;
                int value = sum;
                if (sum >= 10) {
                    num = 1;
                    // value 值取余数
                    value = sum % 10;
                } else {
                    num = 0;
                }
                
                // 创建一个节点
                ListNode *node = new ListNode(value);
                if (front == NULL) {
                    front = node;
                } else {
                    rear->next = node;
                }
                rear = node;
            }
            /**
             如果链表都为空了，但是进位为1，那么需要把进位单独创建一个节点
             */
            if (num > 0) {
                rear->next = new ListNode(num);
            }
            return front;
            
        }
        
        /**
         比较抽象，把节点指向上一个，
         使用一个栈来存储数据，然后在取出来
         Reverse a singly linked list.
         
         Example:
         
         Input: 1->2->3->4->5->NULL
         Output: 5->4->3->2->1->NULL
         */
        ListNode* reverseBetween(ListNode* head) {
            ListNode *prev = NULL;
            ListNode *curr = head;
            while (curr != NULL) {
                // 保存下一个节点，防止断链
                ListNode *nextTemp = curr->next;
                // 让当前节点的下一个指向前一个
                curr->next = prev;
                // 移动前一个位置
                prev = curr;
                // 遍历下一个子串
                curr = nextTemp;
            }
            return prev;
        }
        /***
         Reverse a linked list from position m to n. Do it in one-pass.
         
         Note: 1 ≤ m ≤ n ≤ length of list.
         
         Example:
         
         Input: 1->2->3->4->5->NULL, m = 2, n = 4
         Output: 1->4->3->2->5->NULL
         逆序一个链表中 m 到 n 子序列
         */
        ListNode* reverseBetween2(ListNode* head, int m, int n) {
            if (head == NULL || head->next == NULL || m == n) {
                return head;
            }
            
            if (m > n || m < 0 || n < 0) {
                return head;
            }
            
            ListNode *mPreNode = NULL;
            ListNode *dumpHead = new ListNode(0);
            dumpHead->next = head;
            ListNode *p = dumpHead;
            int count = 0;
            while (p != NULL) {
                if (count == m) {
                    // 找到了第 m 个 节点和第 n 个节点
                    ListNode *cur = p;
                    ListNode *pre = NULL;
                    int temp = 1;
                    while (cur != NULL && temp <= n - m + 1) {
                        ListNode *tempNext = cur->next;
                        cur->next = pre;
                        pre = cur;
                        cur = tempNext;
                        temp += 1;
                        
                    }
                    
                    mPreNode->next = pre;
                    p->next = cur;
                    printLinkedList(dumpHead->next);
                }
                mPreNode = p;
                p = p->next;
                count += 1;
            }
            
            return dumpHead->next;
        }
        
        /***
         Reverse a linked list from position m to n. Do it in one-pass.
         
         Note: 1 ≤ m ≤ n ≤ length of list.
         
         Example:
         
         Input: 1->2->3->4->5->NULL, m = 2, n = 4
         Output: 1->4->3->2->5->NULL
         逆序一个链表中 m 到 n 子序列
         */
        ListNode* reverseBetween3(ListNode* head, int m, int n) {
            if (head == NULL || head->next == NULL || m == n) {
                return head;
            }
            
            if (m > n || m < 0 || n < 0) {
                return head;
            }
            
            //
            ListNode *mNode = NULL;
            ListNode *mFrontNode = NULL;
            ListNode *mNextNode = NULL;
            ListNode *nNode = NULL;
            ListNode *nFrontNode = NULL;
            ListNode *nNextNode = NULL;
            ListNode *p = head;
            ListNode *lastP = NULL;
            int count = 1;
            while (p && count <= n) {
                if (count == m) {
                    mNode = p;
                    if (lastP) {
                        mFrontNode = lastP;
                    }
                    mNextNode = p->next;
                } else if (count == n) {
                    nNode = p;
                    if (lastP) {
                        nFrontNode = lastP;
                    }
                    nNextNode = p->next;
                }
                lastP = p;
                p = p->next;
                count += 1;
            }
            
            if (mFrontNode) {
                mFrontNode->next = nNode;
                nNode->next = mNextNode;
                nFrontNode->next = mNode;
                mNode->next = nNextNode;
            } else {
                head = nNode;
                nFrontNode->next = mNode;
                mNode->next = nNextNode;
            }
            
            return head;
        }
        
        
        
    };
}

#endif /* LEFListSubject_hpp */
