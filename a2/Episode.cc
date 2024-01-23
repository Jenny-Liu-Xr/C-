#include"Episode.h"

Episode::Episode(const string& podcast, int number, const string& name, const string& content)
{
    this->podcast = podcast;
    this->number = number;
    this->name = name;
    this->content = content;
}

void Episode::play(){
    cout<<podcast<<" , "<<name<<" , "<<number<<" , "<<content<<endl;
}
/*
bool Episode::matches(const string& name) {
    return this->name==name;
}
*/
void Episode::print() {
    cout<<"podcast: "<< podcast<<endl;
    cout<<"number: "<< number<<endl;
    cout<<"name: "<< name<<endl;
    cout<<"content: "<< content<<endl;
}