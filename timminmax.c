#include <stdio.h>

int main(){
    int n;
    int a[100];
    int max, min, posMax, posMin;
    printf("hay nhap n: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++){
            printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    max = a[0];
    min = a[0];

    for (int i = 1; i < n; i++) {
    if (a[i] > max) { // Nếu tìm thấy số lớn hơn max hiện tại
        max = a[i];   // Cập nhật giá trị max mới

    }

}
for (int i = 1; i < n; i++) {
    if (a[i] < min) {
        min = a[i];

    }

}
printf("max la: %d \n", max);
printf("min la: %d", min);
return 0;
}
