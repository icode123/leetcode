
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mark=0;
        ListNode rootnode(0);
        ListNode *pcurnode=&rootnode;
        while(l1 || l2)
        {
            int v1=(l1)?l1->val:0;
            int v2=(l2)?l2->val:0;
            int sum=v1+v2+mark;
            mark=sum/10;
            sum=sum%10;
            ListNode *node=new ListNode(sum);
            pcurnode->next=node;
            pcurnode=pcurnode->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(mark>0)
        {
            ListNode *node=new ListNode(mark);
            pcurnode->next=node;
            pcurnode=pcurnode->next;
        }
        return rootnode.next;
    }
};
