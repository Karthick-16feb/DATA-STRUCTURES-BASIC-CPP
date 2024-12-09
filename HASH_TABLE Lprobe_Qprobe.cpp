#include<stdlib.h>
#include<math.h>
using namespace std;
class LProbing;
class QProbing;
class Computer
{
    public:
        friend class LProbing;
        friend class QProbing;
        Computer();
        ~Computer();
        void getdetails();
        void display();
    private:
        string processor,gpu;
        int ram,hd,ATPO;    //Assembly test process order
};
class LProbing
{
    public:
        friend class Computer;
        LProbing(int);
        ~LProbing();
        int isEmpty();
        int isFull();
        int insertObject(Computer&);
        int deleteObject(int);
        void displayL();
        int search(int);
    private:
        int size,cap;
        Computer *table;
};
class QProbing
{
    public:
        friend class Computer;
        QProbing(int);
        ~QProbing();
        int isEmpty();
        int isFull();
        int insertObject(Computer&);
        int deleteObject(int);
        void displayQ();
        int search(int);
    private:
        int size,cap;
        Computer *table;
};
#include"computer.h"
Computer::Computer()
{
    processor="0";
    gpu="0";
    ram=0;
    hd=0;
    ATPO=-1;
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
    cout<<processor<<"\t\t"<<ATPO<<"\t\t"<<gpu<<"\t"<<ram<<"\t"<<hd<<"\n"<<endl;
}
LProbing::LProbing(int c)
{
    int i;
    Computer o;
    cap=c;
    size=0;
    table = new Computer[c];
    for(i=0;i<c;i++)
    {
        table[i]=o;
    }
}
LProbing::~LProbing()
{
    size=0;
    cap=0;
    delete[] table;
    table = NULL;
}
QProbing::QProbing(int c)
{
    int i;
    Computer o;
    cap=c;
    size=0;
    table=new Computer[cap];
    for(i=0;i<c;i++)
    {
        table[i]=o;
    }
}
QProbing::~QProbing()
{
    size=0;
    cap=0;
    delete[] table;
    table = NULL;
}
int LProbing::isFull()
{
    if(size==cap)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int LProbing::isEmpty()
{
    if(size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int LProbing::insertObject(Computer& A)
{
    if(!isFull())
    {
        int i,j,k;
        i=A.ATPO%cap;
        if(table[i].ATPO==-1)
        {
            table[i]=A;
            size++;
            return 1;
        }
        else
        {
            for(j=1;j<=cap;j++)
            {
                k=(i+j)%cap;
                if(table[k].ATPO==-1)
                {
                    table[k]=A;
                    size++;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int LProbing::deleteObject(int atpo)
{
    if(!isEmpty())
    {
        int i,j,k;
        Computer r;
        i=atpo%cap;
        if(table[i].ATPO==atpo)
        {
            table[i]=r;
            size--;
            return 1;
        }
        else
        {
            for(j=1;j<=cap;j++)
            {
                k=(i+j)%cap;
                if(table[k].ATPO==atpo)
                {
                    table[k]=r;
                    size--;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int LProbing::search(int atpo)
{
    if(!isEmpty())
    {
        int i,j,k;
        i=atpo%cap;
        if(table[i].ATPO==atpo)
        {
            cout<<"Processor\t\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
            cout<<i<<": ";
            table[i].display();
            return 1;
        }
        else
        {
            for(j=1;j<=cap;j++)
            {
                k=(i+j)%cap;
                if(table[k].ATPO==atpo)
                {
                    cout<<"Processor\t\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    cout<<k<<": ";
                    table[k].display();
                    return 1;
                }
            }
        }
        return 2;
    }
    return 0;
}
void LProbing::displayL()
{
    int i;
    cout<<"Processor\t\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
    for(i=0;i<cap;i++)
    {
        cout<<i<<": ";
        if(table[i].ATPO==-1)
        {
                cout<<"\t";
        }
        table[i].display();
    }
}
int QProbing::isFull()
{
    if(size==cap)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int QProbing::isEmpty()
{
    if(size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int QProbing::insertObject(Computer& A)
{
    if(!isFull())
    {
        int i,j,k,s;
        i=A.ATPO%cap;
        if(table[i].ATPO==-1)
        {
            table[i]=A;
            size++;
            return 1;
        }
        else
        {
            for(j=1;j<=cap;j++)
            {
                s=(int)(pow(j,2)+0.5);
                k=(i+(s))%cap;
                if(table[k].ATPO==-1)
                {
                    table[k]=A;
                    size++;
                    return 1;
                }
           }
        }
        return 2;
    }
    return 0;
}
int QProbing::deleteObject(int atpo)
{
    if(!isEmpty())
    {
        int i,j,k,s;
        Computer r;
        i=atpo%cap;
        if(table[i].ATPO==atpo)
        {
            table[i]=r;
            size--;
            return 1;
        }
        else
        {
            for(j=1;j<=cap;j++)
            {
                s=(int)(pow(j,2)+0.5);
                k=(i+(s))%cap;
                if(table[k].ATPO==atpo)
                {
                    table[k]=r;
                    size--;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int QProbing::search(int atpo)
{
    if(!isEmpty())
    {
        int i,j,k,s;
        i=atpo%cap;
        if(table[i].ATPO==atpo)
        {
            cout<<"Processor\t\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
            cout<<i<<": ";
            table[i].display();
            return 1;
        }
        else
        {
            for(j=1;j<=cap;j++)
            {
                s=(int)(pow(j,2)+0.5);
                k=(i+(s))%cap;
                if(table[k].ATPO==atpo)
                {
                    cout<<"Processor\t\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    cout<<k<<": ";
                    table[k].display();
                    return 1;
                }
            }
        }
        return 2;
    }
    return 0;
}
void QProbing::displayQ()
{
    int i;
    cout<<"Processor\t\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
    for(i=0;i<cap;i++)
    {
        cout<<i<<": ";
        if(table[i].ATPO==-1)
        {
                cout<<"\t";
        }

        table[i].display();
    }
}
#include"computer.h"
int main()
{
    int i,c,ch,atpo,a;
    Computer o;
    cout<<"\n*****Computer Hardware Application*****\n\n----Hash Table ADT----\n\n";
    cout<<"Enter the tablesize:";
    cin>>c;
    LProbing A(c);
    QProbing S(c);
    while(1)
    {
    start:
    {
        cout<<"\n\nPress\n1 for Linear Probing\n2 for Quadratic Probing\n3 for Exiting\n\n";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                while(1)
                {
                    cout<<"\n\nPress\n1 for Insertion\n2 for Deletion\n3 for Search\n4 for Displaying the hashing table\n5 for exiting\n\n";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                        {
                            cout<<"\nEnter the computer hardware details\n";
                            o.getdetails();
                            i=A.insertObject(o);
                            if(i==1)
                            {
                            cout<<"\nInserted successfully\n";
                            A.displayL();
                            }
                            else
                            {
                            cout<<"\nTable is full\n";
                            }
                            break;
                        }
                        case 2:
                        {
                            cout<<"\nEnter the atpo number for deletion:";
                            cin>>atpo;
                            i=A.deleteObject(atpo);
                            if(i==1)
                            {
                                cout<<"\nDeleted successfull....\n";
                                A.displayL();
                            }
                            else
                            {
                                cout<<"\nDeletion not successfull....\n";
                            }
                            break;
                        }
                        case 3:
                        {
                            cout<<"\nEnter the atpo number for searching:";
                            cin>>atpo;
                            i=A.search(atpo);
                            if(i==1)
                            {
                                cout<<"\nElement Found....\n";
                            }
                            else if(i==2)
                            {
                                cout<<"\nElement Not Found....\n";
                            }
                            else
                            {
                                cout<<"\nHashing table is empty\n";
                            }
                            break;
                        }
                        case 4:
                        {
                            A.displayL();
                            break;
                        }
                        case 5:
                        {
                            cout<<"Exiting...";
                            goto start;
                        }
                        default:
                            cout<<"\nEnter the correct choice:";
                    }
                }
                break;
            }
            case 2:
            {
                while(1)
                {
                    cout<<"\n\nPress\n1 for Insertion\n2 for Deletion\n3 for Search\n4 for Displaying the hashing table\n5 for exiting\n\n";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                        {
                            cout<<"\nEnter the computer hardware details\n";
                            o.getdetails();
                            i=S.insertObject(o);
                            if(i==1)
                            {
                            cout<<"\nInserted successfully\n";
                            S.displayQ();
                            }
                            else
                            {
                            cout<<"\nTable is full\n";
                            }
                            break;
                        }
                        case 2:
                        {
                            cout<<"\nEnter the atpo number for deletion:";
                            cin>>atpo;
                            i=S.deleteObject(atpo);
                            if(i==1)
                            {
                                cout<<"\nDeleted successfull....\n";
                                S.displayQ();
                            }
                            else
                            {
                                cout<<"\nDeletion not successfull....\n";
                            }
                            break;
                        }
                        case 3:
                        {
                            cout<<"\nEnter the atpo number for searching:";
                            cin>>atpo;
                            i=S.search(atpo);
                            if(i==1)
                            {
                                cout<<"\nElement Found....\n";
                            }
                            else if(i==2)
                            {
                                cout<<"\nElement Not Found....\n";
                            }
                            else
                            {
                                cout<<"\nHashing table is empty\n";
                            }
                            break;
                        }
                        case 4:
                        {
                            S.displayQ();
                            break;
                        }
                        case 5:
                        {
                            cout<<"Exiting...";
                            goto start;
                        }
                        default:
                            cout<<"\nEnter the correct choice:";
                    }
                }
                break;
            }
            case 3:
            {
                cout<<"\nExiting....\n";
                exit(0);
            }
            default:
            {
                cout<<"\nEnter the correct choice\n";
            }
        }
   }
 }

}