#include <string>
using namespace std;

// Code above shouldn't be included in your Solution

class Solution {
 public:
  string convert(string s, int numRows) {
    string ans = s;
    int gap = numRows == 1 ? 1 : numRows * 2 - 2;
    int last_row = numRows - 1;
    int row = 0, ans_index = 0, s_index = 0;
    int small_gap = 0;
    int remaim_gap = 0;
    for(; row < numRows; row++){
      s_index = row;
      while(s_index < s.size()){
        ans[ans_index++] = s[s_index];
        s_index += gap;
        if(row != 0 && row != last_row){
          small_gap = s_index - remaim_gap;
          if(small_gap >= s.size())
            break;
          ans[ans_index++] = s[small_gap];
        }
      }
      remaim_gap += 2;      
    }
    return ans;
  }
};