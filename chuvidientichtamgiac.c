#include <stdio.h>
#include <math.h>
int main(){
int a,b,c;
float chuvi,dientich,p;
printf("nhap 3 canh cua tam giac: ");
scanf("%d %d %d", &a, &b, &c);
p=(a+b+c)/2;
chuvi=a+b+c;
dientich=sqrt(p*(p-a)*(p-b)*(p-c));
printf("chu vi la %.2f\n", chuvi);
printf("dien tich la %.2f", dientich);
return 0;
}
