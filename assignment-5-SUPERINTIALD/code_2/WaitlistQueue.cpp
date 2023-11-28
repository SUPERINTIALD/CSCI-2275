#include "WaitlistQueue.hpp"

using namespace std;


WaitlistQueue::WaitlistQueue(int qSize)
{
    /* Already implemented, don't change */
    qFront = qEnd = -1;
    qCapacity = qSize;
    queue = new string[qSize];
}

WaitlistQueue::~WaitlistQueue()
{
    //TODO    
    delete[] queue;
    queue = NULL; 

}

void WaitlistQueue::enqueue(string value)
{
    //TODO
    if (isFull() == true){
        cout << "Waitlist is full. Cannot enqueue.";
    }else{
        if(qFront == -1 && qEnd == -1){
            qFront++;
            qEnd++;
            queue[qEnd] = value;
        }else if(qEnd == qCapacity-1){
            qEnd = 0;
            queue[qEnd] = value;
        }else{
            queue[qEnd+1] = value;
            qEnd++;  
        }
    }

    
}

void WaitlistQueue::dequeue()
{

    if(isEmpty() == true){
        cout << "Waitlist is empty. Cannot dequeue." << endl;        
    }else{
        if (qFront == qEnd){
            queue[qFront] = "";
            qFront++;
            qEnd++;
        }else if(qFront == qCapacity - 1){
            queue[qFront] = "";
            qFront = 0;
        }else{
            queue[qFront] = "";
            qFront++;            
        }        
    }
}

string WaitlistQueue::peek()
{
    //TODO
    string result;
    if (isEmpty()){
        result = "<EMPTY QUEUE>";
    }else{
        result = queue[qFront];        
    }
    return result;
}

void WaitlistQueue::resize(int newSize)
{
    //TODO
    string *tmp = new string[newSize]; //new array


    if (newSize == qCapacity){
        // do nothing
    }
    else{
        
        if (newSize > qCapacity){
            //copy old array to new array
            for (int i = 0; i < qCapacity; i++) 
            {
                tmp[i] = queue[i];            
            }
        }else{
            //copy old array to new array
            for (int i = 0; i < newSize; i++) 
            {
                tmp[i] = queue[i];            
            }
        }

        

        delete[] queue; //delete old array
        queue = tmp; //point old array to new array
    }
	
    cout << "Resizing from " << qCapacity << " to " << newSize << endl;
}

int WaitlistQueue::size()
{
    //TODO
    int counter=0;
    for (int i=0; i<qCapacity; i++){
        if (queue[i] !=""){            
            counter++;
        }
    }

    return counter;
}

int WaitlistQueue::capacity()
{
    //TODO
    return qCapacity;
}

bool WaitlistQueue::isEmpty()
{
    //TODO
    for(int x=0;x<qCapacity;x++)
	{
		if(queue[x] !="")
		{
			return false;
		}
	}
	
    
    qFront = -1;
    qEnd = -1;
    return true;

}

bool WaitlistQueue::isFull()
{
    //TODO
    for(int x=0;x<qCapacity;x++)
	{
		if(queue[x] == "")
		{
			return false;
		}
	}
	return true;

}