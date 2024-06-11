/*N3. Given a string s, find the length of the longest 
substring without repeating characters. */

#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int max = 1;
    int size = 1;
    int flag = 0;
    int j = 0;
    int k = 0;
    if(len == 0) {
        return 0;
    } 
    if(len == 1) {
        return 1;
    }
    for(int i = 1; i<len; ++i) {
            for(j = k ; j<i; ++j) {
                if(s[j] != s[i]) {
                    ++size; 
                } else {
                    flag = 1;
                    break;
                }
            }
            if(flag != 0){
                flag = 0;
                k = j+1;
            }
            if(size>max) {
                max = size;
            }
                size = 1;
    }
    return max;
    
}
