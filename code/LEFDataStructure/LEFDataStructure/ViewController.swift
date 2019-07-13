//
//  ViewController.swift
//  LEFDataStructure
//
//  Created by wsy on 2019/7/11.
//  Copyright © 2019 WSY. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
let datas = [8, 10, 20, 7, 40 , 32 , 12, 3, 19, 26]
let sumSeg = SegmentTree<Int>(datas: datas, defaultValue: 0, merger: { $0 + $1 })
let maxSeg = SegmentTree<Int>(datas: datas, defaultValue: 0) { (a, b) -> Int in
    return max(a, b)
}
let minSeg = SegmentTree<Int>(datas: datas, defaultValue: 0) { (a, b) -> Int in
    return min(a, b)
}

// sum query[3-5] = 79
if let ret = sumSeg.query(ql: 3, qr: 5) {
    print("sum query[3-5] = \(ret)")
}
// max query[3-5] = 40
if let ret = maxSeg.query(ql: 3, qr: 5) {
    print("max query[3-5] = \(ret)")
}
// min query[3-5] = 7
if let ret = minSeg.query(ql: 3, qr: 5) {
    print("min query[3-5] = \(ret)")
}
    }


}

