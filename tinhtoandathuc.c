#include <stdio.h>
#include <math.h>

#define MAX 100

// 1. Hàm nhập hệ số của 1 đa thức
void nhapDaThuc(double poly[], int *bac, char tenDT) {
    printf("\nNhap bac cua da thuc %c: ", tenDT);
    scanf("%d", bac);
    for (int i = *bac; i >= 0; i--) {
        printf("Nhap he so cua x^%d: ", i);
        scanf("%lf", &poly[i]);
    }
}

// 2. Hàm in hệ số của 1 đa thức
void inHeSo(double poly[], int bac, char *tenDT) {
    printf("%s = ", tenDT);
    for (int i = bac; i >= 0; i--) {
        if (i == 0) printf("%.2f", poly[i]);
        else printf("%.2f*x^%d + ", poly[i], i);
    }
    printf("\n");
}

// 3. Hàm tính giá trị của 1 đa thức tại x
double tinhGiaTri(double poly[], int bac, double x) {
    double ketQua = 0;
    for (int i = 0; i <= bac; i++) {
        ketQua += poly[i] * pow(x, i);
    }
    return ketQua;
}

// 4. Hàm tính hệ số của đa thức tổng T = P + Q
int tinhTong(double P[], int bacP, double Q[], int bacQ, double T[]) {
    int bacMax = (bacP > bacQ) ? bacP : bacQ;
    // Khởi tạo đa thức T bằng 0
    for (int i = 0; i <= bacMax; i++) {
        T[i] = 0;
        if (i <= bacP) T[i] += P[i];
        if (i <= bacQ) T[i] += Q[i];
    }
    return bacMax;
}

int main() {
    double P[MAX], Q[MAX], T[MAX];
    int bacP = -1, bacQ = -1, bacT = -1;
    double x;
    int luaChon;

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap he so cua 2 da thuc P, Q\n");
        printf("2. Tinh he so cua da thuc T (T = P + Q)\n");
        printf("3. In he so cua 3 da thuc P, Q, T\n");
        printf("4. In gia tri cua 3 da thuc P, Q, T tai x\n");
        printf("5. Ket thuc\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapDaThuc(P, &bacP, 'P');
                nhapDaThuc(Q, &bacQ, 'Q');
                break;
            case 2:
                if (bacP == -1 || bacQ == -1) {
                    printf("Vui long nhap P va Q truoc!\n");
                } else {
                    bacT = tinhTong(P, bacP, Q, bacQ, T);
                    printf("Da tinh xong đa thuc tong T.\n");
                }
                break;
            case 3:
                if (bacP != -1) inHeSo(P, bacP, "P(x)");
                if (bacQ != -1) inHeSo(Q, bacQ, "Q(x)");
                if (bacT != -1) inHeSo(T, bacT, "T(x)");
                break;
            case 4:
                if (bacP == -1 || bacQ == -1 || bacT == -1) {
                    printf("Chua du du lieu de tinh gia tri!\n");
                } else {
                    printf("Nhap gia tri x = ");
                    scanf("%lf", &x);
                    printf("P(%.2f) = %.2f\n", x, tinhGiaTri(P, bacP, x));
                    printf("Q(%.2f) = %.2f\n", x, tinhGiaTri(Q, bacQ, x));
                    printf("T(%.2f) = %.2f\n", x, tinhGiaTri(T, bacT, x));
                }
                break;
            case 5:
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}