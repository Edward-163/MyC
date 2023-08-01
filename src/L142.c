#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/*

 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    struct ListNode* same;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            same=fast;
            for (int i = 0; i < INT_MAX; ++i){
                if(same==head){
                    return head;
                }
                same=same->next;
                head=head->next;
            }

        }
    }
    return NULL;
}
int main() {
    // @formatter:off
    struct ListNode* one=malloc(sizeof(struct ListNode));
    struct ListNode* two=malloc(sizeof(struct ListNode));
    struct ListNode* thr=malloc(sizeof(struct ListNode));
    struct ListNode* fou=malloc(sizeof(struct ListNode));
    one->val=1;
    two->val=2;
    thr->val=2;
    fou->val=2;
    one->next=two;
    two->next=one;
    two->next=fou;
    fou->next=two;
    struct ListNode* ans=detectCycle(one);

    return 0;
    // @formatter:on
}