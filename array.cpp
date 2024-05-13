#include<iostream>
#include<math.h>

using namespace std;

int * create(int n){
    int * arr = new int[n];
    for (int i = 0; i < 5; i++)
        *(arr + i) = i + n;
    return arr;
}

void display(int * arr, int n){
    for (int i = 0; i < n; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int * Plus(int *arr, int *brr, int n){
    int * crr = new int[n];
    for (int i = 0; i < n; i++){
        *(crr + i) = *(arr + i) + *(brr + i);
    }
    return crr;
}

int main(){
    int *x, *y, *z, n, m;
    cin >> n >> m;
    x = create(n);
    display(x, n);
    y = create(m);
    display(y, m);
    z = Plus(x, y, max(n, m));
    display(z, max(m, n));
    return 0;
}