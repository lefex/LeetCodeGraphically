//
//  LEFSortManager.m
//  DSACode
//
//  Created by wsy on 2019/4/6.
//  Copyright © 2019 Wang,Suyan. All rights reserved.
//

#import "LEFSortManager.h"

@implementation LEFSortManager


/**
 冒泡排序：O(n*n), 由于不需要额外的存储空间，空间复杂度为 O(1)
 @[@3, @9, @4, @1, @5, @10, @2, @7, @6]
 利用两层循环来遍历数组，如果后面的元素大于前面的元素，就交换位置

 @param unsortDatas 未排序的数组
 @return 排序的数组
 */
+ (NSArray *)bubbleSort:(NSArray *)unsortDatas {
    NSMutableArray *unSortArray = [unsortDatas mutableCopy];
    for (int i = 0; i < unSortArray.count -1 ; i++) {
        BOOL isChange = NO;
        for (int j = 0; j < unSortArray.count - 1 - i; j++) {
            // 比较相邻两个元素的大小，后一个大于前一个就交换
            if ([unSortArray[j] integerValue] > [unSortArray[j+1] integerValue]) {
                NSNumber *data = unSortArray[j+1];
                unSortArray[j+1] = unSortArray[j];
                unSortArray[j] = data;
                isChange = YES;
            }
        }
        if (!isChange) {
            // 如果某次未发生数据交换，说明数据已排序
            break;
        }
    }
    return [unSortArray copy];
}


/**
 选择排序：O(n*n), 由于不需要额外的存储空间，空间复杂度为 O(1)
 
 @[@3, @9, @4, @1, @5, @10, @2, @7, @6]
 每次找到最小的元素放到前面
 
 @param unsortDatas 未排序的数组
 @return 排序的数组
 */
+ (NSArray *)seelectSort:(NSArray *)unsortDatas {
    NSMutableArray *unSortArray = [unsortDatas mutableCopy];
    for (int i = 0; i < unSortArray.count; i++) {
        int mindex = i;
        for (int j = i; j < unSortArray.count; j++) {
            // 找到最小元素的index
            if ([unSortArray[j] integerValue] < [unSortArray[mindex] integerValue]) {
                mindex = j;
            }
        }
        // 交换位置
        NSNumber *data = unSortArray[i];
        unSortArray[i] = unSortArray[mindex];
        unSortArray[mindex] = data;
    }
    return [unSortArray copy];
}

/**
 插入排序：O(n*n), 由于不需要额外的存储空间，空间复杂度为 O(1)
 
 @[@3, @9, @4, @1, @5, @10, @2, @7, @6]
 把未排序的数据分为两拨，一波是以第一个元素开始的已排序数据，一波是除第一个元素外的未排序数据，遍历
 未排序的数据，逐步插入到排序数据的合适位置。它会与排序队列中的元素逆向比较，如果小于就交换位置。
 
 @param unsortDatas 未排序的数组
 @return 排序的数组
 */
+ (NSArray *)insertionSort:(NSArray *)unsortDatas {
    NSMutableArray *unSortArray = [unsortDatas mutableCopy];
    
    int preindx = 0;
    NSNumber *current;
    for (int i = 1; i < unSortArray.count; i++) {
        preindx = i - 1;
        // 必须记录这个元素，不然会被覆盖掉
        current = unSortArray[i];
        // 逆序遍历已经排序好的数组

        // 当前元素小于排序好的元素，就移动到下一个位置
        while (preindx >= 0 && [current integerValue] < [unSortArray[preindx] integerValue] ) {
            // 元素向后移动
            unSortArray[preindx+1] = unSortArray[preindx];
            preindx -= 1;
        }
        // 找到合适的位置，把当前的元素插入
        unSortArray[preindx+1] = current;
    }
    return [unSortArray copy];
}


/**
 希尔排序：O(n*n), 由于不需要额外的存储空间，空间复杂度为 O(1)
 @[@3, @9, @4, @1, @5, @10, @2, @7, @6]
 希尔排序(Shell's Sort)是插入排序的一种又称“缩小增量排序”（Diminishing Increment Sort），是直接插入排序算法的一种更高效的改进版本。希尔排序是非稳定排序算法
 
 @param unsortDatas 未排序的数组
 @return 排序的数组
 https://blog.csdn.net/qq_39207948/article/details/80006224
 */
