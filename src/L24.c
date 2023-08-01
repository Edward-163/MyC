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
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* dummy=malloc(sizeof(struct ListNode));
    dummy->val=-1;
    dummy->next=head;
    struct ListNode* slow=dummy;
    struct ListNode* fast=dummy;
    while (true) {
        // step 步进
        if(slow!=NULL && slow->next!=NULL){
            slow=slow->next;
        } else{
            break;
        }
        if(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
        } else{
            break;
        }
        // swap
        int tmp=slow->val;
        slow->val=fast->val;
        fast->val=tmp;
        // 重置slow,让slow和fast重合
        slow=fast;
    }
    return head;
}
int main() {
    // @formatter:off

    return 0;
    // @formatter:on
}