/* 
 * File:   main.cpp
 * Author: Jackson Burger
 * Purpose: main
 * Created on June 26, 2021, 11:41 AM
 */

#include "JQueue.h"

void parenthesisChecker()
{
    char previousChar = 'a';
    string inputString;
    JStack<char> stack;
    cout << "Welcome to the balanced parenthesis checker." << endl
         << "Please provide your input string" << endl;
    getline(cin,inputString);
    
    for (int i=0; i < inputString.length(); i++) //For loop runs for however many characters the inputted string is
    {
        if (inputString[i] == '(' || inputString[i] == '[' || inputString[i] == '{' || inputString[i] == '<') //Places an open bracket
        {
            stack.push(inputString[i]);     //Adds open bracket to stack and stores this into a character variable to check for the closed bracket
            //previousChar = inputString[i];
        }
        else if (inputString[i] == ')' || inputString[i] == ']' || inputString[i] == '}' || inputString[i] == '>') //Places an 
        {           
           previousChar = stack.top();   
           stack.push(inputString[i]);            
           if(previousChar == '(' && stack.top() == ')'){
                stack.pop(); stack.pop();}
           else if (previousChar == '[' && stack.top() == ']'){
               stack.pop(); stack.pop();}
           else if (previousChar == '{' && stack.top() == '}'){
               stack.pop(); stack.pop();}
           else if (previousChar == '<' && stack.top() == '>'){
               stack.pop(); stack.pop();}
        }
    }
    if (stack.getIndex() > 0)
        cout << "Oh no! Your brackets were not balanced :( " << endl;
    else
        cout << "Great job! Your brackets were balanced :) " << endl;
}

bool stringCheck(const string inputString)
{
    bool check = true;
    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i] == 'a' || inputString[i] == 'b' || inputString[i] == 'c') //Checks the user only used a,b, or c
            check = true; //If so then the string is fine
        else
            check = false; //If not then make user input a new string and check again
    }
    return check;
}

void tagSystem()
{
    JQueue<char> q;
    int count = 0;
    bool stop = false;
    string inputString;
    bool checkString = false;
    
    while (checkString == false) //See stringCheck function above, makes sure user enters proper string
    {
        cout << "Welcome to the Collatz sequence tagging system." << endl
         << "The production rules are as follows: " << endl
         << "\ta-->bc" << endl << "\tb-->a" << endl << "\tc-->aaa" << endl
         << "Please provide your input string of {a,b,c} " << endl;
        getline(cin,inputString);
        checkString = stringCheck(inputString);
        if (checkString == false)
            cout << "Please enter only {a,b,c}" << endl;                   
    }
        
    for (int i = 0; i < inputString.length(); i++) //Stores the immediate values of the user inputted string into the queue
        q.insert(inputString[i]);
    
    while (count < 100)  //A count is set to make sure the program runs for an appropriate time
    {
        q.print();
        if (q.getSize() == 1 && q.getFront() == 'a') //Terminating condition (if there is only one item in the queue and its an a)
            count = 500; //Quit out of loop
        else if (q.getFront() == 'a'){          //If the front of queue is an a, remove the first two items and add 'b' and 'c' to the queue
            q.remove(); q.remove(); q.insert('b'); q.insert('c');}
        else if (q.getFront() == 'b'){          //If the front of queue is an b, remove the first two items and add a 'a' to the queue
            q.remove(); q.remove(); q.insert('a');}
        else if (q.getFront() == 'c'){          //If the front of queue is an c, remove the firs two items and add, 'a', 'a', 'a', to queue
            q.remove(); q.remove(); q.insert('a'); q.insert('a'); q.insert('a');}
        count++;
    }
    if (count == 100)       //Checks to see if the loop ran the max 100 iterations
        cout << "Program halted after 100 iterations" << endl;
        
}

using namespace std;
int main() 
{
    int choice = 0;
    
    while (choice != 3)
    {
        cout << "Please choose from the following." << endl
             << "1. Parenthesis Checker" << endl << "2. Tagging System Algorithm" << endl
             << "3. Quit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:{cin.ignore(); parenthesisChecker(); break;}
            case 2:{cin.ignore(); tagSystem(); break;}
            case 3:{break;}
            default:{cout << "Improper input" << endl;}
        }
    }
    
    cout << "Thank you very much for utilizing the stack and queue data structures! Come again :)" << endl;
    return 0;
}
