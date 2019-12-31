//
//  main.cpp
//  Insertion_Sort
//
//  Created by Sun on 2019/12/29.
//  Copyright © 2019 Sun. All rights reserved.
//

#include <iostream>
using namespace std;

void Insert(int key, int *arr, int j){
    while (key < arr[j]) { // 欲插入值 < 前面資料
        arr[j+1] = arr[j];
        j = j - 1;
    }
    arr[j+1] = key ;
}

void Insertion_Sort(int *arr, int n){
    for(int i = 1; i < n; i++){
        Insert(arr[i], arr, i-1); //欲插入的值, 陣列, 前面已排序的資料
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
    
    //將array內的資料一筆一筆的插入，並且同時向前面比較
    Insertion_Sort(arr,6);
    
    //Print Result
    std::cout << "Sorted Data : ";
    printArray(arr, 6);
    return 0;
}
