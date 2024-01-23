#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "Network.h"
using namespace std;

class Client{
    private:
        string name;
        PodArray *local;
    public:
        Client(const string& name);

        ~Client();

        bool download(Network* network,const string& podcast);
        bool stream(Network* network,const string& podcast,int episode);
        void playLocal(const string& podcast,int episode);
};

#endif
