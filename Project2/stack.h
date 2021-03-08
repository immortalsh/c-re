#ifndef STACK_H
#define STACK_H

template<class elemtype>
class stack
{
    public:
        virtual bool isEmpty()const=0;
        virtual void push(const elemtype &x)=0;
        virtual elemtype pop()=0;
        virtual elemtype top()const=0;

        virtual ~stack(){}

};
template<class elemtype>
class seqstack:public stack<elemtype>
{
private:
    elemtype *elem;
    int top_p;
    int maxsize;
    void doublespace();
public:
    seqstack(int initsize=10);
    ~seqstack();
    bool isEmpty()const;
    void push(const elemtype&x);
    elemtype pop();
    elemtype top()const;
    elemtype find(int i);
    int currentlength();

};
template<class elemtype>
seqstack<elemtype>::seqstack(int initsize)
{
    elem=new elemtype[initsize];
    maxsize=initsize;
    top_p=-1;

}
template<class elemtype>
seqstack<elemtype>::~seqstack()
{
    delete[]elem;
}
template<class elemtype>
bool seqstack<elemtype>::isEmpty()const
{
    return top_p==-1;
}
template<class elemtype>
void seqstack<elemtype>::push(const elemtype&x)
{
    if(top_p==maxsize-1) doublespace();
    elem[++top_p]=x;
}
template<class elemtype>
elemtype seqstack<elemtype>::pop()
{
    return elem[top_p--];
}
template<class elemtype>
elemtype seqstack<elemtype>::top()const
{
    return elem[top_p];
}
template<class elemtype>
void seqstack<elemtype>::doublespace()
{
    elemtype *tmp=elem;
    elem=new elemtype[2*maxsize];
    for(int i=0;i<maxsize;++i)
    {
        elem[i]=tmp[i];
    }
    maxsize*=2;
    delete[]tmp;
}
template<class elemtype>
elemtype seqstack<elemtype>::find(int i)
{
    return elem[top_p-i+1];
}
template<class elemtype>
int seqstack<elemtype>::currentlength()
{
    return top_p+1;
}
#endif // STACK_H
