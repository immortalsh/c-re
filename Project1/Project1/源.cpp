#include <iostream>

using namespace std;
template <class elemType>
class seqQueue
{
private:
    elemType* elem;
    int maxSize;
    int front,rear;
    void doubleSpace();
public:
    seqQueue(int size = 10);
    ~seqQueue();
    bool isEmpty()const;
    void enQueue(const elemType& x);
    elemType deQueue();
    elemType getHead()const;
    void swap();
    void print();
};
template <class elemType>
seqQueue<elemType>::seqQueue(int size)
{
    elem = new elemType[size];
    maxSize = size;
    front = rear = 0;
}
template <class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete[]elem;
}
template <class elemType>
bool seqQueue<elemType>::isEmpty()const
{
    return front == rear;
}
template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front + 1) % maxSize;
    return elem[front];
}
template <class elemType>
elemType seqQueue<elemType>::getHead()const
{
    return elem[(front + 1) % maxSize];
}
template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if ((rear + 1) % maxSize == front) doubleSpace();
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
}
template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType* tmp = elem;
    elem = new elemType[2 * maxSize];
    for (int i = 1; i <= maxSize; i++)
        elem[i] = tmp[(front + i) % maxSize];
    front = 0;
    rear = maxSize-1;
    maxSize *= 2;
    delete tmp;
}


struct people
{
    int a_i;
    int c_i;
    int n_i;
};
template <>
void seqQueue<people>::swap()
{
    int c_i1;
    c_i1 = elem[rear].c_i;
    for (int i = 0; i < c_i1; i++)
    {
        if ((rear - i + maxSize - 1) % maxSize == front)
            break;
        if (elem[(rear - i + maxSize) % maxSize].a_i >= elem[(rear - i + maxSize - 1) % maxSize].a_i)

        {
            people tmp;
            tmp = elem[(rear - i+maxSize)%maxSize];
            elem[(rear - i + maxSize) % maxSize] = elem[(rear-i + maxSize - 1) % maxSize];
            elem[(rear-i + maxSize - 1) % maxSize] = tmp;
        }
        else break;
    }
}
template <>
void  seqQueue<people>::print()
{
    for (int i = 1; i <(rear - front + maxSize) % maxSize; i++)
    {
        printf("%d", elem[(front + i) % maxSize].n_i);
        printf(" ");
    }
    printf("%d", elem[rear].n_i);
}
int main()
{
    int num;
    cin >> num;
    people* p;
    p = new people[num];
    for(int i=0; i<num; i++)
    {
        cin >>p[i].a_i >> p[i].c_i;
        p[i].n_i = i+1;
    }
    seqQueue<people> s1;
    for(int i=0; i<num; i++)
    {
        s1.enQueue(p[i]);

        s1.swap();

    }
    s1.print();

}

