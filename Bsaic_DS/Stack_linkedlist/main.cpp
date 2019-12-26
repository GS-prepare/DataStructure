//
//  main.cpp
//  Stack_linkedlist
//
//  Created by Sun on 2019/12/26.
//  Copyright © 2019 Sun. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *link;
};
class stack_linked{
    private:
        int limit;
        Node *top, *del;
        Node *s, *d;
    public:
        stack_linked(){
            limit = 5 ;
        }
    
    //Main function (push, pop, display)
    void push(int data){
        if (isFull()){
            std::cout << "Stack Overflow." << endl;
            return;
        }else{
            Node *tmp = new Node();
            tmp->data = data;
            tmp->link = top;
            top = tmp ;
        }
    }
    
    void pop(){
        if (isEmpty()){
            std::cout << "Stack is empty." << endl;
            return;
        }else{
            del = top;
            top = top->link;
            std::cout << "deleted: " << del->data << endl;
            del = NULL;
        }
    }
    
    void display(){
        if (isEmpty()){
            std::cout << "Stack is empty." << endl;
            return;
        }else{
            reverse();
            while(top != NULL){
                std::cout << top->data << "->";
                top = top->link;
            }
            std::cout << "NULL" << endl;
        }
    }
    
    //Check function(isEmpty()? isFull()?)
    bool isEmpty(){
        return (top == NULL);
    }
    
    bool isFull(){
        int num = 0;
        s = top;
        while(top != NULL){
            top = top->link;
            num++;
        }
        top = s;
        
        return (num >= limit);
    }
    
    //others function(inverse linked-list)
    void reverse(){
        d = NULL;
        s = NULL;
        while(top != NULL){
            s = top->link;
            top->link = d;
            d = top;
            top = s;
        }
        top = d;
    }
};

int main(int argc, const char * argv[]) {
    int choice, data;
    stack_linked sl;
    
    //Implement
    do{
        std::cout << "1) Push in stack " ;
        std::cout << "2) Pop in stack " ;
        std::cout << "3) Display stack and Exit " << endl ;
        std::cin>>choice;
        
        switch(choice){
            case 1: {
                cout << "enter the element : ";
                cin >> data;
                sl.push(data);
                break;
            }
            case 2: {
                sl.pop();
                break;
                
            }
        }
    }while(choice != 3);
    
    
    sl.display();
 
    return 0;
}
