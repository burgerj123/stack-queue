/* 
 * File:   JQueue.cpp
 * Author: Jackson Burger
 * Purpose: JQueue implementation
 * Created on June 27, 2021, 11:05 AM
 */

#include "JQueue.h"

template <typename J> JQueue<J>::JQueue() //Default constructor
{
    count = 0;
    front = 0;
    back = -1;
}

template <typename J> JQueue<J>::JQueue(const JQueue& copyMe) //Copy constructor
{
    count = copyMe.count;
    front = copyMe.front;
    back = copyMe.back;
    for (int i=0; i <= count; i++)
    {
        array[i] = copyMe.array[i];
    }
}

template <typename J> JQueue<J>::~JQueue() //Destructor
{
    //No data allocating
}

template <typename J> void JQueue<J>::insert(const J letter) //Insert into queue
{
    if (!isFull()) //If queue is not full
    {
        back = (back + 1) % size; //Updates the back of the arrays index and wraps around if needed due to this being a circular array
        array[back] = letter;     //The new item is placed at the back end of the array
        count++;
    }
}

template <typename J> J JQueue<J>::remove()           //Removes item from queue
{
    if (!isEmpty())
    {
        J temp = array[front];  //Stores value of the item about to be removed
        front = (front + 1) % size; //Updates the front of the arrays index and wraps around if needed due to this being a circular array
        count--;                    //Removes item
        return temp;
    }
}

template <typename J> bool JQueue<J>::isFull() const
{
    return (count >= size); //If count is greater or equal to size then its full
}

template <typename J> bool JQueue<J>::isEmpty() const
{
    return (count <= 0);        //If count is less than or equal to 0 then the queue is empty
}

template <typename J> J JQueue<J>::getFront()const
{
    return array[front];        //Returns the character at the front end of the array
}

template <typename J> int JQueue<J>::getSize()const
{
    return count;               //Returns the count to signify the amount of items in the queue
}

template <typename J> void JQueue<J>::print() const
{
    if (!isEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % size; //Index is incremented to where it can wrap around the circular array 
            cout << array[index];           //Print at the index of the array
        }
    }
    cout <<  endl;
}

template class JQueue<char>;
template class JQueue<float>;
template class JQueue<int>;
template class JQueue<string>;
