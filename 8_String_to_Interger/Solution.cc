#include <string>
#include <limits.h>

using namespace std;

// Code above shouldn't be included in your Solution
class Solution {
 public:
  int myAtoi(string str) {
    bool is_pos = true;
    bool is_ahead = true;
    long ans = 0;
    for(auto &c : str){
      if(c == ' '){
        if( !is_ahead)
          break;
      }
      else if(c >= '0' && c <= '9'){
        if(is_ahead)
          is_ahead = false;
        ans *= 10;
        ans += c - '0';
        if(ans > INT_MAX)
          return is_pos ? INT_MAX : INT_MIN;    
      }
      else if(c == '+' || c == '-'){
        if(! is_ahead)
          break;
        is_ahead = false;
        is_pos = c == '+';
      }
      else{
        break;
      }
    }
    return is_pos ? ans : -1 * ans;
  }
};