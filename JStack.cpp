/* 
 * File:   JStack.cpp
 * Author: Jackson Burger
 * Purpose: JStack implementation
 * Created on June 26, 2021, 11:51 AM
 */

#include "JStack.h"

template <typename J> JStack<J>::JStack()    //Default constructor
{
    index = 0;
}

template <typename J> JStack<J>::JStack(const JStack& copyMe) //Copy constructor
{
    index = copyMe.index;
    for (int i=0; i < index; i++)
    {
        array[i] = copyMe.array[i];
    }
}

template <typename J> JStack<J>::~JStack() 
{
    //No data allocated
}

template <typename J> void JStack<J>::push(J bracketType)
{
    if (!isFull())
    {
        array[index] = bracketType; //Adds an item to the stack 
        index++;
    }
}

template <typename J> J JStack<J>::pop()
{
    if (!isEmpty())     //Checks that there are items in stack
    {
    index--;                //Removes the top item of stack
    return array[index];
    }
}

template <typename J> J JStack<J>::top()const
{
    return array[index-1];  //Returns the character value of top of stack
}

template <typename J> bool JStack<J>::isFull()const
{
    return (index == size); //If the index is same as size then the stack is full
}

template <typename J> bool JStack<J>::isEmpty()const
{
    return (index == 0);    //If index is at 0 then stack is empty
}

template <typename J> int JStack<J>::getIndex()const
{
    return (index-1); //We do index - 1 since after we push an item we go to the next index which is not filled yet
}

template class JStack<char>;
template class JStack<float>;
template class JStack<int>;
template class JStack<string>;
