#include <stdio.h>
int main(){
int th, nam, songay;
printf("nhap thang và nam: ");
scanf("%d %d", &th, &nam);
if(th>12||th<1){
    printf("hay nhap du lieu hop le");
    return 1;
}
switch(th){
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
songay=31;
break;
case 4:
case 6:
case 9:
case 11:
songay=30;
break;
case 2:
    if((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)){
        songay=29;
    }
    else{
        songay=28;
    }
}

printf("thang %d nam %d co %d ngay",th, nam, songay);
return 0;
}
