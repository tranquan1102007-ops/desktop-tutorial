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

struct Node* createNode() {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Khong du bo nho");
        exit(1);
    }
    printf("Nhap ho ten: ");
    while (getchar() != '\n');
    fgets(newNode->data.Ho_ten, sizeof(newNode->data.Ho_ten), stdin);
    newNode->data.Ho_ten[strcspn(newNode->data.Ho_ten, "\n")] = 0;
    printf("Nhap tuoi: ");
    scanf("%d", &newNode->data.Tuoi);
    printf("Nhap diem TB: ");
    scanf("%f", &newNode->data.Diem_TB);
    newNode->next = NULL;
    return newNode;
}

void addLast(struct Node** head) {
    struct Node* newNode = createNode();
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void display(struct Node* head) {
    printf("\n--- DANH SACH SINH VIEN ---\n%-5s %-20s %-10s %-10s\n", "STT", "Ho ten", "Tuoi", "Diem TB");
    for (int i = 1; head; head = head->next, i++)
        printf("%-5d %-20s %-10d %-10.2f\n", i, head->data.Ho_ten, head->data.Tuoi, head->data.Diem_TB);
}

void insertAfter(struct Node* head, const char* name) {
    while (head && strcmp(head->data.Ho_ten, name)) head = head->next;
    if (!head) {
        printf("Khong tim thay sinh vien ten %s\n", name);
        return;
    }
    struct Node* newNode = createNode();
    newNode->next = head->next;
    head->next = newNode;
}

void deleteNode(struct Node** head, const char* name) {
    struct Node* temp = *head, *prev = NULL;
    while (temp && strcmp(temp->data.Ho_ten, name)) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Khong tim thay sinh vien ten %s\n", name);
        return;
    }
    if (!prev) *head = temp->next;
    else prev->next = temp->next;
    free(temp);
}

void editNode(struct Node* head, const char* name) {
    while (head) {
        if (!strcmp(head->data.Ho_ten, name)) {
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
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1: addLast(&head); break;
            case 2: display(head); break;
            case 3:
                printf("Nhap ten sv dung truoc: ");
                while (getchar() != '\n');
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                insertAfter(head, name);
                break;
            case 4:
                printf("Nhap ten can xoa: ");
                while (getchar() != '\n');
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                deleteNode(&head, name);
                break;
            case 5:
                printf("Nhap ten can sua: ");
                while (getchar() != '\n');
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                editNode(head, name);
                break;
            case 6: return 0;
            default: printf("Lua chon khong hop le.\n");
        }
    }
}