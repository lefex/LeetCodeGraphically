//
//  DataStructer.hpp
//  CppDS
//
//  Created by Wang,Suyan on 2019/6/12.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
// http://c.biancheng.net/view/412.html
// https://www.kancloud.cn/digest/mystl/192550

/**
 标准模板库（英文：Standard Template Library，缩写：STL），是一个C++软件库，大量影响了C++标准程序库但并非是其的一部分。其中包含4个组件，分别为算法、容器、函数、迭代器。[1]
 
 模板是C++程序设计语言中的一个重要特征，而标准模板库正是基于此特征。
 */

#ifndef DataStructer_hpp
#define DataStructer_hpp

using namespace std;

#include <stdio.h>
#include <array>
#include <vector>
#include <string>
// 输入输出
#include <iostream>
#include <deque>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>

class Solucation {
    
public:
    /**
      数组实现比较简单，其实就是对 C 数组的一次封装
     */
    void testArray() {
        // 创建一个数组
        std::array<int, 5> a = {2, 4, 6, 8, 10};
        // 对数组进行遍历
        for (const auto i : a) {
            std::cout << i << std::endl;
        }
        
        // 取第一个值，通过 [index] 获取
        std::cout << "a[0] = " << a[0] << std::endl;
        // 修改数组中第一个值
        a[0] = 5;
        /**
         at 会检查 index 是否越界，越界将 crash，而 a[index] 不会 a.at(6);
         libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: array::at
         */
        a.at(0);
        // 数组是否为空
        a.empty();
        
        // 求数组的长度
        std::cout << "a.size()=" << a.size() << std::endl;
        
        // 获取第4个值
        int index = std::get<4>(a);
        std::cout << "a(4) = " << index << std::endl;
        
        for(int i = 0; i < a.size(); i++) {
            std::cout << a[i] << std::endl;
        }
        
        // 迭代器
        
        std::cout << "end a" << std::endl;
        // 创建一个空数组，数组中的值为0获取与类型相等的其它值
        std::array<int, 5> a2;
        std::cout << "end a2" << a2[0] << std::endl;
        
        // 比较两个数组中的元素是否都相等
        if (a == a2) {
            //
        }
        
        
    }
    // 向量
    void testVector() {
        /**
         vector<T> 它与Array不同，它的大小是可变的，只能在容器的尾部高效
         地添加和删除元素
         */
        std::vector<std::string> v;
        // 增加容器的容量，至少容纳 20 个元素
        v.reserve(20);
        // 初始化一个向量
        std::vector<int> v2 = {2, 4, 5, 7};
        // 声明大小为 5
        std::vector<double> v3(5);
        // v4 中只有一个元素
        std::vector<double> v4{5};
        // v5 中有 5 个元素，值均为 10
        std::vector<double> v5{5, 10};
        // 以数组初始化一个vector
        std::array<std :: string, 5> words {"one", "two","three", "four", "five"};
        std::vector<std::string> words_copy {std::begin(words) , std::end(words)};
        // 通过 v[index] 获取或者修改元素
        std::cout << "v[0] = " << v2[1] << std::endl;
        // 获取第一个元素
        std::cout << "v.front() = " << v2.front() << std::endl;
        // 在末尾插入值为 9
        v2.push_back(9);
        // 在末尾插入值为 2
        v2.emplace_back(2);
        
        // 删除第一个元素，传入的值是一个迭代器
        v2.erase(v2.begin());
        // 长度
        v2.size();
        
        // 删除
        // 删除所有元素
        v2.clear();
        // 删除末尾元素
        v2.pop_back();
        
        // 在末尾插入元素
        v2.insert(v2.end(), 3);
    }
    
    /**
     双端队列，可以在头部和尾部删除元素
     */
    void testDeque() {
        deque<int> my_deque;
        deque<string> name_queue {"lefe", "wsy"};
        cout << "[0] = " <<  name_queue[0] << endl;
        cout << "front = " <<  name_queue.front() << endl;
        cout << "back = " <<  name_queue.back() << endl;
        name_queue.push_back("bx");
        name_queue.pop_front();
    }
    
    /**
     双向链表
     */
    void testList() {
        list<string> words {"hello", "list"};
        // 头部插入元素
        words.push_front("push_fron");
        words.emplace_front("emplace_front");
        // 尾部插入
        words.push_back("push_back");
        words.emplace_back("emplace_back");
        // 指定位置插入
        words.insert(words.begin()++, "insert");
        // 删除元素
        words.remove("push_fron");
        // 通过迭代器来访问链表中的元素
        list<string>::iterator beg_iter = words.begin();
        list<string>::iterator end_iter = words.end();
        cout << "beg_iter:" << *beg_iter << endl;
        cout << "end_iter:"  << *end_iter << endl;
        
        for (auto a : words) {
            cout << a << endl;
        }
    }
    
    /**
     这个是单链表
     drward_list 和 list 最主要的区别是:它不能反向遍历元素；只能从头到尾遍历。
     */
    void testForwardList() {
        forward_list<string> flist {"name", "lefe", "hello"};
        // 计算它的大小
        auto count = distance(begin(flist), end(flist));
        cout << "size:" << count << endl;
        // 头部插入
        flist.push_front("before3");
        // 在头部插入
        flist.insert_after(flist.begin(), "before2");
        // 在头结点前面插入
        flist.insert_after(flist.before_begin(), "before1");
        
        for (auto word : flist) {
            cout << word << endl;
        }
    }
    
