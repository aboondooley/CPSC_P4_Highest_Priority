//
// Created by Alie Boon-Dooley on 11/1/2020.
// For Seattle University, CPSC 5005, P4.Triage
//

#ifndef PROJECT4_HIGHESTPRIORITY_PATIENT_H
#define PROJECT4_HIGHESTPRIORITY_PATIENT_H

#include <string>



class Patient {
public:
    enum Priority {
        immediate = 1, emergency = 2, urgent = 3, minimal = 4
    };
    Patient();
    Patient(std::string name, Priority priorityCode);
    std::string getName() const;
    void setName(std::string newName);
    Priority getPriority() const;
    void setPriority(Priority newPriority);
    int getArrivalOrder() const;
    int compareTo(Patient &other) const;
    std::string toString() const;
    static std::string enumToString(int val);

private:
    static int numPatients;
    std::string name;
    Priority priorityCode;
    int arrivalOrder;
};



#endif //PROJECT4_HIGHESTPRIORITY_PATIENT_H
