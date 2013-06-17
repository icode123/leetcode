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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *newNode;
        if(l1->val<l2->val)
        {
            newNode=l1;
            newNode->next=mergeTwoLists(l1->next,l2);
        }
        else
        {
            newNode=l2;
            newNode->next=mergeTwoLists(l1,l2->next);
        }
        return newNode;
    }
};
