//
//  LEFSortManager.h
//  DSACode
//
//  Created by wsy on 2019/4/6.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEFSortManager : NSObject

+ (NSArray *)bubbleSort:(NSArray *)unsortDatas;

+ (NSArray *)seelectSort:(NSArray *)unsortDatas;

+ (NSArray *)insertionSort:(NSArray *)unsortDatas;

+ (NSArray *)shellSort:(NSArray *)unsortDatas;

+ (NSArray *)quickSort:(NSMutableArray *)unsortDatas leftIndex:(NSInteger)lindex rightIndex:(NSInteger)rIndex;

+ (NSArray *)mergeSort:(NSArray *)unSortArray;

+ (NSArray *)countingSort:(NSArray *)datas;

+ (NSArray *)bucketSort:(NSArray *)datas;

+ (NSArray *)radixSort:(NSArray *)datas;

@end

NS_ASSUME_NONNULL_END
