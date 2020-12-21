//
// Created by winters on 2020/12/15.
//

#ifndef SIMPLE_REDIS_SDS_H
#define SIMPLE_REDIS_SDS_H
#endif //SIMPLE_REDIS_SDS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sds {
    int reserve;// reserve heap space
    int len; // length of str
    char str[];
}sds;

char *sds_init(int size);

char *sds_init_with_str(char *str);

sds *convert_to_struct_ptr(char *str);

int sds_len(char *str);

int sds_reserve(char *str);

char *sds_copy(char *src, char *target);

char *sds_to_pure_c_style_str(char *src);

