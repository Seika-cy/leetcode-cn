/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int strStr(string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    vector<int> next(len2, 0);
    for (int i = 1, j = 0; i < len2; i++) {
      while (j && str2[i] != str2[j]) {
        j = next[j - 1];
      }
      if (str2[i] == str2[j]) {
        j++;
      }
      next[i] = j;
    }

    for (int i = 0, j = 0; i < len1; i++) {
        while(j&&str1[i]!=str2[j])
        {
            j = next[j-1];
        }
        if(str1[i]==str2[j])
            j++;
        if(j==len2)
            return (i-j+1);
    }

    return -1;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
