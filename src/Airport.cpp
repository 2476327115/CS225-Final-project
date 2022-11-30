#include "Airport.h"

// Constructor
Airport::Airport(){
    id_ = 0;
    name_ = "";
    city_ = "";
    latitude_ = 0.0;
    longitude_ = 0.0;

}

<<<<<<< HEAD
Airport::Airport(int id, std::string name, std::string city, float latitude, float longitude) {
=======
Airport::Airport(int id, std::string name, std::string city, std::string country, double latitude, double longitude) {
>>>>>>> main
    id_ = id;
    name_ = name;
    city_ = city;
    country_ = country;
    latitude_ = latitude;
    longitude_ = longitude;
}

Airport::Airport(const Airport& other){
    id_ = other.id_;
    name_ = other.name_;
    city_ = other.city_;
    latitude_ = other.latitude_;
    longitude_ = other.longitude_;
}

bool Airport::operator==(const Airport & other) const{
    if(id_ != other.id_)return false;
    if(name_ != other.name_) return false;
    if(city_ != other.city_) return false;
    if(latitude_ != other.latitude_) return false;
    if(longitude_ != other.longitude_) return false;
    return true;

}

Airport Airport::operator=(const Airport & other) {
    id_ = other.id_;
    name_ = other.name_;
    city_ = other.city_;
    latitude_ = other.latitude_;
    longitude_ = other.longitude_;
    return *this;
}

int Airport::getID() {
    return id_;
}

std::string Airport::getName() {
    return name_;
}