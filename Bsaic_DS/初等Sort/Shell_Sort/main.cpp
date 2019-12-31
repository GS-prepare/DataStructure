//
//  main.cpp
//  Shell_Sort
//
//  Created by Sun on 2019/12/30.
//  Copyright © 2019 Sun. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;


void Shell_Sort(int *arr, int n){
    bool flag; //是否有交換
    int span = floor(n/2); //第一回合 除2取floor
    while(span>=1){ //收斂到1停止
        do{
            flag = false;
            for(int i=0;i<n-span;i++){
                if(arr[i]>arr[i+span]){ //前者>後者
                    swap(arr[i], arr[i+span]);
                    flag = true;
                }
            }
        }while(flag == false);
        span = floor(span/2); //下一回合 再除2取floor
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
    
    Shell_Sort(arr,6);
    
    //Print Result
    std::cout << "Sorted Data : ";
    printArray(arr, 6);
    
    return 0;
}
