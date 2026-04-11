#include <stdio.h>
#include <conio.h>
#include <windows.h> // Thêm thư viện này để dùng hàm Sleep

int main() {
    char ch;

    printf("Chuong trinh bat dau. Hay bam phim C hoac P...\n");


    while (1) {
        printf("NGON NGU LAP TRINH\n");

        if (kbhit()) {
            ch = getch();

            if (ch == 'c' || ch == 'C') {
                printf("   TURBO C\n");
                break;
            }
            else if (ch == 'p' || ch == 'P') {

                printf("TURBO PASCAL\n");
                printf("Bam phim bat ky de ket thuc chuong trinh...");
                getch();
                break;
            }
        }


        Sleep(100);
    }

    return 0;
}
