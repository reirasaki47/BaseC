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
    int n, diemtb, tuoi, i = 0, stt = 0;
    printf("Nhap so sinh vien can tao danh sach: ");
    scanf("%d", &n);
    printf("Danh sach sinh vien\n");
    do {
        i++;
        phieu = (phieu_sv *)malloc(sizeof(phieu_sv));
        printf("Thong tin sinh vien thu %d\n", ++stt);
        printf("Nhap ten sinh vien: ");
        scanf("%s", &hoten);
        printf("Nhap tuoi: ");
        scanf("%d", &tuoi);
        printf("Nhap diem trung binh: ");
        scanf("%d", &diemtb);
        strcpy(phieu -> ho_ten, hoten);
        phieu -> tuoi = tuoi;
        phieu -> diem_tb = diemtb;
        if (phieu_dau == NULL){
            phieu_dau = phieu;
            phieu_cuoi = phieu;
        } else {
            phieu_cuoi -> next = phieu;
            phieu_cuoi = phieu;
        }
        phieu -> next = NULL;
    } while (i != n);
}

void hien_thi_danh_sach(){
    int stt = 0;
    printf("\tDANH SACH SINH VIEN\n");
    printf("STT\tHoTen\tTuoi\tDiemTB\n");
    phieu = phieu_dau;
    while (phieu != NULL){
        printf("%d\t%s\t%d\t%d\n", stt++, phieu -> ho_ten, phieu -> tuoi, phieu -> diem_tb);
        phieu = phieu -> next;
    }
}


void xoa_phieu(){
    char hoten[50];
    printf("Nhap ten sinh vien can xoa: ");
    scanf("%s", &hoten);
    phieu_sv * phieu_truoc, * phieu_can_tim;
    phieu_can_tim = phieu_dau;
    while ((phieu_can_tim != NULL) && strcmpi(phieu_can_tim -> ho_ten, hoten)){
        phieu_truoc = phieu_can_tim;
        phieu_can_tim = phieu_can_tim -> next;
    }
    if (phieu_can_tim == NULL)
        printf("Khong tim thay ten hoc sinh can xoa!");
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
    phieu_sv * phieu_1, * phieu_2, * phieu_tmp;
    phieu_1 = phieu_dau;
    while (phieu_1 != NULL){
        phieu_2 = phieu_1;
        phieu_1 = phieu_1 -> next;
        if (phieu_2 -> diem_tb < phieu_1 -> diem_tb){
            phieu_tmp = phieu_1;
            phieu_1 = phieu_2;
            phieu_2 = phieu_tmp;
        }
    }
}

void  sua_thong_tin(){
    char hoten[50], hoten_sua[50];
    int chon, diemtb, tuoi;
    phieu_sv * phieu_can_tim;
    printf("Muon sua thong tin sinh vien nao? ");
     scanf("%s", &hoten);
    phieu_can_tim = phieu_dau;
    while ((phieu_can_tim != NULL) && strcmpi(phieu_can_tim -> ho_ten, hoten)){
        phieu_can_tim = phieu_can_tim -> next;
    }
    if (phieu_can_tim == NULL)
        printf("Khong tim thay ten nguoi can sua thong tin!\n");
    else {
        printf("Muon sua thong tin nao?\n");
        printf("1. Ho va ten.\n");
        printf("2. Tuoi.\n");
        printf("3. Diem trung binh.\n");
        printf("Vui long nhap so: ");
        scanf("%d", &chon);
        switch (chon){
            case 1: printf("Nhap lai ten: ");
                    scanf("%s", &hoten_sua);
                    strcpy(phieu_can_tim -> ho_ten, hoten_sua);
                    printf("Da sua xong!\n");
                    break;
            case 2: printf("Nhap lai tuoi: ");
                    scanf("%d", &tuoi);
                    phieu_can_tim -> tuoi =  tuoi;
                    printf("Da sua xong!\n");
                    break;
            case 3: printf("Nhap lai diem trung binh: ");
                    scanf("%d", &diemtb);
                    phieu_can_tim -> diem_tb = diemtb;
                    printf("Da sua xong!\n");
                    break; 
            }
        }
    }

void chen_phieu(){
    char hoten_chen[50], hoten_tim[50];
    int diemtb, tuoi;
    phieu_sv * phieu_chen, * phieu_can_tim;
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
    printf("Muon chen sau sinh vien nao? ");
    scanf("%s", &hoten_tim);
    phieu_can_tim = phieu_dau;
    while ((phieu_can_tim != NULL) && strcmpi(phieu_can_tim -> ho_ten, hoten_tim)){
        phieu_can_tim = phieu_can_tim -> next;
    }
    if (phieu_can_tim == NULL)
        printf("Khong tim thay ten sinh vien nay trong danh sach!\n");
    else {
        phieu_chen -> next = phieu_can_tim -> next;
        phieu_can_tim -> next = phieu_chen;
        printf("Da chen xong!\n");
    }
}

int main(){
    int n;
    while (n != 7) {
        printf("1. Tao danh sach sinh vien.\n");
        printf("2. Hien danh sach sinh vien.\n");
        printf("3. Xoa phieu sinh vien bat ki.\n");
        printf("4. Chen phieu sinh vien bat ki.\n");
        printf("5. Sua thong tin sinh vien.\n");
        printf("6. Sap xep cac phieu.\n");
        printf("7. Thoat\n");
        scanf("%d", &n);
        switch (n){
            case 1: tao_danh_sach(); break;
            case 2: hien_thi_danh_sach(); break;
            case 3: xoa_phieu(); break;
            case 4: chen_phieu(); break;
            case 5: sua_thong_tin();break;
            case 6: sap_xep(); break;
        }
    } 
}


