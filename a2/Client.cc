#include "Client.h"

Client::Client(const string &name) {
    this->name = name;
    local = new PodArray();
}
Client::~Client() {
    delete local;
}

bool Client::download(Network *network, const string &podcast) {
    if(local->isFull()){
        cout<<"Local space is already full"<<endl;
        return false;
    }
    Podcast *temp;
    if(network->download(name,podcast,&temp)){
        local->addPodcast(temp);
        return true;
    } else{
        cout<<"Download failed"<<endl;
        return false;
    }
}
bool Client::stream(Network *network, const string &podcast, int episode) {
    Episode *temp;
    if(network->stream(name,podcast,episode,&temp)){
        temp->play();
        return true;
    }
    return false;

}
void Client::playLocal(const string &podcast, int episode) {
    Podcast *temp;
    if(local->getPodcast(podcast,&temp)){
        Episode *ep;
        if(temp->getEpisode(episode,&ep)){
            ep->play();
        } else{
            cout<<"no such episode"<<endl;
        }

    } else{
        cout<<"no such podcast"<<endl;
    }

}