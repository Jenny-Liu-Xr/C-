#include "List.h"

List::List():head(NULL){
}

List::~List() {
    Node* curr=head;
    //  iterate and delete node
    while (curr!=NULL) {
        curr=curr->getFoot();
        delete head;
        head=curr;
    }
}

bool List::isEmpty() {
    return head!=NULL;
}

void List::findProduct(const string& name, Product** prod){
    Node *curr=head;
    *prod=NULL;
    // iterate and find the place
    while(curr)  {
        if(curr->getData()->getName()==name)  {
            *prod=curr->getData();
            break;
        }
        curr=curr->getFoot();
    }
}

void List::add(Product* prod) {
    // construct the new node
    Node* newNode=new Node(prod);
    // if list is empty then the new node become head
    if (head == NULL) {
        head=newNode;
        return;
    }
    // if prod less than head then it become new head
    if(head->getData()->getName() >= prod->getName()) {
        newNode->setFoot(head);
        head->setHead(newNode);
        head=newNode;
        return;
    }
    Node *curr=head,*last=NULL;
    // iterate and find the first one larger than prod
    while(curr&&curr->getData()->getName()<prod->getName()) {
        last=curr;
        curr=curr->getFoot();
    }
    last->setFoot(newNode);
    newNode->setHead(last);
    // if new node is not end
    if(curr) {
        curr->setHead(newNode); 
        newNode->setFoot(curr);
    }
}
void List::print()  {
    cout<<"List: ";
    Node* curr=head;
    // iterate and print node
    while(curr)  {
        cout<<curr->getData()->getName()<<' ';
        curr=curr->getFoot();
    }
    cout<<endl;
}