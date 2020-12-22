//
// Created by winters on 2020/12/15.
//

#include "sds.h"

/**
 * convert to pure c style str and free SDS src space
 * @param src
 * @return
 */
char *sds_to_pure_c_style_str(char *src) {
    size_t dst_size = (convert_to_struct_ptr(src)->len + 1) * sizeof(char);
    char *dst = malloc(dst_size);
    memcpy(dst, src, dst_size);
    free(convert_to_struct_ptr(src));
    return dst;
}

char *sds_init_with_str(char *str) {
    return sds_copy(str, sds_init(strlen(str)));
}

char *sds_init(int size) {
    char *sds_str = malloc(sizeof(SDS) + (size + 1) * sizeof(char));
    SDS *sds_str_ = sds_str;
    sds_str_->len = 0;
    sds_str_->reserve = size;
    char *str = sds_str + sizeof(int) * 2;
    str[size + 1] = '\0';
    return str;
}

SDS *convert_to_struct_ptr(char *str) {
    return (SDS *) (str - sizeof(int) * 2);
}

int sds_len(char *str) {
    return convert_to_struct_ptr(str)->len;
}

int sds_reserve(char *str) {
    return convert_to_struct_ptr(str)->reserve;
}

/**
 * @param src  c-style str
 * @param target SDS str
 * if SDS-space is not enough to copy c-style str
 * return NULL
 * @return return copy
 */
char *sds_copy(char *src, char *target) {
    //we assume src is c style str
    int count = strlen(src);
    char *temp = src;
    if (sds_reserve(target) < count) {
        return NULL;
    }
    for (int i = 0; *temp != '\0'; temp++, i++) {
        target[i] = *temp;
    }
    convert_to_struct_ptr(target)->len = count;
    return target;
}

#ifdef GEN_SDS_DEMO

void main() {

    //in stack
    SDS s;
    s.len = 1;
    s.reserve = 2;

    //in heap
    SDS *s_in_heap = (SDS *) malloc(sizeof(SDS) + 10 * sizeof(char));
    s_in_heap->reserve = 0;
    s_in_heap->len = 10;
    strcpy(s_in_heap->str, "12456789\0");
    printf("s_in_heap->reserve: %d\n", s_in_heap->reserve);
    printf("s_in_heap->len: %d\n", s_in_heap->len);
    printf("s_in_heap->str: %s\n", s_in_heap->str);
}

#endif