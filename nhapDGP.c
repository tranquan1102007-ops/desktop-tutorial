#include <stdio.h>

int main() {
    float gdp2014, gdpHienTai, tocDo;
    int nam = 2014;


    printf("Nhap GDP nam 2014: ");
    scanf("%f", &gdp2014);
    printf("Nhap toc do tang truong (%%): ");
    scanf("%f", &tocDo);

    gdpHienTai = gdp2014;

    printf("\n|Nam\tGDP|\n");

    // Vong lap xu ly
    while (gdpHienTai<gdp2014*2) { // (1) Dien dieu kien tiep tuc vao day
        printf("|%d\t%.1fƯ\n", nam, gdpHienTai);

        // (2) Viet cong thuc cap nhat gdpHienTai tai day
        gdpHienTai=gdpHienTai+(gdpHienTai*(tocDo/100));
        nam++; // Tang nam len 1
    }

    return 0;
}
