#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };


class Solution {
public:
    void copyList(Node* head) {
        Node * temp = head, *n = head->next;
        while (temp) {
            Node *copy = new Node(temp->val);
            temp->next = copy;
            copy->next = n;
            temp = n;
            if (n)
                n = n->next;
        }
    }
public:
    void handleRandom(Node *head) {
        Node *temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
public:
    Node *detach(Node *head) {
        Node *dummy = new Node(-1);
        Node *tail = dummy, *temp = head;
        while (temp) {
            tail ->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        return dummy->next;
    }
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL )
            return head;
        copyList(head);
        handleRandom(head);
        Node *ans = detach(head);
        return ans;
    }
};