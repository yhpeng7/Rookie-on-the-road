/**
 * 我的思路：位运算 
 */
 
int hammingWeight(uint32_t n) {
    int count = 0;
    while(n){
        count++;
        n = n & (n - 1);
    }
    return count;
}