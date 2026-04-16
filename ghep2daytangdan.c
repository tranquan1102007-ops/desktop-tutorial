#include <stdio.h>
#include <stdlib.h>

#define MAX 200

// 1. Hàm nhập 1 dãy số theo chiều tăng dần
void nhapDay(int a[], int *n, char tenDay) {
    printf("\nNhap so luong phan tu cho day %c: ", tenDay);
    scanf("%d", n);
    printf("Nhap cac phan tu cho day %c (phai nhap tang dan):\n", tenDay);
    for (int i = 0; i < *n; i++) {
        printf("%c[%d] = ", tenDay, i);
        scanf("%d", &a[i]);
        
        // Kiem tra tinh tang dan (Optional - giup du lieu dau vao chuan hon)
        if (i > 0 && a[i] < a[i-1]) {
            printf("Loi: Ban phai nhap so lon hon hoac bang %d. Nhap lai!\n", a[i-1]);
            i--; 
        }
    }
}

// 2. Hàm ghép 2 dãy số (Thuat toan Merge)
void ghepDay(int a[], int n, int b[], int m, int c[], int *p) {
    int i = 0, j = 0, k = 0;

    // So sanh va dua phan tu nho hon vao day c
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // Neu day a con phan tu, dua het vao c
    while (i < n) {
        c[k++] = a[i++];
    }

    // Neu day b con phan tu, dua het vao c
    while (j < m) {
        c[k++] = b[j++];
    }

    *p = k; // Cap nhat so phan tu cua day c
    printf("\nDa ghep xong hai day!\n");
}

// 3. Hàm in 1 dãy số
void inDay(int a[], int n, char *label) {
    printf("%s: ", label);
    if (n == 0) {
        printf("(Trong)");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

int main() {
    int a[MAX], b[MAX], c[MAX*2];
    int n = 0, m = 0, p = 0;
    int luaChon;

    while (1) {
        printf("\n========= MENU =========\n");
        printf("1. Nhap 2 day so nguyen tang dan\n");
        printf("2. Ghep hai day\n");
        printf("3. In 3 day so\n");
        printf("4. Ket thuc\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapDay(a, &n, 'A');
                nhapDay(b, &m, 'B');
                break;
            case 2:
                if (n == 0 && m == 0) {
                    printf("Vui long nhap du lieu o muc 1 truoc!\n");
                } else {
                    ghepDay(a, n, b, m, c, &p);
                }
                break;
            case 3:
                inDay(a, n, "Day A");
                inDay(b, m, "Day B");
                inDay(c, p, "Day C (Sau khi ghep)");
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