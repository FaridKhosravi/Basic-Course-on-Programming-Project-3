// Project-03 has done by Farid Khosravi studentnumber:267964

#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;


class Queue {
  public:
    Queue();


    bool find(int chore_number, int &running_number);     // find chore number and delete it and its description.


    void add_to_end(const string& new_chore);             // Add new chore to the end of the service queue.


    bool remove_from_front(string& removed_chore);        // Remove the chore who has been waiting the longest
                                                          // i.e. the chore in the fromt of the queue.


    bool is_empty() const;                                // Is there any chores waiting.


    void print(int &running_number) const;                // Print the priority levels and chores currently waiting in queue.


    ~Queue();

private:
    struct Cell {                                        // Structor Cell.
        string chore_description;                        // Chore description.
        Cell *next_ptr;                                  // Pointer to the next element of the linked list.
    };


    Cell* first_ptr_;                                    // Pointer to the first element of the linked list.


    Cell* last_ptr_;                                     // Pointer to the last element of the linked list.
};

#endif // QUEUE_H
