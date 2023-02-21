#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

    char data;
    Node* next ;

    Node(char data){
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

    void push(char d){
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

bool isbalance(Stack s ,string str){

    char ch ;

        for(int i=0 ; i<str.length() ; i++){

            ch = str[i] ;

            if(ch=='(' || ch=='{' || ch=='['){
                s.push(ch) ;
            
            }
            else if(ch==')' || ch=='}' || ch==']'){

                if(s.isEmpty()) {cout << 1 << endl;return false ;}

                if(ch == ')' && s.peek()!='(') {cout << 2 ;return false ;}

                if(ch == '}' && s.peek()!='{') {cout << 3 ;return false;}

                if(ch == ']' && s.peek()!='[') {cout << 4 ;return false;}

                else s.pop() ;

            }

        }

        if(s.isEmpty()) return true ;
        else return false; 

        
    }

int main(){
    Stack s;
  
    string str ;

    cin >> str ;
    int len = str.length();
    bool flag = true;
    
    flag = isbalance(s,str);

    if(flag == true ) cout << "Balanced" << endl;
    else cout << "ImBalanced "<< endl;


}