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
    ListNode *merge(ListNode *head1,ListNode *head2)
    {
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        ListNode *mergehead=NULL;
        if(head1->val<head2->val)
        {
            mergehead=head1;
            mergehead->next=merge(head1->next,head2);
        }
        else
        {
            mergehead=head2;
            mergehead->next=merge(head1,head2->next);
        }
        return mergehead;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(lists.size()==0) return NULL;
        int listSize=lists.size();
        while(listSize>1)
        {
            int halfSize=(1+listSize)/2;
            for(int i=0;i<halfSize && i+halfSize<listSize;i++)
            {
                lists[i]=merge(lists[i],lists[i+halfSize]);
            }
            listSize=halfSize;
        }
        return lists[0];
    }
};
