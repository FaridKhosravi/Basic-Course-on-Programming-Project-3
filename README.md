# Basic-Course-on-Programming-Project-3
C++

The purpose of this programming project:

To practise using dynamic data structures in somewhat more complex situations compared to the ones introduced during the lectures and exercise periods.
To let your skills shine when it comes to earlier subject matters that you should be very familiar by now. These include classes, modules, programming style, etc.

One thing you should really understand (and it will be repeated later in these instructions) is that you are not allowed to you STL-library's ready data structures in your program. All the containers/data structures you need in your program must be hand made by you from scratch. You are allowed to use string to manipulate text.

The program to be implemented:

In this project you will implement a simple prototype for a program that can be used to handle a list of things/jobs/chores/etc that have some sort of level of urgency attached to them. For example one might have the following chores to do:

Urgency	Chores
Extremely urgent	(priority level 3)	do tomorrow's homework,
empty the stinking garbage bin,
feed the goldfish,
buy toilet paper
Normal urgency	(priority level 2)	pay the electricity bill,
vacuum,
wash dishes
Low urgency	(priority level 1)	play videogames,
have a party,
learn to parachute
The idea is that the chores in the higher priority levels must be finished before the chores in the lower levels. If there are multiple chores in particular priority level, they must be finished in the order there were added to the level's chore list i.e. in FIFO (first in first out) order.

The number of priority levels might vary. In a list of houseworks like above three levels is probably enough. But there are situations in which more or less levels would work better. This hints to the directions that the priority list implemented in this project should probably allow the user to specify how many separate levels of priorities the list has.

Your job in this project is to implement:

a data structure that allows an easy manipulation of the priority lists as explained above and
a simple command line (textual) user interface for testing the data structure in question.

The external behavior of the program:

When the program starts if will print the following prompt on the screen:

    chores>␣ 
    
As usual the ␣ above means that there is one space character in its place. You are not supposed to print ␣ character on the screen. The   represents the cursor indicating that the program is waiting for a line of input.

After this, every time the program prints the above prompt, the user can type any of the following commands:

init number_of_priority_levels

A new priority list is created (for testing purposes). If there was an earlier list, it is destroyed and a new one is initialized from scratch (unless an error condition is met). The number of priority levels in the new list equals to the number given at the end of the input line (number_of_priority_levels).
Examples of use, the colored text emphasises the user input:

    chores> init 3
    New priority list with levels 1-3 initialized.
    chores> init 10
    New priority list with levels 1-10 initialized.
    chores> init 0
    Error: it is not possible to create a priority list with 0 or less levels.
    chores> init
    Error: the number of priority levels is missing.
    chores> init a
    Error: the number of priority levels must be an integer larger than 0.
    chores>  
    
Error conditions that are possible with init command:

The number of priority levels is missing.
The number of priority levels given is not an integer that is larger than zero.
If an error happens, the error message given in the example above will be printed. Also, if there was an old exising priority list, it will not be erased after the user inputs an erroneous init command.

Please make a note that the rest of the commands (besides quit) the test user interface recognizes can not be used before (non-erroneus) init command has been input at least once. You should print an error message in these cases even if it is not explicitly mentioned in each command's error conditions.

add priority_level chore_description

A new chore will be added to the end of the priority_level's tasks. The textual content of the chore will be whatever non-empty text the user types after the priority_level (i.e. chore_description).

Examples of use:

    chores> init 3
    New priority list with levels 1-3 initialized.
    chores> add 2 pay the electricity bill
    New chore added to priority level 2.
    chores> add 3 feed the goldfish
    New chore added to priority level 3.
    chores> add 2 vacuum
    New chore added to priority level 2.
    chores> add 2 wash dishes
    New chore added to priority level 2.
    chores> add 0 fix the bike tire
    Error: priority level must be an integer between 1-3.
    chores> add 4 fix the bike tire
    Error: priority level must be an integer between 1-3.
    chores> add 3
    Error: chore description is missing.
    chores> add fix the bike tire
    Error: priority level must be an integer between 1-3.
    chores> add
    Error: priority level and chore description are missing.
    chores>  
    
Error conditions that are possible with add command are pretty thoroughly expressed in the examples above.

It should also be quite clear how the program behaves in the case of an input error: after printing an error message the program execution continues normally.

print

This command prints out the current state of the chore list. The printing order is from highest priority level to the lowest. Within on priority level the chores are printed in FIFO order (the one added first is printed first etc.). Each chore is preceeded by a running number.
The following example will clarify the output format. It assumes that the user has just input the lines used above in the example for add command:

    chores> print
    Priority level 3:
    ␣␣1. feed the goldfish
    Priority level 2:
    ␣␣2. pay the electricity bill
    ␣␣3. vacuum
    ␣␣4. wash dishes
    chores> print 1
    Error: extra text after print command.
    chores>  
    
The character ␣ has its usual meaning: one space is printed instead.

Notice how nothing is printed for priority levels that have no chores assigned to them (priority level 1 in this example).

If there are no chores left on any priority level, nothing is printed:

    chores> print
    chores>  
    
There is only one error condition when it comes to print command. Its behavior is clear from the example above.

next

This command prints the chore that the next in turn: the element from the highest priority level that has chores left. The chore chosen is the one whose turn it is in FIFO order. In other words the core that has been on the list the longest.

If we continue the example above, the program should behave as follows:

    chores> next
    feed the goldfish
    chores> print
    Priority level 2:
    ␣␣1. pay the electricity bill
    ␣␣2. vacuum
    ␣␣3. wash dishes
    chores> next
    pay the electricity bill
    chores> print
    Priority level 2:
    ␣␣1. vacuum
    ␣␣2. wash dishes
    chores> next
    vacuum
    chores> print
    Priority level 2:
    ␣␣1. wash dishes
    chores> next
    wash dishes
    chores> print
    chores> next
    --- no chores left ---
    chores> print
    chores> next 1
    Error: extra text after next command.
    chores>  
    
Once again the only error condition in next command is clearly identified in the example.

erase running_number

Removes the chore whose running number is running_number from the chore list. The following example should clarify the behavior of erase command:
    chores> print
    Priority level 3:
    ␣␣1. feed the goldfish
    Priority level 2:
    ␣␣2. pay the electricity bill
    ␣␣3. vacuum
    ␣␣4. wash dishes
    chores> erase 1
    chores> erase 3
    chores> print
    Priority level 2:
    ␣␣1. pay the electricity bill
    ␣␣2. vacuum
    chores> erase 3
    Error: there is no such chore.
    chores> erase 0
    Error: the running number must be larger than 0.
    chores> erase
    Error: the running number is missing.
    chores>  
    
The error conditions related to erase command and the program's behavior in these situations are presented in the example above.

quit

The program ends without any further printouts.

There are no error conditions whatsoever related to quit command. It will end the program even if init command has not yet been used or if there is extra text on the command line after the keyword "quit".

The special requirements for this project:

As always this project has some special requirements that must be fullfilled for the program to achieve a passing grade. Following is the list of these requirements:

You are not allowed to use any STL containers in your program. All the data structures that are used to store the chore list information must be dynamic and self implemented. You have two choices: linked lists or dynamic arrays (or any combination of those).
You can use string library to store textual information (i.e. the chore descriptions etc.).

All the dynamic memory your program allocates with new must be released with delete before the program ends. As a matter of fact there should be no kind of memory management issues in your program.
To achieve this you should test your program with valgrind memory analyzer. It can be accessed in Qt Creator through Top Menu » Analyze » Valgrind Memory Analyzer.
