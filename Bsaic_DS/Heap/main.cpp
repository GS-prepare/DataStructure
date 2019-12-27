//
//  main.cpp
//  Heap
//
//  Created by Sun on 2019/12/27.
//  Copyright © 2019 Sun. All rights reserved.
//
// Create Max-Heap & Heap Sort

#include <iostream>
using namespace std;

void adjust(int tree[], int i, int n){
    int k, child_no ;
    k = tree[i];
    child_no = 2*i+1;
    
    while(child_no <= n){
        if (child_no < n){ //代表有右兒子
            //左、右兒子先互相比較
            if(tree[child_no] < tree[child_no+1]) child_no++;
            //max(左兒子、右兒子) 再跟父親比較
        }
        if(k >= tree[child_no]){
            break;
        }else{
            tree[child_no/2] = tree[child_no]; //兒子的值取代父親
            child_no = child_no * 2 + 1; //往下繼續adjust
        }
    }
    
    tree[child_no/2] = k;
}

void maxHeap_Create(int tree[], int n){
    for (int i = n/2-1; i>=0 ; i--){ // last parent node ->  root
        adjust(tree, i, n);
    }
}

int main(int argc, const char * argv[]) {
    int tree[11] = {8, 26, 5, 77, 1, 61, 11, 60, 15, 49, 19};
    int n = 11;
    //Establish the max-heap
    maxHeap_Create(tree,n);
    
    for(int i = 0;i < 11;i++){
        std::cout << tree[i] << " | " ;
    }
    
    return 0;
}
