#include <stdio.h>
#include "src/sds.h"

int main() {
    //TODO use epoll or libev to implement io read/write
    char *sds = sds_init_with_str("test");
    printf("sds: %s\n", sds);
    printf("len: %d\n", sds_len(sds));
    return 0;
}
