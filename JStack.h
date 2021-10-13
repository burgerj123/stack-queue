/* 
 * File:   JStack.h
 * Author: Jackson Burger
 * Purpose: Jstack header file
 * Created on June 26, 2021, 11:51 AM
 */

#include <iostream>
using namespace std;
template <typename J> class JStack 
{
public:
    JStack();
    JStack(const JStack& copyMe);
    virtual ~JStack();
    
    void push(J bracketType);
    J pop();
    J top()const;
    bool isFull()const;
    bool isEmpty()const;
    int getIndex()const;
    
private:
    static const int size = 100;
    J array[size];
    int index;
};
