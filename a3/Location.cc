#include "Location.h"

const string Location::NONE="Empty";

Location::Location(char code,int number):id(string(1,code)+to_string(number)),product(NONE),quantity(0) {
}

Location::~Location(){}

int Location::getQuantity(){
    return quantity;
}

void Location::setQuantity(int amount){
    quantity=amount;
}

string Location::getId(){
    return id;
}
string Location::getProduct(){
    return product;
}

bool Location::isEmpty() {
    return quantity==0;
}

bool Location::isAvailable() {
    return product==NONE;
}

void Location::print() {
    cout<<"Location: "<<id<<" product:\""<<product<<"\" quantity:"<<quantity<<endl;
}

void Location::setProduct(const string& product) {
    this->product=product;
}

void Location::setNONE() {
    product=NONE;
}