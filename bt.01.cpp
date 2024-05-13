#include <iostream>

using namespace std;

/* void in_array(int arr[], int n){
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void out_array(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int  main(){

int n, array[50];

    cout << "Vui long nhap so phan tu: ";
    cin >> n;
    in_array(array, n);
    out_array(array, n);
    cout << endl;
    return 0;

} */

int main(){
    int *p, x;
    x = 3;
    *p = x;
    cout << p << endl;
    return 0;
}
