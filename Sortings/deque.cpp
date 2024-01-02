#include<iostream>
using namespace std;
class Deque{
    int a[4];
    int front;
    int rear;
    public:
    Deque(){
        front = -1;
        rear = -1;
    }
    void insertatfront();
    void insertatback();
    void removefromfront();
    void removefromback();
    void gefront();
    void gerear();
    void display();
};
void Deque::display(){
    if(rear == -1){
        cout<<"Queue is empty\n";
    }
    else{
    int dum = front;
    int i;
    for (i = front; i != rear; i = (i + 1) % 4){
        cout << a[i]<<" -} ";}
        cout<<a[i]<<" -} ";
    cout<<"NULL\n";

}
}
void Deque::insertatback(){
    int ch;
    cout<<"Enter the integer\n";
    cin>>ch;
    if(front == -1 && rear == -1){
        front ++;
        rear ++;
        a[front] = ch;
    }
    else if(front == (rear+1)%4){
        cout<<"Overflow\n";
    }
    else{
        rear = (rear+1)%4;
        a[rear] = ch;
    }
}
void Deque::removefromfront(){
    if(front == -1 && rear == -1){
        cout<<"Underflow\n";
    }
    else{
        if(front == rear){
            front =-1;
            rear = -1;
        }
        else{
            front = (front+1)%4;
        }
    }
}
void Deque::removefromback(){
    if(front == -1 && rear ==-1){
        cout<<"Underflow\n";
    }
    else{
        if(rear == front){
            front =-1;
            rear = -1;
        }
        else{
            rear = (rear+3)%4;
        }
    }
}
void Deque::insertatfront(){
    cout<<"Enter the integer\n";
    int ch;
    cin>>ch;
    if(front == -1 && rear == -1){
        front ++;
        rear++;
        a[front] = ch;
    }
    else{
        if(rear == (front+3)%4){
            cout<<"Overflow\n";
        }
        else{
            front = (front+3)%4;
            a[front] = ch;
        }
    }
}
void Deque::gefront(){
    if(front == -1 && rear == -1){
        cout<<"Deque is empty\n";
    }
    else{
        cout<<"The top element is\n";
        cout<<a[front]<<"\n";
    }
}
void Deque::gerear(){
    if(front == -1 && rear == -1){
        cout<<"Deque is empty\n";
    }
    else{
        cout<<"The rear element is\n";
        cout<<a[rear]<<"\n";
    }
}
int main(){
    Deque d1;
    bool flag = true;
    while(flag){
    cout<<"------MENU------\n";
    cout<<"1.Enter the elment in front\n";
    cout<<"2.Enter the elment in the back\n";
    cout<<"3.Delete from the front \n";
    cout<<"4.Delete from the back\n";
    cout<<"5.Get the top Element\n";
    cout<<"6.Get the back element \n";
    cout<<"7.Display data\n";
    cout<<"8.Exit\n";
    cout<<"Enter the correct choice number\n";
    int ch;
    cin>>ch;
    switch (ch){
        case 1:{
            d1.insertatfront();
            break;
        }
        case 2:{
            d1.insertatback();
            break;
        }
        case 3:{
            d1.removefromfront();
            break;
        }
        case 4:{
            d1.removefromback();
            break;
        }
        case 5:{
            d1.gefront();
            break;
        }
        case 6:{
            d1.gerear();
            break;
        }
        case 7:{
            d1.display();
            break;
        }
        case 8:{
            flag = false;
            break;
        }
        default :{
            cout<<"Enter the correct choice number\n";
            break;
        }
    }
    }
    return 0;
}
