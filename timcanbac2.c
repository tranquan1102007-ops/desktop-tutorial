#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d;
    float x1, x2;
    printf("\nNhap vao 3 so a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == 0)
    {
        if (b != 0)
        {
            printf("Phuong trinh %dx + %d = 0 co 1 nghiem x: %f\n", b, c, -c / (float)b);
        }
        else
        {
            if (c == 0)
                printf("Phuong trinh vo so nghiem\n");
            else
                printf("Phuong trinh vo nghiem\n");
        }
    }
    else
    {
        d = b * b - 4 * a * c;

if(d<0)
{
printf("Phuong trinh vo nghiem\n ");
}
else if (d==0)
{
printf("Phuong trinh %dx2 + %dx + %d = 0 co nghiem kep: %f\n ",a,b,c,(float)-b/(2*a));
}
else
{
x1 = (-b - sqrt(d))/(2*a);
x2 = (-b + sqrt(d))/(2*a);
printf("Phuong trinh %dx2 + %dx + %d = 0 co 2 nghiem la x1 = %f, x2 = %f\n ",a,b,c, x1,x2);
}
getch();

}
}
