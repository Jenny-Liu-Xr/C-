#include"Subscriber.h"

Subscriber::Subscriber(const string& name, const string& creditcard){
    this->name = name;
    this->creditcard = creditcard;
}

bool Subscriber::matches(const string& name){
    if(this->name == name){
        return true;
    }
    return false;
}

void Subscriber::print(){
    cout<<"name "<<name<<endl;
    cout<<"creditcard "<<creditcard<<endl;
}