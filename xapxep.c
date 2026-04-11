#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *x, const void *y) {
    int a = *(const int *)x;
    int b = *(const int *)y;
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int main(void) {
    int n, i;
    printf("nhap n phan tu:  ");
    int a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    qsort(a, (size_t)n, sizeof a[0], cmp_int);
    printf("\nday so sau sap xep: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
