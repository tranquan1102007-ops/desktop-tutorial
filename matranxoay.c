#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// 1. Hàm nhập n
void nhapN(int *n) {
    printf("Nhap cap cua ma tran n (n > 0): ");
    scanf("%d", n);
    while (*n <= 0) {
        printf("n phai duong. Nhap lai: ");
        scanf("%d", n);
    }
}

// 2. Hàm tính các phần tử của ma trận xoáy
void tinhMaTranXoay(int a[MAX][MAX], int n) {
    int giaTri = 1;
    int hangDau = 0, hangCuoi = n - 1;
    int cotDau = 0, cotCuoi = n - 1;

    while (giaTri <= n * n) {
        // Di tu trai sang phai (hang dau)
        for (int i = cotDau; i <= cotCuoi; i++) {
            a[hangDau][i] = giaTri++;
        }
        hangDau++;

        // Di tu tren xuong duoi (cot cuoi)
        for (int i = hangDau; i <= hangCuoi; i++) {
            a[i][cotCuoi] = giaTri++;
        }
        cotCuoi--;

        // Di tu phai sang trai (hang cuoi)
        if (hangDau <= hangCuoi) {
            for (int i = cotCuoi; i >= cotDau; i--) {
                a[hangCuoi][i] = giaTri++;
            }
            hangCuoi--;
        }

        // Di tu duoi len tren (cot dau)
        if (cotDau <= cotCuoi) {
            for (int i = hangCuoi; i >= hangDau; i--) {
                a[i][cotDau] = giaTri++;
            }
            cotDau++;
        }
    }
    printf("\nDa tinh toan xong ma tran xoay.\n");
}

// 3. Hàm hiển thị ma trận
void hienThiMaTran(int a[MAX][MAX], int n) {
    printf("\nMa tran xoay %dx%d la:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    int a[MAX][MAX];
    int n = 0;
    int luaChon;
    int daTinh = 0;

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap n\n");
        printf("2. Tinh ma tran xoay\n");
        printf("3. Hien thi ma tran xoay\n");
        printf("4. Ket thuc\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapN(&n);
                daTinh = 0; // Reset trang thai khi n thay doi
                break;
            case 2:
                if (n == 0) {
                    printf("Vui long nhap n o muc 1 truoc!\n");
                } else {
                    tinhMaTranXoay(a, n);
                    daTinh = 1;
                }
                break;
            case 3:
                if (daTinh == 0) {
                    printf("Vui long tinh ma tran o muc 2 truoc!\n");
                } else {
                    hienThiMaTran(a, n);
                }
                break;
            case 4:
                printf("Tam biet!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}