#include<stdio.h>
#include<math.h>

//hàm nhập mảng(1 chiều) 
    void nhap_mang(int array[], int n){
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    }

//hàm xuất mảng(1 chiều)
    void xuat_mang(int array[], int n){
    for (int i = 0; i < n; i++)
        printf("%d", array[i]);
    }

//hàm nhập mảng 2 chiều
    void nhap_mang_2(int mtr[][60], int hang, int cot){
        for (int i = 0; i < hang; i++)
            for (int j = 0; j < cot; j++){
                scanf("%d", &mtr[i][j]);
            }
        }

//hàm xuất mảng 2 chiều
    void xuat_mang_2(int mtr[][60], int hang, int cot){
        for (int i = 0; i < hang; i++){
            for (int j = 0; j < cot; j++)
                printf("%-5d", mtr[i][j]);
            printf("\n\n");
        }
    }

//bài số 1: giải phương trình bậc 2
void bai_1(int a, int b, int c){
    float delta = 0; float x_1 = 0.00; float x_2 = 0.00; 
    delta = pow(b, 2) - (4*(a * c));
    if (delta > 0){
        x_1 = ((-b) - sqrt(delta)) / (2*a);
        x_2 = ((-b) + sqrt(delta)) / (2*a);
        printf("2 nghiem thuc: %.2f va %.2f", x_1, x_2);
    }
    else if (delta == 0){
        x_1 = x_2 = -(b) / (2*a);
        printf("2 nghiem kep: %.2f", x_1);
    }
    else {
        printf("phuong trinh vo nghiem? =))");
    }
    }
    
//bài số 3: tìm các ước chung của 1 số
void bai_3(int a){
    for (int i = 1; i < a; i++)
    {
        if ((a % i) == 0)
        {
            printf("%d ", i);
        }
    }
    
}

//bài số 6: tính trung bình cộng của các số dương và trung bình cộng các số âm.
    //trung bình cộng các số dương.
    float bai_6_1(int a[], int n){
        int x = 0; float s = 0;
        for (int i = 0; i < n; i++)
            if (a[i] >= 0)
            {
                s += a[i];
                x++;
            }
        s = (double)s/ x;
        return s;
    }
    //trung bình cộng các số âm.
    float bai_6_2(int a[], int n){
        int y = 0; float s = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < 0)
            {
                s += a[i];
                y++;
            }
        s = (double)s / y;
        return s;
    }

//bài số 8: tính tổng của 1 chia cho n giai thừa
double bai_8(int n){
    int i, giai_thua = 1;
    double s = 0;
    for (i = 1; i <= n; i++)
    {
        giai_thua *= i;
        s += (float)1 / giai_thua;
    }
    return  s;
    }

//bài số 9: tính tổng của 1 chia cho n bình phương
double bai_9(int n){
    double s = 0;
    for (int i = 1; i <= n; i++)
        {
            s += (float)1/pow(i, 2);
        }
    return s;
}

