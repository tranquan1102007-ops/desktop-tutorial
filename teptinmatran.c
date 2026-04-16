#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Hàm hiển thị ma trận ra màn hình (để kiểm tra)
void hienThiMaTran(int matrix[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// 1 & 2. Hàm đọc tệp MA_TRAN.C
int docTep(char *filename, int *n, int *m, int A[MAX][MAX], int B[MAX][MAX]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Loi: Khong mo duoc tep %s\n", filename);
        return 0;
    }

    // Đọc n và m
    fscanf(f, "%d %d", n, m);

    // Đọc ma trận A
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(f, "%d", &A[i][j]);
        }
    }

    // Đọc ma trận B
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(f, "%d", &B[i][j]);
        }
    }

    fclose(f);
    printf("Da doc du lieu tu tep thanh cong.\n");
    return 1;
}

// 3. Hàm tính và ghi ma trận C vào cuối tệp
void ghiMaTranC(char *filename, int n, int m, int A[MAX][MAX], int B[MAX][MAX]) {
    int C[MAX][MAX];
    
    // Tính ma trận C = A + B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Ghi vào cuối tệp (chế độ "a" - append)
    FILE *f = fopen(filename, "a");
    if (f == NULL) {
        printf("Loi: Khong the ghi vao tep.\n");
        return;
    }

    fprintf(f, "\nMa tran tong C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(f, "%d ", C[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    printf("Da ghi ma tran tong C vao cuoi tep MA_TRAN.C\n");
}

int main() {
    int n, m;
    int A[MAX][MAX], B[MAX][MAX];
    int luaChon;
    char *fileName = "MA_TRAN.C";
    int daDoc = 0;

    while (1) {
        printf("\n---------- MENU ----------\n");
        printf("1. Doc tep MA_TRAN.C\n");
        printf("2. Ghi ma tran C bo sung vao cuoi tep\n");
        printf("3. Ket thuc\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                daDoc = docTep(fileName, &n, &m, A, B);
                if (daDoc) {
                    printf("Ma tran A (%dx%d):\n", n, m);
                    hienThiMaTran(A, n, m);
                    printf("Ma tran B (%dx%d):\n", n, m);
                    hienThiMaTran(B, n, m);
                }
                break;
            case 2:
                if (daDoc) {
                    ghiMaTranC(fileName, n, m, A, B);
                } else {
                    printf("Vui long chon muc 1 de doc du lieu truoc!\n");
                }
                break;
            case 3:
                printf("Dang thoat chuong trinh...\n");
                exit(0);
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}