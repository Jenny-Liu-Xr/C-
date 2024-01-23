#include "WHLocation.h"
#include "defs.h"

int WHLocation::nextId=1;
const int WHLocation::capacity=WHLOC_CAPACITY;
const char WHLocation::code='A';

WHLocation::WHLocation():Location(code,nextId){
    nextId++;
}

WHLocation::~WHLocation(){}

int WHLocation::getCapacity() {
    return capacity;
}

bool WHLocation::add(const string& product,int amount) {
    // if it`s available and it will fit then add amount to it and return true
    // else return false
    if((!isAvailable()&&getProduct()!=product)||getQuantity()+amount>capacity) return false;
    setProduct(product);
    setQuantity(getQuantity()+amount);
    return true;
}

bool WHLocation::remove(int amount) {
    // return false when quantity less than parameter
    if(getQuantity()<amount) return false;
    setQuantity(getQuantity()-amount);
    // if empty assign none to it
    if(getQuantity()==0) setNONE();
    return true;
}
