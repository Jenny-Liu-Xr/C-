#include "Network.h"

Network::Network(string name) {
    netname=name;
    podarrays=new PodArray();
    subarrays=new Subscriber*[MAX_SUBS];
    numSubs=0;
}

bool Network::getPodcast(const string &podcast, Podcast **pod) {
    return podarrays->getPodcast(podcast,pod);
}

bool Network::getSubscriber(const string &name, Subscriber **sub) {
    for(int i = 0; i < numSubs; i++){
        if(subarrays[i]->matches(name)){
            *sub = subarrays[i];
            return true;
        }
    }
    cout<<"no such subscriber"<<endl;
    return false;
}

bool Network::addPodcast(const string& podcast, const string& host) {
    return podarrays->addPodcast(new Podcast(podcast,host));
}
bool Network::removePodcast(const string &title) {
    return podarrays->removePodcast(title);
}
bool Network::addEpisode(const string &podcast, const string &title, const string &content) {
    return podarrays->addEpisode(podcast,title,content);
}
bool Network::addSubscriber(const string &name, const string &creditcard) {
    if( numSubs >= MAX_SUBS) return false;
    subarrays[numSubs++] = new Subscriber(name, creditcard);
    return true;
}
bool Network::download(const string &subscriber, const string &podcast, Podcast ** pod) {
    if(!hasSubscriber(subscriber)){
        return false;
    }
    if(podarrays->getPodcast(podcast,pod)){
        return true;
    } else{
        cout<<"no such podcast"<<endl;
        return false;
    }
}
bool Network::stream(const string &subscriber, const string &podcast, int episode, Episode ** ep) {
    if(!hasSubscriber(subscriber)){
        return false;
    }
    Podcast *temp;
    if(podarrays->getPodcast(podcast,&temp)){
        if(temp->getEpisode(episode,ep)){
            return true;
        } else {
            cout<<"no such episode"<<endl;
            return false;
        }
    } else {
        cout<<"no such podcast"<<endl;
        return false;
    }
}

bool Network::hasSubscriber(const string &name) {
    for(int i = 0; i < numSubs; i++){
        if(subarrays[i]->matches(name)){
            return true;
        }
    }
    cout<<"no such subscriber"<<endl;
    return false;
}

void Network::print() {
    cout<<"netname : "<<netname<<endl;

    cout<<"podarrays---------------------------podarrays"<<endl;
    podarrays->print();
    cout<<"\n\n";
    cout<<"subarrays---------------------------subarrays"<<endl;
    for(int i = 0; i < numSubs; i++){
        subarrays[i]->print();
    }
    cout<<"\n\n";


}