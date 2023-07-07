#include<iostream>
#include "node.h"
using namespace std;



class SLL{
    public:
    Node* head;
    SLL();
    void insertFirst(int data);
    void print();
    void insertLast(int data);
    void Delete(int data);
    Node* search(int data);

};
SLL::SLL(){
    this->head=NULL;
}

Node* SLL::search(int value){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==value){
            return temp;
        }
        temp=temp->next;
    }
    
    return NULL;
}
void SLL::insertLast(int data){
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;

}
void SLL::insertFirst(int data){
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    
    n->next=head;
    head=n;
}
void SLL::Delete(int value){
   
    Node* temp=head;
    if(temp->data==value){
        head=temp->next;
        return;
    }

    while (temp->next!=NULL)
    {
        if(temp->next->data==value){
            temp->next=temp->next->next;
            return;
        }
        
        temp=temp->next;
    }
    while(temp!=NULL){
        if(temp->next->data==value){
            temp->next=NULL;
        }
        temp=temp->next;
    }

    


    
    
}

void SLL::print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}


int main(){
    SLL s;
    s.insertLast(5);
    s.insertLast(7);
    s.insertLast(9);
    s.insertFirst(1);
    s.print();

    s.Delete(1);
    
   
    s.print();
    Node* n=s.search(9);
    if(n!=NULL){
        
        cout<<n->data<<endl;
    }
    else cout<<"Not Found"<<endl;
}

