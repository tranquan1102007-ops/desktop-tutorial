#include <stdio.h>
int main(){
int x,y;
int a=1;
printf("nhap x va y: ");
scanf("%d %d", &x, &y);
for(int i=0;i<y;i++){
    a=x*a;
}
printf("luy thua cua x mu y la:%d", a);
return 0;
}
