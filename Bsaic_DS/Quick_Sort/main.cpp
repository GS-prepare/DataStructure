//
//  main.cpp
//  Quick_Sort
//
//  Created by Sun on 2019/12/31.
//  Copyright © 2019 Sun. All rights reserved.
//

#include <iostream>
using namespace std;

void Quick_Sort(int arr[], int L, int R){
    if(L<R){
        int i = L, j = R+1, pivot = arr[L]; //initial
        do{
            do i++; while(arr[i] < pivot); // 找陣列資料中 ≥pivot 的值
            do j--; while(arr[j] > pivot); // 找陣列資料中 ≤pivot 的值
            if(i<j) swap(arr[i], arr[j]); // i,j 交錯時，資料交換
        }while(i<j);
        swap(arr[L], arr[j]); //將pivot值交換到正確的位置上
        Quick_Sort(arr, L, j-1); //recursion 解左半邊
        Quick_Sort(arr, j+1, R); //recursion 解右半邊
    }
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        std::cout << arr[i] << " | " ;
    }
    std::cout << endl;
}

int main(int argc, const char * argv[]) {
    int arr[9] = {23, 3, 33, 1, 58, 18, 60, 45, 15};
    std::cout << "Original Data : ";
    printArray(arr,9);
    
    //Using Divide and Conquar
    Quick_Sort(arr,0,8);
    
    //Print Result
    std::cout << "Sorted Data : ";
    printArray(arr, 9);
    return 0;
}
