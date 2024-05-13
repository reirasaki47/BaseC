#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct sv{ 
    char name[50];
    int score, age;
    struct sv * next;
} pr_sv;

pr_sv * pr, * pr_first, * pr_last;

void CreateList(){
    char nam_e[50];
    int n, scor_e, ag_e, i = 0, stt = 0;
    cout << "Nhap so sv can tao danh sach: ";
    cin >> n;
    cout << "Danh sach sinh vien: " << endl;
    do {
        i++;
        pr = (pr_sv *)malloc(sizeof(pr_sv));
        cout << "Thong tin sinh vien thu %d" << ++stt << endl;
        cout << "Nhap ten sinh vien: " << endl;
        cin >> nam_e;
        cout << "Nhap diem trung binh: " << endl;
        cin >> scor_e;
        cout << "Nhap tuoi: " << endl;
        cin >> ag_e;
        strcpy(pr -> name, nam_e);
        pr -> age = ag_e;
        pr -> score = scor_e;
        if (pr_first == NULL){
            pr_first = pr;
            pr_last = pr;
        } else {
            pr_last -> next = pr;
            pr_last = pr; 
        }
        pr -> next = NULL;
    } while (i != n);
}

void DisplayList(){
    int stt = 0;
    cout << "\tDANH SACH SINH VIEN" << endl;
    cout << "STT\t" << "HoTen\t" << "Tuoi\t" << "Diem" << endl;
    pr = pr_first;
    while (pr != NULL){
        cout << stt++ << "\t" << pr -> name << "\t" << pr -> age << "\t" << pr ->score << endl;
        pr = pr -> next; 
    } 
}

void RemovePR(){
    char nam_e[50];
    cout << "Nhap ten sinh vien can xoa: " << endl;
    cin >> nam_e;
    pr_sv * pr_previous, * pr_need;
    pr_need = pr_first;
    while ((pr_need != NULL) && strcmpi(pr_need -> name, nam_e)){
        pr_previous = pr_need;
        pr_need = pr_need -> next;
    }
    if (pr_need == NULL)
        cout << "Khong tim thay ten sinh vien can xoa!" << endl;
    else {
        if (pr_need -> next == NULL)
            pr_previous -> next = NULL;
        else if (pr_need == pr_first)
                pr_first = pr_need -> next;
            else pr_previous -> next = pr_need -> next;
            free(pr_need);
            cout << "Da xoa xong!" << endl;
    }
}

void InsertPR(){
    char name_in[50], name_find[50];
    int score, age;
    pr_sv * pr_insert, * pr_need;
    cout << "Nhap ho ten sinh vien can chen: " << endl;
    cin >> name_in;
    cout << "Nhap tuoi cua sv nay: " << endl;
    cin >> age;
    cout << "Nhap diem cua sv nay: " << endl;
    cin >> score;
    strcpy(pr -> name, name_in);
    pr -> age = age;
    pr -> score = score;
    pr -> next = NULL;
    pr_insert = pr;
    cout << "Muon chen sau sinh vien nao? ";
    cin >> name_find;
    pr_need = pr_first;
    while ((pr_need != NULL) && strcmpi(pr_need -> name, name_find)){
        pr_need = pr_need -> next;
    }
    if (pr_need == NULL){
        cout << "Khong tim thay ten sinh vien nay trong danh sach" << endl;
    } else {
        pr_insert -> next = pr_need -> next;
        pr_insert -> next =  
    }
    
}