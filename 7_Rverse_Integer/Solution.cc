#include <string>
#include <limits.h>
using namespace std;

// Code above shouldn't be included in your Solution
class Solution {
 public:
  int reverse(int x) {
    bool is_pos = x > 0;
    long buffer = 0;
    if(is_pos)
      x = -x;
    while( x != 0){
      buffer = buffer * 10 + x % 10;
      if(buffer < INT_MIN)
        return 0;
      x /= 10;
    }
    return static_cast<int>(is_pos? -buffer: buffer);
  }
};