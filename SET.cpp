#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Node;
class Set;
class Computer
{
    public:
        friend class Node;
        friend class Set;
        Computer();
        ~Computer();
        void getdetails();
        void display();
    private:
        string processor,gpu;
        int ram,hd,ATPO;    //Assembly test process order
};
class Node
{
    public:
        friend class Set;
        friend class Computer;
        Node();
        Node(Computer& ob , int info);
        ~Node();
    private:
        Computer data;
        int info;
};
class Set
{
    public:
        friend class Node;
        friend class Computer;
        Set(Node*,int);
        ~Set();
        int unionBySize(int,int);
        int find(int);
        void displaySet();
    private:
        Node *S;
        int capacity;
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
Node::Node()
{
    Computer o;
    data=o;
    info=-1;
}
Node::Node(Computer& ob,int info)
{
    data.processor=ob.processor;
    data.ATPO=ob.ATPO;
        data.gpu=ob.gpu;
        data.ram=ob.ram;                    //In GB
        data.hd=ob.hd;              //In TB
        this->info=info;
}
Node::~Node()
{
    info=-1;
}
Set::Set(Node *arr,int c)
{
    int i;
    capacity=c;
    S = new Node[c+1];
    for(i=1;i<=capacity;i++)
    {
        S[i]=arr[i];
    }
}
Set::~Set()
{
    capacity=0;
    delete S;
    S = NULL;
}
int Set::unionBySize(int root1,int root2)
{
    if(root1 != root2)
    {
        int size;
        size=S[root1].info + S[root2].info;
        if(S[root1].info <= S[root2].info)
        {
            S[root1].info=size;
            S[root2].info=root1;
            return 1;
        }
        else
        {
            S[root2].info=size;
            S[root1].info=root2;
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
int Set::find(int a)
{
    if(S[a].info>0)
    {
        return find(S[a].info);
    }
    else
    {
        return a;
    }
}
void Set::displaySet()
{
    int i,j;
    for(i=1;i<=capacity;i++)
    {
        if(S[i].info<0)
        {
            cout<<"\nRoot Node in a equivalence class: ";
            cout<<i<<endl;
            for(j=1;j<=capacity;j++)
            {
                if(S[j].info>0)
                {
                    if(i==S[j].info ||find(S[j].info)==i)
                    {
                        cout<<"\n\tNode in the same Equivalence class with root "<<i<<" is ";
                        cout<<j<<endl;
                    }
                }
            }
        }
        else
        {
            continue;
        }
    }
}
#include"computer.h"
int main()
{
    int i,c,capa,a,b,r1,r2;
    Computer o;
    cout<<"\n*****Computer Hardware Application*****\n\n";
    cout<<"Enter the size of the set:";
    cin>>capa;
    Node *arr=new Node[capa+1];
    for(i=1;i<=capa;i++)
    {
        cout<<"\nEnter the computer hardware details\n";
        o.getdetails();
        Node *n=new Node(o,-1);
        arr[i]=*n;
    }
    Set A(arr,capa);
    while(1)
    {
        cout<<"\n\nPress\n1 for Union\n2 for Find\n3 for Displaying the equivalence class\n4 for exiting\n\n";
        cin>>c;
        switch(c)
        {
            case 1:
            {
                cout<<"\nEnter the Number for union\n";
                cin>>a>>b;
                r1=A.find(a);
                r2=A.find(b);
                i=A.unionBySize(r1,r2);
                if(i==1)
                {
                    cout<<"\nUnion operation performed successfully...\n";
                    A.displaySet();
                }
                else if(i==0)
                    cout<<"\nAlready in same equivalence class...\n";
                break;
            }
            case 2:
            {
                cout<<"\nEnter the node to find the root node:";
                cin>>a;
                if(a<=capa && a>0)
                {
                    r1=A.find(a);
                    cout<<"\nThe root node is "<<r1<<endl;
                }
                else
                {
                    cout<<"\nEnter the valid node...\n";
                }
                break;
            }
            case 3:
            {
                A.displaySet();
                break;
            }
            case 4:
            {
                cout<<"Exiting...";
                exit(0);
            }
            default:
                cout<<"\nEnter the correct choice:";
        }
    }
}