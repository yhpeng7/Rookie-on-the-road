/**
 * 我的思路：遍历数组的时候，用max更新每个点能跳到的最远的点
*/

//优秀代码，自己写的代码太丑，就不放出来了
bool canJump(int* nums, int numsSize) {
    int max = 0;
    int i;
    for (i = 0; i < numsSize-1 && i <= max; i++) {
        max = max>nums[i]+i?max:nums[i]+i;
    }
    if (max >= numsSize-1) {
        return true;
    } else {
        return false;
    }
}