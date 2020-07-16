#include <vector>
using namespace std;

// Code above shouldn't be included in your Solution

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int target_index = (nums1.size() + nums2.size()) / 2;
    int target_count = 1;
    if(target_index * 2 == (nums1.size() + nums2.size()))
      target_count = 2;

    double ans = 0;
    for(int i = 0; i < target_count; i++){
      int mid_index = FindTarget(nums1, nums2, target_index);
      if(mid_index == -1){
        mid_index = FindTarget(nums2, nums1, target_index);
        ans += nums2[mid_index];
      }
      else{
        ans += nums1[mid_index];
      }
      --target_index;
    }
    return ans / target_count;
  }
 private:
  int FindTarget(vector<int>& current, vector<int>& other, int target_index){
    int target_count = target_index + 1;
    int start = 0;
    int end = current.size();
    int size_sum = current.size() + other.size();

    int bigger_count, smaller_count;
    int other_b, other_s;
    while(start != end){
      int mid = (start + end) / 2;
      bigger_count = CountNumber(current[mid], current, true) + CountNumber(current[mid], other, true);
      smaller_count = CountNumber(current[mid], current, false) + CountNumber(current[mid], other, false);


      if(smaller_count >= target_count)
        end = mid;
      else if(bigger_count > (size_sum - target_count))
        start = mid + 1;
      else
        return mid;
    }
    return -1;
  }
  int CountNumber(int target, vector<int>& nums, bool is_bigger){
    int start = 0;
    int end = nums.size();
    while(start != end){
      int mid = (start + end ) / 2;

      if(target > nums[mid])
        start = mid + 1;
      else if (target == nums[mid] && is_bigger)
        start = mid + 1;
      else
        end = mid;     
    }
    if(is_bigger)
      return nums.size() - start;
    else
      return start;
  }
};