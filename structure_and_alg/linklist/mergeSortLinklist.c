/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *Merge(struct ListNode *head1, struct ListNode *head2)
{
    struct ListNode *L, *pre;
    L = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre = L;
    while (head1 != NULL && head2 != NULL) {
        if (head1->val < head2->val) {
            pre->next = head1;
            head1 = head1->next;
        } else {
            pre->next = head2;
            head2 = head2->next;
        }
        pre = pre->next;
    }
    while (head1 != NULL) {
        pre->next = head1;
        head1 = head1->next;
        pre = pre->next;
    }
    while (head2 != NULL) {
        pre->next = head2;
        head2 = head2->next;
        pre = pre->next;
    }
    pre = L->next;
    free(L);
    L = NULL;
    return pre;
}
// struct ListNode *FindMid(struct ListNode *head, struct ListNode *tail)
// {
//     if (head == NULL) {
//         return NULL;
//     }
//     if (head->next == tail) {
//         head->next = NULL;
//         return head;
//     }
//     struct ListNode *slow, *fast;
//     slow = fast = head;
//     while (fast != tail) {
//         slow = slow->next;
//         fast = fast->next;
//         if (fast != tail) {
//             fast = fast->next;
//         }
//     }
//     struct ListNode *mid = slow;
//     return Merge(FindMid(head, mid), FindMid(mid, tail));
// }
// struct ListNode* sortList(struct ListNode* head){
//     return ToSortList(head, NULL);
// }

struct ListNode* sortList(struct ListNode* head){
    int length = 0;
    struct ListNode *p, *pre, *cur, *head1, *head2, *L, *record;
    p = head;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = head;
    for (int len = 1; len < length; len = len * 2) {
        pre = L; cur = pre->next;
        while (cur != NULL) {
            head1 = cur;
            for (int i = 1; i < len && cur->next != NULL; i++) {
                cur = cur->next;
            }
            head2 = cur->next;
            cur->next = NULL;
            cur = head2;
            for (int i = 1; i < len && cur != NULL && cur->next != NULL; i++) {
                cur = cur->next;
            }
            if (cur == NULL) {
                record = NULL;
            } else {
                record = cur->next;
                cur->next = NULL;
            }
            struct ListNode *pSort = Merge(head1, head2);
            pre->next = pSort;
            while (pre->next != NULL) {
                pre = pre->next;
            }
            cur = record;
        }
    }
    return L->next;
}