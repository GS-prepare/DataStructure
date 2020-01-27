//
//  main.cpp
//  Merge_Sort
//
//  Created by Sun on 2020/1/27.
//  Copyright © 2020 Sun. All rights reserved.
//

#include <iostream>
#include "cmath"
#include <limits>
using namespace std;



void Merge(int arr[], int L, int R, int m) {
    int n1 = m - L + 1;
    int n2 = R - m;
    
    //copy arr[] to Larr & Rarr
    int* Larr = new int[n1];
    for (int i = 0; i < n1; i++) {
        Larr[i] = arr[L+i];
    }
    
    int* Rarr = new int[n2];
    for (int i = 0; i < n2; i++) {
        Rarr[i] = arr[i+m+1];
    }
    
    Larr[n1] = std::numeric_limits<int>::max();
    Rarr[n2] = std::numeric_limits<int>::max();
    
    int i = 0, j = 0;
    for(int k = L; k <= R; k++){
        if(Larr[i]<=Rarr[j]){
            arr[k] = Larr[i];
            i++;
        }else{
            arr[k] = Rarr[j];
            j++;
        }
    }
}

void Merge_Sort(int arr[], int L, int R) {
    if (L < R) {
        int m = floor((L + R) / 2);
        Merge_Sort(arr, L, m);  //遞迴排序子陣列 A[L...m]
        Merge_Sort(arr, m + 1, R); //遞迴排序子陣列 A[m+1...R]
        Merge(arr, L, R, m);  //子陣列合併 T(n) = O(n)
    }
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        std::cout << arr[i] << " | " ;
    }
    std::cout << endl;
}

int main() {
    int arr[9] = {23, 3, 33, 1, 58, 18, 60, 45, 15};
    std::cout << "Original Data : ";
    printArray(arr,9);
    
    cout << endl;
    Merge_Sort(arr, 0, 8);
    //Print Result
    std::cout << "Sorted Data : ";
    printArray(arr, 9);
   
    return 0;
}


