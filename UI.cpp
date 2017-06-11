// Project-03 has done by Farid Khosravi studentnumber:267964

#include "commands.h"
#include "queue.h"
#include "UI.h"
#include <iostream>
#include <string>


bool init_flag = false;                                // this flag is used to prevent of using add command before inserting number of priorities.

void UI::run_command(smatch input, commands& init) {   // UI has an input from regex and objects by type of commands class.
                                                       // this function is used for error handling and operating commands.


    if (input.str(1)== "init") {                       // This part detects the first string of regex output and if it is "init" enter it to the
        init_flag = true;                              // next if clause. I check the structure of the regex out put that contains number of priority
            if (input.str(2)== "") {                   // and no more character to operate the command. messages of error handling is clear in each part.
                if (input.str(3)== ""){
                    cout <<"Error: the number of priority levels is missing."<<endl;
                } else if (input.str(3)!= "") {
                    cout <<"Error: the number of priority levels must be an integer larger than 0."<<endl;
                }
            } else if (input.str(2)== "0") {
                cout <<"Error: it is not possible to create a priority list with 0 or less levels."<<endl;
            } else if (input.str(2)!=""){
              init.initialize(stoi(input.str(2)));
              cout << "New priority list with levels 1-"<< init.levels_number() << " initialized."<<endl;
            }


    } else if(input.str(1)== "add") {                 // This part detects the first string of regex output and if it is "add" enter it to the
        if (init_flag) {                              // next if clause. I check the structure of the regex output that contains number of priority
        if (input.str(2)!="" && input.str(3)=="") {   // and description of the chore to operate the command. messages of error handling is clear in each part.
                cout <<"Error: chore description is missing."<<endl;
        } else if (input.str(2)=="" && input.str(3)== "") {
            cout <<"Error: priority level and chore description are missing."<<endl;
        } else if (input.str(2)== "0" or input.str(2)== "" or stoi(input.str(2))>init.levels_number()) {
            cout <<"Error: priority level must be an integer between 1-"<< init.levels_number()<<"."<<endl;
        } else {
            int add_level = stoi(input.str(2));
            init.add(add_level , input.str(3));
            cout << "New chore added to priority level "<< input.str(2) << "."<<endl;
          }
        } else {
            cout <<"Error: no priority level inserted."<<endl;
        }


    } else if(input.str(1)== "next") {              // This part detects the first string of regex output and if it is "next" enter it to the
        if (input.str(2)!="" or input.str(3)!=""){  // next if clause. I check the structure of the regex output that shouldn't contains any character to operate the command. messages of error handling is clear in each part.
            cout << "Error: extra text after next command."<<endl;
        } else {
            string temp("");
            init.next(temp);
        }

    } else if(input.str(1)== "print") {             // This part detects the first string of regex output and if it is "print" enter it to the
        if (input.str(2)!="" or input.str(3)!=""){  // next if clause. I check the structure of the regex output that shouldn't contains any character to operate the command. messages of error handling is clear in each part.
            cout << "Error: extra text after print command."<<endl;
        } else {
            init.print();
        }

    } else if(input.str(1)== "erase") {             // This part detects the first string of regex output and if it is "erase" enter it to the
        if (input.str(2)==""){                      // next if clause. I check the structure of the regex output that contains number of chore
            cout << "Error: the running number is missing."<<endl;   // which we want to erase.messages of error handling is clear in each part.
        } else if (input.str(2)=="0"){
             cout << "Error: the running number must be larger than 0."<<endl;
        } else {
            init.erase(stoi(input.str(2)));
        }

    } else if(input.str(1)== "quit") {              // This part detects the first string of regex output and if it is "quit" enter it to the
        if (input.str(2)!="" or input.str(3)!=""){  // next if clause. I check the structure of the regex output that shouldn't contains any character to operate the command. messages of error handling is clear in each part.
            cout << "Error: extra text after quit command."<<endl;
        } else {
        init.quit();
        }
    }
}
