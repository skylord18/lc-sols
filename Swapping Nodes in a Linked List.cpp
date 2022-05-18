#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *beforekStart = dummy;
        for (int i = 0; i < k; ++i)
        {
            /* code */
            beforekStart = beforekStart->next;
        }
        ListNode * slow = dummy, *fast = dummy;
        for (int i = 0; i < k; ++i)
        {
            /* code */
            fast = fast->next;
        }
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        swap(beforekStart->val, slow->next->val);
        return dummy->next;
    }
};