#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// Code above shouldn't be included in your Solution

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_multimap<int, int> hash_table;
    vector<bool> should_not_check(nums.size(), false);
    vector<int> ans;
    int i = 0;
    for(int n: nums)
      hash_table.insert(pair<int, int>(n, i++));
    i = 0;
    for(; i < nums.size(); i++){
      if(should_not_check[i])
        continue;

      should_not_check[i] = true;
      auto result = hash_table.equal_range(target - nums[i]);
      auto current = result.first;
      while(current != result.second){
        if(! should_not_check[current->second]){
          ans.push_back(i);
          ans.push_back(current -> second);
          break;
        }
        current++;
      }
    }
    return ans;
  }
};