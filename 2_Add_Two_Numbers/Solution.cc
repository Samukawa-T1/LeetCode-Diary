struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Code above shouldn't be included in your Solution

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        int sum = 0;     
        sum += l1->val;
        sum += l2->val;
        l1 = l1 ->next;
        l2 = l2 -> next;
        bool add = sum > 9;
        if(add)
          sum -= 10;
        auto ans = new ListNode(sum);
        auto current = ans;
        while(l1 || l2){
          sum = add ? 1 : 0;
          if(l1) {sum += l1 -> val; l1 = l1 ->next;}
          if(l2) {sum += l2 -> val; l2 = l2 ->next;}
          add = sum > 9;
          if(add)
            sum -= 10;
          current ->next = new ListNode(sum);
          current = current->next;
        }
        if(add)
          current->next = new ListNode(1);
        return ans;
    }
};