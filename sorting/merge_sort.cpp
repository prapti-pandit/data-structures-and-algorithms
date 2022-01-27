#include <iostream>
using namespace std;

void merge(int *array, int l, int mid, int h) {
    int i, j;

    i = l;
    j = mid+1;

    while (i <= h && j <= h) {
        if (array[i] <= array[j]) {
            i++;
        } else {
            //for shifting elements one step to right to make space for array[j]
            int tmp = array[j];
            for (int k = j; k > i; k--) {
                array[k] = array[k-1];
            }
            array[i] = tmp;
            i++;
            j++;
        }
    }
}

void merge_sort(int *array, int l, int h) {
    int mid  = 0;

    if (l < h) {
        mid = (l + h) / 2;

        merge_sort(array, l, mid);
        merge_sort(array, mid+1, h);
        merge(array, l, mid, h);
    }
}

int main(void) {
    int size = 9;
    int array[] = {10,16,8,12,15,6,3,9,5};

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ,";
    }
    cout << endl;

    merge_sort(array, 0, size-1);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ,";
    }
    cout << endl;

    return 0;
}
