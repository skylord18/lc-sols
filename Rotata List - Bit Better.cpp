#include<bits/stdc++.h>
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
    void rotate(vector<int>& nums, int k) {
        int  n  = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end();)

    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        vector<int> vv;
        ListNode *temp = head;
        while (temp) {
            vv.push_back(temp->val);
            temp = temp->next;
        }
        rotate(vv, k);
        temp = head;
        int i = 0;
        while (temp) {
            temp->val = vv[i];
            i++;
            temp = temp->next;
        }
        return head;

    }
};