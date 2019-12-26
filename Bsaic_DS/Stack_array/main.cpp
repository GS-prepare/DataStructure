//
//  main.cpp
//  Stack_array
//
//  Created by Sun on 2019/12/26.
//  Copyright © 2019 Sun. All rights reserved.
//
// Implementing Stack using Arrays

#include <iostream>
using namespace std;

class stack_array{
private :
   
    
public:
  
    const int static  n = 5; // n = stack size(0~4)
    int arr[n]; //arr[]
    int top = -1; //No Data (initial)
    
    //Main Function (push, pop, display)
    void push(int data){
        if (isFull()) {
            std::cout << "Stack Overflow." << endl;
            return;
        }else{
            arr[++top] = data;
            std::cout << "Inserted : " << data << endl;
        }
    }
    
    void pop(){
        if (isEmpty()){
            std::cout << "Stack is empty." << endl;
            return;
        }else{
            std::cout << "Deleted : " << arr[top--] << endl;
        }
    }
    
    void display(){
        if (isEmpty()){
            std::cout << "Stack is empty." << endl;
            return;
        }else{
            std::cout << "Stack : " ;
            for(int i=0; i<=top; i++){
                std::cout << arr[i] <<  " | " ;
            }
            std::cout << " " << endl;
        }
    }
    
    //Check function (isEmpty? isFull?)
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top >= n-1);
    }
    
    
    
};

int main(int argc, const char * argv[]) {
    int choice, data;
    
    //create stack using array
    stack_array sa;
    
    //Implement
    do{
        std::cout << "1) Push in stack " ;
        std::cout << "2) Pop in stack " ;
        std::cout << "3) Display in stack " ;
        std::cout << "4) Exit " << endl;
        std::cin>>choice;
        
        switch(choice){
            case 1: {
                cout << "enter the element : ";
                cin >> data;
                sa.push(data);
                break;
            }
            case 2: {
                sa.pop();
                break;
                
            }
            case 3: {
                sa.display();
                break;
            }
        }
    }while(choice != 4);
    
   
    return 0;
}
