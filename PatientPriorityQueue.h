//
// Created by Alie Boon-Dooley on 11/1/2020.
// For Seattle University, CPSC 5005, P4.Triage
//

#ifndef PROJECT4_HIGHESTPRIORITY_PATIENTPRIORITYQUEUE_H
#define PROJECT4_HIGHESTPRIORITY_PATIENTPRIORITYQUEUE_H

#include <vector>
#include "Patient.h"

using namespace std;


/**
 *The PatientPriorityQueue class holds patient objects in the 'waiting room'
 * and keeps them in the order in which they must be seen based on their
 * priority level and how long they have been waiting.
 * The PPQ class acts like a MinHeap, in that the lowest numbers indicate the
 * highest priority level. Patients are called by priority level, and within
 * priority level, the higher priority goes to patients who have been waiting
 * the longest.
 * Clients can add patients to the queue (enqueue), and delete them from the
 * queue (dequeue) as well as peek at any member in the queue (peek(index))
 * as well as the first member in the queue (peek()). They can also see how
 * many patients are still waiting (size) and see if the waiting room is
 * empty (empty).
 */

class PatientPriorityQueue {
private:
    std::vector<Patient> data; // container for patients

    /**
     * Private helper
     * The value at data[index] may violate the heap invariants by being a
     * higher priority than it's ancestors.
     * If so, fix it by swapping with ancestors as necessary.
     * @param index of data that may have too high of a priority relative to
     * parent (and further ancestors)
     */
    void percolateUp(int index);

    /**
     * Private helper
     * The value at data[index] may violate the heap invariants by being a
     * lower priority than it's descendants
     * If so, fix it by swapping with descendents as necessary.
     * @param index of data that may be too low relative to parent (and other
     * descendents)
     */
    void percolateDown(int index);

    /**
     * Returns the parent's index
     * @param index of child
     * @return index of parent
     */
    int parent(int index) const;

    /**
     * Returns the index of the left child
     * @param index of the parent
     * @return index of the left child
     */
    int left(int index) const;

    /**
     * Returns the index of the lright child
     * @param index of the parent
     * @return index of the right child
     */
    int right(int index) const;

    /**
     * Returns whether the parent has a left child
     * @param parent index of the parent
     * @return true if the parent has a left child, false if not
     */
    bool hasLeft(int parent) const;

    /**
     * Returns whether the parent has a right child
     * @param parent index of the parent
     * @return true if the parent has a right child, false if not
     */
    bool hasRight(int parent) const;

public:

    /**
     * No arg constructor
     */
    PatientPriorityQueue();

    /**
     * Peeks at the first patient in the queue (highest priority)
     * @return a reference to the first object in the priority queue
     */
    const Patient &peek() const;

    /**
     * Peeks at the patient at the specified index
     * @param index of the patient to look at
     * @return a reference to the patient at the index
     */
    const Patient &peek(int index) const;

    /**
     * Pops off (returns and removes) the patient with the highest priority
     * who should be seen next
     * @return patient to be seen enxt
     */
    Patient dequeue();

    /**
     * Adds a new patient to the waiting room, in the correct order
     * @param p new patient to add
     */
    void enqueue(Patient p);

    /**
     * Get the number of patients in the waiting room
     * @return number of patients in the waiting room
     */
    int size() const;

    /**
     * Gets whether there is anyone in the waiting room/queue
     * @return true if there are patients waitin, false if not
     */
    bool empty() const;

};


#endif //PROJECT4_HIGHESTPRIORITY_PATIENTPRIORITYQUEUE_H
