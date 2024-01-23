#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include "PodArray.h"
#include "Subscriber.h"
using namespace std;

class Network{
    private:
        string netname;
        PodArray *podarrays;
        Subscriber **subarrays;
        int numSubs;
    public:
        Network(string name);
        bool getPodcast(const string& podcast,Podcast** pod);
        bool getSubscriber(const string& name,Subscriber** sub);

        bool addPodcast(const string& podcast,const string& host);
        bool removePodcast(const string& title);
        bool addEpisode(const string& podcast,const string& title,const string& content);
        bool addSubscriber(const string& name,const string& creditcard);

        bool download(const string& subscriber,const string& podcast,Podcast**);  //sub==name  podcast==title
        bool stream(const string& subscriber,const string& podcast,int episode,Episode**);
        bool hasSubscriber(const string& name);

        void print();
};


#endif
