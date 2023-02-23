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
        //free(temp) ;

    }


    char  peek(){

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

    int Search(char data){

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

int prec(char ch){
    if(ch == '^') return 3 ;
    else if(ch == '*' || ch == '/') return 2 ;
    else if(ch == '+' || ch == '-') return 1 ;
    else return -1 ;
}


string InfinixTOPostfix(Stack s , string str){

    int len = str.length() ;
    char ch ; 
    string result  ;
    

    for(int i=0 ; i<len ; i++){
        ch = str[i] ;
        
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            result+=ch ;
        }
        else if(ch == '('){
            s.push(ch) ;
        }else if(ch == ')'){
            while(s.peek()!='('){
                result+=s.peek() ;
                s.pop();
            }

            s.pop() ;
        }else{

            while(!s.isEmpty() && prec(ch) <= prec(s.peek()) ){
                result+=s.peek() ;
                s.pop();
            }

            s.push(ch) ;
        }
    }

    while(!s.isEmpty()){
        result+=s.peek();
        s.pop();
    }

    return result;
}

int main(){

    Stack s;
  
    string str ;

    cin >> str ;

    string ans = InfinixTOPostfix(s,str);
    cout << ans << endl;


}