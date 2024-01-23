#include"Podcast.h"

Podcast::Podcast(string title, string host){
    this->title = title;
    this->host = host;
    this->numEps = 0;
    episodes = new Episode*[MAX_EPS];
}

Podcast::Podcast(const Podcast& p){
    this->title = p.title;
    this->host = p.host;
    this->numEps = p.numEps;
    for(int i = 0; i < p.numEps; i++){
        episodes[i] = new Episode(*p.episodes[i]);
    }
}

Podcast::~Podcast() {
    for(int i = 0; i < numEps; i++){
        delete episodes[i];
    }
    delete [] episodes;
}

string Podcast::getTitle(){
    return title;
}

string Podcast::getHost(){
    return host;
}

int Podcast::getNumEpisodes(){
    return numEps;
}

bool Podcast::addEpisode(const string& title, const string& content)
{
    if(numEps >= MAX_EPS){
        return false;
    } else {
        this->episodes[numEps] = new Episode(this->title, numEps+1, title, content);
        this->numEps += 1;
        return true;
    }
}

bool Podcast::getEpisode(int index, Episode** ep){
    if(index >= this->numEps){
        return false;
    } else {
        *ep = this->episodes[index];
        return true;
    }
}

bool Podcast::lessThan(Podcast &pod) {
    return this->title<=pod.title;
}

bool Podcast::matches(const string& title) {
    return this->title==title;
}

void Podcast::print() {
    cout<<"title: "<<title<<endl;
    cout<<"host: "<<host<<endl;
    cout<<"numEps: "<< numEps<<endl;
    for(int i=0;i<numEps;i++){
        episodes[i]->print();
    }
}