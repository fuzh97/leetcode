/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> maxHeap;     //大顶堆，堆顶为小的一半元素的最大值
    priority_queue<int, vector<int>, greater<int>> minHeap;  //小顶堆，堆顶为大的一半元素的最小值
    MedianFinder() {
    }

    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            //两边元素个数相等时，加入到左边的元素中,即大顶堆中
            //加入的过程需要先将元素加入小顶堆，调整之后，将堆顶加入大顶堆
            //即能保证加入的元素一定是右边元素中最小的
            minHeap.push(num);
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        } else {
            //反之，左边元素比右边元素多一个，加入到右边元素中，即小顶堆中
            //加入的过程需要先将元素加入大顶堆，调整之后，将堆顶加入小顶堆
            //即能保证加入的元素一定是左边元素中最大的
            maxHeap.push(num);
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) * 1.0 / 2;
        } else {
            return maxHeap.top() * 1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
