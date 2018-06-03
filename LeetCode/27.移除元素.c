/*
 * 我的思路：用i从前到后检测nums[i]是否和val相等，用j从后到前检测nums[j]是否和val不相等，若是符合要求，交换nums[i]和nums[j]，直到i > j。
 * 注意点;
   * 内层检测nums[j]的条件要加上j > i。
   * 还有最后在交换nums[i]和nums[j]时加了一个判断条件(i != j)后，执行用时大幅降低
 */

int removeElement(int* nums, int numsSize, int val) {
    int i,j,temp,count;
    for(i = 0,count = 0,j = numsSize - 1;i < numsSize;i++){
        if(nums[i] == val){
			//注意判断j > i。。。细节
            for(;nums[j] == val && j > i;j--)
                ;
			//此处不加判断条件也行，但程序耗时会有所增加
            if(i != j)
                temp = nums[i],nums[i] = nums[j],nums[j] = temp;
        }
    /*排除i = j时数组元素是val的情况*/
    if(nums[i] != val){
        printf("%d,",nums[i]);
        count++;
    }
    }
    return count;
}