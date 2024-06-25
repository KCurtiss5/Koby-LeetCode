/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long sum = getSum(l1) + getSum(l2);
        return buildLL(sum);
    }

    ListNode* buildLL(long long sum){
        ListNode* ret = new ListNode(sum%10);
        ListNode* cur = ret;
        sum /= 10;
        while (sum > 0) {
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            sum = sum / 10;
        }
        cout << ret->val;
        return ret;
    }

    long long getSum(ListNode* l) {
        long long sum = 0;
        long long multiplier = 1;
        while (l){
            sum += l->val * multiplier;
            multiplier *= 10;
            l = l->next;
        }
        return sum;
    }
};

/*
This is my first attempt. Where essentially, I read both linked lists, then add up the solution, then turn the sum into a linked
list of its own. However, this fails test cases (even with a long long sum). This makes sense as a use case for using a linked
list in this way is storing an incredibly long number. So I have to re-design the algorithm, likely to stream read the numbers
and carry the ten.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = (l1 != nullptr ? l1->val : 0) +
                      (l2 != nullptr ? l2->val : 0) +
                      carry;

            carry = sum / 10;
            sum %= 10;

            cur->next = new ListNode(sum);
            cur = cur->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        return head->next;
    }
};

/*
Implements algorithm from above where we read digits in a stream-like fashion and creates a linkedlist as it goes.
Runtime - 19ms Beats 71.25%
Memory - 75.98 MB Beats 86.71%
*/