#include<iostream>
#include<climits>
using namespace std;

void swap (int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *array, int l, int  h) {
	int pivot = array[l];
	int i = l;
	int j = h;

    while  (i < j) {
		do{
			i++;
        } while (array[i] <= pivot);
		cout << "i:" << i <<", ";
        do {
		    j--;
		} while (array[j] > pivot);
		cout << "j:" << j << ", ";
		if (i < j) {
		    swap(&array[i], &array[j]);
		}
    }
    //swap old pivot with new  pivot
    swap(&array[l], &array[j]);

    return j;
}

void quick_sort(int *array, int l, int h) {
    int pivot;
    cout << "quick sort call for l,h :" << l << " ,"<< h << endl;
	if (l < h) {
		pivot = partition(array, l, h);
		cout << "pivot: " << pivot << endl;
		quick_sort(array, l, pivot);
		quick_sort(array, pivot+1, h);
    }
}

int main() {
	int size = 9;
	int array[] = {10,16,8,12,15,6,3,9,5,INT_MAX};
	for (int i = 0; i < size; i++) {
		cout << array[i] << ", ";
    }
    cout << endl;
    quick_sort(array,0,size);
    for (int i = 0; i < size; i++) {
		cout << array[i] << ", ";
    }
	return 0;
}


