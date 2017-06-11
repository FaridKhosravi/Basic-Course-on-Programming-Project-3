// Project-03 has done by Farid Khosravi studentnumber:267964

#ifndef COMMANDS_H
#define COMMANDS_H
#include "queue.h"


using namespace std;

class commands {

    public:

        commands(int number_of_priorities);                       // Commands structor and its destructor which initializes number of priorities
        ~commands();                                              // at the start of the program.

        void initialize(int number_of_priorities);                // Initialize function for initializing number of priorities.

        bool add(int priority , const string& task_description);  // Add function adds chores description and their priority.


        bool next(std::string& task_description);                 // Next function deletes the chore which has highest priority in the queue.

        void print() const;                                       // Print function prints each priority and its chores.

        void erase(int chore_number);                             // Erase function erases the chore number and its description.

        void quit() const;                                        // Quit function abort the code and exit program.

        int levels_number();                                      // Level_number function returns the number of priorities.

    private:

        Queue* array_of_priority_queues_;                        // It is a private object in the commands class by type Queue.

        int number_of_priorities_;                               // Private Variable that contains number of priorities.

};

#endif // COMMANDS_H
