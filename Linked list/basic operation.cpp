#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void delete_node(Node* &head,int val)
{

    Node* temp = head;
    Node* prev = head;
    while(temp->data !=val){
        prev =temp;
        temp=temp->next;
    }
    if(temp->data == val){
        prev->next = temp->next;
    }
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(6);
    Node *temp = head;
    temp = temp->next;
    temp->next = new Node(7);
    temp = temp->next;
    temp->next = new Node(10);
    temp = temp->next;
    temp->next = new Node(12);
    delete_node(head,5);

    // Node* head = new Node;
    // head->data = 5;
    // head->next = new Node;
    // Node* temp = head;
    // temp = temp->next;
    // temp->data = 45;
    // temp->next = new Node;
    // temp = temp->next;

    // temp->data = 50;
    // temp->next=NULL;

    display(head);

    return 0;
}