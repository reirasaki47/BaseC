#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> Convert1(int w, int p, int a) {
    vector<int> xrr;
    float m, t;
    m = round(log2(p));
    t = round(m / w);
    for (int i = t - 1; i >= 0; i--) {
        xrr.push_back(int(a / pow(2, w * i)));
        a = a - (pow(2, w * i) * xrr.back());
    }
    return xrr;
}

vector<int> Plus(const vector<int>& arr, const vector<int>& brr, int w) {
    vector<int> crr;
    int scale = pow(2, w);
    int e = 0;
    int size = max(arr.size(), brr.size());
    crr.resize(size, 0);

    for (int i = 0; i < size; i++) {
        if (i < arr.size()) crr[i] += arr[i];
        if (i < brr.size()) crr[i] += brr[i];
        crr[i] += e;
        if (crr[i] >= scale) {
            crr[i] -= scale;
            e = 1;
        } else {
            e = 0;
        }
    }

    return crr;
}

void Display(const vector<int>& xrr) {
    for (int i = xrr.size() - 1; i >= 0; i--) {
        cout << xrr[i] << " ";
    }
    cout << endl;
}

int main() {
    int w;
    double a, b, p;
    cout << "Nhap so W: ";
    cin >> w;
    cout << "Nhap truong p: ";
    cin >> p;
    cout << "Nhap hai so a va b: ";
    cin >> a >> b;

    vector<int> arr = Convert1(w, p, a);
    cout << "Bieu dien cua so a la: ";
    Display(arr);

    vector<int> brr = Convert1(w, p, b);
    cout << "Bieu dien cua so b la: ";
    Display(brr);

    vector<int> Plus1 = Plus(arr, brr, w);
    cout << "Ket qua cua phep cong la: ";
    Display(Plus1);

    return 0;
}
