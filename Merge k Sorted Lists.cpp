class Solution {
public:
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(auto list: lists) {
            if(list)
            q.push(list);
        }
        if(q.empty())  
            return NULL;
        ListNode* head = q.top();
        q.pop();
        if(head->next) q.push(head->next);
        ListNode* temp = head;
        while(!q.empty()) {
            temp->next = q.top();
            q.pop();
            temp = temp->next;            
            if(temp->next)
            q.push(temp->next);
        }
        return head;
    }
};