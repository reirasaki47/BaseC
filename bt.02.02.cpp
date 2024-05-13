#include <iostream>
#include <math.h>

using namespace std;

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

int * Plus(int * arr, int * brr, int w, int t){
    int * crr = new int[50], scale, e;
    scale = pow(2, w);
    crr[0] = 0;
    crr[0] = arr[0] + brr[0];
    if (crr[0] > scale){
        crr[0] = crr[0] % scale;
        e = 1;
    } else {
        e = 0;
    }
    for (int i = 1; i < t; i++){
        crr[i] = arr[i] + brr[i] + e;
        if (crr[i] > scale){
            crr[i] = crr[i] % scale;
            e = 1;
        } else {
            e = 0;
        }
    }
    return crr;
}

int * Sub(int * arr, int * brr, int w, int t){
    int * crr = new int[50], scale, e;
    scale = pow(2, w);
    crr[0] = 0;
    crr[0] = arr[0] - brr[0];
    if (crr[0] < 0){
        crr[0] = pow(2, w) + crr[0];
        e = 1;
    } else {
        e = 0;
    }
    for (int i = 1; i < t; i++){
        crr[i] = arr[i] - brr[i] - e;
        if (crr[i] < 0){
            crr[i] = crr[i] + pow(2, w);
            e = 1;
        } else {
            e = 0;
        }
    }
    return crr;
}

void Display(int * xrr, int n){
    for (int i = n - 1; i >= 0; i--){
        cout << *(xrr + i) << " ";
    }
}

int main(){
    int w, *Plus1, *Sub1, t, *arr, *brr;
    double a, b, p;
    cout << "Nhap so W: ";
    cin >> w;
    cout << "Nhap truong p: ";
    cin >> p;
    cout << "Nhap hai so a va b: ";
    cin >> a >> b;
    t = round(round(log2(p)) / w);
    cout << "Bieu dien cua so a la: ";
    arr = Convert(w, p, a);
    Display(arr, t);
    cout << endl;
    cout << "Bieu dien cua so b la: ";
    brr = Convert(w, p, b);
    Display(brr, t);
    cout << endl;
    Plus1 = Plus(arr, brr, w, t);
    cout << "Ket qua cua phep cong la: ";
    Display(Plus1, t);
    cout << endl;
    Sub1 = Sub(arr, brr, w, t);
    cout << "Ket qua cua phep tru la: ";
    Display(Sub1, t);
    cout << endl;
} 