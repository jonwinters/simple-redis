//
// Created by winters on 2020/12/16.
//

#ifndef SIMPLE_REDIS_LINKED_LIST_H
#define SIMPLE_REDIS_LINKED_LIST_H

#endif //SIMPLE_REDIS_LINKED_LIST_H

#include <stdbool.h>

//double ended queue

typedef struct node {
    struct node *prv;
    struct node *next;
    void *val;
} node;

typedef struct linked_list {
    //private
    node *head;
    node *tail;

    void *(*add_first)(void *val);
    void *(*add_last)(void *val);
} linked_list;

typedef struct linked_list_iterator {
    //private
    linked_list *linked_list;
} linked_list_iterator;


//public

void *add_first(void *val);

void *add_last(void *val);

linked_list *init_linked_list();

bool has_next();