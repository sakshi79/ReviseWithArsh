// Question link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map <int,ListNode*> pre_sum;
        int sum = 0;
        pre_sum[sum] = dummy;
        
        while(head)
        {
            sum += head->val;
            pre_sum[sum] = head; // Will remove those nodes that add up to zero
            head = head->next;
        }

        head = dummy;
        sum = 0;
        while(head)
        {
            sum += head->val;
            ListNode* tmp = pre_sum[sum];
            if(tmp != head)
                head->next = tmp->next;
            head = head->next;
        }
        return dummy->next;
    }
};
