#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *mergeTwoLists2(struct ListNode *list1, struct ListNode *list2) {
    if (list1 == NULL && list2 == NULL)return NULL;
    /// bug:栈分配
//    struct ListNode* dummy = {0, NULL};
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode) * 102);
    struct ListNode *dmove = dummy;
    // 只要2个list还有节点在就一直循环
    while (list1 != NULL || list2 != NULL) {
        if (list1 == NULL) {
            dmove->next = list2;
//            dmove++;//指针可不可这么写??
            dmove = dmove->next;
        }
        if (list2 == NULL) {
            dmove->next = list1;
            dmove = dmove->next;
        }

        /// bug:sig fault
        if (list1->val < list2->val) {
            struct ListNode *tmp = list1->next;
            list1->next = NULL;//断链
            dmove->next = list1;
            dmove = dmove->next;
            list1 = tmp;
        } else {
            struct ListNode *tmp = list2->next;
            list2->next = NULL;//断链
            dmove->next = list2;
            dmove = dmove->next;
            list2 = tmp;
        }
    }

    return dummy->next;
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (!l1)return l2;
    if (!l2)return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main() {
    /// bug:多写了个*
    //struct ListNode * list1={1,{3,NULL}};
    /// bug:sig,经测试,这么组装就是不行
//    struct ListNode list1 = {1, NULL};
//    struct ListNode list2 = {2, {4, NULL}};

    struct ListNode l3={3,NULL};
    struct ListNode list1 = {1, &l3};
    struct ListNode l4={4,NULL};
    struct ListNode list2 = {2, &l4};
    struct ListNode *res=mergeTwoLists(&list1, &list2);
    return 0;
}

