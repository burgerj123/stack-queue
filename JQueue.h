/* 
 * File:   JQueue.h
 * Author: Jackson Burger
 * Purpose: JQueue Header file
 * Created on June 27, 2021, 11:05 AM
 */


#include "JStack.h"

using namespace std;

template <typename J> class JQueue
{
    public:
        JQueue();
        JQueue(const JQueue& copyMe);
	~JQueue();
	void insert(const J letter);
	J remove();
        J getFront() const;
        int getSize() const;
	bool isFull() const;
	bool isEmpty() const;        
        void print() const;
                
    private:
        static const int size = 100;
	J array[size];
	int count, front, back;

};
