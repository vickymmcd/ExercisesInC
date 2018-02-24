#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char *res = icmpcode_v4(1);
    char *message = "test1 failed: code 1 should return host unreachable";
    mu_assert(message, strcmp(res, "host unreachable") == 0);
    return NULL;
}

static char *test2() {
    char *res = icmpcode_v4(5);
    char *message = "test2 failed: code 5 should return source route failed";
    mu_assert(message, strcmp(res, "source route failed")==0);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }

    return result != 0;
}
