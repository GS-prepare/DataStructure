//
//  main.cpp
//  Selection_Sort
//
//  Created by Sun on 2019/12/29.
//  Copyright © 2019 Sun. All rights reserved.
//

#include <iostream>
using namespace std;

void Selection_Sort(int *arr, int n){
    for(int i=0;i<=n-1;i++){ //從arr[0]開始與後面的值比較，共做n-1回合
        int tmp = i;
        for(int j = i+1; j<n; j++){ //arr[i+1] ~ arr[n-1] 比大小
            if(arr[j] < arr[tmp]) tmp = j; //將較小的值的index暫存到tmp
        }
        swap(arr[i], arr[tmp]); 
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
    
    Selection_Sort(arr,6);
    
    //Print Result
    std::cout << "Sorted Data : ";
    printArray(arr, 6);
    return 0;
}