+ (NSArray *)shellSort:(NSArray *)unsortDatas {
    NSMutableArray *unSortArray = [unsortDatas mutableCopy];
    // len = 9
    int len = (int)unSortArray.count;
    // floor 向下取整，所以 gap的值为：4，2，1
    for (int gap = floor(len / 2); gap > 0; gap = floor(gap/2)) {
        // i=4;i<9;i++ (4,5,6,7,8)
        for (int i = gap; i < len; i++) {
            // j=0,1,2,3,4
            // [0]-[4] [1]-[5] [2]-[6] [3]-[7] [4]-[8]
            for (int j = i - gap; j >= 0 && [unSortArray[j] integerValue] > [unSortArray[j+gap] integerValue]; j-=gap) {
                // 交换位置
                NSNumber *temp = unSortArray[j];
                unSortArray[j] = unSortArray[gap+j];
                unSortArray[gap+j] = temp;
            }
        }
    }
    return [unSortArray copy];
}


/**
 快速排序

 @param unSortArray 待排序序列
 @param lindex 待排序序列左边的index
 @param rIndex 待排序序列右边的index
 @return 排序结果
 */
+ (NSArray *)quickSort:(NSMutableArray *)unSortArray leftIndex:(NSInteger)lindex rightIndex:(NSInteger)rIndex {
    NSInteger i = lindex; NSInteger j = rIndex;
    // 取中间的值作为一个支点
    NSNumber *pivot = unSortArray[(lindex + rIndex) / 2];
    while (i <= j) {
        // 向左移动，直到找打大于支点的元素
        while ([unSortArray[i] integerValue] < [pivot integerValue]) {
            i++;
        }
        // 向右移动，直到找到小于支点的元素
        while ([unSortArray[j] integerValue] > [pivot integerValue]) {
            j--;
        }
        // 交换两个元素，让左边的大于支点，右边的小于支点
        if (i <= j) {
            // 如果 i== j，交换个啥？
            if (i != j) {
                NSNumber *temp = unSortArray[i];
                unSortArray[i] = unSortArray[j];
                unSortArray[j] = temp; }
            i++;
            j--;
        }
    }
    // 递归左边，进行快速排序
    if (lindex < j) {
        [self quickSort:unSortArray leftIndex:lindex rightIndex:j];
    }
    // 递归右边，进行快速排序
    if (i < rIndex) {
        [self quickSort:unSortArray leftIndex:i rightIndex:rIndex];
    }
    return [unSortArray copy];
}

+ (NSArray *)mergeSort:(NSArray *)unSortArray {
    NSInteger len = unSortArray.count;
    // 递归终止条件
    if (len <= 1) {
        return unSortArray;
    }
    NSInteger mid = len / 2;
    // 对左半部分进行拆分
    NSArray *lList = [self mergeSort:[unSortArray subarrayWithRange:NSMakeRange(0, mid)]];
    // 对右半部分进行拆分
    NSArray *rList = [self mergeSort:[unSortArray subarrayWithRange:NSMakeRange(mid, len-mid)]];
    // 递归结束后执行下面的语句
    NSInteger lIndex = 0;
    NSInteger rIndex = 0;
    // 进行合并
    NSMutableArray *results = [NSMutableArray array];
    while (lIndex < lList.count && rIndex < rList.count) {
        if ([lList[lIndex] integerValue] < [rList[rIndex] integerValue]) {
            [results addObject:lList[lIndex]];
            lIndex += 1;
        } else {
            [results addObject:rList[rIndex]];
            rIndex += 1;
        }
    }
    // 把左边剩余元素加到排序结果中
    if (lIndex < lList.count) {
        [results addObjectsFromArray:[lList subarrayWithRange:NSMakeRange(lIndex, lList.count-lIndex)]];
    }
    // 把右边剩余元素加到排序结果中
    if (rIndex < rList.count) {
        [results addObjectsFromArray:[rList subarrayWithRange:NSMakeRange(rIndex, rList.count-rIndex)]];
    }
    return results;
};

