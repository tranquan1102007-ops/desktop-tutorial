#include <stdio.h>
int main(){
float A[100][100];
int m,n,i,j;
printf("nhap so hang: ");
scanf("%d", &m);
printf("nhap so cot: ");
scanf("%d", &n);

// 0. Nhập ma trận
printf("Nhap cac phan tu cua ma tran:\n");
for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        printf("A[%d][%d] = ", i, j);
        scanf("%f", &A[i][j]);
    }
}

// 1. Tìm Max và Min
float max = A[0][0];
float min = A[0][0];
for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        // Kiểm tra xem A[i][j] có lớn hơn max không?
        if(A[i][j] > max) {
            max = A[i][j];
        }
        // Kiểm tra xem A[i][j] có nhỏ hơn min không?
        if(A[i][j] < min) {
            min = A[i][j];
        }
    }
}

// 2. In ma trận ra màn hình
printf("\nMa tran vua nhap la:\n");
for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        printf("%.2f\t", A[i][j]); // In phần tử và một khoảng trắng tab
    }
    printf("\n"); // Hết một hàng thì xuống dòng
}

// 3. In kết quả cuối cùng
printf("Gia tri lon nhat (max) la: %.2f\n", max);
printf("Gia tri nho nhat (min) la: %.2f\n", min);
return 0;
}
