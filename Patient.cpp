//
// Created by Alie Boon-Dooley on 11/1/2020.
// For Seattle University, CPSC 5005, P4.Triage
//

#include "Patient.h"
#include <string>

using namespace std;

int Patient::numPatients = 0;

Patient::Patient() {
    name = "";
    priorityCode = minimal;
    arrivalOrder = ++numPatients;

}

Patient::Patient(std::string name, Patient::Priority priorityCode) {
    this->name = name;
    this->priorityCode = priorityCode;
    this->arrivalOrder = ++numPatients;
}

std::string Patient::toString() const {
    return name + " { pri=" + enumToString(priorityCode) + ", arrive=" +
           to_string(arrivalOrder) + " }";;
}

void Patient::setName(std::string newName) {
    name = newName;
}

std::string Patient::getName() const {
    return name;
}

void Patient::setPriority(Patient::Priority newPriority) {
    priorityCode = newPriority;
}

Patient::Priority Patient::getPriority() const {
    return priorityCode;
}

int Patient::getArrivalOrder() const {
    return arrivalOrder;
}

int Patient::compareTo(Patient &other) const {
    if (this->priorityCode < other.priorityCode) {
        return -1;
    }
    if (this->priorityCode == other.priorityCode) {
        if (this->arrivalOrder < other.arrivalOrder) {
            return -1;
        }
    }
    return 1;
}

std::string Patient::enumToString(int val) {
    switch (val) {
        case 1:
            return "immediate";
        case 2:
            return "emergency";
        case 3:
            return "urgent";
        case 4:
            return "minimal";
        default:
            return "";
    }

}




