// Project-03 has done by Farid Khosravi studentnumber:267964

#include <iostream>
#include <string>

#include "commands.h"
#include "queue.h"


Queue::Queue(): first_ptr_{nullptr}, last_ptr_{nullptr} { //initializing first and last pointer in Queue structor.
}


Queue::~Queue() {                                        // destructor of Queue.
   while ( first_ptr_ != nullptr ) {
      Cell* remove_ptr = first_ptr_;
      first_ptr_ = first_ptr_->next_ptr;

      delete remove_ptr;
   }
}



void Queue::print(int &running_number) const {          // Print functions gets the running number and started to print
    Cell *print_ptr = first_ptr_;                       // the chore description and its number which is showed by running number
    while ( print_ptr != nullptr ) {                    // in each priority from the first inserted chore to the last one.
      cout << "  " << running_number << ". " << print_ptr->chore_description << endl;
      ++running_number;
      print_ptr = print_ptr->next_ptr;
   }
}

void Queue::add_to_end(const string& new_chore) {       // This function gets the string input as description of chore and add it to the
    Cell *new_cell_ptr = new Cell;                      // the end of the queue of the priority which is specified in the commands class.
                                                        // new_cell_ptr is a variable of type Cell and gets the chore_description and 
    new_cell_ptr->chore_description = new_chore;        // and make the next memory null for the next chore description.
    new_cell_ptr->next_ptr = nullptr;

    if ( first_ptr_ == nullptr ) {
        first_ptr_ = new_cell_ptr;
        last_ptr_ = new_cell_ptr;
    } else {
        last_ptr_->next_ptr = new_cell_ptr;
        last_ptr_ = new_cell_ptr;
    }
}


bool Queue::remove_from_front(string& removed_chore) { // This function is used by next command. it gets an empty string as input and 
   if ( is_empty() ) {                                 // finds the chore which is fisrt inserted and should be first output.
      return false;
   }

   Cell *remove_ptr = first_ptr_;

   removed_chore = remove_ptr->chore_description;

   if ( first_ptr_ == last_ptr_ ) {
      first_ptr_ = nullptr;
      last_ptr_ = nullptr;
   } else {
      first_ptr_ = first_ptr_->next_ptr;
   }

   delete remove_ptr;

   return true;
}


bool Queue::is_empty() const {                        // This is a bool function and shows that each priority is empty or not by returning
    return first_ptr_ == nullptr;                     // the value first pointer.
}

bool Queue::find(int chore_number, int& running_number){  // this is a bool function and get the chore_number as integer and running number
    Cell *find_ptr = first_ptr_;                          //  as reference to find the specified chore which we want to erase.
    Cell* prev_ptr = first_ptr_;                          // in the linked list.
    bool find_flag = false;
    while ( find_ptr != nullptr ) {
      if (running_number == chore_number && find_flag == false) {  // If the number of chores which is inserted in the erase command
          if (find_ptr==first_ptr_){                               // is equal to running_number it goes to this part and replace
                                                                   // it by next chores and return true and if the number of chores
              first_ptr_=first_ptr_->next_ptr;                     // is not in the list it returns false.

          }else if (find_ptr==last_ptr_){

              prev_ptr->next_ptr=nullptr;
              last_ptr_=prev_ptr;


          }else{

              prev_ptr->next_ptr=find_ptr->next_ptr;

          }

          delete find_ptr;
          find_flag = true;
          return true;
      } else {
      ++running_number;
      prev_ptr=find_ptr;
      find_ptr = find_ptr->next_ptr;
    }
  }
    return false;
}
