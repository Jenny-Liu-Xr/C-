#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>
#include "defs.h"

using namespace std;

class Location {
    private:
        static const string NONE;
        string id;
        string product;
        int quantity;
    public:
        Location(char,int);
        virtual ~Location();
        bool isEmpty();
        bool isAvailable();
        void print();
        void setProduct(const string&);
        void setNONE();
        /* getter */
        int getQuantity();
        void setQuantity(int);
        string getId();
        string getProduct();
        /* virtual functions */
        virtual int getCapacity()=0;
        virtual bool add(const string&,int)=0;
        virtual bool remove(int)=0;
};

#endif