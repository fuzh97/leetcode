/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        /*
    1.确定分割线两端数组元素个数
    2.找见分割线
    */
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2)
            return findMedianSortedArrays(nums2, nums1);  //保证第一个数组较短一些
        //确定分隔线两边数组元素的个数 直接使用(len1 + len2 + 1) / 2 有可能越界
        int totalLeft = len1 + (len2 - len1 + 1) / 2;
        //在nums1的区间[0,len1]里查找恰当的分隔线
        //使得nums1[i-1]<=nums2[j] && nums2[j-1]<=nums1[i]
        int left = 0, right = len1;
        /*
        while (left < right) {
          // left == right时 循环退出
          //分隔线在第一个数组的位置 同理（left + right) / 2 有可能越界
          //+1是为了不出现死循环，即left永远小于right的情况，同时保证不会出现下标越界，即i-1<0的情况。
          int i = left + (right - left + 1) / 2;  //第一个数组左边元素的个数
          int j = totalLeft - i;  //分隔线在第二个数组左边元素的个数
          if (nums1[i - 1] > nums2[j]) {
            //第一个数组分隔线左边元素大于第二个数组分隔线右边元素
            //分隔线需要左移 下一轮在[left,i-1]里面寻找
            right = i - 1;
          } else {
            // 此时说明条件满足，应当将左指针右移到i的位置
            // 下一轮在[i,right]里面寻找
            //  [left(i),right] 如果i = left + (right - left) / 2
            //
        如果只有两个元素的时候，一旦左边界为i，区间就不会缩小了，即死循环，因此要在判断的时候向上取整，即int
            //  i = left + (right - left + 1) / 2 这里要加一
            //  同时可以保证i不会取到0，即i-1不会越界
            left = i;
          }
        }
        */
        while (left < right) {
            int i = left + (right - left) / 2;
            int j = totalLeft - i;
            if (nums2[j - 1] > nums1[i]) {
                //第二个数组的分隔线左边元素大于第一个数组分隔线右边的元素
                //说明分隔线需要向右移 下一轮在[i+1,right]里面查找
                //因为这样不会导致系循环，于是这里不需要上取整，i的定义里不需要加一，同时i不会取到m导致越界
                left = i + 1;
            } else {
                //否则下一轮搜索区间为[left,i]
                right = i;
            }
        }
        int i = left, j = totalLeft - i;  //分隔线的位置;
        // i=0说明第一个数组分隔线左边没有值，为了不影响其与nums2LeftMax的比较，将其设置为Int的最小值
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        // j=len1说明第一个数组分隔线左边没有值，为了不影响其与nums2RightMin的比较，将其设置为Int的最大值
        int nums1RightMin = i == len1 ? INT_MAX : nums1[i];
        // j=0说明第一个数组分隔线左边没有值，为了不影响其与nums1LeftMax的比较，将其设置为Int的最小值
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        // j=len2说明第一个数组分隔线左边没有值，为了不影响其与nums1RightMin的比较，将其设置为Int的最大值
        int nums2RightMin = j == len2 ? INT_MAX : nums2[j];
        if ((len1 + len2) % 2 == 1) {
            //如果两数组长度之和为奇数
            return max(nums1LeftMax, nums2LeftMax);
        } else {
            //两数组长度
            //之和为偶数
            return (double)((max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin))) / 2;
        }
    }
};
// @lc code=end
