#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class MinHeap;
class Computer
{
    public:
        friend class MinHeap;
        Computer();
        ~Computer();
        void getdetails();
        void display();
    private:
        string processor,gpu;
        int ram,hd,ATPO;    //Assembly test process order
};
class MinHeap
{
    public:
        friend class Computer;
        MinHeap(int);
        ~MinHeap();
        int isEmpty();
        int isFull();
        int insertObject(Computer&);
        void deleteMin();
        Computer min();
        void displayHeap();
        int search(int);
    private:
        int heapsize,heapcap;
        Computer *heap;
};
#include"computer.h"
Computer::Computer()
{
    processor="0";
    gpu="0";
    ram=0;
    hd=0;
    ATPO=0;
}
Computer::~Computer()
{

}
void Computer::getdetails()
{
    cout<<"\nEnter the processor name:";
    cin>>processor;
    cout<<"Enter the partial serial number(partial ATPO):";
    cin>>ATPO;
    cout<<"Enter the gpu name:";
    cin>>gpu;
    cout<<"Enter the ram size:";
    cin>>ram;
    cout<<"Enter the hard disk capacity:";
    cin>>hd;
}
void Computer::display()
{
    cout<<processor<<"\t\t"<<ATPO<<"\t\t"<<gpu<<"\t"<<ram<<"\t"<<hd<<"\t\t"<<endl;
}
MinHeap::MinHeap(int c)
{
    int i,s;
    Computer o;
    heapsize=0;
    for(i=1,s=i;i<=c;i++)
    {
        s=s+pow(2,i);
    }
    cout<<s;
    heapcap=s+1;
    heap = new Computer[heapcap+1];
    for(i=1;i<heapcap+1;i++)
    {
        heap[i]=o;
    }
}
MinHeap::~MinHeap()
{
    heapsize=0;
    heapcap=0;
    delete heap;
    heap = NULL;
}
int MinHeap::isFull()
{
    if(heapsize==heapcap-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int MinHeap::isEmpty()
{
    if(heapsize==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Computer MinHeap::min()
{
    return heap[1];
}
int MinHeap::insertObject(Computer& o)
{
    Computer a;
    int i,j;
    if(!isFull())
    {
        heap[++heapsize]=o;
        for(i=heapsize,j=ceil(heapsize/2);i!=0 && j!=0;i=ceil(i/2),j=ceil(j/2))
        {
            if(heap[i].ATPO >= heap[j].ATPO)
            {
                break;
            }
            else if(heap[i].ATPO < heap[j].ATPO)
            {
                cout<<"\n"<<heap[i].ATPO<<" is percolated up\n";
                a = heap[i];
                heap[i]=heap[j];
                heap[j]=a;
            }
        }
        return 1;
    }
    return 0;
}
void MinHeap::deleteMin()
{
    int i,child;
    Computer o,a;
    heap[1]=heap[heapsize];
    heap[heapsize--]=o;
    for(i=1;i*2<=heapsize;i=child)
    {
        child=i*2;
        if(child != heapsize && heap[child+1].ATPO < heap[child].ATPO)
        {
            child++;
        }
        if(heap[i].ATPO > heap[child].ATPO)
        {
            cout<<"\n"<<heap[i].ATPO<<" is Percolated Down\n";
            a = heap[i];
            heap[i]=heap[child];
            heap[child] = a;
        }
        else
        {
            break;
        }
    }
}
int MinHeap::search(int atpo)
{
    int i;
    for(i=1;i<=heapsize;i++)
    {
        if(heap[i].ATPO == atpo)
        {
            cout<<"\nProcessor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
            heap[i].display();
            return 1;
        }
    }
    return 0;
}
void MinHeap::displayHeap()
{
    if(!isEmpty())
    {
        cout<<"\nMinHeap\n\n";
        int i;
        cout<<"Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
        for(i=1;i<=heapsize;i++)
        {
            heap[i].display();
        }
    }
    else
    {
        cout<<"\n\nMinheap is empty\n";
    }
}
#include"computer.h"
int main()
{
    int i,c,capa,atpo;
    Computer S;
    cout<<"\n*****Computer Hardware Application*****\n\n---Implementing Priority Queue using MinHeap---\n";
    cout<<"\nEnter the Height:";
    cin>>capa;
    MinHeap A(capa);
    while(1)
    {
        cout<<"\n\nPress\n1 for Insert\n2 for DeleteMin\n3 for Search\n4 for FindMin\n5 for Displaying the Minheap\n6 for exiting\n\n";
        cin>>c;
        switch(c)
        {
            case 1:
            {
                cout<<"\nEnter the computer hardware details\n";
                S.getdetails();
                i=A.insertObject(S);
                if(i)
                {
                    cout<<"\nInserted successfully...\n";
                    A.displayHeap();
                }
                else
                    cout<<"\nMinheap is full\n";
                break;
            }
            case 2:
            {
                if(!A.isEmpty())
                {
                    A.deleteMin();
                    cout<<"\nDeleted successfully...\n";
                    A.displayHeap();
                }
                else
                    cout<<"\nMinheap is empty\n";
                break;
            }
            case 3:
            {
                if(!A.isEmpty())
                {
                    cout<<"Enter the ATPO number for searching:";
                    cin>>atpo;
                    i=A.search(atpo);
                    if(i)
                    {
                        cout<<"\n\nElement Found\n";
                    }
                    else
                    {
                        cout<<"\n\nElement Not Found\n";
                    }
                }
                else
                    cout<<"\nMinheap is empty\n";
                break;
            }
            case 4:
            {
                if(!A.isEmpty())
                {
                    Computer a=A.min();
                    cout<<"\nMinimum Element...\n";
                    cout<<"Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    a.display();
                }
                else
                    cout<<"\nMinheap is empty\n";
                break;
            }
            case 5:
            {
                A.displayHeap();
            }
            case 6:
            {
                cout<<"Exiting...";
                exit(0);
            }
            default:
                cout<<"\nEnter the correct choice:";
        }
    }
}