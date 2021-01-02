//
// Created by winters on 2020/12/16.
//

#include "linked_list.h"
#include <stdlib.h>
#include <memory.h>

void *add_first(linked_list *self, void *val) {
    if (self->tail == NULL && self->head == NULL) {
        return push(self, val);
    }
    node *n = (node *) malloc(sizeof(node));
    n->val = val;

    self->head->prv = n;
    n->next = self->head;
    self->head = n;
    return val;
}

void *add_last(linked_list *self, void *val) {
    return push(self, val);
}

/**
 * remove from first
 * @param self
 * @return
 */
void *remove_first(linked_list *self) {
    node * head = self->head;
    if (self->head == NULL){
        return NULL;
    }

    if (self->tail == self->head) {
        self->head = NULL;
        self->tail = NULL;
        void *val = head->val;
        free(head);
        return val;
    }

    self->head = head->next;
    void *val = head->val;
    free(head);
    return val;
}

/**
 * see pop
 * @param self
 * @return
 */
void *remove_last(linked_list *self) {
    return pop(self);
}

/**
 *
 * @param self
 * @return val
 */
void *pop(linked_list *self) {
    node *tail = self->tail;
    if (tail == NULL) {
        return NULL;
    }

    if (self->tail == self->head) {
        self->head = NULL;
        self->tail = NULL;
        void *val = tail->val;
        free(tail);
        return val;
    }

    self->tail = tail->prv;
    self->tail->next = NULL;
    void *val = tail->val;
    free(tail);
    return val;
}

/**
 *
 * @param self
 * @param val
 * @return val
 */
void *push(linked_list *self, void *val) {
    node *n = (node *) malloc(sizeof(node));
    n->val = val;

    if (self->head == NULL && self->tail == NULL) {
        self->head = n;
        self->tail = n;
        return val;
    }

    self->tail->next = n;
    n->prv = self->tail;
    self->tail = n;
    return val;
}

linked_list *init_linked_list() {
    linked_list * ptr =  (linked_list *) malloc(sizeof(linked_list) * 1);
    memset(ptr,0,sizeof(struct linked_list));
    return ptr;
}

// public iterator
linked_list_iterator *iterator(){
    //TODO
    return NULL;
}

bool has_next(linked_list_iterator *self){
    //TODO
    return NULL;
}