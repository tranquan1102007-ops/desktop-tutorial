#include <stdio.h>
int main(){
int n;
printf("nhap n:  ");
scanf("%d", &n);
long long giaithua=1;
for(int i=1;i<=n;i++){
    giaithua *= i;
}
printf("giai thua la: %lld", giaithua);
return 0;
}
