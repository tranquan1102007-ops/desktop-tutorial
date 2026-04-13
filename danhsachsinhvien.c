#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char Ho_ten[50];
    int Tuoi;
    float Diem_TB;
} SV;

struct Node {
    SV data;
    struct Node* next;
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void readLine(char str[], int size) {
    if (fgets(str, size, stdin) == NULL) {
        str[0] = '\0';
        return;
    }
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

struct Node* createNode() {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Khong du bo nho");
        exit(EXIT_FAILURE);
    }

    printf("Nhap ho ten: ");
    clearInputBuffer();
    readLine(newNode->data.Ho_ten, sizeof(newNode->data.Ho_ten));
    printf("Nhap tuoi: ");
    scanf("%d", &newNode->data.Tuoi);
    printf("Nhap diem TB: ");
    scanf("%f", &newNode->data.Diem_TB);
    newNode->next = NULL;
    return newNode;
}

void addLast(struct Node** head) {
    struct Node* newNode = createNode();
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node* head) {
    printf("\n--- DANH SACH SINH VIEN ---\n");
    printf("%-5s %-20s %-10s %-10s\n", "STT", "Ho ten", "Tuoi", "Diem TB");
    int i = 1;
    while (head != NULL) {
        printf("%-5d %-20s %-10d %-10.2f\n", i++, head->data.Ho_ten, head->data.Tuoi, head->data.Diem_TB);
        head = head->next;
    }
}

void insertAfter(struct Node* head, const char name[]) {
    struct Node* p = head;
    while (p != NULL && strcmp(p->data.Ho_ten, name) != 0) {
        p = p->next;
    }
    if (p != NULL) {
        struct Node* newNode = createNode();
        newNode->next = p->next;
        p->next = newNode;
    } else {
        printf("Khong tim thay sinh vien ten %s\n", name);
    }
}

void deleteNode(struct Node** head, const char name[]) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && strcmp(temp->data.Ho_ten, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay sinh vien ten %s\n", name);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void editNode(struct Node* head, const char name[]) {
    while (head != NULL) {
        if (strcmp(head->data.Ho_ten, name) == 0) {
            printf("Nhap lai tuoi: ");
            scanf("%d", &head->data.Tuoi);
            printf("Nhap lai diem TB: ");
            scanf("%f", &head->data.Diem_TB);
            return;
        }
        head = head->next;
    }
    printf("Khong tim thay sinh vien ten %s\n", name);
}

int main() {
    struct Node* head = NULL;
    int choice;
    char name[50];

    while (1) {
        printf("\n1. Tao danh sach\n2. Hien thi\n3. Chen sinh vien\n4. Xoa sinh vien\n5. Sua sinh vien\n6. Ket thuc\nChon: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                addLast(&head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Nhap ten sv dung truoc: ");
                clearInputBuffer();
                readLine(name, sizeof(name));
                insertAfter(head, name);
                break;
            case 4:
                printf("Nhap ten can xoa: ");
                clearInputBuffer();
                readLine(name, sizeof(name));
                deleteNode(&head, name);
                break;
            case 5:
                printf("Nhap ten can sua: ");
                clearInputBuffer();
                readLine(name, sizeof(name));
                editNode(head, name);
                break;
            case 6:
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }
    return 0;
}

