// Problem

// Remove all elements from a linked list of integers that have value val.


// Example

// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5



//-----------------------------------------------------------------------------------------------------
// Solution
#include <bits/stdc++.h>
using namespace std;



D//efinition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* itr = head;
        head = NULL;
        ListNode* tmp = NULL;
        while(itr!=NULL){
            cout<<itr->val<<" ";
            if(itr->val!=val){
                cout<<".";
                if(head==NULL)head = itr;
                else tmp->next = itr;
                tmp = itr;
            }
            itr = itr->next;
        }
        if(tmp!=NULL)
        tmp->next = NULL;
        return head;
    }
};