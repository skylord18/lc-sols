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
    bool isPalindrome(vector<int> list) {
        int n = list.size();
        bool isPalindromeList = true;
        for (int i = 0; i < n / 2; ++i)
        {
            /* code */
            if (list[i] != list[n - i - 1]) {
                isPalindromeList = false;
                break;
            }
        }
        return isPalindromeList;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        ListNode *header = head;
        while (header != NULL) {
            list.push_back(header->val);
            header = header->next;
        }
        if (isPalindromeList)
            return true;
        else
            return false;

    }
};