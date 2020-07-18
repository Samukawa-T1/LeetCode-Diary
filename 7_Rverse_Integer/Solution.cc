#include <string>
#include <limits.h>
using namespace std;

// Code above shouldn't be included in your Solution
class Solution {
 public:
  int reverse(int x) {
    string buffer = to_string(x);
    int i1 = x < 0? 1 : 0;
    int i2 = buffer.size() - 1;
    char c;
    while(i2 > i1){
      c = buffer[i1];
      buffer[i1++] = buffer[i2];
      buffer[i2--] = c;
    }
    long res = stol(buffer);
    if(res > INT_MAX)
      return 0;
    if(res < INT_MIN)
      return 0;
    return static_cast<int>(res);
  }
};