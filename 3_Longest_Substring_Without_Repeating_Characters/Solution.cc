#include <string>
using namespace std;

// Code above shouldn't be included in your Solution

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    bool dic[300];
    int max_count = 0;
    for(auto &b: dic)
      b = false;
    int head = 0;
    int tail = 0;

    while(tail != s.size()){
      if(!dic[s[tail]]){
        dic[s[tail]] = true;
        ++tail;
      }
      else{
        if(tail - head > max_count)
          max_count = tail - head;
        while(dic[s[tail]])
          dic[s[head++]] = false;
      }
    }
    if(tail - head > max_count)
          max_count = tail - head;
    return max_count;
  }
};