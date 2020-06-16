//
//  main.c
//  quiz0
//
//  Created by Tai Wei Tseng on 2020/06/02.
//  Copyright © 2020 man27382210. All rights reserved.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int LENGTH = 10;

typedef struct __list {
    int data;
    struct __list *next;
} list;

list *sort(list *start) {
    if (!start || !start->next)
        return start;
    list *left = start;
    list *right = left->next;
    left->next = NULL;    // LL0
    
    left = sort(left);
    right = sort(right);
    
    for(list *merge = NULL; left || right;) {
        if (!right || (left && left->data < right->data)) {
            if (!merge) {
                start = merge = left;    // LL1
            } else {
                merge->next = left;    // LL2
                merge = merge->next;
            }
            left = left->next;    // LL3
        } else {
            if (!merge) {
                start = merge = right;    // LL4
            } else {
                merge->next = right;    // LL5
                merge = merge->next;
            }
            right = right->next;    // LL6
        }
    }
    return start;
}

list *q_new(int d)
{
    list *tmp = malloc(sizeof(list));
    if (!tmp) {
        printf("Malloc fail");
        return NULL;
    }
    tmp->data = d;
    tmp->next = NULL;
    return tmp;
}

void q_free(list *head)
{
    while (head != NULL) {
        list *tmp = head;
        head = head->next;
        free(tmp);
    }
}

list *q_insert_lot(list *tail, int *data, int length)
{
    int i;
    list *tmp;
    tmp = tail = q_new(data[0]);
    if (!tail) {
        printf("Insert first node failed\n");
        return NULL;
    }

    for (i = 1; i < length; i++) {
        tail->next = q_new(data[i]);
        if (!tail->next) {
            printf("Insert %d-th node failed\n", i);
            q_free(tmp);
            return NULL;
        }
        tail = tail->next;
    }

    return tmp;
}

int *random_array(int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (tmp == NULL) {
        printf("Malloc int array fail!\n");
        return NULL;
    }
    int i;
    for (i = 0; i < size; i++)
        tmp[i] = rand() % 100;

    return tmp;
}

void printHeap(list *heap) {
    printf("%i \n", heap -> data);
    if (heap -> next != NULL) {
        printHeap(heap -> next);
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int *numbers = random_array(LENGTH);
    list *q_tail = NULL;
    list *q_head = q_insert_lot(q_tail, numbers, LENGTH);
    sort(q_head);
    printHeap(q_head);
    return 0;
}
