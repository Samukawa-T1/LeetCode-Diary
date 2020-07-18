class Solution {
 public:
  bool isPalindrome(int x) {
    if(x < 0)
      return false;
    int set[10];
    int num_size = 0;
    while(x > 0){
      set[num_size++] = x % 10;
      x /= 10;
    }
    int begin = 0, end = num_size - 1;
    while(begin < end){
      if(set[begin++]!= set[end--])
        return false;
    }
    
    return true;
  }
};