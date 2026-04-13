#include <stdio.h>

int main() {
    int a, b, c;
    printf("Nhap 3 canh cua tam giac: ");

    // Kiem tra dau vao co hop le khong
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Vui long nhap so nguyen hop le!");
        return 1;
    }

    // 1. Kiem tra dieu kien ton tai tam giac
    if (a + b > c && a + c > b && b + c > a) {

        // 2. Kiem tra tam giac deu
        if (a == b && b == c) {
            printf("Tam giac deu\n");
        }
        // 3. Kiem tra tam giac vuong (Dinh ly Pythagoras)
        else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a)) {
            // Co the ket hop kiem tra vuong can o day neu muon
            printf("Tam giac vuong\n");
        }
        // 4. Kiem tra tam giac can
        else if (a == b || a == c || b == c) {
            printf("Tam giac can\n");
        }
        // 5. Truong hop con lai
        else {
            printf("Tam giac thuong\n");
        }

    } else {
        printf("Day khong phai la 3 canh cua mot tam giac!\n");
    }

    return 0;
}
