//Description : Merge Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

void merging(int arr[], int l, int h, int m) {
    int N1 = m - l + 1;                 //Left Array Size     
    int N2 = h - m;                     //Right Array Size
    int left[N1];                         
    int right[N2];
    for (int i = 0; i < N1; i++) {
        left[i] = arr[l + i];          //Copy elements to left array
    }
    for (int j = 0; j < N2; j++) {
        right[j] = arr[m + 1 + j];    //Copy elements to right array
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < N1 && j < N2) {       //Inserting back the elements from left and right array
        if (left[i] <= right[j]) {   //If left element is smaller than the right one then we push 
            arr[k++] = left[i++];    //left element to our main array(arr)   
        } else {
            arr[k++] = right[j++];   //else we push right element to the main array
        }
    }
    for (; i < N1; i++) {          
        arr[k++] = left[i];         
    }
    for (; j < N2; j++) {
        arr[k++] = right[j];
    }
    return;
}

void merge_sort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + ((h - l) / 2));
        merge_sort(arr, l, mid);          
        merge_sort(arr, mid + 1, h);      
        merging(arr, l, h, mid);          
    }
    return;
}

int main() {
    int n;

    cout << "Enter length of array: "; 
    cin >> n;

    int items[n];

    cout << "Enter values: "; 
    for(int i = 0; i < n; i++) {
        cin >> items[i];
    }

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    merge_sort(items, 0, n);

    cout << "After sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";

    return 0;
}
