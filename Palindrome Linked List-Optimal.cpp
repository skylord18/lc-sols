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
    ListNode * reverseList(ListNode * head) {
        ListNode *prev = NULL, *curr = head, *nxt = head->next;
        while (curr != NULL) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (nxt != NULL)
                nxt = nxt->next;

        }
        return prev;

    }
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL)
            return true;

        ListNode *slow = head, * fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);

        ListNode *strt = head, * mid = slow->next;
        while (mid != NULL) {
            if (strt->val != mid->val) {
                return false;
            }
            strt = strt->next;
            mid = mid->next;
        }
        return true;
    }
};