#include <stdio.h>

#define MAX 50

// 1. Hàm nhập 1 ma trận
void nhapMaTran(float mat[MAX][MAX], int rows, int cols, char name) {
    printf("Nhap cac phan tu cho ma tran %c (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d] = ", name, i, j);
            scanf("%f", &mat[i][j]);
        }
    }
}

// 2. Hàm tính tích 2 ma trận C = A * B
void tinhTich(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n, int p, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Da tinh xong ma tran tich C.\n");
}

// 3. Hàm hiển thị 1 ma trận
void hienThiMaTran(float mat[MAX][MAX], int rows, int cols, const char* label) {
    printf("\n%s:\n", label);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Hàm main điều khiển menu
int main() {
    float A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, p, m;
    int choice;
    int inputDone = 0, calcDone = 0;

    do {
        printf("\n--- MENU QUAN LY MA TRAN ---\n");
        printf("1. Nhap 2 ma tran A(nxp) va B(pxm)\n");
        printf("2. Tinh tich 2 ma tran (C = A x B)\n");
        printf("3. Hien thi ca 3 ma tran\n");
        printf("4. Ket thuc\n");
        printf("Chon chuc nang (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap kich thuoc n, p, m: ");
                scanf("%d %d %d", &n, &p, &m);
                nhapMaTran(A, n, p, 'A');
                nhapMaTran(B, p, m, 'B');
                inputDone = 1;
                calcDone = 0; // Reset trạng thái tính toán khi có dữ liệu mới
                break;
            case 2:
                if (inputDone) {
                    tinhTich(A, B, C, n, p, m);
                    calcDone = 1;
                } else {
                    printf("Loi: Ban chua nhap ma tran!\n");
                }
                break;
            case 3:
                if (inputDone) {
                    hienThiMaTran(A, n, p, "Ma tran A");
                    hienThiMaTran(B, p, m, "Ma tran B");
                    if (calcDone) {
                        hienThiMaTran(C, n, m, "Ma tran tich C");
                    } else {
                        printf("\n(Ma tran C chua duoc tinh)\n");
                    }
                } else {
                    printf("Loi: Khong co du lieu de hien thi!\n");
                }
                break;
            case 4:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 4);

    return 0;
}