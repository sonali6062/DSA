/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/
APPROACH1:
class Solution {
public:
    ListNode *sortList(ListNode *head) {
      ListNode* temp=head;
      int c0=0,c1=0,c2=0;
      while(temp!=NULL){
        if(temp->val==0)
        c0++;
        if(temp->val==1)
        c1++;
        if(temp->val==2)
        c2++;
        temp=temp->next;
      }
      temp=head;
      while(temp!=NULL){
        if(c0>0){
          temp->val=0;
          c0--;
        }
        else if(c1>0){
          temp->val=1;
          c1--;
        }
        else if(c2>0){
          temp->val=2;
          c2--;
        }
        temp=temp->next;
      }
     return head;


    }
};
Time complexity=O(2n)
Space complexity=O(1)

APPROACH2:
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode* zeroHead = new ListNode(-1);
        ListNode* oneHead = new ListNode(-1);
        ListNode* twoHead = new ListNode(-1);

        ListNode *zero = zeroHead;
        ListNode* one = oneHead;
        ListNode* two = twoHead;
        ListNode* temp = head;

        while (temp != nullptr) {
            ListNode* nextNode = temp->next; // Store the next node
            if (temp->val == 0) {
                zero->next = temp;
                zero = temp;
                zero->next = nullptr; // Terminate the sublist
            } else if (temp->val == 1) {
                one->next = temp;
                one = temp;
                one->next = nullptr; // Terminate the sublist
            } else {
                two->next = temp;
                two = temp;
                two->next = nullptr; // Terminate the sublist
            }
            temp = nextNode; // Move to the next node
        }

        zero->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;

        ListNode* newHead = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};
Time complexity=O(n)
Space Complexity=O(1)
