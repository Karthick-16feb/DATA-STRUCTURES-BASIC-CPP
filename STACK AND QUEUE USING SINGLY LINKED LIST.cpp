#include<iostream>
#include<stdlib.h>
using namespace std;
class Stack;
class Node;
class Queue;
class Computer
{
    public:
        friend class Node;
        friend class Stack;
        friend class Queue;
        Computer();
        ~Computer();
        void getdetails();
        void display();
        void display1();
        string pros();
    private:
        string processor,gpu;
        int ram,harddisk;
        float scrcsize;
};
class Node
{
    public:
        friend class Stack;
        friend class Queue;
        friend class Computer;
        Node(Computer&,Node*);
        ~Node();
    private:
        Computer data;
        Node *next;
};
class Stack
{
    public:
        Stack();
        ~Stack();
        int isEmpty();
        int pop();
        int push(Node *newNode);
        int peek();
        int size();
        int displayStack();
        int MakeStackEmpty();
    private:
        Node *top;
};
class Queue
{
    public:
        Queue();
        ~Queue();
        int isEmpty();
        int dequeue();
        int enqueue(Node *newNode);
        int peek();
        int size();
        int displayQueue();
        int MakeQueueEmpty();
    private:
        Node *first;
};
#include"computer.h"
Computer::Computer()
{
    processor="";
    gpu="";
    ram=0;              //In GB
    harddisk=0;         //In TB
    scrcsize=0;         //In Inches
}
Computer::~Computer()
{

}
void Computer::getdetails()
{
    cout<<"\nEnter the processor name:";
    cin>>processor;
    cout<<"Enter the gpu name:";
    cin>>gpu;
    cout<<"Enter the ram size:";
    cin>>ram;
    cout<<"Enter the hard disk capacity:";
    cin>>harddisk;
    cout<<"Enter the screen size:";
    cin>>scrcsize;
}
void Computer::display1()
{
    cout<<"Processor name:"<<processor<<endl;
    cout<<"GPU name:"<<gpu<<endl;
    cout<<"Ram size:"<<ram<<endl;
    cout<<"Hard disk capacity:"<<harddisk<<endl;
    cout<<"Screen size:"<<scrcsize<<endl;
}
void Computer::display()
{
    cout<<processor<<"\t\t"<<gpu<<"\t\t"<<ram<<"\t"<<harddisk<<"\t\t"<<scrcsize<<"\t\t"<<endl;
}
string Computer::pros()
{
    return processor;
}
Node::Node(Computer& ob,Node* next)
{
    data.processor=ob.processor;
        data.gpu=ob.gpu;
        data.ram=ob.ram;                    //In GB
        data.harddisk=ob.harddisk;     //In TB
        data.scrcsize=ob.scrcsize;
    next=next;
}
Node::~Node()
{
    next=NULL;
}
Stack::Stack()
{
    top=NULL;
}
Stack::~Stack()
{
    top=NULL;
}
int Stack::isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::push(Node *newNode)
{
    if(isEmpty())
    {
        top=newNode;
    }
    else
    {
        newNode->next=top;
        top=newNode;
    }
    return 1;
}
int Stack::pop()
{
    if(isEmpty())
                return -1;
        else
        {
                Node *temp = top;
                top = top->next;
                delete temp;
                temp = NULL;
                return 1;
        }
        return -2;
}
int Stack::peek()
{
        if(!isEmpty())
        {
            cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
            top->data.display();
            return 1;
        }
        else
        {
                return -1;
        }
}
int Stack::displayStack()
{
    int i=0;
    if(!isEmpty())
    {
        Node *temp=top;
        cout<<"\nComputer Hardware details\n";
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        while(temp!=NULL)
        {
            temp->data.display();
            temp=temp->next;
            i++;
        }
        if(i>0)
            return 1;
        return -1;
    }
    else
        return -2;
}
int Stack::size()
{
    Node *temp = top;
        int count = 0;
        while(temp!=NULL)
        {
                count++;
                temp = temp->next;
        }
        return count;
}
int Stack::MakeStackEmpty()
{
    if(!isEmpty())
    {
        Node *temp = top;
        while(temp!=NULL)
        {
                top = top->next;
                delete temp;
                temp = top;
        }
        top = NULL;
        return 1;
    }
    else
        return -2;
}
Queue::Queue()
{
    first=NULL;
}
Queue::~Queue()
{
    first=NULL;
}
int Queue::isEmpty()
{
    if(first==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Queue::enqueue(Node *newNode)
{
    if(isEmpty())
    {
        first=newNode;
        return 1;
    }
    else
    {
        Node *temp=first;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        return 1;
    }
    return -1;
}
int Queue::dequeue()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        Node *temp=first;
        first=first->next;
        delete temp;
        temp=NULL;
        return 1;
    }
    return -2;
}
int Queue::peek()
{
    if(!isEmpty())
    {
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        first->data.display();
        return 1;
    }
    else
    {
        return -1;
    }
}
int Queue::size()
{
    Node *temp=first;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int Queue::displayQueue()
{
    int i=0;
    if(!isEmpty())
    {
        Node *temp=first;
        cout<<"\nComputer Hardware details\n";
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        while(temp!=NULL)
        {
            temp->data.display();
            temp=temp->next;
            i++;
        }
        if(i>0)
            return 1;
        return -1;
    }
    else
        return -2;
}
int Queue::MakeQueueEmpty()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        Node *temp=first;
        while(temp!=NULL)
        {
            first=first->next;
            delete temp;
            temp=first;
        }
        first=NULL;
        return 1;
    }
    return -2;
}
#include"computer.h"
int main()
{
    int choice,s,c,i,index,pos;
    string processor;
    Computer ob,o;
    Stack A;
    Queue S;
    repeat:
    {
        cout<<"\nStack & Queue Application For Computer Hardware Details using Linked List\n"<<endl;
        cout<<"\nPress\n1 for Stack Application using Linked List\n\n2 for Queue Application using Linked List\n\n3 for Exiting\n\n";
        cin>>c;
        while(1)
        {
            switch(c)
            {
                case 1:
                {
                    cout<<"\n***Computer Hardware Application***\n\n---Using Stack---\n";
                    while(1)
                    {
                        cout<<"\n\nPress\n1 for push\n2 for pop\n3 for peek\n4 for size\n5 for make stack empty\n6 for displaying the stack\n7 for exiting\n\n";
                        cin>>choice;
                        switch(choice)
                        {
                            case 1:
                            {
                                cout<<"\nFor Pushing...\n";
                                cout<<"\nEnter the computer hardware details\n";
                                ob.getdetails();
                                Node *newnode=new Node(ob,NULL);
                                i=A.push(newnode);
                                if(i==1)
                                {
                                    cout<<"\nPushed successfully...\n";
                                    A.displayStack();
                                }
                                else
                                    cout<<"\nStack is full\n";
                                break;
                            }
                            case 2:
                            {
                                i=A.pop();
                                if(i==1)
                                {
                                    cout<<"\nPoping was done successfully...\n";
                                    A.displayStack();
                                }
                                else
                                    cout<<"\nStack is empty\n";
                                break;
                            }
                            case 3:
                            {
                                cout<<"\n";
                                i=A.peek();
                                if(i==1)
                                {
                                    cout<<"\nPeek operation was done\n";
                                }
                                else
                                {
                                    cout<<"\nStack is empty...\n"<<endl;
                                }
                                break;
                            }
                            case 4:
                            {
                                i=A.size();
                                cout<<"\nSize:"<<i<<endl;
                                break;
                            }
                            case 5:
                            {
                                i=A.MakeStackEmpty();
                                if(i==1)
                                {
                                    cout<<"\nMade the stack as an empty stack\n";
                                }
                                else
                                {
                                    cout<<"\nStack is empty..\n";
                                }
                                break;
                            }
                            case 6:
                            {
                                i=A.displayStack();
                                if(i!=1)
                                    cout<<"\nStack empty...\n";
                                else if(i==1)
                                    cout<<"\nDisplayed successfully...\n";
                                break;
                            }
                            case 7:
                            {
                                cout<<"\nExiting stack\n\n";
                                goto repeat;
                            }
                            default:
                                cout<<"\nEnter the correct choice:";
                        }
                    }
                }
                case 2:
                {
                    cout<<"\n***Computer Hardware Application***\n\n---Using Queue---\n";
                    while(1)
                    {
                        cout<<"\n\nPress\n1 for Enqueue\n2 for Dequeue\n3 for peek\n4 for size\n5 for make Queue empty\n6 for displaying the Queue\n7 for exiting\n\n";
                        cin>>choice;
                        switch(choice)
                        {
                            case 1:
                            {
                                cout<<"\nFor Enqueue...\n";
                                cout<<"\nEnter the computer hardware details\n";
                                ob.getdetails();
                                Node *newnode=new Node(ob,NULL);
                                if(S.enqueue(newnode))
                                {
                                    cout<<"\nEnqueued successfully...\n";
                                    S.displayQueue();
                                }
                                else
                                    cout<<"\nQueue is full\n";
                                break;
                            }
                            case 2:
                            {
                                cout<<"\nFor Dequeue..\n";
                                i=S.dequeue();
                                if(i==1)
                                {
                                    cout<<"\nDequeue was done successfully...\n";
                                    S.displayQueue();
                                }
                                else
                                    cout<<"\nQueue is empty\n";
                                break;
                            }
                            case 3:
                            {
                                cout<<"\n";
                                i=S.peek();
                                if(i==1)
                                {
                                    cout<<"\nPeek operation was done\n";
                                }
                                else
                                {
                                    cout<<"\nQueue is empty...\n"<<endl;
                                }
                                break;
                            }
                            case 4:
                            {
                                i=S.size();
                                cout<<"\nSize:"<<i<<endl;
                                break;
                            }
                            case 5:
                            {
                                i=S.MakeQueueEmpty();
                                if(i==1)
                                {
                                    cout<<"\nMade the Queue as an empty Queue\n";
                                }
                                else
                                {
                                    cout<<"\nQueue is empty..\n";
                                }
                                break;
                            }
                            case 6:
                            {
                                i=S.displayQueue();
                                if(i!=1)
                                    cout<<"\nQueue empty...\n";
                                else if(i==1)
                                    cout<<"\nDisplayed successfully...\n";
                                break;
                            }
                            case 7:
                            {
                                cout<<"\nExiting queue\n\n";
                                goto repeat;
                            }
                            default:
                                cout<<"\nEnter the correct choice:";
                        }
                    }
                }
                case 3:
                {
                    cout<<"\nExiting...\n";
                    exit(0);
                }
                default:
                {
                    cout<<"\n\nEnter the correct choice\n\n";
                }
            }
        }
    }
}