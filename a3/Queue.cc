#include "Queue.h"

Queue::Queue():head(NULL),tail(NULL) {
}

Queue::~Queue() {
    Node* curr=head;
    // iterate and delete node
    while (curr) {
        curr=curr->getFoot();
        delete head;
        head=curr;
    }
}

bool Queue::isEmpty() {
    return head==NULL;
}

void Queue::peekFirst(WHLocation** loc) {
    // if queue is empty assign NULL to loc 
    // else assign head`s data and update head
    if(head==NULL) {
        *loc=NULL;
    }else  {
        *loc=head->getData();
    }
}

void Queue::popFirst(WHLocation** loc) {
    // if queue is empty assign NULL to loc 
    //else assign head`s data and update head
    if(head==NULL) {
        *loc=NULL;
    }else  {
        *loc=head->getData();
        Node* tmp=head;
        head=head->getFoot();
        delete tmp;
        if(head==NULL) tail=NULL;
    }
}

void Queue::addLast(WHLocation* loc) {
    // if the queue is empty,assign loc to head and tail
    // else add it to the back of tail and update tail
    Node* last=new Node(loc);
    if(tail==NULL) {
        tail=head=last;
    }else {
        tail->setFoot(last);
        last->setHead(tail);
        tail=last;
    }
}

void Queue::print()  {
    cout<<"Queue: ";
    Node* curr=head;
    while(curr)  {
        cout<<curr->getData()->getProduct()<<' ';
        curr=curr->getFoot();
    }
    cout<<endl;
}