#include <stdio.h>
#include <math.h>
int main(){
int a,b,num1,num2,temp,bcnn;
scanf("%d %d" ,&num1,&num2);
a = num1;
    b = num2;
while(b!=0){
    temp = a % b;
    a = b;
        b = temp;
}

bcnn = (num1 * num2) / a;
printf("boi chung nho nhat la: %d", bcnn);
return 0;
}
