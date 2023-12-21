#include <iostream>
#include <stdlib.h>
using namespace std;

int linear_search(int arr[],int lengh, int key) {
    for (int i = 0; i <= lengh - 1; i++) {
        if(arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int binary_search(int arr[],int low, int high, int key){
    int mid;
    // Itereate until reach to the end of array
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(key == arr[mid]) return mid;
        if(key > arr[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int del(int arr[], int length, int key){
    int index = binary_search(arr, 0, length - 1, key);

    if (index == -1) {
    cout << "item not found!";
    return length;
    }

    for (int i = index; i <= length -2; i++) {
        arr[i] = arr[i + 1];
    }

    return length - 1;   // 1,2,3,4,5,6,7,8,9,10  (6) 
    // 1,2,3,4,5,7,8,9,10,10
}

int insert_unsorted(int array[], int length, int num_items, int key) {
    if (length <= num_items) {
        return num_items;
    }

    array[num_items] = key;
    return num_items + 1;
}

int insert_sorted(int array[], int length, int num_items, int key) {
    if (length <= num_items) {
        return num_items;
    }

    int i;
    for (i = num_items - 1; (i > 0 && array[i] > key); i--) {
        array[i + 1] = array[i];
    }

    array[i + i] = key;

    return num_items + 1;
}

void merge_sorted(int a[], int b[], int num_a, int num_b){
    int i = num_b;
    int j = 0;
    int k = 0;

    while (k < (num_a + num_b)) {
        if((i < (num_a + num_b) && a[i] <= b[j]) || j == num_b) {
            a[k] = a[i];
            k++;
            i++;
        } else {
            a[k] = b[j];
            k++;
            j++;
        }
    }
}

int find_povit(int arr[], int low, int high) {
    if (high < low) return -1;
    if (high == low) return low; // Only 1 index available
    int mid = (low + high) / 2;

    if (mid < high && arr[mid] > arr[mid + 1]) {
        return mid;
    }

    if (mid > low && arr[mid] < arr [mid -1]) {
       return mid -1;
    }

    if (arr[low] >= arr[mid]) {
        find_povit(arr, low, mid - 1);
    }

    return find_povit(arr, mid - 1, high);
}

int binary_search_unsorted(int arr[], int num, int key) {
    int pivot = find_povit(arr, 0, num - 1);

    if (pivot == -1) binary_search(arr, 0, num - 1, key);

    if(arr[pivot] == key) return pivot;   

    if(arr[0] <= key) return binary_search(arr, 0, pivot - 1, key);

    return binary_search(arr, pivot - 1, num - 1, key);
}