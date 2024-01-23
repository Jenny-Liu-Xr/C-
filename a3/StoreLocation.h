#ifndef STORELOCATION_H
#define STORELOCATION_H
#include"Location.h"

class StoreLocation: public Location
{
    private:
        static const char code;
        static const int capacity;
        static int nextId;

    public:
        StoreLocation();
        ~StoreLocation();
        void setProduct(const string&);
        int getFreeSpace();
        virtual int getCapacity();
        virtual bool add(const string&, int);
        virtual bool remove(int);    
};

#endif