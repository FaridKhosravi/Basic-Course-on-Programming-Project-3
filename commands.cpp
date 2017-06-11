// Project-03 has done by Farid Khosravi studentnumber:267964

#include "commands.h"
#include "queue.h"
#include <iostream>
#include <stdio.h>
#include <locale>


commands::commands(int number_of_priorities):                       // Commands initializes value of number_of_priorities in the private variable
    array_of_priority_queues_(new Queue[number_of_priorities]),     // number_of_priorities and initializes the number of indexes of array_of_priority_queues_
    number_of_priorities_(number_of_priorities){}                   // and make a new object by type of Queue.

commands::~commands(){
    delete[] array_of_priority_queues_;                             // Delete the array_of_priority_queues_ to make it empty.
}


void commands::initialize(int number_of_priorities){                // Initialize the number of priorities which is inserted by init command.
  delete[] array_of_priority_queues_;                               // Delete previous arraye.
    array_of_priority_queues_ = new Queue[number_of_priorities];    // Make a new array by type of Queue in initialize by number_of_priorities
    number_of_priorities_ = number_of_priorities;                   // and also for private variable number_of_priorities_.
}

bool commands::add(int priority , const string& task_description){  // By variable priority get the number of priority of the chore and by task_description
                                                                    // get the description of the chore and add it to the end of the queue in the priority
                                                                    // which is specified by priority variable.
    array_of_priority_queues_[priority-1].add_to_end(task_description);
    return true;
}


bool commands::next(string& task_description){                      // Next searches in each priority and queue of each of them to find the highest priority
                                                                    // chore to do and then delete it from the queue and then replace it by the next one.
    for (int i=number_of_priorities_-1;i>=0;--i){
        if(not array_of_priority_queues_[i].is_empty() ){

            array_of_priority_queues_[i].remove_from_front(task_description);
            cout << task_description << endl;                       // Print the tast which is done.
            return true;
        }
    }
    cout << "--- no chores left ---" <<endl;                        // If there is no chores to do print this message.
    return false;

}


void commands::print() const {

    int running_number = 1;                                        // This is a local variable which is used to initialize internal counting of the
    for (int i = number_of_priorities_-1 ; i>= 0 ;--i){            // chores in the print fucntion. Print function starts to print from the highest
        if (not array_of_priority_queues_[i].is_empty()){          // priority and the highest chore to the lowest one.
        cout<<"Priority level "<< i+1 <<":"<<endl;
        array_of_priority_queues_[i].print(running_number);
        cout<<endl;
        }
    }
}

void commands::erase(int chore_number) {

    int running_number=1;                                         // This is a local variable which is used to initialize internal counting of the
    for (int i = number_of_priorities_-1 ; i>=0 ;--i){            // chores in the erase fucntion. by similar logic to print this function finds the
        if (not array_of_priority_queues_[i].is_empty()){         // chore number and its description which is inserted by "chore_number" the then replace
            if (array_of_priority_queues_[i].find(chore_number,running_number)){  // it by next chores(actually delete it).
                return;
            }
        }
    }
    if (chore_number > running_number-1){                        // If the number of chores which has inserted is more than what we have in all priority
        cout <<"Error: there is no such chore."<<endl;           // lists this error msg will print.
    }
}

void commands::quit() const {                                   // This function will quit the running program by abort command.
    abort();
}

int commands::levels_number()  {                                // This function just return the number of priorities to use it in the
    return number_of_priorities_;                               // object of commands class.
}
