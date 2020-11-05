//
// Created by Alie Boon-Dooley on 11/1/2020.
// For Seattle University, CPSC 5005, P4.Triage
//

#ifndef PROJECT4_HIGHESTPRIORITY_PATIENT_H
#define PROJECT4_HIGHESTPRIORITY_PATIENT_H

#include <string>

/**
 * The Patient Class creates individual patient objects which contain the
 * name and priority level of the patient in the waiting room, plus the order
 * which they arrived in the waiting room. The client can create patients, as
 * well as get their name, compare them to other patients, with respect to
 * when they should be seen, and print a string representation of them.
 * Patients can have four priority levels: immediate = 1, emergency = 2, urgent = 3, minimal = 4
 */

class Patient {
public:
    /**
     * Four levels of priority a patient can have
     */
    enum Priority {
        immediate = 1, emergency = 2, urgent = 3, minimal = 4
    };

    /**
     * No-arg constructor Constructor
     */
    Patient();

    /**
     * Argument ctor creates a patient with a name and priority level already
     * specified
     * @param name the patient's name, can have spaces
     * @param priorityCode priority level of the patient
     */
    Patient(std::string name, Priority priorityCode);

    /**
     * Returns a string containing the patients name
     * @return the patient's name
     */
    std::string getName() const;

    /**
     * Compares one patient to another to see who should be seen first
     * @param other the patient to compare this patient with
     * @return -1 if this patient should be first, 1 if the other patient
     * should be first
     */
    int compareTo(Patient &other) const;

    /**
     * Creates a print-able string that represents the patient, including
     * their name and priority level
     * @return string representation of the patient
     */
    std::string toString() const;


private:
    static int numPatients; // keeps track of the total number of patients
    std::string name; // the patient's name - can contain spaces, punctuation
    Priority priorityCode; // the patient's priority level
    int arrivalOrder; // arrival in which they arrived in ER waiting room

    /**
     * Private static helper function that prints out the priority level name
     * instead of the int that corresponds to the priority level name
     * @param val enum int value
     * @return enum priority level name
     */
    static std::string enumToString(int val);
};


#endif //PROJECT4_HIGHESTPRIORITY_PATIENT_H
