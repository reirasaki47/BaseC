#include <iostream>
#include <math.h>

using namespace std;

int * Convert(int w, int p, double a){
    float m = round(log2(p));
    float t = round(m / w);
    int * alpha = new int[50];
    for (int i = t - 1; i >= 0; i--){
        alpha[i] = int (a / pow(2, w * i));
        a = a - (pow(2, w * i) * alpha[i]);
    }
    return alpha;
}

int * Plus(int * arr, int * brr, int w, int t, bool check){
    int * epsilon = new int[1], * crr = new int[50]; 
    int scale = pow(2, w);
    crr[0] = arr[0] + brr[0];
    if (crr[0] > scale){
        crr[0] = crr[0] % scale;
        epsilon[0] = 1;
    } else {
        epsilon[0] = 0;
    }
    for (int i = 1; i < t; i++){
        crr[i] = arr[i] + brr[i] + epsilon[0];
        if (crr[i] > scale){
            crr[i] = crr[i] % scale;
            epsilon[0] = 1;
        } else {
            epsilon[0] = 0;
        }
    }
    if (check == false){
        return crr;
    } else {
        return epsilon;
    }
}

int * Sub(int * arr, int * brr, int w, int t, bool check){
    int * epsilon = new int[1], * crr = new int[50]; 
    int scale = pow(2, w);
    crr[0] = arr[0] - brr[0];
    if (crr[0] < 0){
        crr[0] = crr[0] + pow(2, w);
        epsilon[0] = 1;
    } else {
        epsilon[0] = 0;
    }
    for (int i = 1; i <  t; i++){
        crr[i] = arr[i] - brr[i] - epsilon[0];
        if (crr[i] < 0){
            crr[i] = crr[i] + pow(2, w);
            epsilon[0] = 1;
        } else {
            epsilon[0] = 0;
        }
    }
    if (check == false){
        return crr;
    } else {
        return epsilon;
    }
}

int * FieldCheck(int * crr, int * prr, int * epsilon, int w, int t){
    int e;
    if (epsilon[0] == 1){
        crr[0] = crr[0] - prr[0];
        if (crr[0] < 0){
            crr[0] = crr[0] + pow(2, w);
            e = 1;
        } else {
            e = 0;
        }
        for (int i = 1; i < t; i++){
            crr[i] = crr[i] - prr[i] - e;
            if (crr[i] < 0){
                crr[i] = crr[i] + pow(2, w);
                e = 1;
            } else {
                e = 0;
            }
        }
        return crr;
    } else {
        return crr;
    }
}

void Display(int * Convert, int t){
    for (int i = t - 1; i >= 0; i--)
        cout << Convert[i] << " ";
    cout << endl;
}

int main(){
    bool check;
    int * Fieldplus, * Fieldsub;
    int w, t, * arr, * brr, * prr, * plus_a, * plus_r, * sub_a, * sub_r;
    double a, b, p;
    cout << "Nhap so W: ";  cin >> w;
    cout << "Nhap truong P: ";  cin >> p;
    cout << "Nhap so a va b: ";   cin >> a >> b;
    t = round(round(log2(p)) / w);
    cout << "Bieu dien cua a la: ";
    arr = Convert(w, p, a);
    Display(arr, t);
    cout << "Bieu dien cua b la: ";
    brr = Convert(w, p, b);
    Display(brr, t);
    cout << "Bieu dien cua p la: ";
    prr = Convert(w, p, p);
    Display(prr, t);
    plus_a = Plus(arr, brr, w, t, false);
    cout << "Ket qua cua phep cong la: ";
    Display(plus_a, t);
    plus_r = Plus(arr, brr, w, t, true);
    cout << "Epsilon cuoi cua phep cong = ";
    Display(plus_r, 1);
    Fieldplus = FieldCheck(plus_a, prr, plus_r, w, t);
    cout << "Ket qua cua phep cong so lon la: ";
    Display(Fieldplus, t);
    sub_a = Sub(arr, brr, w, t, false);
    cout << "Ket qua cua phep tru la: ";
    Display(sub_a, t);
    sub_r = Sub(arr, brr, w, t, true);
    cout << "Epsilon cuoi cua phep tru = ";
    Display(sub_r, 1);
    Fieldplus = FieldCheck(sub_a, prr, sub_r, w, t);
    cout << "Ket qua cua phep tru so lon la: ";
    Display(Fieldplus, t);
}