/**
 * 我的思路：第一步通过循环找出所有长度最小的字符串长度minLen,声明一个minLen大小的字符数组，第二步用双重循环依次比较所有字符串的第一个到第minLen个元素，如果相等就保存到theSameString数组中，不行等就结束
 * 注意点：1. 考虑输入字符数组中包含空字符串的情况
 *         2. 考虑无任何输入的情况
 *         3. 考虑要以'\0'结尾
 *         4. 考虑该字符数组只有一个元素的情况
 */
 
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0){
        return "";
    }else if(strsSize == 1){
        return strs[0];
    }
    int minLen = strlen(strs[0]);
    int i,j,k = 0,index = 1;
    
    for(i = 1;i < strsSize;i++){
        if(strlen(strs[i]) < minLen){
            minLen = strlen(strs[i]);
            if(minLen == 0){
                return "";
            }
        }
    }
    
    char *theSameString = (char *)malloc(minLen * sizeof(char));
    for(j = 0;j < minLen && index;j++){
        for(i = 0;i < strsSize - 1;i++){
            if(strs[i][j] != strs[i + 1][j]){     
                index = 0;
                break;
            }
        }
            if(index){
                theSameString[k++] = strs[i][j];
            }
    }
    theSameString[k] = '\0';
    return theSameString;
}