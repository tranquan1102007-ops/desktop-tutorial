#include <stdio.h>
int main(){
int a[100];
int n,temp, i, j;
printf("nhap n: ");
scanf("%d", &n);
for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
}
for(int i=0;i<n;i++){
   printf("%d ", a[i]);
}
int max=a[0];
int min=a[0];
for(int i=1;i<n;i++){
    if(a[i]>max){
        max=a[i];
    }
}
for(int i=1;i<n;i++){
    if(a[i]<min){
        min=a[i];
    }
}
printf("\nmin la: %d\n", min);
printf("max la: %d", max);
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(a[i]>a[i+1]){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=a[i];

        }
    }
}
for(int i=0;i<n;i++){
    printf("\n%d", a[i]);
}
return 0;
}
