#include<iostream>
#include<stdlib.h>
using namespace std;
class AStack;
class Computer
{
    public:
        friend class AStack;
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
class AStack
{
    public:
        AStack();
        AStack(Computer *,int,int);
        ~AStack();
        int isFull();
        int isEmpty();
        int pop();
        int push(Computer &elt);
        int peek();
        int search(string pros);
        int size();
        int displayStack();
        int MakeStackEmpty();
    private:
        Computer *arr;
        int top,capacity;
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
AStack::AStack()
{
    int i;
    capacity=5;
    top=-1;
    arr=new Computer[capacity];
    Computer o;
    for(i=0;i<capacity;i++)
        arr[i]=o;
}
AStack::AStack(Computer *a,int t,int c)
{
    int i;
    capacity=c;
    top=t;
    arr=new Computer[capacity];
    for(i=0;i<top+1;i++)
        arr[i]=a[i];
    Computer o;
    for(i=top+1;i<capacity;i++)
        arr[i]=o;
}
AStack::~AStack()
{
    top=0;
    capacity=0;
    delete arr;
    arr = NULL;
}
int AStack::isFull()
{
    if(top == capacity-1)
        return 1;
    else
        return 0;
}
int AStack::isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int AStack::push(Computer& elt)
{
    int i;
    if(isFull())
    {
        return 0;
    }
    else if(!isEmpty())
    {
        arr[++top]=elt;
        return 1;
    }
    else
    {
        arr[0]=elt;
        top++;
        return 1;
    }
    return -1;
}
int AStack::pop()
{
    int i;
    if(!isEmpty())
    {
        Computer o;
        arr[top--]=o;
        return 1;
    }
    else
    {
        return 0;
    }
}
int AStack::peek()
{
    if(!isEmpty())
    {
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        arr[top].display();
        return 1;
    }
    else
    {
        return -1;
    }
}
int AStack::search(string pros)
{
    int j=0;
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        for(int i=0;i<top+1;i++)
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
int AStack::MakeStackEmpty()
{
    int i;
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        Computer o;
        for(i=top;i>=0;i--)
        {
            arr[i]=o;
            top--;
        }
        return 1;
    }
    return -2;
}
int AStack::displayStack()
{
    int i;
    if(!isEmpty())
    {
        int t=top;
        cout<<"\nComputer Hardware details\n";
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        for(i=t;i>=0;i--)
        {
            arr[i].display();
        }
        cout<<"\n\n";
    }
    else
        return -1;
    return 1;
}
int AStack::size()
{
    if(!isEmpty())
    {
        return top+1;
    }
    else
    {
        return -1;
    }
}
#include"computer.h"
int main()
{
    int choice,t,c,i,index,pos;
    string pros;
    Computer *a;
    Computer o[10];
    Computer ob;
    cout<<"\n***Computer Hardware Application***\n\n---Using Stack ADT---\n";
    AStack obj;
    while(1)
    {
        cout<<"\n\nPress\n1 for push\n2 for pop\n3 for peek\n4 for search\n5 for make stack empty\n6 for displaying the stack\n7 for exiting\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nFor Pushing...\n";
                cout<<"\nEnter the computer hardware details\n";
                ob.getdetails();
                if(obj.push(ob))
                {
                    cout<<"\nPushed successfully...\n";
                    obj.displayStack();
                }
                else
                    cout<<"\nStack is full\n";
                break;
            }
            case 2:
            {
                i=obj.pop();
                if(i==1)
                {
                    cout<<"\nPoping was done successfully...\n";
                    obj.displayStack();
                }
                else
                    cout<<"\nStack is empty\n";
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
                    cout<<"\nStack is empty...\n"<<endl;
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
                    cout<<"\nStack is empty\n";
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
                i=obj.MakeStackEmpty();
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
                i=obj.displayStack();
                if(i==-1)
                    cout<<"\nStack empty...\n";
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