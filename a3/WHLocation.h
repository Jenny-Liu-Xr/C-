#ifndef WHLOCATION_H
#define WHLOCATION_H
#include  "Location.h"

class WHLocation :public Location
{
    private:
        static const char code;
        static const int capacity;
        static int nextId;
    public:
        WHLocation();
        ~WHLocation();
        virtual int getCapacity();
        virtual bool add(const string&,int);
        virtual bool remove(int);
};


#endif