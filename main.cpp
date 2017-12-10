#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
//    寻找最大的回文字串
//    遍历字符串寻找回文中心，然后向前后拓展
    int minIndex;
    int maxLen;
    string longestPalindrome(string s) {
        int len = s.length();
        if(len < 2)
            return s;

        for (int i = 0; i < len; ++i) {
            extendPalindrome(s, i, i);    //回文字串是奇数
            extendPalindrome(s, i, i+1);  //回文字串是偶数
        }

        return s.substr(minIndex, maxLen);
    }

    void extendPalindrome(string s, int l, int r) {
        while (s[l] == s[r] && l >= 0 && r <= s.length()-1) {
            l --;
            r ++;
        }

        if(maxLen < r-l-1) {
            minIndex = l+1;
            maxLen = r-l-1;
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}