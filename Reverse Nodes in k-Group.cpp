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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k<2) return head;
        ListNode **pStart=&head;
        while(*pStart)
        {
            ListNode *pEnd=*pStart;
            for(int i=1;pEnd && i<k;i++) pEnd=pEnd->next;
            if(pEnd)
            {
                ListNode *pSubTail=*pStart;
                for(int i=1;i<k;i++)
                {
                    ListNode *pNext=pSubTail->next;
                    pSubTail->next=pNext->next;
                    pNext->next=*pStart;
                    *pStart=pNext;
                }
                pStart=&(pSubTail->next);
            }
            else break;
        }
        return head;
    }
};



