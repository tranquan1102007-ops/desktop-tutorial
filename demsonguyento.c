#include <stdio.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0; // Số nhỏ hơn 2 không phải SNT
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0; // Nếu chia hết cho số nào đó thì không phải SNT
    }
    return 1; // Là số nguyên tố
}

int main() {
    int n;
    int count = 0;
    int a[100];

    printf("Nhap n: ");
    scanf("%d", &n);

    // Nhập mảng
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // Đếm số nguyên tố
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            count++;
        }
    }

    printf("Co %d so nguyen to trong mang.\n", count);

    return 0;
}
