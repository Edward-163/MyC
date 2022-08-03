#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
你的实现应该支持如下操作：
MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 */

typedef struct {
    int *arr;
    int headidx;
    int tailidx;
    int k;
    int realk;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *obj = malloc(sizeof(MyCircularQueue));
    if (k < 0) {
        return NULL;
    }
    int *arr = malloc(sizeof(int) * k);
    obj->arr = arr;

    obj->k = k;
    obj->realk = 0; // empty
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (obj->realk == 0) {
        obj->arr[0] = value;
        obj->realk++;
        obj->headidx = 0; // 0 first
        obj->tailidx = 0; // k-1 last
        return true;
    }
    if (obj->realk < obj->k) {
        obj->tailidx++;
        if (obj->tailidx > obj->k - 1) {
            obj->tailidx = 0;
        }
        obj->arr[obj->tailidx] = value;
        obj->realk++;
        return true;
    } else {
        return false;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (obj->realk >= 1) {
        obj->headidx++;
        if (obj->headidx > obj->k - 1) {
            obj->headidx = 0;
        }
        obj->realk--;
        return true;
    } else {
        return false;
    }
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (obj->realk == 0) {
        return -1;
    }
    return obj->arr[obj->headidx];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (obj->realk == 0) {
        return -1;
    }
    return obj->arr[obj->tailidx];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    return obj->realk == 0; // 0 empty
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    return obj->realk == obj->k;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->arr);
    free(obj);
}

int main()
{
    // @formatter:off
    MyCircularQueue *obj = myCircularQueueCreate(3); // 设置长度为 3 1730
    printf("%d \n",myCircularQueueEnQueue(obj,1));fflush(stdout);  // 返回 true
    printf("%d \n",myCircularQueueEnQueue(obj,2));fflush(stdout);  // 返回 true
    printf("%d \n",myCircularQueueEnQueue(obj,3));fflush(stdout);  // 返回 true
    printf("%d \n",myCircularQueueEnQueue(obj,4));fflush(stdout);  // 返回 false，队列已满
    printf("%d \n",myCircularQueueRear(obj));fflush(stdout);  // 返回 3
    printf("%d \n",myCircularQueueIsFull(obj));fflush(stdout);  // 返回 true
    printf("%d \n",myCircularQueueDeQueue(obj));fflush(stdout);  // 返回 true
    printf("%d \n",myCircularQueueEnQueue(obj,4));fflush(stdout);  // 返回 true
    printf("%d \n",myCircularQueueRear(obj));fflush(stdout);  // 返回 4
    return 0;
    // @formatter:on
}