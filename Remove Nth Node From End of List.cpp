/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL || n<=0) return NULL;
        ListNode *pre=NULL;
        ListNode *cur=head;
        ListNode *first=head;
        while(--n>0)
        {
            first=first->next;
            if(first==NULL) return NULL;//链表节点总个数可能少于N；
        }
        while(first->next)
        {
            pre=cur;
            cur=cur->next;
            first=first->next;
        }
        if(cur==head)
        {
           head=head->next; 
        }
        else
        {
           pre->next=cur->next; 
        }
        delete cur;
        return head;
    }
};


