/*
**********************************************
** Copyright (C) 2021 V.N. Anirudh Oruganti **
**********************************************

Student Name: V.N. Anirudh Oruganti
Class: CSCE 350
Assignment: Homework #1: Question #5
Email: oruganti@email.sc.edu

*/
#include <iostream>
#include <vector>
/*
****** Question 5 (Reference) ******
There a n lockers in a hallway, numbered sequentially from 1 to n. Initially, all the locker
doors are closed. You make n passes by the lockers, each time starting with locker #1. 
On the ith pass, i = 1, 2, …., n, you toggle the door of every ith locker: if the door is
closed, you open it; if it is open, you close it. After the last pass, display the following
output:
(a) Which locker doors are open and which ones are closed?
(b) Give the count of open locker doors are open?
Hint: Accept user input for number of passes and number of locker doors.
*/
int main()
{
    // numPass = number of passes user input.
    int numPass = 0;
    // numLock = number of locks user input.
    int numLock = 0;
    // numDoors = number of doors that are open.
    int numDoors = 0;

    // numOpen = A vector with keep status of all locker doors and their states (Closed or Open).  
    std::vector<char> numOpen;

    //Req for User's Input for #Locker and #Passes.
    std::cout << "\nPlease Enter the Number of Lockers: ";
    std::cin >> numLock;
    std::cout << "Please Enter the Number of Passes: ";
    std::cin >> numPass;

    // Since vectors start with 0,1,2...n, adds a static element to start at One insted of Zero.  
    numOpen.push_back('L');
    //Sets "C" to indicate all lockers that are closed initially.
    for (int i = 1; i <= numLock; ++i)
    {
        numOpen.push_back('C');
    }
    std::cout << "\n5(a) Which locker doors are open and which ones are closed?\n         The chart down below shows you the doors that are opened and closed after the final pass.\n         \"C\" denotes for when the locker is closed.\n         \"O\" denotes for when the locker is open.\n"
              << std::endl;
    // i = nth pass; ii = nth locker; the outer "for" loop goes over the total number of passes the user entered.
    // Inner "for" loop goes over number of lockers user entered.
    for (int i = 1; i <= numPass; ++i)
    {
        // Sets # of open doors to zero at the beginning of every itr.
        numDoors = 0;
        for (int ii = 1; ii <= numLock; ++ii)
        {
            // If the remainder is not zero, it skips the locker since it is not the nth locker.
            // If the remainder is zero, it opens the locker if it is closed and vice versa.
            int remainder = ii % i;
            if (remainder == 0)
                numOpen[ii] = (numOpen[ii] == 'C') ? 'O' : 'C';
            // This if statement counts #number of lockers which are open during itr.
            if (numOpen[ii] == 'O')
                ++numDoors;
        }
    }
    // Displays vector after the final pass.
    std::cout << "After Final Pass: [ ";
    for (int i = 1; i <= numLock; ++i)
    {
        std::cout << numOpen[i] << " ";
    }
    std::cout << "]" << std::endl;

    // Displays and answers question 5(b)
    std::cout << "\n5(b) Give the count of open locker doors are open?\n        On the final iteration there are " << numDoors << " doors open." << std::endl;

    return 0;
}