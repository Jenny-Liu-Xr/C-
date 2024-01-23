#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <string>

using namespace std;

class Subscriber {
    private:
        string name, creditcard;

    public:
        Subscriber(const string& name, const string& creditcard);
        bool matches(const string& name);
        void print();
};

#endif