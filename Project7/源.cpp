#include<iostream>
#include"string.h"
using namespace std;

template<class Type>
class priorityQueue
{
public:
    priorityQueue(int capacity=100);
    priorityQueue(const Type *items, int size);
    ~priorityQueue();
    bool isEmpty()const;
    void enQueue(const Type& x);
    int find(const Type& x);
    Type deQueue();
    Type getHead()const;
    void decrease(int i, Type v);
private:
    int currentSize;
    Type* array;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);

};
template <class Type>
priorityQueue<Type>::priorityQueue(int capacity)
{
    array = new Type[capacity];
    maxSize = capacity;
    array[0] = -1;
    currentSize = 0;
}
template <class Type>
priorityQueue<Type>::~priorityQueue()
{
    delete []array;
}
template <class Type>
bool priorityQueue<Type>::isEmpty()const
{
    return currentSize == 0;
}
template <class Type>
Type priorityQueue<Type>::getHead()const
{
    return array[1];
}
template <class Type>
void priorityQueue<Type>::enQueue(const Type &x)
{
    if (currentSize == maxSize - 1) doubleSpace();
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
        array[hole] = array[hole / 2];
    array[hole] = x;
}
template<class Type>
Type priorityQueue<Type>::deQueue()
{
    Type minItem;
    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}
template<class Type>
void priorityQueue<Type>::percolateDown(int hole)
{
    int child;
    Type tmp = array[hole];
    for(;hole*2<=currentSize;hole=child)
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])
            child++;
        if (array[child] < tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}
template<class Type>
void priorityQueue<Type>::buildHeap()
{
    for (int i = currentSize / 2; i > 0; i--)
        percolateDown(i);
}
template<class Type>
priorityQueue<Type>::priorityQueue(const Type *items,int size):maxSize(size+10),currentSize(size)
{
    array = new Type[maxSize];
    array[0] = -1;
    for (int i = 0; i < size; i++)
        array[i + 1] = items[i];
    buildHeap();
}
template<class Type>
void priorityQueue<Type>::doubleSpace()
{
    Type* tmp = array;
    maxSize *= 2;
    array = new Type[maxSize];
    for (int i = 0; i <= currentSize; i++)
        array[i] = tmp[i];
    delete tmp;
}
template<class Type>
int priorityQueue<Type>::find(const Type &x)
{
    int s=0;
    Type min=array[1];
    
    for (int i = 1; i <= currentSize; i++)
        if (array[i] > x)
        {
            min = array[i];
            s = i;
            break;
        }
    for (int i = 1; i <= currentSize; i++)
    {
        
        if (array[i] > x)
            if (array[i] < min)
            {
                min = array[i];
                s = i;
            }
    }
    return s;
}
template<class Type>
void priorityQueue<Type>::decrease(int i,Type v)
{
    Type tmp=array[1];
     array[i] = array[i] - v;
        for (; i / 2 >= 1; i /= 2)
        {
            if (array[i] < array[i / 2])
            {
                tmp = array[i / 2];
                array[i / 2] = array[i];
                array[i] = tmp;
            }
        }
       
    
}
int main()
{
    int num=0,num1=0,i1=0,v=0,num2=0,num3=0;
    cin >> num;
    char* s;
    s = new char[20];
    int* out;
    out = new int[num + 1];
    
    priorityQueue<int> s1(100);
    for (int i = 1; i <= num; i++)
    {
        cin >> s;
        if (!strcmp(s, "insert"))
        {
            cin >> num1;
            s1.enQueue(num1);
        }
        if (!strcmp(s, "find"))
        {

            cin >> num3;
            out[num2++] = s1.find(num3);

        }
        if (!strcmp(s, "decrease"))
        {

            cin >> i1 >> v;
            s1.decrease(i1, v);

        }


    }
    for (int i = 0; i < num2; i++)
        cout << out[i] << '\n';
    delete []out;
    delete []s;
   
    return 0;
}

