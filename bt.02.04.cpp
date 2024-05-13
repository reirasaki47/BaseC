#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

vector<int> Convert(int w, int p, int a){
    vector<int> xrr;
    float m, t;
    m = round(log2(p));
    t = round(m / w);
    for (int i = t - 1; i >= 0; i--){
        xrr.push_back(int(a / pow(2, w * i)));
        a = a - (pow(2, w * i) * xrr.back());
    }
    return xrr;
}

vector<int> Plus(const vector<int>& arr, const vector<int>& brr, int w){
    vector<int> crr;
    int scale, e, size;
    scale = pow(2, w);
    e = 0;
    crr.resize(max(arr.size(), brr.size()), 0);
    crr[0] = arr[0] + brr[0];
    if (crr[0] > scale){
        crr[0] = crr[0] % scale;
        e = 1;
    } else {
        e = 0;
    }
    for (int i = crr.size(); i > 0; i--){
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

vector<int> Sub(const vector<int>& arr, const vector<int>& brr, int w){
    vector<int> crr;
    int scale, e, size;
    scale = pow(2, w);
    e = 0;
    crr.resize(max(arr.size(), brr.size()), 0);
    crr[0] = arr[0] - brr[0];
    if (crr[0] < 0){
        crr[0] = pow(2, w) + crr[0];
        e = 1;
    } else {
        e = 0;
    }
    for (int i = crr.size(); i > 0; i--){
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

void Display(vector<int>& xrr){
    for (int i = 0; i < xrr.size(); i++){
        cout << xrr[i] << " ";
    }
    cout << endl;
}

int main(){
    int w;
    double a, b, p;
    cout << "Nhap so W: ";
    cin >> w;
    cout << "Nhap truong F: ";
    cin >> p;
    cout << "Nhap hai so a va b: ";
    cin >> a >> b;
    Convert(w, p, a);
    
    vector<int> arr = Convert(w, p, a);
    cout << "Bieu dien cua so a la: ";
    Display(arr);

    vector<int> brr = Convert(w, p, b);
    cout << "Bieu dien cua so b la: ";
    Display(brr);

    vector<int> plus = Plus(arr, brr, w);
    cout << "Tong cua a va b la: ";
    Display(plus);

    vector<int> sub = Sub(arr, brr, w);
    cout << "Hieu cua a va b la: ";
    Display(sub);

    return 0;

}