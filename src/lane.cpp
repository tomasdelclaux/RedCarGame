#include "lane.h"

bool Lane::getDirection(){
    return direction;
}

int Lane::getLaneRefx(){
    return laneRefx;
}

std::list<Vehicle> &Lane::getVehicles(){
    return vehicles;
}

void Lane::updatePositions(){
    for (auto &vehicle : vehicles){
        if (!this->getDirection()){
            vehicle.y += vehicle.velocity()*vehicle.getAcceleration()*2;
        }
        else {
            vehicle.y += vehicle.velocity()*vehicle.getAcceleration();
        }
    }
}

void Lane::addVehicle(){
    if (vehicles.size() > 0 && vehicles.back().y <= 180){
        return;
    }
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<std::mt19937::result_type> probability(1,100);
    if (probability(engine) <= PNewVehicle){
        PNewVehicle ++;
        if (probability(engine) < PWhatVehicle['T']){
            vehicles.emplace_back(Vehicle(truck));
        }
        else if (probability(engine) < PWhatVehicle['G']){
            vehicles.emplace_back(Vehicle(gTruck));
        }
        else if (probability(engine) < PWhatVehicle['B']){
            vehicles.emplace_back(Vehicle(blue));
        }
    }
};

void Lane::removeVehicles(){
    auto end = this->laneHeight;
    vehicles.remove_if([end] (auto &i) { return i.y > end;});
}

