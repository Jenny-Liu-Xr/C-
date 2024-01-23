#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode {
    private:
        string name, content, podcast;
        int number;

    public:
        Episode(const string& podcast, int number, const string& name, const string& content);
        void play();
        //bool Episode::matches(const string& name);
        void print();
};

#endif