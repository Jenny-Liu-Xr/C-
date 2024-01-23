#include "StoreLocation.h"
#include "defs.h"

int StoreLocation::nextId=1;
const int StoreLocation::capacity=SLOC_CAPACITY;
const char StoreLocation::code='A';

StoreLocation::StoreLocation():Location(code,nextId){
    nextId++;
}

StoreLocation::~StoreLocation(){}

void StoreLocation::setProduct(const string& product) {
    Location::setProduct(product);
}

int StoreLocation::getFreeSpace() {
    return capacity-getQuantity();
}

int StoreLocation::getCapacity() {
    return capacity;
}

bool StoreLocation::add(const string& product,int amount) {
    // if it`s available and it will fit then add amount to it and return true
    // else return false
    if((!isAvailable()&&getProduct()!=product)||getQuantity()+amount>capacity) return false;
    setProduct(product);
    setQuantity(getQuantity()+amount);
    return true;
}

bool StoreLocation::remove(int amount) {
    // return false when quantity less than parameter
    if(getQuantity()<amount) return false;
    setQuantity(getQuantity()-amount);
    return true;
}
