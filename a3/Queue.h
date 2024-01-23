#ifndef QUEUE_H
#define QUEUE_H

#include "WHLocation.h"
class Queue
{
    private:
        class Node  {
            private:
                WHLocation* data;
                Node *head;
                Node *foot;
            public:
                Node(WHLocation* data):data(data),head(NULL),foot(NULL){};
                Node* getHead(){return head;}
                Node* getFoot(){return foot;}
                void setFoot(Node* foot) {this->foot=foot;}
                void setHead(Node* head) {this->head=head;}
                WHLocation* getData() {return data;}
        };
        Node *head,*tail;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void peekFirst(WHLocation** loc);
        void popFirst(WHLocation** loc);
        void addLast(WHLocation* loc);
        void print();
};

#endif