APPROACH 1:
class Solution {
public:
    ListNode *addOne(ListNode *head) {
        if (head == nullptr)
            return new ListNode(1); // If the list is empty, return 1

        vector<int> t;
        ListNode* temp = head;
        while (temp != nullptr) {
            t.push_back(temp->val);
            temp = temp->next;
        }

        int n = t.size();
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            int sum = t[i] + carry;
            t[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry)
            t.insert(t.begin(), carry); // Insert carry if needed

        // Create new linked list from the updated vector
        ListNode* newHead = new ListNode(t[0]);
        temp = newHead;
        for (int i = 1; i < t.size(); i++) {
            temp->next = new ListNode(t[i]);
            temp = temp->next;
        }

        return newHead;
    }
};
Time complexity=O(N)
Space complexity=O(N)


APPROACH2:
class Solution {
public:
    // Reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* addOne(ListNode* head) {
        if (!head) return new ListNode(1);  // Empty list edge case

        // Step 1: Reverse the linked list
        head = reverseList(head);

        // Step 2: Add 1 and handle carry
        ListNode* curr = head;
        int carry = 1;

        while (curr) {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            // If no carry left, break early
            if (carry == 0) break;

            // If we're at the end and still have carry, create new node
            if (!curr->next && carry) {
                curr->next = new ListNode(0);  // Create placeholder node
            }

            curr = curr->next;
        }

        // Step 3: Reverse back to original order
        return reverseList(head);
    }
};
Time Complexity=O(N)
Space complexity=O(1)
