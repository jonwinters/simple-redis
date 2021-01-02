//
// Created by winters on 2020/12/16.
//

#include "linked_list.h"
#include <stdlib.h>
#include <memory.h>

void *add_first(LINKED_LIST *self, void *val) {
    if (self->tail == NULL && self->head == NULL) {
        return push(self, val);
    }
    NODE *n = (NODE *) malloc(sizeof(NODE));
    n->val = val;

    self->head->prv = n;
    n->next = self->head;
    self->head = n;
    return val;
}

void *add_last(LINKED_LIST *self, void *val) {
    return push(self, val);
}

/**
 * remove from first
 * @param self
 * @return
 */
void *remove_first(LINKED_LIST *self) {
    NODE *head = self->head;
    if (self->head == NULL) {
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
void *remove_last(LINKED_LIST *self) {
    return pop(self);
}

/**
 *
 * @param self
 * @return val
 */
void *pop(LINKED_LIST *self) {
    NODE *tail = self->tail;
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
void *push(LINKED_LIST *self, void *val) {
    NODE *n = (NODE *) malloc(sizeof(NODE));
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

LINKED_LIST *init_linked_list() {
    LINKED_LIST *ptr = (LINKED_LIST *) malloc(sizeof(LINKED_LIST) * 1);
    memset(ptr, 0, sizeof(LINKED_LIST));
    return ptr;
}

// public iterator
LINKED_LIST_ITERATOR *iterator(LINKED_LIST *self) {
    //TODO
    return NULL;
}

bool has_next(LINKED_LIST_ITERATOR *self) {
    //TODO
    return NULL;
}