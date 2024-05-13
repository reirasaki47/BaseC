#include <iostream>
#include <math.h>

using namespace std;

void create(int arr[], int n){
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int * Convert(int w, int p, int a){
    float m, t;
    m = round(log2(p));
    t = round(m / w);
    int * xrr = new int[50];
    for (int i = t - 1; i >= 0; i--){
        *(xrr + i) = int (a / pow(2, w * i));
        a = a - (pow(2, w * i) * xrr[i]);
    }
    return xrr;
}

int * Plus(int * arr, int * brr, int * prr, int w, int t){
    int * crr = new int[50], scale, e;
    int * drr = new int[50];
    scale = pow(2, w);
    crr[t] = arr[t] + brr[t];
    if (crr[t] > scale){
        crr[t] = crr[t] % scale;
        e = 1;
    } else {
        e = 0;
    }
    for (int i = t - 1; i >= 0; i--){
        crr[i] = arr[i] + brr[i] + e;
        if (crr[i] > scale){
            crr[i] = crr[i] % scale;
            e = 1;
        } else {
            e = 0;
        }
    }
    int k = -1;
    for (int i = t; i >= 0; i--){
        drr[k] = crr[i];
        k++;
    }
    if (e == 1){
        drr[0] = drr[0] - prr[0];
        if (drr[0] < 0){
            drr[0] = drr[0] + pow(2, w);
            e = 1;
        } else {
            e = 0;
        }
        for (int i = 1; i < t; i++){
            drr[i] = drr[i] - prr[i] - e;
            if (drr[i] < 0){
                drr[i] = drr[i] + pow(2, w);
                e = 1;
            } else {
                e = 0;
            }
        }
    }
    return drr;
}

void Display(int * xrr, int n){
    for (int i = n - 1; i >= 0; i--){
        cout << *(xrr + i) << " ";
    }
}

int main(){
    int w, *Plus1, *Sub1, t, arr[50], brr[50], *prr;
    double a, b, p;
    cout << "Nhap so W: ";
    cin >> w;
    cout << "Nhap truong p: ";
    cin >> p;
    cout << "Nhap mang a: ";
    create(arr, 4);
    cout << "Nhap mang b: ";
    create(brr, 4);
    t = round(round(log2(p)) / w);
    /*cout << "Bieu dien cua so a la: ";
    arr = Convert(w, p, a);
    Display(arr, t);
    cout << endl;
    cout << "Bieu dien cua so b la: ";
    brr = Convert(w, p, b);
    Display(brr, t);
    cout << endl;*/
    cout << "Bieu dien cua so a la: ";
    Display(arr, t);
    cout << endl;
    cout << "Bieu dien cua so b la: ";
    Display(brr, t);
    cout << endl;
    cout << "Bieu dien cua so p la: ";
    prr = Convert(w, p, p);
    Display(prr, t);
    cout << endl;
    Plus1 = Plus(arr, brr, prr, w, t);
    cout << "Ket qua cua phep cong hai so lon la: ";
    Display(Plus1, t);
    cout << endl;
} 