    /**
     栈，底层使用了双端队列实现
     */
    void testStack() {
        stack<int> s;
        s.push(1);
        s.push(3);
        s.pop();
        int top = s.top();
        cout << "top=" << top << endl;
        s.size();
    }
    
    /**
     队列，底层使用了双端队列实现
     */
    void testQueue() {
        queue<int> s;
        s.push(1);
        s.push(3);
        s.pop();
        s.front();
        s.back();
        s.size();
    }
    
    /**
     优先队列：
     */
    void testPriorityQueue() {
        
    }
    
    /**
     堆：
     */
    void testHeap() {
        vector<int> numbers {6, 2, 7, 3, 5};
    }
    
    /**
     map：
     map 后面保存的是 pair 类型
     */
    void testMap() {
        // 初始化
        map<string, string> m;
        pair<map<string, string>::iterator, bool> ret_iter = m.insert(pair<string, string>("name", "lefe"));
        if (ret_iter.second == false) {
            cout << "name have existed" << endl;
        }
        // 初始化
        map<int, string> m2 = {
            {2014, "iOS"},
            {2015, "Android"},
        };
        // 单值插入
        m["name"] = "wsy";
        // 多指插入
        m.insert({{"age", "20"}, {"from", "nmg"}});
        
        m.insert({"baby" , "true"});
        
        cout << "size = " << m.size() << endl;

        // 使用迭代器删除
        m.erase(m.begin());
        
        // 查找
        map<string, string>::iterator find_iter = m.find("from");
        if (find_iter != m.end()) {
            cout << "find" << endl;
        }
        
        // 遍历, key 是有序的
        for (pair<string, string> v : m) {
            cout << v.first << " = " << v.second << endl;
        }
        // 删除全部元素
        m.clear();
    }
    
    /**
     pair：保存两个值（可以是任意类型）
     */
    void testPair() {
        pair<string, string> p = {"name", "lefex"};
        // 通过first 和 second 来获取第一个和第二个值
        cout << p.first;
        cout << p.second;
    }
    
    /**
     tuple：元组，可以存放不同类型的多个元素，是 pair 的扩展
     */
    void testTuple() {
        pair<string, string> p = {"name", "lefex"};
        // 创建一个 tuple，类型为 <strinng, int, double, pair>
        auto my_tuple = make_tuple("name", 20, 10.3, p);
        // 获取第一个元素
        cout << "0 = " << get<0>(my_tuple) << endl;
        // 获取第二个元素
        cout << "1 = " << get<1>(my_tuple) << endl;
    }
    
    /**
     map：
     */
    void testMultimap() {
        
    }
    
    /**
     map：
     */
    void testHash() {
        
    }
    
    /**
     UnorderMap：无序的 map
     */
    void testUnorderMap() {
        unordered_map<string, string> m;
    }
    
    /**
     set：使用树来实现，其中保存的元素是有序的
     */
    void testSet() {
        set<int> s {1, 3, 4};
    }
    
    /**
     multiSet：保存重复的对象
     */
    void testMultiSet() {
        
    }
    
    /**
     unorderSet：无序的
     */
    void testUnorderSet() {
        // set_union
        // set_intersection
        // set_difference
    }
    
    /**
     迭代器（iterator）有时又称光标（cursor）是程序设计的软件设计模式，
     可在容器对象（container，例如链表或数组）上遍访的接口，设计人员无需关心
     容器对象的内存分配的实现细节。
     
     迭代器可以进行运算，比如：++，--，==，！=，加减一个整型 迭代器直接也可以做运算
     每种容器都定义了自己的迭代器
     通过解引用操作来访问迭代器所指向的值
     const_iterator类型只能用于读取容器内元素，但不能改变其值
     */
    void testIterator() {
        vector<string> words = {"hello", "world", "and", "lefe"};
        
        // 迭代器取出的就是值对应的指针
        vector<string>::iterator beg_iter = words.begin();
        for (; beg_iter != words.end(); beg_iter++) {
            cout << *beg_iter << endl;
        }
        // 使用迭代器访问第一个元素
        cout << "first = " << *(words.begin()) << endl;
        // 使用迭代器访问最后个元素，end 迭代器并不指向 vector 中的任何一个元素
        // 它相当于一个哨兵来检测是否处理完所有的元素
        cout << "end = " << *(words.end()-1) << endl;
        // 使用迭代器修改值
        vector<string>::iterator beg_nomal_iter = words.begin();
        *beg_nomal_iter = "new_hello";
        cout << "first_new = " << *beg_nomal_iter << endl;
        // const 迭代器
        vector<string>::const_iterator beg_const_iter = words.begin();
        cout << "first_const = " << *beg_const_iter << endl;
        // const 迭代器只能访问值，不能修改
        // *beg_const_iter = "new_hello";
        
        /**
         input
         output
         forward
         bidirectional
         random access 随机访问迭代器 vector.begin()
         迭代器会分成不同的种类：
         input: 输入，只能一次读一个元素，向前移动
         output: 输出，想容器中写入元素
         1.reverse_iterator: 反向获取值
         */
        vector<string>::reverse_iterator re_iter = words.rbegin();
        // 逆向访问 words 中的单词
        re_iter += 1;
        cout << "reverse: " << *re_iter << endl;
        
    }
};

#endif /* DataStructer_hpp */