//bài số 10: in âm dương ra hai dòng.
void bai_10(int a[], int n){
    for (int i = 0; i < n; i++)
        if (a[i] >= 0)
            printf("%-3d", a[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            printf("%-3d", a[i]);
    }

//bài số 11: in phần tử âm cuối cùng.
void bai_11(int a[], int n){
    for (int i = n; i > 0; i--)
        if (a[i] < 0)
            {
                printf("%d", a[i]);
                break;
            }
        }


//bài số 12: gộp mảng và sắp xếp theo thứ tự tăng dần.
void bai_12(int a[], int b[], int n, int m){
    int p, i, j, c[60], var_in = 0;
    p = m + n;
    for (i = 0; i < p; i++)
        {
            if (i < n)
            {
                c[i] = a[i];
            }
            else {
                c[i] = b[i - n];
            }
        }
    for (i = 0; i < p - 1; i++)
        for (j = i + 1; j < p; j++)
            if (c[i] > c[j])
                {
                    var_in = c[j];
                    c[j] = c[i];
                    c[i] = var_in;
                }
    for (i = 0; i < p; i++)
        {
            printf("%d ", c[i]);
        }
    }

//bài số 13: tách mảng thành một mảng âm và một mảng dương.
void bai_13(int a[], int n){
    int b[60], c[60], i, j = 0, k = 0;
    for (i = 0; i < n; i++)
        {
            if (a[i] < 0)
                {
                    b[j] = a[i];
                    j++;
                }
            else{
                    c[k] = a[i];
                    k++;
                }  
        }
    for (i = 0; i < j; i++)
        {
            printf("%d ", b[i]);
        }
    printf("\n");
    for (i = 0; i < k; i++)
        {
            printf("%d ", c[i]);
        }
}

//bài số 14: in ma trận hình xoắn ốc.
void bai_14(int n){
    int hang, cot, p, i, j;
    p = n * n;
    hang = n;
    cot = n;
    int mt_2[30][30], x, y, z, w, hang_tren = 0, cot_trai = 0;
    int hang_duoi = hang - 1, cot_phai = cot - 1;
    int k = 1;
    //lặp cho đến khi phần tử mt_1 = p
    
    while (k <= p)
        {
            //vòng lặp thứ nhất
            for (x = cot_trai; x <= cot_phai; x++)
            {
                mt_2[hang_tren][x] = k++;
            }
            hang_tren++;
            //vòng lặp thứ hai
            for (y = hang_tren; y <= hang_duoi; y++)
            {
                mt_2[y][cot_phai] = k++;
            } 
            cot_phai--;
            //vòng lặp thứ ba
            for (z = cot_phai; z >= cot_trai; z--)
            {
                mt_2[hang_duoi][z] = k++;
            }
            hang_duoi--;
            //vòng lặp thứ tư
            for (w = hang_duoi; w >= hang_tren; w--)
            {
                mt_2[w][cot_trai] = k++;
            }
            cot_trai++;
        }
        
    for (i = 0; i < hang; i++){
        for (j = 0; j < cot; j++)
            {
                printf("%-5d", mt_2[i][j]);
            }
        printf("\n\n");
}
}

//bài số 15: tính giá trị tích các phần tử âm
int bai_15(int a[], int n){
    int t = 1;
    for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
                t *= a[i];
        }
    return t;
}

//bài 16: in tích 2 ma trận
void bai_16(int hang1, int cot1, int hang2, int cot2, int mtrx[][60], int mtrx2[][60]){
    int i, j, k;
    int mtrx3[60][60];
    for (i = 0; i < hang1; i++)
        for (j = 0; j < cot2; j++){
            int tong = 0;
            for (k = 0; k < cot1; k++)
                {
                    tong += mtrx[i][k] * mtrx2[k][j];
                }
            mtrx3[i][j] = tong;
        } 
    for (i = 0; i < hang1; i++){
        for (j = 0; j < cot2; j++)
            {
                printf("%-5d", mtrx3[i][j]);
            }
        printf("\n\n");
    }
}

//bài 17: thực hiện chuyển vị ma trận
void bai_17(int hang, int cot, int mtr[][60]){
    int tmp = 0, t = 0;
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < i; j++){
            tmp = mtr[i][j];
            mtr[i][j] = mtr[j][i];
            mtr[j][i] = tmp;
        }
        t = hang; hang = cot; cot = t;
}

