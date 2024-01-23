#include "PodArray.h"

PodArray::PodArray(){
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

PodArray::PodArray(PodArray& pa){
	podcasts = new Podcast*[MAX_PODS];
	for (int i =0 ; i < pa.numPods; ++i){
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}
	numPods = pa.numPods;

}


PodArray::~PodArray(){
	for (int i = 0; i < numPods; ++i){
		delete podcasts[i];
	}
	delete [] podcasts;
}

bool PodArray::addPodcast(Podcast* p){
	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
}

bool PodArray::removePodcast(const string& title){
	for(int i = 0; i < numPods; i++){
        if(podcasts[i]->matches(title)){
            delete podcasts[i];
            for(int j = i; j < numPods-1; j++){
                podcasts[i]=podcasts[i+1];
            }
            delete podcasts[numPods-1];
            numPods -= 1;
            return true;
        }
    }
    return false;
}

bool PodArray::getPodcast(const string& title, Podcast** pod){
	for(int i = 0; i < numPods; i++){
        if(podcasts[i]->matches(title)){
            *pod=new Podcast(*podcasts[i]) ;
            return true;
        }
    }
    return false;
}

bool PodArray::isFull(){
	return numPods >= MAX_PODS;
}

int PodArray::size(){
	return numPods;
}

bool PodArray::addEpisode(const string &podcast, const string &title, const string &content) {
    for(int i = 0; i < numPods; i++){
        if(podcasts[i]->matches(podcast)){
            podcasts[i]->addEpisode(title,content);
            return true;
        }
    }
    return false;
}

void PodArray::print(){
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
