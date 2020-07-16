#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// Code above shouldn't be included in your Solution

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_table;
    vector<int> ans;
    int i = 0;
    for(int n: nums)
      hash_table.insert(pair<int, int>(n, i++));

    i = 0;
    for(; i < nums.size(); i++){
      auto result = hash_table.equal_range(target - nums[i]);
      if(result.first != result.second){
        if(result.first->second != i){
          ans.push_back(i);
          ans.push_back(result.first->second);
          break;
        }
      }
    }
    return ans;
  }
};