int main()

    {
        int bt1_1, bt1_2, bt1_3, bt3, bt6, bt8, bt9, bt10;
        int bt11, bt12_1, bt12_2, bt13, bt14, bt15, bai_tap;
        int hang_1, cot_1, hang_2, cot_2;
        int a_rray[60], b[60], c[60], mtrix[60][60], mtrix_2[60][60];
        printf("nhap bai tap can giai: ");
        scanf("%d", &bai_tap);
        switch (bai_tap)
        {
        case 1: printf("bai tim nghiem phuong trinh bac 2: a?, b?, c?  ");
                scanf("%d %d %d", &bt1_1, &bt1_2, &bt1_3);
                bai_1(bt1_1, bt1_2, bt1_3);
                break;

        case 3: printf("bai tim cac uoc chung: n? ");
                scanf("%d", &bt3);
                bai_3(bt3);
                break;

        case 6: printf("bai tim tong tb duong va tb am: n? ");
                scanf("%d", &bt6);
                printf("array? ");
                nhap_mang(a_rray, bt6);
                printf("trung binh cac so duong: %.2f", (double)bai_6_1(a_rray, bt6));//tính trung bình dương
                printf("\ntrung binh cac so am: %.2f", (double)bai_6_2(a_rray, bt6));//tính trung bình âm
                break;

        case 8: printf("bai tong 1/giai_thua: n? ");
                scanf("%d", &bt8);
                printf("%f", bai_8(bt8));
                break;

        case 9: printf("bai tong 1/binh_phuong: n? ");
                scanf("%d", &bt9);
                printf("%f", bai_9(bt9)); 
                break;

        case 10:printf("bai in am duong tren hai dong khac nhau: n? ");
                scanf("%d", &bt10);
                printf("array? ");
                nhap_mang(a_rray, bt10);
                bai_10(a_rray, bt10);
                break;

        case 11:printf("bai in phan tu am cuoi cung: n? ");
                scanf("%d", &bt11);
                printf("array? ");
                nhap_mang(a_rray, bt11);
                bai_11(a_rray, bt11);
                break;

        case 12:printf("bai gop 2 mang lai va sap xep: ");
                printf("\na? ");
                scanf("%d", &bt12_1);
                printf("mang a: ");
                nhap_mang(a_rray, bt12_1);
                printf("b? ");
                scanf("%d", &bt12_2);
                printf("mang b: ");
                nhap_mang(b, bt12_2);
                bai_12(a_rray, b, bt12_1, bt12_2);
                break;

        case 13:printf("bai tach mang thanh mot mang am va mot mang duong: ");
                scanf("%d", &bt13);
                printf("array? ");
                nhap_mang(a_rray, bt13);
                bai_13(a_rray, bt13);
                break;

        case 14:printf("bai in ma tran hinh xoan oc: ");
                scanf("%d", &bt14);
                bai_14(bt14);
                break;
        case 15:printf("bai tinh tich cac phan tu am: ");
                scanf("%d", &bt15);
                nhap_mang(a_rray, bt15);
                printf("Gia tri tich cac phan tu am trong day: %d", bai_15(a_rray, bt15));
                break;

        case 16:printf("bai tinh tich 2 ma tran\n");
                printf("Nhap hang 1: "); scanf("%d", &hang_1);
                printf("Nhap cot 1: "); scanf("%d", &cot_1);
                nhap_mang_2(mtrix, hang_1, cot_1);
                printf("Nhap hang 2: "); scanf("%d", &hang_2);
                printf("Nhap cot 2: "); scanf("%d", &cot_2);
                nhap_mang_2(mtrix_2, hang_2, cot_2);
                printf("\n");
                bai_16(hang_1, cot_1, hang_2, cot_2, mtrix, mtrix_2);
                break;

        case 17:printf("bai chuyen vi ma tran: \n");
                printf("Nhap hang: "); scanf("%d", &hang_1);
                printf("Nhap cot: "); scanf("%d", &cot_1);
                nhap_mang_2(mtrix, hang_1, cot_1);
                xuat_mang_2(mtrix, hang_1, cot_1);
                printf("\n");
                bai_17(hang_1, cot_1, mtrix);
                int t = 0; t = hang_1; hang_1 = cot_1; cot_1 = t;
                xuat_mang_2(mtrix, hang_1, cot_1);
                break;

        default: printf("vui long nhap dung bai tap da lam!");   
        return 1;
        }
        printf("\n");
    }