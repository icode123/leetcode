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
    ListNode *reverse(ListNode *head,int k)
    {
        ListNode *pre=NULL;
        ListNode *cur=head;
        ListNode *next;
        int count=0;
        while(cur!=NULL&&count<k)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
            count++;
        }
        if(next!=NULL) head->next=reverse(next,k);
        return pre;
    }
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
        return reverse(head,2);
    }
};

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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode **ppre=&head;//二级指针
        while(true)
        {
            ListNode *n0=*ppre;
            if(n0==NULL) return head;
            ListNode *n1=n0->next;
            if(n1==NULL) return head;
            *ppre=n1;
            n0->next=n1->next;
            n1->next=n0;
            ppre=&(n0->next);
        }
        return head;
    }
};

