//
//  main.cpp
//  Bubble_Sort
//
//  Created by Sun on 2019/12/29.
//  Copyright © 2019 Sun. All rights reserved.
//

#include <iostream>
using namespace std;

void Bubble_Sort(int *arr, int n){
    for(int i=n-1; i>=1; i--){
        bool flag = false; //記錄當回合是否有SWAP
        for(int j=0; j<i; j++){ //兩兩比較
            if(arr[j]>arr[j+1]){ // 前面data > 後面data
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (flag == false) break; //No swap => 已排序完成
    }
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        std::cout << arr[i] << " | " ;
    }
    std::cout << endl;
}

int main(int argc, const char * argv[]) {
    int arr[6] = {12, 29, 20, 19, 1, 15};
    std::cout << "Original Data : ";
    printArray(arr,6);
    
    Bubble_Sort(arr,6);
    
    //Print Result
    std::cout << "Sorted Data : ";
    printArray(arr, 6);
    return 0;
}
