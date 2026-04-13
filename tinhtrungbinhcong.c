#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    float a[n];
    float sum_pos = 0, sum_neg = 0;
    int count_pos = 0, count_neg = 0;

    // Nhap mang
    for(int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }

    // Xu ly du lieu
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            sum_pos += a[i];
            count_pos++;
        } else if(a[i] < 0) {
            sum_neg += a[i];
            count_neg++;
        }
    }

    // In ket qua
    if(count_pos > 0)
        printf("TBC so duong = %.2f\n", sum_pos / count_pos);
    else
        printf("Day khong co so duong.\n");

    if(count_neg > 0)
        printf("TBC so am = %.2f\n", sum_neg / count_neg);
    else
        printf("Day khong co so am.\n");

    return 0;
}
