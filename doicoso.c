#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc Stack
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Khởi tạo Stack
void init(Stack *s) {
    s->top = -1;
}

// 1. Hàm push(): đẩy một phần tử vào ngăn xếp
void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->top++;
        s->data[s->top] = value;
    } else {
        printf("Stack day!\n");
    }
}

// 2. Hàm pop(): loại bỏ và trả về 1 phần tử khỏi ngăn xếp
int pop(Stack *s) {
    if (s->top >= 0) {
        int value = s->data[s->top];
        s->top--;
        return value;
    }
    return -1; // Stack rỗng
}

// 3. Hàm chuyen_co_so(): đổi thập phân n sang hệ cơ số b
void chuyen_co_so(Stack *s, int n, int b) {
    init(s);
    if (n == 0) {
        push(s, 0);
        return;
    }
    while (n > 0) {
        push(s, n % b); // Đẩy số dư vào Stack
        n = n / b;      // Chia lấy phần nguyên
    }
}

// 4. Hàm hienketqua(): hiển thị kết quả ra màn hình
void hienketqua(Stack *s) {
    char digits[] = "0123456789ABCDEF";
    printf("Ket qua: ");
    while (s->top >= 0) {
        printf("%c", digits[pop(s)]);
    }
    printf("\n");
}

// Hàm main(): hiển thị menu điều khiển
int main() {
    Stack s;
    int n, choice;

    do {
        printf("\n--- MENU CHUYEN DOI CO SO ---\n");
        printf("1. Chuyen mot so nguyen duong sang he 2\n");
        printf("2. Chuyen mot so nguyen duong sang he 8\n");
        printf("3. Chuyen mot so nguyen duong sang he 16\n");
        printf("4. Ket thuc\n");
        printf("Chon chuc nang (1-4): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Nhap so thap phan n (n>=0): ");
            scanf("%d", &n);

            if (choice == 1) chuyen_co_so(&s, n, 2);
            else if (choice == 2) chuyen_co_so(&s, n, 8);
            else if (choice == 3) chuyen_co_so(&s, n, 16);

            hienketqua(&s);
        } else if (choice != 4) {
            printf("Lua chon khong hop le!\n");
        }

    } while (choice != 4);

    printf("Chuong trinh ket thuc.\n");
    return 0;
}