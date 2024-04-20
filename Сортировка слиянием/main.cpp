#include <iostream>

using namespace std;

int merge(int *a, int left, int mid, int right) {
    int pars = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int array_left[n1];
    int array_right[n2];
    for (int i = 0; i < n1; i++) {
        array_left[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        array_right[j] = a[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 or j < n2) {
        if ((i != n1 and array_left[i] <= array_right[j]) or j == n2) {
            a[left + k] = array_left[i];
            i++;
        } else {
            a[left + k] = array_right[j];
            pars += mid - left + 1 - i;
            j++;
        }
        k++;
    }
    return pars;
}

int merge_sort(int *array, int left, int right) {
    int pars = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        pars += merge_sort(array, left, mid);
        pars += merge_sort(array, mid + 1, right);
        pars += merge(array, left, mid, right);
    }
    return pars;
}

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        array[i] = c;
    }
    cout << merge_sort(array, 0, n - 1);
}