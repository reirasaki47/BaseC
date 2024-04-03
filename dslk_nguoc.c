#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sv{
    char ho_ten[50];
    int diem_tb, tuoi;
    struct sv * next;
} phieu_sv;

phieu_sv * phieu, * phieu_dau, * phieu_cuoi;

void tao_danh_sach(){
    char hoten[50];
    int n, diemTB, tuoi, i = 0, stt = 0;
    printf("Nhap so sinh vien can tao danh sach: ");
    scanf("%d", &n);
    phieu_cuoi = NULL;
    printf("Danh sach sinh vien\n");
    do {
        i++;
        phieu = (phieu_sv *)malloc(sizeof(phieu_sv));
        printf("Thong tin sinh vien so: %d\n", ++stt);
        printf("Nhap ten sinh vien: ");
        scanf("%s", &hoten);
        printf("Nhap tuoi: ");
        scanf("%d", &tuoi);
        printf("Nhap diem trung binh: ");
        scanf("%d", &diemTB);
        strcpy(phieu -> ho_ten, hoten);
        phieu -> tuoi = tuoi;
        phieu -> diem_tb = diemTB;
        phieu -> next = phieu_cuoi;
        phieu_cuoi = phieu;
    } while (i != n);
}

void hienDanhSach(){
    int stt = 0;
    phieu = phieu_cuoi;
    printf("\tDANH SACH SINH VIEN\n");
    printf("STT\tHoTen\tTuoi\tDiemTB\n");
    while (phieu != NULL){
        printf("%d\t%s\t%d\t%d\n", ++stt, phieu -> ho_ten, phieu -> tuoi, phieu -> diem_tb);
        phieu = phieu -> next;
    }
}

void chen_phieu(){
    phieu_sv * phieu_can_tim, * phieu_chen;
    char hoten_chen[50], hoten_tim[50];
    int tuoi, diemtb;
    phieu = (phieu_sv *)malloc(sizeof(phieu_sv));
    printf("Nhap ho ten sinh vien can chen: ");
    scanf("%s", &hoten_chen);
    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    printf("Nhap diem trung binh: ");
    scanf("%d", &diemtb);
    strcpy(phieu -> ho_ten, hoten_chen);
    phieu -> tuoi = tuoi;
    phieu -> diem_tb = diemtb;
    phieu -> next = NULL;
    phieu_chen = phieu;
    printf("Muon chen sau sinh vien nao?");
    scanf("%s", &hoten_tim);
    phieu_can_tim = phieu_cuoi;
    while ((phieu_can_tim != NULL) && strcmpi(phieu_can_tim -> ho_ten, hoten_tim)){
        phieu_can_tim = phieu_can_tim -> next;
    }
    if (phieu_can_tim == NULL)
        printf("Khong co sinh vien nay trong danh sach!");
    else { 
        phieu_chen -> next = phieu_can_tim -> next;
        phieu_can_tim -> next = phieu_chen;
        printf("Da chen xong!");
    }
}

void xoa_phieu(){
    char hoten[50];
    phieu_sv * phieu_can_tim, * phieu_truoc;
    phieu_can_tim = phieu_cuoi;
    printf("Nhap ho ten sinh vien can xoa: ");
    scanf("%s", &hoten);
    while ((phieu_can_tim != NULL) && strcmpi(phieu_can_tim -> ho_ten, hoten)){
        phieu_truoc = phieu_can_tim;
        phieu_can_tim = phieu_can_tim -> next;
    }
    if (phieu_can_tim == NULL)
        printf("Khong tim thay sinh vien can xoa!");
    else {
        if (phieu_can_tim -> next == NULL)
            phieu_truoc -> next = NULL;
        else if (phieu_can_tim == phieu_dau)
            phieu_dau = phieu_can_tim -> next;
                else phieu_truoc -> next = phieu_can_tim -> next;
        free(phieu_can_tim);
        printf("Da xoa xong!\n");
    }
}

void sap_xep(){

}

void sua_thong_tin(){
    
}

int main(){
    int n;
    do {
        printf("1. Tao danh sach sinh vien.\n");
        printf("2. Hien thi danh sach sinh vien.\n");
        printf("3. Xoa phieu sinh vien theo ten.\n");
        printf("4. Chen them sinh vien vao sau.\n");
        printf("5. Thoat\n");
        scanf("%d", &n);
        switch (n){
            case 1: tao_danh_sach(); break;
            case 2: hienDanhSach(); break;
            case 3: xoa_phieu(); break;
            case 4: chen_phieu(); break;
        } 
    } while (n != 5);
}