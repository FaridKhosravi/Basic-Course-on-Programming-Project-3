// Project-03 has done by Farid Khosravi studentnumber:267964

#include <iostream>
#include <regex>
#include <string>

#include "commands.h"
#include "queue.h"
#include "UI.h"

using namespace std;

const string SPACES = "[[:space:]]*";                  // An string by any number of space.
const string ANY_EXCEPT_SPACES = "[^[:space:]]*";      // An string by anything except space which is used to get commands.
const string DIGIT = "[[:digit:]]+";                   // An string of integers which is used to get the number of priority or number of chore we want to delete.
const string ANY = ".*";                               // An string of anything for description of chores.
int start=0;
UI interface;

int main() {
commands init(0);                                     // Initialize init as an object of commands class by zero priority.

    regex reg(                                        // Structure of the regex for input the first is number of space then
                SPACES                                // anything except space which is used to get commands and I used If clause for detecting
              + "("                                   // each command like as "init" or "add" or others then we have space and then
              + ANY_EXCEPT_SPACES                     // integer inputs and the space and finally description of chores.
              +")"
              + SPACES
              + "("
              + DIGIT
              + ")?"
              + SPACES
              + "("
              + ANY
              + ")?"
                );
    smatch result;                                   // regex returns "result" by type of smatch.
    string line;

    while ( cout << "chores> " and getline(cin, line) ) { // I read the input line here and test it to see is it match with my
        if ( regex_match(line, result, reg) ) {           // regex structure, if it is then I test it to see do we have one of our command
                                                          // in the first string of result.if it is ok use run_command function of UI to do the operation.
            if (result.str(1)=="init" or result.str(1)=="add" or result.str(1)=="next" or result.str(1)=="erase" or
                    result.str(1)=="print" or result.str(1)=="quit") {
            interface.run_command(result, init);
            } else {

                cout << "wrong command!! try again." << endl;    // If there is wrong command we have this error.
            }
        } else {

            cout << "no command!! try again." << endl;           // // If there is no command we have this error.
        }
    }
}
