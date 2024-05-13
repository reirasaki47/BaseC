#include <iostream>
#include <math.h>

using namespace std;

int * Convert1(int w, int p, int a){
    static int xrr[50];
    float m, t;
    m = round(log2(p));
    t = round(m / w);
    for (int i = t - 1; i >= 0; i--){
        *(xrr + i) = int (a / pow(2, w * i));
        a = a - (pow(2, w * i) * xrr[i]);
    }
    return xrr;
}

int * Convert2(int w, int p, int a){
    static int xrr[50];
    float m, t;
    m = round(log2(p));
    t = round(m / w);
    for (int i = t - 1; i >= 0; i--){
        *(xrr + i) = int (a / pow(2, w * i));
        a = a - (pow(2, w * i) * xrr[i]);
    }
    return xrr;
}

int * Plus(int * arr, int * brr, int w, int t){
    static int crr[50], scale, e;
    scale = pow(2, w);
    crr[0] = 0;
    crr[0] = arr[0] + brr[0];
    if (crr[0] > scale){
        crr[0] = crr[0] % scale;
        e = 1;
    } else {
        e = 0;
    }
    for (int i = 1; i < t - 1; i++){
        *(crr + i) = *(arr + i) + *(brr + i) + e;
        if (crr[i] > scale){
            crr[i] = crr[i] % scale;
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

//void Plus(int arr[], int brr[]){}

int main(){
    int w, *Plus1, *Sub1, t;
    double a, b, p;
    cout << "Nhap so W: ";
    cin >> w;
    cout << "Nhap truong p: ";
    cin >> p;
    cout << "Nhap hai so a va b: ";
    cin >> a >> b;
    t = round(round(log2(p)) / w);
    cout << "Bieu dien cua so a la: ";
    Display(Convert1(w, p, a), t);
    cout << endl;
    cout << "Bieu dien cua so b la: ";
    Display(Convert2(w, p, b), t);
    cout << endl;
    Plus1 = Plus(Convert1(w, p, a), Convert2(w, p, b), w, round(round(log2(p)) / w));
    cout << "Ket qua cua phep cong la: ";
    Display(Plus1, t);
    cout << endl;
}