+ (NSArray *)countingSort:(NSArray *)datas {
    // 1.找出数组中最大数和最小数
    NSNumber *max = [datas firstObject];
    NSNumber *min = [datas firstObject];
    for (int i = 0; i < datas.count; i++) {
        NSNumber *item = datas[i];
        if ([item integerValue] > [max integerValue]) {
            max = item;
        }
        if ([item integerValue] < [min integerValue]) {
            min = item;
        }
    }
    // 2.创建一个数组 countArr 来保存 datas 中元素出现的个数
    NSInteger sub = [max integerValue] - [min integerValue] + 1;
    NSMutableArray *countArr = [NSMutableArray arrayWithCapacity:sub];
    for (int i = 0; i < sub; i++) {
        [countArr addObject:@(0)];
    }
    // 3.把 datas 转换成 countArr，使用 datas[i] 与 countArr 的下标对应起来
    for (int i = 0; i < datas.count; i++) {
        NSNumber *aData = datas[i];
        NSInteger index = [aData integerValue] - [min integerValue];
        countArr[index] = @([countArr[index] integerValue] + 1);
    }
    // 4.从countArr中输出结果
    NSMutableArray *resultArr = [NSMutableArray arrayWithCapacity:datas.count];
    for (int i = 0; i < countArr.count; i++) {
        NSInteger count = [countArr[i] integerValue];
        while (count > 0) {
            [resultArr addObject:@(i + [min integerValue])];
            count -= 1;
        }
    }
    return [resultArr copy];
}

+ (NSArray *)bucketSort:(NSArray *)datas {
    // 1.找出数组中最大数和最小数
    NSNumber *max = [datas firstObject];
    NSNumber *min = [datas firstObject];
    for (int i = 0; i < datas.count; i++) {
        NSNumber *item = datas[i];
        if ([item integerValue] > [max integerValue]) {
            max = item;
        }
        if ([item integerValue] < [min integerValue]) {
            min = item;
        }
    }
    // 2.创建桶
    int maxBucket = 3;
    NSMutableArray *buckets = [NSMutableArray arrayWithCapacity:maxBucket];
    for (int i = 0; i < maxBucket; i++) {
        NSMutableArray *aBucket = [NSMutableArray array];
        [buckets addObject:aBucket];
    }
    // 3.把数据分配到桶中，桶中的数据是有序的
    // a.计算桶中数据的平均值，这样分组数据的时候会把数据放到对应的桶中
    float space = ([max integerValue] - [min integerValue] + 1) / (maxBucket*1.0);
    for (int i = 0; i < datas.count; i++) {
        // b.根据数据值计算它在桶中的位置
        int index = floor(([datas[i] integerValue] - [min integerValue]) / space);
        NSMutableArray *bucket = buckets[index];
        int maxCount = (int)bucket.count;
        NSInteger minIndex = 0;
        for (int j = maxCount - 1; j >= 0; j--) {
            if ([datas[i] integerValue] > [bucket[j] integerValue]) {
                minIndex = j+1;
                break;
            }
        }
        [bucket insertObject:datas[i] atIndex:minIndex];
    }
    // 4.把桶中的数据重新组装起来
    NSMutableArray *results = [NSMutableArray array];
    [buckets enumerateObjectsUsingBlock:^(NSArray *obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [results addObjectsFromArray:obj];
    }];
    
    return results;
}

+ (NSArray *)radixSort:(NSArray *)datas {
    NSMutableArray *tempDatas;
    NSInteger maxValue = 0;
    int maxDigit = 0;
    int level = 0;
    do {
        // 1.创建10个桶
        NSMutableArray *buckets = [NSMutableArray array];
        for (int i = 0; i < 10; i++) {
            NSMutableArray *array = [NSMutableArray array];
            [buckets addObject:array];
        }
        // 2.把数保存到桶中
        for (int i = 0; i < datas.count; i++) {
            NSInteger value = [datas[i] integerValue];
            // 求一个数的多次方
            int xx = (level < 1 ? 1 : (pow(10, level)));
            // 求个位数、十位数....
            int mod = value / xx  % 10;
            [buckets[mod] addObject:datas[i]];
            // 求最大数为了计算最大数
            if (maxDigit == 0) {
                if (value > maxValue) {
                    maxValue = value;
                }
            }
        }
        // 3.把桶中的数据重新合并
        tempDatas = [NSMutableArray array];
        for (int i = 0; i < 10; i++) {
            NSMutableArray *aBucket = buckets[i];
            [tempDatas addObjectsFromArray:aBucket];
            
        }
        // 4.求出数组中最大数的位数, 只需计算一次
        if (maxDigit == 0) {
            while(maxValue > 0){
                maxValue = maxValue / 10;
                maxDigit++;
            }
        }
        // 5.继续下一轮排序
        datas = tempDatas;
        level += 1;
        
    } while (level < maxDigit);
    
    return tempDatas;
}


@end
