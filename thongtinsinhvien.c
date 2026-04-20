#include <stdio.h>
int main(){
struct thongtinsinhvien{
char hoten[25],diachi[50];
int tuoi;
float diemtb;
}lop[100];
#define sv lop[i]
 int n,i;
    printf("nhap so luong sinh vien:");
    scanf("%d", &n);
 for (int i=0;i<n;i++){
    printf("nhap thong tin sinh vien thu: %d\n", i+1);
    printf ("ho va ten:");
    scanf("%s", &sv.hoten);
    printf("dia chi:" );
    scanf("%s", &sv.diachi);
    printf("tuoi:");
    scanf("%d", &sv.tuoi);
    printf("diem tb:");
    scanf("%f", &sv.diemtb);
 }
 for(int i=0;i<n;i++){
    printf("thong tin sinh vien thu : %d\n", i+1);
    printf("ho va ten: %s\n", sv.hoten);
    printf("dia chi: %s\n", sv.diachi);
    printf("tuoi: %d\n", sv.tuoi);
    printf("diem tb: %.2f", sv.diemtb);
 }
 return 0;
}
