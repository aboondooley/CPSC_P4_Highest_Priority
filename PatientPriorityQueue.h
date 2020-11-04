//
// Created by Alie Boon-Dooley on 11/1/2020.
// For Seattle University, CPSC 5005, P4.Triage
//

#ifndef PROJECT4_HIGHESTPRIORITY_PATIENTPRIORITYQUEUE_H
#define PROJECT4_HIGHESTPRIORITY_PATIENTPRIORITYQUEUE_H

#include <vector>
#include "Patient.h"
using namespace std;

class PatientPriorityQueue {

private:
    std::vector<Patient> data;

    void percolateUp(int index);
    void percolateDown(int index);
    void heapify();
    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;
    bool hasLeft(int parent) const;
    bool hasRight(int parent) const;

public:
    PatientPriorityQueue();
    const Patient &peek() const;
    Patient dequeue();
    void enqueue(Patient p);
    int size() const;

};


#endif //PROJECT4_HIGHESTPRIORITY_PATIENTPRIORITYQUEUE_H
