class MyCircularQueue {
public:
 
    // front = front of the queue
    // rear = rear end of the circular queue
    // sz = maximum size of the circular queue
    // len = current length of the queue
 
    int front,rear,sz,len=0;
 
    // linear representation of the circular queue
    vector<int> CirQue;
 
    // parameterized constructor
    MyCircularQueue(int k)
    {
 
        // initialize default values
        sz = k;
        front = 0;
        rear = 0;
 
        // fill -1 by default
        CirQue.assign(k,-1);
    }
 
    bool enQueue(int value)
    {
        if(isFull())
            return false;
 
        // increment size of the circular queue
        len++;
 
        CirQue[rear] = value;
 
        rear++;
 
        rear%=sz;
 
        return true;
    }
 
    bool deQueue()
    {   
        if(isEmpty())
            return false;
 
        // decrement size of the circular queue
        len--;
 
        CirQue[front] = -1;
 
        front = (front+1)%sz;
 
        return true;
 
    }
 
    int Front()
    {
        if(isEmpty())
            return -1;
 
        return CirQue[front];
    }
 
    int Rear()
    {
        if(isEmpty())
            return -1;
 
        int index = rear-1;
 
        if(index<0)
            index = index + sz;
 
        return CirQue[index];
    }
 
    bool isEmpty()
    {
        if(len==0)
            return true;
 
        return false;
    }
 
    bool isFull()
    {
        if(len==sz)
            return true;
 
        return false;
    }
};