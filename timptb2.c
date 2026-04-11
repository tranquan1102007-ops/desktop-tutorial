#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2;

    // Bước tiếp theo: Nhập dữ liệu
    printf("Nhap he so a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    // Tính Delta ở đây...
    delta=b*b-4*a*c;
    if (delta<0){
        printf("phuong trinh vo nghiem");
    }
    else if (delta==0){
        x1=x2=-b/(2*a);
        printf("pt co 1 nghiem duy nhat %.2f", x1);
    }
    else {
        x1=(-b-sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
        printf("phuong trinh co 2 nghiem %.2f,%.2f", x1,x2);
    }
    return 0;
}
