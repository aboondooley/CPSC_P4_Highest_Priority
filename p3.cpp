//
// Created by Kevin Lundeen on 10/21/20.
// For Seattle University, CPSC 5005, P4.Triage
//


#include <fstream>
#include <iostream>
#include <string>
#include "PatientPriorityQueue.h"
#include "Patient.h"

using namespace std;

/**
 * Prints help menu.
 */
void help() {
    cout << "add <priority-code> <patient-name>" << endl
         << "            Adds the patient to the triage system." << endl
         << "            <priority-code> must be one of the 4 accepted priority codes:"
         << endl
         << "                1. immediate 2. emergency 3. urgent 4. minimal"
         << endl
         << "            <patient-name>: patient's full legal name (may contain spaces)"
         << endl
         << "next        Announces the patient to be seen next. Takes into account the"
         << endl
         << "            type of emergency and the patient's arrival order."
         << endl
         << "peek        Displays the patient that is next in line, but keeps in queue"
         << endl
         << "list        Displays the list of all patients that are still waiting"
         << endl
         << "            in the order that they have arrived."
         << endl
         << "load <file> Reads the file and executes the command on each line"
         << endl
         << "help        Displays this menu" << endl
         << "quit        Exits the program" << endl;
}

/**
 * Prints welcome message.
 */
void welcome() {
    cout << "\nWelcome to the Emergency Room Triage Program! \n"
            "This program is a priority queue system for a hospital emergency "
            "room. \nThe staff needs to enter the name and the priority "
            "level of each patient. \nThe program takes care of the order in "
            "which the patients should be seen. \n"
            "Patients with the highest priority level will be highest in the "
            "queue.\nWithin that priority level, patients are ordered by how "
            "long they have been waiting, (longest waiting is seen first.)"
            "\nType 'help' to see all of your options. " <<
         endl;
}

/**
 * Prints farewell message.
 */
void goodbye() {
    cout << "\n\n Thank you for using the Emergency Room Triage program! \n\n";
}

/**
 * Delimits (by space) the string from user or file input.
 * @param s string from user or file input (return value is also erased from it)
 * @return the substring of s up to the first space (or to end of string if no
 *         spaces)
 */
string delimitBySpace(string &s) {
    const char delimiter = ' ';
    string result;
    int pos = s.find(delimiter);
    if (pos != string::npos) {
        result = s.substr(0, pos);
        s.erase(0, pos + 1);
    } else {
        result = s;
    }
    return result;
}

/**
 * Adds the patient to the waiting room.
 * @param line     command line
 * @param priQueue queue to manipulate
 */
void addPatientCmd(string line, PatientPriorityQueue &priQueue) {
    string priority, name;

    // get priority and name
    priority = delimitBySpace(line);
    if (priority.length() == 0) {
        cout << "Error: no priority code given." << endl;
        return;
    }
    name = line;
    if (name.length() == 0) {
        cout << "Error: no patient name given." << endl;
        return;
    }
    int b, e;
    b = name.find_first_not_of(" \t");
    e = name.find_last_not_of(" \t");
    name = name.substr(b, e - b + 1);
    // I used this post as a reference for getting rid of the trailing and
    // leading spaces: https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
    Patient::Priority pri;
    if (priority == "immediate" || priority == "emergency" ||
        priority == "urgent" || priority == "minimal") {
        if (priority == "immediate") pri = Patient::immediate;
        if (priority == "emergency") pri = Patient::emergency;
        if (priority == "urgent") pri = Patient::urgent;
        if (priority == "minimal") pri = Patient::minimal;
        Patient p(name, pri);
        priQueue.enqueue(p);
        cout << "Added patient \"" << name << "\" to the priority system." <<
             endl;
    } else {
        cout << "Error: invalid priority code given." << endl;
        return;
    }
}

/**
 * Displays the next patient in the waiting room that will be called.
 * @param priQueue queue to manipulate
 */
void peekNextCmd(PatientPriorityQueue &priQueue) {
    if (!priQueue.empty()) {
        cout << "Highest priority patient to be called next: " <<
             priQueue.peek().getName() << endl;
    } else {
        cout << "Nobody is in the queue." << endl;
        return;
    }
}

/**
 * Removes a patient from the waiting room and displays the name on the screen.
 * @param priQueue queue to manipulate
 */
void removePatientCmd(PatientPriorityQueue &priQueue) {
    if (!priQueue.empty()) {
        cout << "This patient will now be seen: " <<
             priQueue.dequeue().getName() << endl;
    } else {
        cout << "Nobody is in the queue." << endl;
        return;
    }
}

/**
 * Displays the list of patients in the waiting room.
 * @param priQueue queue to manipulate
 */
void showPatientListCmd(PatientPriorityQueue &priQueue) {
    cout << "# patients waiting: " << priQueue.size() << endl;
    if (!priQueue.empty()) {
        for (int i = 0; i < priQueue.size(); i++) {
            cout << priQueue.peek(i).toString() << endl;
        }
    }
}

// forward declare:
void execCommandsFromFileCmd(string filename, PatientPriorityQueue &priQueue);

/**
 * Process the line entered from the user or read from a file.
 * @param line     command text
 * @param priQueue queue to manipulate
 * @return         false to quit; true otherwise
 */
bool processLine(string line, PatientPriorityQueue &priQueue) {
    // get command
    string cmd = delimitBySpace(line);
    if (cmd.length() == 0) {
        cout << "Error: no command given.";
        return false;
    }

    // process user input
    if (cmd == "help")
        help();
    else if (cmd == "add")
        addPatientCmd(line, priQueue);
    else if (cmd == "peek")
        peekNextCmd(priQueue);
    else if (cmd == "next")
        removePatientCmd(priQueue);
    else if (cmd == "list")
        showPatientListCmd(priQueue);
    else if (cmd == "load")
        execCommandsFromFileCmd(line, priQueue);
    else if (cmd == "quit")
        return false;
    else
        cout << "Error: unrecognized command: " << cmd << endl;

    return true;
}

/**
 * Reads a text file with each command on a separate line and executes the
 * lines as if they were typed into the command prompt.
 * @param filename  of file with text commands
 * @param priQueue  queue to manipulate
 */
void execCommandsFromFileCmd(string filename, PatientPriorityQueue &priQueue) {
    ifstream infile;
    infile.open(filename);
    if (infile) {
        string line;
        while (getline(infile, line)) {
            cout << endl << "triage> " << line;
            cout << endl;
            processLine(line, priQueue);
        }
    } else {
        cout << "Error: could not open file." << endl;
    }
    infile.close();
}

/**
 * Main entry into triage program.
 * @return EXIT_SUCCESS
 */
int main() {
    welcome();

    // process commands
    PatientPriorityQueue priQueue;
    string line;
    do {
        cout << endl << "triage> ";
        getline(cin, line);
    } while (processLine(line, priQueue));

    goodbye();
    return EXIT_SUCCESS;
}
