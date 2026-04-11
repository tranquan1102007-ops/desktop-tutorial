#include <stdio.h>

int main() {
    int n;
    long long tong = 0;
    long long giaithua_hientai = 1;

    printf("Nhap n: ");
    if (scanf("%d", &n) != 1) {
        printf("Du lieu nhap vao khong hop le!");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        // Tinh i! dua tren (i-1)! da co san
        giaithua_hientai *= i;

        // Cong don vao tong
        tong += giaithua_hientai;
    }

    printf("Tong giai thua tu 1! den %d! la: %lld\n", n, tong);

    return 0;
}
