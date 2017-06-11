// Project-03 has done by Farid Khosravi studentnumber:267964

#ifndef UI_H
#define UI_H

#include "commands.h"
#include "queue.h"

#include <iostream>
#include <regex>

using namespace std;

class UI {
public:

    void run_command(smatch input , commands &init);        // this function is used for detecting command operate it and error handling.


private:

    int number_of_priorities_;                              // private variable of number of priorities.
};

#endif // UI_H
