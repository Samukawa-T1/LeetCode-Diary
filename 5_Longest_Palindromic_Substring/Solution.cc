#include<string>
using namespace std;

// Code above shouldn't be included in your Solution

class Solution {
 public:
  string longestPalindrome(string s) {
    string longest;
    int max_lengh = 0;
    int begin, end;
    int half_one, half_two;
    for(int i = 0; i < s.size(); i++){
      half_one = FindHalf(i, i, s);
      begin = i - half_one;
      end = i + half_one + 1;
      if(i > 0){
        if(s[i] == s[i-1]){
          half_two = FindHalf(i - 1, i, s);
          if(half_one < half_two + 1){
            begin = i - half_two - 1;
            end = i + half_two + 1;
          }
        }         
      } 
      if(max_lengh < (end - begin)){
        max_lengh = end - begin;
        longest = string(s.begin() + begin, s.begin() + end);
      }   
    }
    return longest;
  }
 private:
  inline int FindHalf(int index_1, int index_2,const string& kS){
    int j = 0;
    do{
      if(index_1 - j < 0)
        return --j;
      if(index_2 + j >= kS.size())
        return --j;
      if(kS[index_1 - j] != kS[index_2 + j])
        return --j;
    }while(++j);

    return j;
  }
};