#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc dữ liệu cho mặt hàng
typedef struct {
    char Ten_hang[50];
    float Don_gia;
    int So_luong;
    float Thanh_tien;
} HangHoa;

// 1. Hàm nhập dữ liệu mới (ghi đè tệp cũ)
void nhapMoi(char *filename) {
    FILE *f = fopen(filename, "wb"); // Mở chế độ ghi nhị phân (wb)
    if (f == NULL) {
        printf("Khong the mo tep!\n");
        return;
    }
    int n;
    HangHoa h;
    printf("Nhap so luong mat hang muon nhap: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap mat hang thu %d:\n", i + 1);
        printf("- Ten hang: "); fflush(stdin); gets(h.Ten_hang);
        printf("- Don gia: "); scanf("%f", &h.Don_gia);
        printf("- So luong: "); scanf("%d", &h.So_luong);
        h.Thanh_tien = h.Don_gia * h.So_luong;
        
        fwrite(&h, sizeof(HangHoa), 1, f);
    }
    fclose(f);
    printf("Da luu du lieu thanh cong!\n");
}

// 2. Hàm bổ sung dữ liệu vào cuối tệp
void boSung(char *filename) {
    FILE *f = fopen(filename, "ab"); // Mở chế độ ghi nối tiếp (ab)
    if (f == NULL) {
        printf("Khong the mo tep!\n");
        return;
    }
    int n;
    HangHoa h;
    printf("Nhap so luong mat hang muon bo sung (it nhat 2): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap mat hang bo sung %d:\n", i + 1);
        printf("- Ten hang: "); fflush(stdin); gets(h.Ten_hang);
        printf("- Don gia: "); scanf("%f", &h.Don_gia);
        printf("- So luong: "); scanf("%d", &h.So_luong);
        h.Thanh_tien = h.Don_gia * h.So_luong;
        
        fwrite(&h, sizeof(HangHoa), 1, f);
    }
    fclose(f);
}

// 3. Hàm hiển thị nội dung tệp
void hienThi(char *filename) {
    FILE *f = fopen(filename, "rb"); // Mở chế độ doc nhị phân (rb)
    if (f == NULL) {
        printf("Tep rong hoac chua ton tai!\n");
        return;
    }
    HangHoa h;
    int stt = 1;
    float tongTien = 0;
    
    printf("\n%30s\n", "SO LIEU BAN HANG");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "STT", "Ten Hang", "Don gia", "So luong", "Thanh tien");
    
    while (fread(&h, sizeof(HangHoa), 1, f)) {
        printf("%-5d %-20s %-10.1f %-10d %-10.1f\n", stt++, h.Ten_hang, h.Don_gia, h.So_luong, h.Thanh_tien);
        tongTien += h.Thanh_tien;
    }
    printf("%40s %-10.1f\n", "Tong tien", tongTien);
    fclose(f);
}

// Hàm main điều khiển menu
int main() {
    char filename[] = "SO_LIEU.C";
    int chon;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap so lieu ban hang len tep\n");
        printf("2. Ghi bo sung so lieu vao cuoi tep\n");
        printf("3. Hien thi noi dung tep\n");
        printf("4. Ket thuc\n");
        printf("Chon chuc nang (1-4): ");
        scanf("%d", &chon);
        
        switch(chon) {
            case 1: nhapMoi(filename); break;
            case 2: boSung(filename); break;
            case 3: hienThi(filename); break;
            case 4: printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 4);
    
    return 0;
}