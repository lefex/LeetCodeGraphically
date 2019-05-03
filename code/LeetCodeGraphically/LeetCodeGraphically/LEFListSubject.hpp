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
            // 判断m和n的合法性
            if (m > n || m < 0 || n < 0) {
                return head;
            }
            
            ListNode *mPreNode = NULL;
            // 创建一个虚拟头结点，这样为了统一逻辑
            ListNode *dumpHead = new ListNode(0);
            dumpHead->next = head;
            ListNode *p = dumpHead;
            int count = 0;
            while (p != NULL) {
                // 查找第 m 个节点
                if (count == m) {
                    // 找到了第 m 个 节点，对第 >= m && <= n 的子链表进行反转
                    ListNode *cur = p;
                    ListNode *pre = NULL;
                    int temp = 1;
                    // 前进 n - m + 1 个节点，进行反转
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
                // 记录 m 的前一个节点，由于加了个虚拟节点，mPreNode 肯定不为空
                mPreNode = p;
                p = p->next;
                count += 1;
            }
            
            return dumpHead->next;
        }
        /**
         237. Delete Node in a Linked List
         
         Write a function to delete a node (except the tail) in a singly linked list,
         
         given only access to that node.
         
         
         Given linked list -- head = [4,5,1,9], which looks like following:
         
         4->5->1->9
         
         Example 1:
         
         Input: head = [4,5,1,9], node = 5
         
         Output: [4,1,9]
         
         Explntion: You are given the seond node with value 5, the linked list should
         
         become 4 -> 1 -> 9 after calling your function.
         
         Example 2:
         
         Input: head = [4,5,1,9], node = 1
         
         Output: [4,5,9]
         
         Explntion: You are given the third node with value 1, the linked list should
         
         become 4 -> 5 -> 9 after calling your function.
         
         The linked list will have at least two elements.
         
         All of the nodes' values will be unique.
         
         The given node will not be the tail and it will always be a valid node of the linked
         
         list.
         
         Do not return anything from your function.
         */
        void deleteNode(ListNode* node) {
            // 记录上一个节点
            ListNode *last = NULL;
            while (node) {
                // 最后一个节点，不为空
                if (node->next) {
                    node->val = node->next->val;
                } else {
                    last->next = NULL;
                }
                last = node;
                node = node->next;
            }
        }
        
        
        /**
         203. Remove Linked List Elements
         Remove all elements from a linked list of integers that have value val.
         
         Example:
         
         Input:  1->2->6->3->4->5->6, val = 6
         Output: 1->2->3->4->5
         

         */
        ListNode* removeElements(ListNode* head, int val) {
            //
            ListNode *cur = NULL;
            ListNode *rHead = NULL;
            while (head) {
                if (head->val != val) {
                    if (!rHead) {
                        rHead = head;
                        cur = head;
                    } else {
                        cur->next = head;
                        cur = cur->next;
                    }
                } else {
                    // 1->null 1
                    if (cur && cur->next) {
                        cur->next = NULL;
                    }
                }
                head = head->next;
            }
            return rHead;
        }
        
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // 新建一个虚拟节点
            ListNode *dumpHead = new ListNode(0);
            dumpHead->next = head;
            // 前一个指针，指向虚拟节点
            ListNode *first = dumpHead;
            // 后一个指针，指向虚拟节点
            ListNode *second = dumpHead;
            
            // 找到 second 的位置
            int count = 0;
            while (count < n + 1) {
                second = second->next;
                count += 1;
            }
            
            // 当 second->next 为空的时候，p的next就是要删除的节点
            while (second) {
                first = first->next;
                second = second->next;
            }
            // 删除节点并释放内存
            ListNode *delNode = first->next;
            first->next = delNode->next;
            delete delNode;
            // 删除 dumpHead 并释放内存
            ListNode *ret = dumpHead->next;
            delete dumpHead;
            
            return ret;
        }
        
        /**
         328. Odd Even Linked List
         Medium
         
         Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
         
         You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
         
         Example 1:
         
         Input: 1->2->3->4->5->NULL
         Output: 1->3->5->2->4->NULL
         
         Example 2:
         
         Input: 2->1->3->5->6->4->7->NULL
         Output: 2->3->6->7->1->5->4->NULL
         
         Note:
         
         The relative order inside both the even and odd groups should remain as it was in the input.
         The first node is considered odd, the second node even and so on ...
         
         */
        ListNode* oddEvenList(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
            ListNode *first = NULL;
            ListNode *second = NULL;
            ListNode *curFirst = NULL;
            ListNode *curSecond = NULL;
            ListNode *cur = head;
            int n = 1;
            while (cur) {
                cout << "cur: ";
                printLinkedList(cur);
                ListNode *temp = cur->next;
                // 清空当前节点的下一个节点
                cur->next = NULL;
                
                // 奇数
                if (first == NULL) {
                    first = cur;
                    curFirst = first;
                } else {
                    curFirst->next = cur;
                    curFirst = curFirst->next;
                }
                
                // 如果有偶数，继续处理偶数
                cur = temp;
                if (cur) {
                    ListNode *temp2 = cur->next;
                    cur->next = NULL;
                    if (second == NULL) {
                        second = cur;
                        curSecond = second;
                    } else {
                        curSecond->next = cur;
                        curSecond = curSecond->next;
                    }
                    cur = temp2;
                }
                
                n += 2;
                cout << "first: ";
                printLinkedList(first);
                cout << "second: ";
                printLinkedList(second);
            }
            curFirst->next = second;
            return first;
        }
        
        /**
         24. Swap Nodes in Pairs
         
         Given a linked list, swap every two adjacent nodes and return its head.
         You may not modify the values in the list's nodes, only nodes itself may be changed.
         
         Example:
         Given 1->2->3->4, you should return the list as 2->1->4->3.
         
         Runtime: 4 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
         Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Swap Nodes in Pairs.
         */
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return NULL;
            }
            // 结果的头节点
            ListNode *retHead = NULL;
            // 结果的当前节点
            ListNode *curRet = NULL;
            while (head) {
                printLinkedList(head);
                ListNode *temp = head->next;
                head->next = NULL;
                // 第一个节点
                ListNode *first = head;
                
                head = temp;
                if (head) {
                    ListNode *temp2 = head->next;
                    head->next = NULL;
                    // 第二个节点
                    ListNode *second = head;
                    
                    // 第二个节点先与第一个节点
                    if (!retHead) {
                        retHead = second;
                        retHead->next = first;
                        curRet = retHead->next;
                    } else {
                        curRet->next = second;
                        second->next = first;
                        curRet = first;
                    }
                    
                    head = temp2;
                } else {
                    curRet->next = first;
                    curRet = first;
                }
                printLinkedList(retHead);
            }
            return retHead;
        }
        
        /**
         旋转单链表，思想就是让两边成为一个环，然后移动尾指针
         61. Rotate List
         Medium
         
         Given a linked list, rotate the list to the right by k places, where k is non-negative.
         
         Example 1:
         
         Input: 1->2->3->4->5->NULL, k = 2
         Output: 4->5->1->2->3->NULL
         Explanation:
         rotate 1 steps to the right: 5->1->2->3->4->NULL
         rotate 2 steps to the right: 4->5->1->2->3->NULL

         */
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL) {
                return NULL;
            }
            int listNum = 1;
            ListNode *tail = head;
            
            //find tail and count listNum
            while(tail->next != NULL){
                listNum++;
                tail = tail->next;
            }
            tail->next = head;
            int newHeadIndex = listNum - k % listNum;
            
            for(int i = 0; i < newHeadIndex; i++){
                tail = tail->next;
            }
            
            head = tail->next;
            tail->next = NULL;
            
            return head;
        }
        
        
        /**
         141. Linked List Cycle
         Easy
         
         Given a linked list, determine if it has a cycle in it.
         
         To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
         */
        bool hasCycle(ListNode *head) {
            return false;
        }
    };
}
#endif /* LEFListSubject_hpp */
