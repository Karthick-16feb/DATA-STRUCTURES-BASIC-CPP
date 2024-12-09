#include<iostream>
#include<stdlib.h>
using namespace std;
class LList;
class Node;
class Computer
{
        public:
                friend class Node;
                friend class LList;
                Computer();
                ~Computer();
                void getdetails();
                void display1();
                void display();
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
class Node
{
    public:
        friend class LList;
        Node(Computer&,Node*);
        ~Node();
    private:
        Computer data;
        Node *next;
};
class LList
{
    public:
        LList();
        ~LList();
                int isEmpty();
                int insertAtFirst(Node *newnode);
                int insertAtLast(Node *newnode);
                int deleteByPosition(int pos);
                int insertByPosition(Node *newnode,int pos);
                int deleteAtFirst();
                int deleteAtLast();
                int searchByValue(string processor);
                int insertBeforeGivenElement(Node *newn,Node *newnode);
                int displayList();
    private:
        Node *first;
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
LList::LList()
{
    first=NULL;
}
LList::~LList()
{
    delete first;
    first=NULL;
}
int LList::isEmpty()
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
int LList::insertAtFirst(Node *newnode)
{
    if(isEmpty())
    {
        first=newnode;
    }
    else
    {
        newnode->next=first;
        first=newnode;
    }
    return 1;
}
int LList::insertAtLast(Node *newnode)
{
    if(isEmpty())
    {
        first=newnode;
    }
    else
    {
        Node *temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return 1;
}
int LList::deleteAtLast()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        if(first->next!=NULL)
        {
            Node *temp=first;
            Node *prev=first;
            while(temp->next != NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            delete temp;
            temp = NULL;
        }
        else
        {
            delete first;
            first == NULL;
        }
    }
    return 1;
}
int LList::deleteAtFirst()
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
}
int LList::insertBeforeGivenElement(Node *newn , Node *newnode)
{
    int i=0;
    if(isEmpty())
    {
        return -1;
    }
    else if(first->next==NULL)
    {
        if(first->data.scrcsize==newnode->data.scrcsize)
        {
            newn->next=first;
            first=newn;
            return 1;
        }
    }
    else
    {
        Node *temp=first;
        Node *prev=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            if(temp->data.scrcsize==newnode->data.scrcsize && temp->data.processor==newnode->data.processor && temp->data.harddisk==newnode->data.harddisk && temp->data.gpu==newnode->data.gpu && temp->data.ram==newnode->data.ram)
            {
                newn->next=temp;
                prev->next=newn;
                i++;
            }
            prev=prev->next;
            if(i>0)
            {
                return 1;
            }
        }

    }
    return -2;
}
int LList::deleteByPosition(int pos)
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        if(first->next==NULL && pos==1)
        {
            delete first;
            first=NULL;
            return 1;
        }
        else if(first->next!=NULL && pos==1)
        {
            Node *temp=first;
            first=temp->next;
            delete temp;
            return 1;
        }
        else
        {
            int i=1;
            Node *temp=first;
            Node *prev=first;
            while(temp->next!=NULL && i!=pos)
            {
                prev=temp;
                temp=temp->next;
                i++;
            }
            if(i==pos)
            {
                prev->next=temp->next;
                delete temp;
                temp=NULL;
            }
            return 1;
        }
    }
    return -2;
}
int LList::insertByPosition(Node *newnode,int pos)
{
    if(isEmpty())
    {
        if(pos==1)
        {
            first=newnode;
            return 1;
        }
        else if(pos!=1)
        {
            return -1;
        }
    }
    else
    {
        int i=1;
        Node *temp=first;
        Node *prev=first;
        if(first->next!=NULL && i==pos)
        {
            newnode->next=first;
            first=newnode;
            return 1;
        }
        while(temp->next!=NULL && i != pos)
        {
            temp=temp->next;
            i++;
            if(i==pos)
            {
                continue;
            }
            prev=prev->next;
        }
        if(i==pos)
        {
            newnode->next=temp;
            prev->next=newnode;
            return 1;
        }
    }
    return -2;
}
int LList::searchByValue(string processor)
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        int i=1;
        Node *temp=first;
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        while(temp!=NULL)
        {
            if(temp->data.processor==processor)
            {
                temp->data.display();
            }
            temp=temp->next;
        }
        return 1;
    }
    return -2;
}
int LList::displayList()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        Node *temp=first;
        cout<<"\nComputer Hardware details\n";
        cout<<"Processor\tGPU\t\tRam\tHarddisk\tScreensize\t"<<endl;
        while(temp!=NULL)
        {
            temp->data.display();
            temp=temp->next;
        }
        return 1;
    }
}
#include"computer.h"
int main()
{
    int choice,s,c,i,index,pos;
    float ss;
    string processor;
    Computer ob,o;
    LList obj;
    while(1)
    {
        cout<<"\n\nPress\n1 for Insert at first\n2 for Insert at last\n3 for Delete at first\n4 for Delete at last\n5 for Delete by position\n6 for Search by value\n7 for Insert by position\n8 for Insert before the given element\n9 for Displaying the linked list\n10 for Exiting\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nEnter the computer hardware details\n";
                ob.getdetails();
                Node *newnode=new Node(ob,NULL);
                i=obj.insertAtFirst(newnode);
                if(i==1)
                {
                    cout<<"\nInserted successfully...\n";
                    obj.displayList();
                }
                else
                    cout<<"\nInsertion not successfull\n";
                break;
            }
            case 2:
            {
                cout<<"\nEnter the computer hardware details\n";
                ob.getdetails();
                Node *newnode=new Node(ob,NULL);
                i=obj.insertAtLast(newnode);
                if(i==1)
                {
                    cout<<"\nInserted successfully...\n";
                    obj.displayList();
                }
                else
                    cout<<"\nInsertion not successfull\n";
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
                cout<<"Enter the position:";
                cin>>pos;
                i=obj.deleteByPosition(pos);
                if(i==-2)
                {
                    cout<<"\nThe position is beyond the availability or less than 0\n";
                }
                else if(i==-1)
                {
                    cout<<"\nList is empty";
                }
                else if(i==1)
                {
                    cout<<"\nDeleted successfully...\n";
                    obj.displayList();
                }
                break;
            }
            case 6:
            {
                cout<<"\nEnter the processor that need to be searched:";
                cin>>processor;
                i=obj.searchByValue(processor);
                if(i==-1)
                {
                    cout<<"\nList is empty...\n";
                }
                else if(i==-2)
                {
                    cout<<"\nDetails is not present in the index..\n";
                }
                else
                {
                    cout<<"\nSearched successfully..\n";
                }
                break;
            }
            case 7:
            {
                cout<<"Enter the position:";
                cin>>pos;
                cout<<"Enter the details to be inserted\n\n";
                ob.getdetails();
                Node *newnode=new Node(ob,NULL);
                i=obj.insertByPosition(newnode,pos);
                if(i==-2)
                {
                    cout<<"\nThe position is beyond the availability or less than 0\n";
                }
                else if(i==-1)
                {
                    cout<<"\nList is empty...\n";
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
                cout<<"\nEnter the details of the computer that need to be checked for before insertion\n";
                ob.getdetails();
                Node *newnode=new Node(ob,NULL);
                cout<<"\nEnter the details of the computer that need to be inserted\n";
                o.getdetails();
                Node *newn=new Node(o,NULL);
                i=obj.insertBeforeGivenElement(newn,newnode);
                if(i==1)
                {
                    cout<<"Inserted successfully...\n";
                    obj.displayList();
                }
                else if(i==-1)
                {
                    cout<<"\nList empty\n";
                }
                else if(i==-2)
                {
                    cout<<"\nGiven details is not present...\n";
                }
                break;
            }
            case 9:
            {
                i=obj.displayList();
                if(i==-1)
                    cout<<"\nList empty...\nDisplaying is not possible\n";
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