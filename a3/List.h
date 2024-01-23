#ifndef LIST_H
#define LIST_H

#include "Product.h"

class List
{
    private:
        class Node  {
            private:
                Product* data;
                Node *head;
                Node *foot;
            public:
                Node(Product* data):data(data){};
                Node* getHead(){return head;}
                Node* getFoot(){return foot;}
                void setFoot(Node* foot) {this->foot=foot;}
                void setHead(Node* head) {this->head=head;}
                Product* getData() {return data;}
        };
        Node *head;
    public:
        List();
        ~List();
        bool isEmpty();
        void findProduct(const string& name, Product** prod);
        void add(Product* prod);
        void print();
};

#endif
