//
// Created by winters on 2020/12/16.
//

#ifndef SIMPLE_REDIS_LINKED_LIST_H
#define SIMPLE_REDIS_LINKED_LIST_H

#endif //SIMPLE_REDIS_LINKED_LIST_H

#include <stdbool.h>

//double ended queue

typedef struct node {
    struct node *next;
    struct node *prv;
    void *val;
} node;

typedef struct linked_list {
    //private
    node *head;
    node *tail;
} linked_list;

typedef struct linked_list_iterator {
    //private
    linked_list *linked_list;
    node * current;

} linked_list_iterator;


//public

void *add_first(linked_list * self,void *val);

void *add_last(linked_list * self,void *val);

void *remove_first(linked_list * self);

void *remove_last(linked_list * self);

void * pop(linked_list * self);

void * push(linked_list * self,void * val);

linked_list *init_linked_list();

// public iterator

linked_list_iterator * iterator();

bool has_next(linked_list_iterator * self);