class Solution {
 public:
  bool isPalindrome(int x){
    if(x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int rev_last = 0;
    while(x > rev_last) {
     rev_last = rev_last * 10 + x % 10;
      x /= 10;
    }
    return x == rev_last || x == rev_last/10;
  }
};