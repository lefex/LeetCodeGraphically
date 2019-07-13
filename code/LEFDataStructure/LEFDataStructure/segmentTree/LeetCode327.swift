//
//  LeetCode327.swift
//  LEFDataStructure
//
//  Created by wsy on 2019/7/13.
//  Copyright © 2019 WSY. All rights reserved.
//

import Foundation

class Solution {
    var datas: [Int]!
    var trees: [Int]!
    var merger: (_ a: Int, _ b: Int) -> Int
    init(datas: [Int], defaultValue: Int, merger: @escaping (_ a: Int, _ b: Int) -> Int) {
        self.merger = merger
        self.datas = datas
        // trees 初始化，大小为源数据源的 4 倍
        trees = Array(repeating: defaultValue, count: datas.count * 4)
        // 构建线段树
        bulidSegment(l: 0, r: datas.count-1, curIndex: 0)
    }

    
    // 构建线段树，取值范围为 l....r，curIndex 为线段树节点的位置
    private func bulidSegment(l: Int, r: Int, curIndex: Int) {
        if l == r {
            // 叶子节点
            trees[curIndex] = datas[l]
            return
        }
        // 左孩子节点
        let lchildIndex = leftChildIndex(index: curIndex)
        // 右孩子节点
        let rchildIndex = rightChildIndex(index: curIndex)
        // 中间节点
        let mid = l + (r - l) / 2
        // 构建左子树，范围为 [ l...mid ]
        bulidSegment(l: l, r: mid, curIndex: lchildIndex)
        // 构建右子树，范围为 [ mid+...r ]
        bulidSegment(l: mid+1, r: r, curIndex: rchildIndex)
        // 通过 merger 求得左右子树节点的数据
        trees[curIndex] = merger(trees[lchildIndex], trees[rchildIndex])
    }
    
    // 查询区间范围的值
    func query(ql: Int, qr: Int) -> Int? {
        if ql < 0 || ql > qr || ql > datas.count - 1 || qr < 0 || qr > datas.count - 1 {
            return nil
        }
        return query(tIndex: 0, l: 0, r: datas.count - 1, ql: ql, qr: qr)
    }
    
    // [0-5] [0-2]
    private func query(tIndex: Int, l: Int, r: Int, ql: Int, qr: Int) -> Int? {
        //        print("tIndex=\(tIndex),l=\(l),r=\(r), ql=\(ql), qr=\(qr)")
        if l == ql && r == qr {
            return trees[tIndex]
        }
        
        let mid = l + (r - l) / 2
        let lchildIndex = leftChildIndex(index: tIndex)
        let rchildIndex = rightChildIndex(index: tIndex)
        
        if qr <= mid {
            // 查找区间都在左子树
            return query(tIndex: lchildIndex, l: ql, r: mid, ql: ql, qr: qr)
        } else if ql >= mid + 1 {
            // 查找区间都在右子树
            return query(tIndex: rchildIndex, l: mid+1, r: r, ql: ql, qr: qr)
        }
        
        // 既在 left 又在 right，分开查 left 和 right，查到结构后 merger
        let lresult = query(tIndex: lchildIndex, l: l, r: mid, ql: ql, qr: mid)
        let rresult = query(tIndex: rchildIndex, l: mid + 1, r: r, ql: mid + 1, qr: qr)
        if let lresult = lresult {
            if let rresult = rresult {
                // 查询结果需要 merger 操作
                return merger(lresult, rresult)
            }
        }
        return nil
    }
    
    func set(index: Int, value: Int) {
        if index < 0 || index > datas.count {
            return
        }
        // 更新源数据中的值
        datas[index] = value
        // 更新线段树种的值
        set(index: index, value: value, tIndex: 0, l: 0, r: datas.count-1)
    }
    
    // 更新 index 对应的值为 value，tIndex 为当前树的根节点，l、r 表示区间
    private func set(index: Int, value: Int, tIndex: Int, l: Int, r: Int) {
        if l == r {
            // 叶子节点
            trees[tIndex] = value
            return
        }
        let mid = l + (r-l) / 2
        let lchildIndex = leftChildIndex(index: tIndex)
        let rchildIndex = rightChildIndex(index: tIndex)
        if index <= mid {
            // 在左子树更新
            set(index: index, value: value, tIndex: lchildIndex, l: l, r: mid)
        } else if index >= mid+1 {
            // 在右子树更新
            set(index: index, value: value, tIndex: rchildIndex, l: mid + 1, r: r)
        }
        // 递归回朔的时候，需要更新红色节点的值，执行 merger
        trees[tIndex] = merger(trees[lchildIndex], trees[rchildIndex])
    }
    
    
    func leftChildIndex(index: Int) -> Int {
        return 2 * index + 1;
    }
    
    func rightChildIndex(index: Int) -> Int {
        return 2 * index + 2;
    }
}

