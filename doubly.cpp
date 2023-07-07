#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class doubly{
    public:
    Node* head;
    doubly();
    void print();
    void insertLast(int data);
    void insertFirst(int data);
    void Delete(int data);
    Node* search(int data);
    void insertAfterOne(int value,int to_insert);

};
doubly::doubly(){
    this->head=NULL;
}

Node* doubly::search(int value){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==value){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void doubly::print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
void doubly::insertLast(int data){
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
    n->prev=temp;
}
void doubly::insertFirst(int data){
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head->prev=n;
    head=n;
    
}
void doubly::Delete(int value){
    Node* temp=head;
    if(temp->data==value){
        head=temp->next;
        return;
    }
    while(temp->next!=NULL){
        if(temp->next->data==value){
            
            temp->next=NULL;
            return;
        }
        temp=temp->next;
    }
    while(temp->next!=NULL){
        if(temp->next->data==value){
            temp->next=temp->next->next;
            temp->next->next->prev=temp;
            return;
        }
        temp=temp->next;
    }

    
}
void doubly::insertAfterOne(int value,int to_insert){
    Node* n= new Node(to_insert);
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==value){
            n->next=temp->next;
            temp->next->prev=n;

            temp->next=n;
            n->prev=temp;
        }
        temp=temp->next;
    }
    
}


int main(){
    doubly d;
    // for(int i=0;i<3;i++){
    //     int n;
    //     cin>>n;
    //     d.insertLast(n);
    // }
    d.insertLast(1);
    d.insertLast(2);
    d.insertLast(3);
    d.insertFirst(5);
    d.insertFirst(4);
    d.print();
    d.Delete(3);
    cout<<endl;
    d.print();
    d.insertAfterOne(5,10);
    cout<<endl;
    d.print();
    Node* n=d.search(3);
    if(n!=NULL){
        cout<<endl<<"Search result: "<<n->data<<endl;
    }
    else cout<<endl<<"Not Found"<<endl;

}
