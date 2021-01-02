//
// Created by winters on 2020/12/16.
//

#ifndef SIMPLE_REDIS_LINKED_LIST_H
#define SIMPLE_REDIS_LINKED_LIST_H

#endif //SIMPLE_REDIS_LINKED_LIST_H

#include <stdbool.h>

//double ended queue

typedef struct node {
    struct NODE *next;
    struct NODE *prv;
    void *val;
} NODE;

typedef struct linked_list {
    //private
    NODE *head;
    NODE *tail;
} LINKED_LIST;

typedef struct linked_list_iterator {
    //private
    LINKED_LIST *linked_list;
    NODE * current;

} LINKED_LIST_ITERATOR;


//public

void *add_first(LINKED_LIST * self, void *val);

void *add_last(LINKED_LIST * self, void *val);

void *remove_first(LINKED_LIST * self);

void *remove_last(LINKED_LIST * self);

void * pop(LINKED_LIST * self);

void * push(LINKED_LIST * self, void * val);

LINKED_LIST *init_linked_list();

// public iterator

LINKED_LIST_ITERATOR * iterator(LINKED_LIST * self);

bool has_next(LINKED_LIST_ITERATOR * self);