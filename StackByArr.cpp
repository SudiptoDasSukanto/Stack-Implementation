#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:

    int *arr ;
    int size ;
    int top;

    Stack(int size){
        this->size = size ;
        arr = new int[size] ;
        top = -1 ;
    }

    void push(int data){
        if(size-top>1){
            top++ ;
            arr[top] = data ;
        }
        else cout << "Stack overFlow\n";
    }

    void pop(){
        if(top>=0) top--;
        else cout << "Stack Underflow" << endl;
    }

    int peek(){
        if(top>=0) return arr[top] ;
        else cout << "Stack is Empty\n" ;

        return -1;
    }

    bool isEmpty(){
        if(top==-1) return true ;
        else return false;
    }

    void display(){
        int temp = top ;

        if(temp==-1) {
            cout << "Stack empty" << endl;
            return;
        }
        while(temp>-1){
            cout << arr[temp] << " " ;
            temp-- ;
        }cout << endl;
    }

    int Size(){
        return top+1 ;
    }
};

int main(){
    
    Stack st(4) ;
    st.push(1) ;
    st.push(2) ;
    st.push(3) ;
    
    st.display();
    cout << "Size : " << st.Size()<< endl;

    st.pop();
    st.display();

    cout << st.peek() << endl;

    cout << st.isEmpty()<< endl;

    cout << "Size : " << st.Size()<< endl;

}