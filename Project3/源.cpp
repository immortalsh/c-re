#include <iostream>
using namespace std;
#include <iostream>
#include <stdlib.h>

#include <ctime>
template <class elemtype>
class queue
{
public:
    virtual bool isEmpty()const = 0;
    virtual void enqueue(const elemtype& x) = 0;
    virtual elemtype dequeue() = 0;
    virtual elemtype gethead()const = 0;
    virtual ~queue() {}
};
template<class elemtype>
class linkqueue :public queue<elemtype>
{
private:
    struct node
    {
        elemtype data;

        node* next;
        node(const elemtype& x, node* N = NULL)
        {

            data = x;

            next = N;
        }
        node() :next(NULL) {}
        ~node() {}
    };
    node* front, * rear;

public:
    linkqueue();
    ~linkqueue();
    bool isEmpty()const;
    void enqueue(const elemtype& x);
    elemtype dequeue();
    elemtype gethead()const;


};


template <class elemtype>
linkqueue<elemtype>::linkqueue()
{
    front = rear = NULL;
}
template <class elemtype>
linkqueue<elemtype>::~linkqueue()
{
    node* tmp;
    while (front != NULL)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}
template <class elemtype>
bool linkqueue<elemtype>::isEmpty()const
{
    return front == NULL;

}
template <class elemtype>
elemtype linkqueue<elemtype>::gethead()const
{
    return front->data;
}
template <class elemtype>
void linkqueue<elemtype>::enqueue(const elemtype& x)
{
    if (rear == NULL)
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}
template <class elemtype>
elemtype linkqueue<elemtype>::dequeue()
{
    node* tmp = front;
    elemtype value = front->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete tmp;

    return value;
}
struct node
{
	int num;
	int number;
	node* leftchild;
	node* rightbro;
	node(int x=0,int i=0)
	{
		num = x;
		number = i;
		leftchild = rightbro = NULL;
	}
    
};
struct snode
{
	int leftc;
	int rightb;
	int ss;
};
void preorder(node *p)
{
    if (p == NULL) return;
    cout << p->num << ' ';
    preorder(p->leftchild);
    preorder(p->rightbro);
}
void postorder(node *p)
{
    if (p == NULL) return;
    postorder(p->leftchild);
     cout << p->num << ' ';
    postorder(p->rightbro);
  
}
void levelorder(node *p)
{

    linkqueue<node*> que;
    node* q;
    q = new node();
    que.enqueue(p);
   while(!que.isEmpty())
   {
       q = que.dequeue();
       while(q!=NULL)

    {
       cout << q->num<<' ';
        
        if (q->leftchild) que.enqueue(q->leftchild);

        q = q->rightbro;
        
    } }
    
    
    
    
}
int main()
{
	int num1,m=0;
	cin >> num1;
	snode* s1;
	node* root;
	node** s2;
    root = new node();
	s2 = new node* [num1];
	s1 = new snode[num1];
    bool* flag;
    flag = new bool[num1];
	for(int i=0;i<num1;i++)
	{
		cin >> s1[i].leftc >> s1[i].rightb >> s1[i].ss;
	}
	for(int i=0;i<num1;i++)
	{
		s2[i] = new node(s1[i].ss,i);
	}
    
    for (int i = 0; i < num1; i++)
        flag[i] = false;
    for (int i = 0; i < num1; i++)
    {
       if(s1[i].leftc)
        flag[s1[i].leftc - 1] = true;
       if(s1[i].rightb)
        flag[s1[i].rightb - 1] = true;
    }
    for (int i = 0; i < num1; i++)
    {
        if (!flag[i])
            m = i;
    }
    root = s2[m];
	node* p = root;
    linkqueue<node*> que;
    que.enqueue(root);
    
    while (!que.isEmpty())
    {
        p = que.dequeue();
        if (s1[p->number].leftc != 0) que.enqueue(p->leftchild = s2[s1[p->number].leftc-1]);
        if (s1[p->number].rightb != 0) que.enqueue(p->rightbro = s2[s1[p->number].rightb-1]);
    }
    preorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    levelorder(root);
    

}