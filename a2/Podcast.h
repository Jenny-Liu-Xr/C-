#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include"defs.h"
#include"Episode.h"
#include"Subscriber.h"

using namespace std;

class Podcast {
    private:
        string title, host;
        int numEps;
        Episode** episodes;

    public:
        Podcast(string title, string host);
        Podcast(const Podcast&);
        ~Podcast();
        string getTitle();
        string getHost();
        int getNumEpisodes();
        bool addEpisode(const string& title, const string& content);
        bool getEpisode(int index, Episode** ep);
        bool lessThan(Podcast& pod);
        bool matches(const string& title);
        void print();
};

#endif