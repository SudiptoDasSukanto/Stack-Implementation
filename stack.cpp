#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node* next ;

    Node(int data){
        this->data = data ;
        this->next = NULL ;
    }
};

class Stack{
    Node* top ;

    public: 

    Stack(){
        top = NULL ;
    }

    bool isEmpty(){
        return top==NULL ;
    }

    void push(int d){
        Node* temp = new Node(d) ;

        if(!temp){
            cout << "Stack Overflow\n";
            exit(1) ;
        }

        temp->next = top ;
        top = temp ;
    }

    void pop(){
        Node* temp = top ;

         if(isEmpty()){
            cout << "Stack Underflow\n";
            exit(1);
        }
    
        top = top->next ;

        delete temp ;
        // free(temp) ;
    }


    int  peek(){
        Node* temp = top ;

        if(temp!=NULL)

        return temp->data ;

        else exit(1) ;

    }

    int Size(){

        int cnt=0 ;
        Node* temp = top ;

        if(temp==NULL){
            return 0 ;
        }

        while(temp!=NULL){
            cnt++ ;
            temp = temp->next ;
        }

        return cnt;
    }

    int Search(int data){

        Node* temp = top ;
        int p = 0 ;
        while(temp->data != data){
            p++ ;
            temp = temp->next ;
            if(temp==NULL){
                return -1 ;
            }
            
        }

        return p ;
        
    }

    void display(){
        Node* temp = top ;

         if(temp==NULL){
            cout << "Stack Underflow\n";
            exit(1);
        }


        while(temp!=NULL){

            cout << temp->data  <<  " ";
            temp = temp->next ;
        }
    }

};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.Size() << endl;

    s.display();

    cout << endl << s.Search(10) ;

    cout << endl << s.peek()  << endl;;
    s.pop();
    cout << s.Size() << endl;

    s.display() ;

    cout << endl << s.peek() << endl;

    if(s.isEmpty()) cout << "Empty\n";
    else cout << "No\n" ;

}