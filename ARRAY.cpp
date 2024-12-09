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
                float screensize();
                string pro();
                string gpu1();
                int ram1();
                int hd();
        private:
                string processor,gpu;
                int ram,harddisk;
                float scrcsize;
};
class A_List
{
        public:
                A_List();
                A_List(Computer *,int,int);
                ~A_List();
                int isFull();
                int isEmpty();
                int insertAtFirst(Computer &elt);
                int insertAtLast(Computer &elt);
                int insertByPosition(Computer &elt,int pos);
                int insertByIndex(Computer &elt,int ind);
                int deleteAtFirst();
                int deleteAtLast();
                Computer searchByIndex(int ind);
                int searchByValue(float ss);
                int deleteBeforeGivenElement(Computer &o);
                int displayList();
                int length();
        private:
                Computer *arr;
                int size,capacity;
};
#include"computer.h"
Computer::Computer()
{
        processor="";
        gpu="";
        ram=0;              //In GB
        harddisk=0;     //In TB
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
float Computer::screensize()
{
    return scrcsize;
}
string Computer::gpu1()
{
    return gpu;
}
string Computer::pro()
{
    return processor;
}
int Computer::hd()
{
    return harddisk;
}
int Computer::ram1()
{
    return ram;
}
A_List::A_List()
{
        int i;
        capacity=5;
        size=0;
        arr=new Computer[capacity];
        Computer o;
        for(i=0;i<capacity;i++)
                arr[i]=o;
}
A_List::A_List(Computer *a,int s,int c)
{
        int i;
        capacity=c;
        size=s;
        arr=new Computer[capacity];
        for(i=0;i<size;i++)
                arr[i]=a[i];
        Computer o;
        for(i=size;i<capacity;i++)
        arr[i]=o;
}
A_List::~A_List()
{
        size=0;
        capacity=0;
        delete arr;
        arr = NULL;
}
int A_List::isFull()
{
        if(size == capacity)
                return 1;
        else
                return 0;
}
int A_List::isEmpty()
{
        if(size==0)
                return 1;
        else
                return 0;
}
int A_List::insertAtFirst(Computer& elt)
{
    int i;
    if(isEmpty())
    {
        arr[0]=elt;
        size++;
    }
    else if(!isFull())
    {
        for(i=size;i>0;i--)
            arr[i]=arr[i-1];
        arr[0]=elt;
        size++;
    }
    else
        return -1;
    return 1;
}
int A_List::insertAtLast(Computer& elt)
{
    int i;
    if(!isFull())
        arr[size++]=elt;
    else
        return -1;
    return 1;
}
int A_List::deleteAtFirst()
{
    int i;
    if(isEmpty())
        return -1;
    else
    {
        Computer obj;
        for(i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        arr[size-1]=obj;
        size--;
    }
    return 1;
}
int A_List::deleteAtLast()
{
    if(!isEmpty())
    {
        Computer obj;
        arr[size-1]=obj;
        size--;
        return 1;
    }
    else
        return -1;
}
Computer A_List::searchByIndex(int ind)
{
    return arr[ind];
}
int A_List::searchByValue(float ss)
{
    int i=0;
    if(size>0)
    {
        while(i<size)
        {
            if(arr[i].screensize()==ss)
            {
                return i;
            }
            i++;
        }
    }
    return -1;
}
int A_List::insertByIndex(Computer &elt,int ind)
{
    int i;
    if(ind<0 || ind>size)
    {
        return -1;
    }
    else
    {
        if((isFull()))
        {
            return -2;
        }
        else
        {
            for(i=size;i>ind;i--)
                arr[i]=arr[i-1];
            arr[ind]=elt;
            size++;
        }
        return 1;
    }
}
int A_List::insertByPosition(Computer &elt,int pos)
{
    int i;
    if(pos<0 || pos>size+1)
        return -1;
    else
    {
        if(isFull())
        {
            return -2;
        }
        else
        {
            for(i=size;i>pos-1;i--)
                arr[i]=arr[i-1];
            arr[pos-1]=elt;
            size++;
        }
        return 1;
    }

}
int A_List::deleteBeforeGivenElement(Computer &o)
{
    int i,j;
    Computer o1;
    for(i=1;i<size;i++)
    {
        if(o.pro()==arr[i].pro() && o.hd()==arr[i].hd() && o.screensize()==arr[i].screensize() && o.gpu1()==arr[i].gpu1() && o.ram1()==arr[i].ram1())
        {
            for(j=i;j<size;j++)
            {
                arr[j-1]=arr[j];
            }
            arr[size-1]=o1;
            size--;
            return 1;
        }

    }
    return -2;
}
int A_List::displayList()
{
    int i;
    if(!isEmpty())
    {
        cout<<"\nComputer Hardware details\n";
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        for(i=0;i<size;i++)
        {
            arr[i].display();
        }
        cout<<"\n\n";
    }
    else
        return -1;
    return 1;
}
int A_List::length()
{
    return size;
}
#include"computer.h"
int main()
{
    int choice,s,c,i,index,pos;
    float ss;
    Computer *a;
    Computer o[10];
    Computer ob;
    cout<<"Enter the size and capcity:";
    cin>>s>>c;
    a = new Computer[c];
    for(i=0;i<s;i++)
    {
        o[i].getdetails();
        a[i]=o[i];
    }
    A_List obj(a,s,c);
    while(1)
    {
        cout<<"\n\nPress\n1 for insert at first\n2 for insert at last\n3 for delete at first\n4 for delete at last\n5 for search by index\n6 for search by value\n7 for insert by position\n8 for delete before the given element\n9 for displaying the list\n10 for exiting\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nEnter the computer hardware details\n";
                ob.getdetails();
                if(obj.insertAtFirst(ob))
                {
                    cout<<"\nInserted successfully...\n";
                    obj.displayList();
                }
                else
                    cout<<"\nList is full\n";
                break;
            }
            case 2:
            {
                cout<<"\nEnter the computer hardware details\n";
                ob.getdetails();
                if(obj.insertAtLast(ob))
                {
                    cout<<"\nInserted successfully...\n";
                    obj.displayList();
                }
                else
                    cout<<"\nList is full\n";
                break;
            }
            case 3:
            {
                cout<<"\n";
                if(obj.deleteAtFirst()==1)
                {
                    cout<<"\nDeleted at First\n";
                    obj.displayList();
                }
                else
                {
                    cout<<"\nList is empty...\n"<<endl;
                }
                break;
            }
            case 4:
            {
                cout<<"\n";
                if(obj.deleteAtLast()==1)
                {
                    cout<<"\nDeleted element at last\n";
                    obj.displayList();
                }
                else
                    cout<<"\nList is empty...\n";
                break;
            }
            case 5:
            {
                cout<<"\nEnter the index for searching:";
                cin>>index;
                s=obj.length();
                if(index<0 || index>=s)
                {
                    cout<<"\nEnter index is beyond the bound\n";
                }
                else
                {
                    ob=obj.searchByIndex(index);
                    cout<<"\nDetails is present in the respective index:\n";
                    ob.display1();
                }
                break;
            }
            case 6:
            {
                cout<<"\nEnter the screen size for searching:";
                cin>>ss;
                index=obj.searchByValue(ss);
                if(index==-1)
                {
                    cout<<"\nElement not found or List is empty\n";
                }
                else
                {
                    cout<<"\nScreen Size is present in "<<index<<"th index"<<endl;
                    obj.displayList();
                }
                break;
            }
            case 7:
            {
                cout<<"Enter the position:";
                cin>>pos;
                cout<<"Enter the details to be inserted\n\n";
                ob.getdetails();
                i=obj.insertByPosition(ob,pos);
                if(i==-1)
                {
                    cout<<"\nThe position is beyond the size or less than 0\n";
                }
                else if(i==-2)
                {
                    cout<<"\nList is full...\n";
                }
                else
                {
                    cout<<"\nInserted successfully...\n";
                    obj.displayList();
                }
                break;
            }
            case 8:
            {
                cout<<"\nEnter the details that need to be present before the deleting detail\n";
                ob.getdetails();
                if(obj.deleteBeforeGivenElement(ob)==1)
                {
                        cout<<"\nDeleted successfully...\n";
                        obj.displayList();
                }
                else
                {
                        cout<<"\nEntered element is not present in the list or element is in first position...\n";
                }
                break;
            }
            case 9:
            {
                i=obj.displayList();
                if(i==-1)
                    cout<<"\nList empty...\n";
                else if(i==1)
                    cout<<"\nDisplayed successfully...\n";
                break;
            }
            case 10:
            {
                cout<<"Exiting...";
                exit(0);
            }
            default:
                cout<<"\nEnter the correct choice:";
        }
    }
}