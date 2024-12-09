#include<iostream>
#include<stdlib.h>
using namespace std;
class A_List;
class Computer
{
    public:
        friend class A_list;
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
class AQueue
{
    public:
        AQueue();
        AQueue(Computer *,int,int,int);
        ~AQueue();
        int isFull();
        int isEmpty();
        int dequeue();
        int enqueue(Computer &elt);
        int peek();
        int search(string pros);
        int size();
        int displayQueue();
        int MakeQueueEmpty();
    private:
        Computer *arr;
        int front,rear,capacity;
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
AQueue::AQueue()
{
    int i;
    capacity=5;
    rear=-1;
    front=-1;
    arr=new Computer[capacity];
    Computer o;
    for(i=0;i<capacity;i++)
        arr[i]=o;
}
AQueue::AQueue(Computer *a,int f,int r,int c)
{
    int i;
    capacity=c;
    front=f;
    rear=r-1;
    arr=new Computer[capacity];
    for(i=f;i<=rear;i++)
        arr[i]=a[i];
    Computer o;
    for(i=rear+1;i<capacity;i++)
        arr[i]=o;
}
AQueue::~AQueue()
{
    rear=0;
    front=0;
    capacity=0;
    delete arr;
    arr = NULL;
}
int AQueue::isFull()
{
    if(rear+1 == capacity)
        return 1;
    else
        return 0;
}
int AQueue::isEmpty()
{
    if(front==-1 && rear==-1 || (front>rear))
        return 1;
    else
        return 0;
}
int AQueue::enqueue(Computer& elt)
{
    int i;
    if(!isFull())
    {
        if(front==-1 && rear==-1)
        {
            arr[0]=elt;
            front=0;
            rear=0;
            return 1;
        }
        else if(isFull())
        {
            return 0;
        }
        else
        {
            arr[++rear]=elt;
            return 2;
        }
    }
    return 0;
}
int AQueue::dequeue()
{
    int i;
    Computer o;
    if(!isEmpty())
    {
        if(front==0 && rear==0)
        {
            arr[front]=o;
            front=-1;
            rear=-1;
        }
        else
        {
            arr[front]=o;
            front++;
        }
        return 1;
    }
    else
    {
        return -1;
    }
}
int AQueue::peek()
{
    if(!isEmpty())
    {
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        arr[front].display();
        return 1;
    }
    else
    {
        return -1;
    }
}
int AQueue::search(string pros)
{
    int j=0;
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        for(int i=front;i<rear+1;i++)
        {
            if(arr[i].pros()==pros)
            {
                arr[i].display();
                j++;
            }
        }
        if(j>0)
        {
            return 1;
        }
    }
    return -2;
}
int AQueue::MakeQueueEmpty()
{
    int i;
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        Computer o;
        for(i=front;i<=rear;i++)
        {
            arr[i]=o;
            front++;
        }
        return 1;
    }
    return -2;
}
int AQueue::displayQueue()
{
    int i;
    if(!isEmpty())
    {
        cout<<"\nComputer Hardware details\n";
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        for(i=front;i<=rear;i++)
        {
            arr[i].display();
        }
        cout<<"\n\n";
        return 1;
    }
    else
    {
        return -1;
    }
}
int AQueue::size()
{
    if(!isEmpty())
    {
        return (rear-front)+1;
    }
    else
    {
        return -1;
    }
}
#include"computer.h"
int main()
{
    int choice,r,f,c,i,index,pos;
    string pros;
    Computer *a;
    Computer o[10];
    Computer ob;
    cout<<"\n***Computer Hardware Application***\n\n---Using Linear Queue ADT---\n";
    AQueue obj;
    while(1)
    {
        cout<<"\n\nPress\n1 for Enqueue\n2 for Dequeue\n3 for peek\n4 for search\n5 for make Queue empty\n6 for displaying the Queue\n7 for exiting\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nFor Enqueue...\n";
                cout<<"\nEnter the computer hardware details\n";
                ob.getdetails();
                if(obj.enqueue(ob))
                {
                    cout<<"\nEnqueued successfully...\n";
                    obj.displayQueue();
                }
                else
                    cout<<"\nQueue is full\n";
                break;
            }
            case 2:
            {
                cout<<"\nFor Dequeue..\n";
                i=obj.dequeue();
                if(i==1)
                {
                    cout<<"\nDequeue was done successfully...\n";
                    obj.displayQueue();
                }
                else
                    cout<<"\nQueue is empty\n";
                break;
            }
            case 3:
            {
                cout<<"\n";
                i=obj.peek();
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
                cout<<"\nEnter the processor name for searching:";
                cin>>pros;
                i=obj.search(pros);
                if(i==-1)
                {
                    cout<<"\nQueue is empty\n";
                }
                else if(i==-2)
                {
                    cout<<"\nElement not found..\n";
                }
                else
                {
                    cout<<"\nSearching was done successfully..."<<endl;
                }
                break;
            }
            case 5:
            {
                i=obj.MakeQueueEmpty();
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
                i=obj.displayQueue();
                if(i==-1)
                    cout<<"\nQueue empty...\n";
                else if(i==1)
                    cout<<"\nDisplayed successfully...\n";
                break;
            }
            case 7:
            {
                cout<<"Exiting...";
                exit(0);
            }
            default:
                cout<<"\nEnter the correct choice:";
        }
    }
}