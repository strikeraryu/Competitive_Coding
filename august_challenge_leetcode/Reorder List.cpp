// Problem

// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, only nodes itself may be changed.




// Example

// Given 1->2->3->4, reorder it to 1->4->2->3.

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.




//-----------------------------------------------------------------------------------------------------
// Solution

#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    void printlist(ListNode* head) 
{ 
    while (head != NULL) { 
        cout << head->val << " "; 
        if (head->next) 
            cout << "-> "; 
        head = head->next; 
    } 
    cout << endl; 
} 
public:
    void reorderList(ListNode* head) {
        if(!head)return ;
        ListNode* t=head,*r=head->next;
        while(r && r->next){
            t = t->next;
            r = r->next->next;
        }
        ListNode* tort = t->next;
        t->next = NULL;
        ListNode* rev = NULL;
        while(tort){
            ListNode *tmp = tort->next;
            tort->next = rev;
            rev = tort;
            tort = tmp;
        }
        ListNode* curr = new ListNode(1);
        ListNode* head1 = head;
        while(head1 || rev){
            if(head1){
                curr->next = head1;
                head1 = head1->next;
                curr = curr->next;
            }
            if(rev){
                curr->next = rev;
                rev = rev->next;
                curr = curr->next;
            }
        }
    }
};