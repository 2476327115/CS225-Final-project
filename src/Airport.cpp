#include "Airport.h"

// Constructor
<<<<<<< HEAD
=======
Airport::Airport(){
    id_ = 0;
    name_ = "";
    city_ = "";
    latitude_ = "";
    longitude_ = "";

}

>>>>>>> jinfan
Airport::Airport(int id, std::string name, std::string city, std::string latitude, std::string longitude) {
    id_ = id;
    name_ = name;
    city_ = city;
    latitude_ = latitude;
    longitude_ = longitude;
}

<<<<<<< HEAD
Airport::Airport(Airport &other) {
=======
Airport::Airport(const Airport& other){
>>>>>>> jinfan
    id_ = other.id_;
    name_ = other.name_;
    city_ = other.city_;
    latitude_ = other.latitude_;
    longitude_ = other.longitude_;
}

Airport Airport::operator=(const Airport & other) {
<<<<<<< HEAD

=======
    id_ = other.id_;
    name_ = other.name_;
    city_ = other.city_;
    latitude_ = other.latitude_;
    longitude_ = other.longitude_;
    return *this;
>>>>>>> jinfan
}
