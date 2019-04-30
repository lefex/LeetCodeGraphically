# LeetCodeGraphically
### 图解 LeetCode 算法，让算法"活"起来。

数据结构和算法是面试非常重要的内容，有些算法非常难以理解，仅靠文字描述很难让读者明白算法思想。如果通过图示的方式来描述算法和数据结构，会形象很多，读者也容易理解算法的真实含义。

这个项目目的是让学习数据结构和算法变得更轻松，我会逐步解析LeetCode上的题目，在学习算法的同时也会讲解设计到的数据结构。



## 公众号



图解算法相关的文章每天都会在公众号发布，欢迎关注我的公众号「超越技术」，和我一同学习！！！

<img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/cyjs_qr.png?raw=true" title="lefex" width="200"/>



## 图解排序算法

[代码位置](https://github.com/lefex/LeetCodeGraphically/blob/master/code/LeetCodeGraphically/LeetCodeGraphically/LEFSortManager.h)

| [图解排序 1/10 - 冒泡排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483822&idx=1&sn=ff5b8abd13ac4e89953dd07f16eca8d3&chksm=fabb013dcdcc882be39d9aad8c462de93eb7bcf49234caa5dd7403cc67bb84f4d2168a1952a5&scene=21#wechat_redirect) | 冒泡排序是通过比较两个相邻元素的大小实现排序，如果前一个元素大于后一个元素，就交换这两个元素 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/maopao.jpeg?raw=true" title="lefex" width="200"/> |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [图解排序 2/10 - 插入排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483828&idx=1&sn=d8f0675f4e54e3b273c90c59be54eaeb&chksm=fabb0127cdcc883158bb0791f26cae1ea8494b496744f802b22babb4c03eaaef25e98dfbff57&scene=21#wechat_redirect) | 选择排序的核心思想是把一个待排序序列，分成 2 部分，前半部分为有序序列，后半部分为无序序列，遍历后半部分数据，插入到前半部分已经排序好的序列，最终得到一个有序序列 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/charu.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 3/10 - 希尔排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483834&idx=1&sn=d91d9d354d765da8bece9c06510f3a5d&chksm=fabb0129cdcc883f5c48e76a7690b4fe698415827c82c8ef4c8482a8618fdff05258f13eff03&token=623725354&lang=zh_CN#rd) | 把一个序列分组，对分组后的内容进行[**插入排序**](http://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483828&idx=1&sn=d8f0675f4e54e3b273c90c59be54eaeb&chksm=fabb0127cdcc883158bb0791f26cae1ea8494b496744f802b22babb4c03eaaef25e98dfbff57&scene=21#wechat_redirect)，这里的分组只是逻辑上的分组，不会重新开辟存储空间 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/shell.001.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 4/10 - 快速排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483843&idx=1&sn=0d0e23585aacaa4a291c201a155f7617&chksm=fabb0150cdcc88464eacf4f6b60a0562171658cb4e0c6262b2fb9ecd02c194e58faae777ab0f&scene=21#wechat_redirect) | 对待排序序列通过一个「支点」（支点就是序列中的一个元素，别把它想的太高大上）进行拆分，使得左边的数据小于支点，右边的数据大于支点。然后把左边和右边再做一次递归，直到递归结束 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/quick.001.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 5/10 - 归并排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483848&idx=1&sn=35145839503cf88a88fdd6e964a6c90d&chksm=fabb015bcdcc884d06dccf879889abed4f680cbb62e07aae65a82ce7f7a28de9a0c29d0c0cce&scene=21#wechat_redirect) | 归并排序，采用分治思想，先把待排序序列拆分成一个个子序列，直到子序列只有一个元素，停止拆分，然后对每个子序列进行边排序边合并 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/guibing.001.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 6/10 - 堆排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483889&idx=1&sn=4c92c6d9fdb9b0fbc3cc99ee1a2fcadf&chksm=fabb0162cdcc8874bb601ed836f996dcd849f50993960d07e34539f6779b2dc295fcad0d4d63&scene=21#wechat_redirect) | 堆排序需要借助于一种数据结构「堆」，注意下文说的都是 「大根堆」。排序的过程中需要不断进行重组堆（heapify 阶段） | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/heap.003.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 7/10 - 计数排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483892&idx=1&sn=2af95b49be0ac263a9fa16444c06a360&chksm=fabb0167cdcc8871c15cf1bb85ef625cc4395e91cbe8f81bdbcb1e47a3d8af30310b0adb4f79&scene=21#wechat_redirect) | 计数排序的核心思想是把一个无序序列 A 转换成另一个有序序列 B，从 B 中逐个“取出”所有元素，取出的元素即为有序序列 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/count.001.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 8/10 - 桶排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483894&idx=1&sn=050c2d219cc16021db0f6cec83045257&chksm=fabb0165cdcc88737c673df3424b615e0e64cc5a0501d9c97cd26bfcff651a60a2d19a43f585&scene=21#wechat_redirect) | 桶排序的核心思想是把数据分到若干个“桶”中，对“桶”中的元素进行排序，最终把“桶”中已排序好的数据合并为一个有序序列。 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/bucket.001.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 9/10 - 基数排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483895&idx=1&sn=0c3097272d4587963a026cf699d10ce0&chksm=fabb0164cdcc88724dfaebd98087baa914f33253bd9278c95f48859529f34943185e83ee2f62&scene=21#wechat_redirect) | 基数排序是从待排序序列找出可以作为排序的「关键字」，按照「关键字」进行多次排序，最终得到有序序列。 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/diget.001.jpeg?raw=true" title="lefex" width="200"/> |
| [图解排序 10/10 - 选择排序](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483897&idx=1&sn=8fd337d568a9f56fd1e926fb1012565c&chksm=fabb016acdcc887ce4f0e438a4fb2704c62cf4996a0abda2f2f2f6a629d52aef3be01df46010&scene=21#wechat_redirect) | 选择排序的思想是，依次从「无序列表」中找到一个最小的元素放到「有序列表」的最后面 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/xuanze.jpeg?raw=true" title="lefex" width="200"/> |



## 图解LeetCode链表相关算法

[代码位置](https://github.com/lefex/LeetCodeGraphically/blob/master/code/LeetCodeGraphically/LeetCodeGraphically/LEFListSubject.hpp)

| [图解 LeetCode 链表: 83. Remove Duplicates from Sorted List](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483939&idx=1&sn=5e68e353c5216ff197b8403152d03c02&chksm=fabb02b0cdcc8ba6fab84dca5b239dd44f0d1924fa5c559b681688c46ca885e00f0b93b9fe9a&token=623725354&lang=zh_CN#rd) | 给定一个「有序」的链表，去掉重复的节点，每个节点只能出现一次 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/let_83.png?raw=true" title="lefex" width="200"/> |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [图解 LeetCode 链表: 82. Remove Duplicates from Sorted List II](https://mp.weixin.qq.com/s?__biz=MzUzMTk3ODc0OA==&mid=2247483940&idx=1&sn=0f71bdcf10b28e523770b8d7d10acbd8&chksm=fabb02b7cdcc8ba1a00c9018834d480bddeeac837d57e7c2940619aafd5b418f1ebfa564c2dd&token=623725354&lang=zh_CN#rd) | 移除链表中出现过多次的节点，解这道题的思路也是「水管思路」，对水管进行拆分，重组。链表中可能出现多个重复节点，需要把这些重复的节点全部干掉 | <img style="border-radius: 30px" src="https://github.com/lefex/LeetCodeGraphically/blob/master/images/let_82.png?raw=true" title="lefex" width="200"/> |

