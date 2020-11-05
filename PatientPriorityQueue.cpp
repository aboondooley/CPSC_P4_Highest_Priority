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

bool PatientPriorityQueue::empty() const {
    return data.empty();
}

const Patient &PatientPriorityQueue::peek() const {
    if (empty())
        throw invalid_argument("empty queue");
    return data[0];
}

const Patient &PatientPriorityQueue::peek(int index) const {
    if (empty())
        throw invalid_argument("empty queue");
    if (index >= size()) {
        throw invalid_argument("index out of bounds");
    }
    return data[index];
}

void PatientPriorityQueue::enqueue(Patient p) {
    data.push_back(p);
    percolateUp(size() - 1);
}

Patient PatientPriorityQueue::dequeue() {
    Patient ret = peek();
    data[0] = data[size() - 1];
    data.pop_back();
    percolateDown(0);
    return ret;
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

void PatientPriorityQueue::percolateDown(int index) {
    if (hasLeft(index)) {
        int child = left(index);
        if (hasRight(index)) {
            int r = right(index);
            if (data[r].compareTo(data[child]) == -1) {
                child = r;
            }
        }
        if (data[child].compareTo(data[index]) == -1) {
            swap(data[child], data[index]);
            percolateDown(child);
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
















