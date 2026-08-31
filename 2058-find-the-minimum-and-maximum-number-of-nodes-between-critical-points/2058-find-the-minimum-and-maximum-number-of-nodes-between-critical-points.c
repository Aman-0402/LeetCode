/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int* nodesBetweenCriticalPoints(
    struct ListNode* head,
    int* returnSize
) {
    int* ans = (int*)malloc(2 * sizeof(int));

    *returnSize = 2;

    ans[0] = -1;
    ans[1] = -1;

    int first = -1;
    int last = -1;
    int prevCritical = -1;

    int minDist = 1000000000;

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;

    int index = 1;

    while (curr->next != NULL) {

        int critical =
            (curr->val > prev->val &&
             curr->val > curr->next->val) ||

            (curr->val < prev->val &&
             curr->val < curr->next->val);

        if (critical) {

            if (first == -1) {
                first = index;
            }

            if (prevCritical != -1) {
                int distance = index - prevCritical;

                if (distance < minDist) {
                    minDist = distance;
                }
            }

            prevCritical = index;
            last = index;
        }

        prev = curr;
        curr = curr->next;
        index++;
    }

    // Less than two critical points
    if (first == last) {
        return ans;
    }

    ans[0] = minDist;
    ans[1] = last - first;

    return ans;
}