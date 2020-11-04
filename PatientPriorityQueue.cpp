//
// Created by Alie Boon-Dooley on 11/1/2020.
// For Seattle University, CPSC 5005, P4.Triage
//

#include "PatientPriorityQueue.h"
#include <vector>
#include <stdexcept>
using namespace std;

PatientPriorityQueue::PatientPriorityQueue() {}

int PatientPriorityQueue::size() const {
    return data.size();
}

void PatientPriorityQueue::enqueue(Patient p) {
    data.push_back(p);
    percolateUp(size() - 1);
}

void PatientPriorityQueue::percolateUp(int index) {
    if (index > 0) {
        int p = parent(index);
        if (data[index].compareTo(data[p]) == -1) {
            swap(data[index], data[p]);
            percolateUp(p);
        }
    }
}

int PatientPriorityQueue::parent(int index) const {
    return (index - 1) / 2;
}

int PatientPriorityQueue::left(int index) const {
    return index * 2 + 1;
}

int PatientPriorityQueue::right(int index) const {
    return left(index) + 1;
}

bool PatientPriorityQueue::hasLeft(int parent) const {
    return left(parent) < size();
}

bool PatientPriorityQueue::hasRight(int parent) const {
    return right(parent) < size();
}






