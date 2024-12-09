#include<stdlib.h>
using namespace std;
class Graph;
class CQueue;
class Computer
{
    public:
        friend class Graph;
        friend class CQueue;
        Computer();
        ~Computer();
        void getdetails();
        void display();
    private:
        string processor,gpu;
        int ram,hd,ATPO;    //Assembly test process order
};
class Graph
{
    public:
        friend class Computer;
        Graph(int v);
        ~Graph();
        void getGraph();
        void getAdjMatrix();
        void dfs(int);
        void DFS(int);
        void BFS(int);
        void displayAdj();
    private:
        int v;
        Computer *vertex;
        int **adj;
        bool *visited;

};
class CQueue
{
    public:
        friend class Computer;
        CQueue(int);
        ~CQueue();
        int isFull();
        int isEmpty();
        int dequeue();
        int enqueue(int);
    private:
        int *arr;
        int front,rear,capacity;
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
    cout<<processor<<"\t"<<ATPO<<"\t\t"<<gpu<<"\t"<<ram<<"\t"<<hd<<"\n"<<endl;
}
CQueue::CQueue(int c)
{
    int i;
    capacity=c;
    front=-1;
    rear=-1;
    arr=new int[capacity];
    for(i=0;i<capacity;i++)
        arr[i]=-1;
}
CQueue::~CQueue()
{
    rear=0;
    front=0;
    capacity=0;
    delete[] arr;
    arr = NULL;
}
int CQueue::isFull()
{
    if((rear+1)%capacity == front)
        return 1;
    else
        return 0;
}
int CQueue::isEmpty()
{
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}
int CQueue::enqueue(int elt)
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
            return -1;
        }
        else
        {
            rear=(rear+1)%capacity;
            arr[rear]=elt;
            return 2;
        }
    }
    return -1;
}
int CQueue::dequeue()
{
    int i;
    if(!isEmpty())
    {
        if(front==rear)
        {
            i=arr[front];
            arr[front]=-1;
            front=-1;
            rear=-1;
            return i;
        }
        else
        {
            i=arr[front];
            arr[front]=-1;
            front =(front+1)%capacity;
            return i;
        }
        return 1;
    }
    else
    {
        return -1;
    }
}
Graph::Graph(int v)
{
    this->v=v;
    vertex = new Computer[v];
    adj = new int*[v];
    for(int i=0;i<v;i++)
    {
        adj[i] = new int[v];
    }
    visited = new bool[v];
}
Graph::~Graph()
{
    delete[] vertex;
    vertex = NULL;
    for(int i=0;i<v;i++)
    {
        delete[] adj[i];
    }
    delete [] adj;
    adj = NULL;
    delete[] visited;
    visited = NULL;
}
void Graph::getGraph()
{
    Computer o;
    for(int i=0;i<v;i++)
    {
        o.getdetails();
        vertex[i]=o;
    }
}
void Graph::getAdjMatrix()
{
    int k;
    cout<<"\nType 1 if a vertex is connected else Type 0\n";
    for(int i=0;i<v;i++)
    {
        cout<<"\nIs Vertex V"<<i+1<<" is Connected to any other vertex"<<endl;
        for(int j=0;j<v;j++)
        {
            cin>>k;
            adj[i][j]=k;
        }
    }
}
void Graph::displayAdj()
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

void Graph::dfs(int s)
{
    int i;
    for(i=0;i<v;i++)
    {
        visited[i]=false;
    }
    DFS(s);
    for(i=0;i<v;i++)
    {
        if(!visited[i])
        {
            cout<<"\nDisconnected Graph\n\n";
            cout<<"   Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
            DFS(i);
        }
    }

}
void Graph::DFS(int s)
{
    int j;
    visited[s]=true;
    cout<<s<<": ";
    vertex[s].display();
    for(j=0;j<v;j++)
    {
        if(adj[s][j])
        {
            if(!visited[j])
            {
                DFS(j);
            }
        }
    }
}
void Graph::BFS(int s)
{
    int i,j;
    for(i=0;i<v;i++)
    {
        visited[i]=false;
    }
    CQueue A(v);
    start:
    {
        A.enqueue(s);
        while(!A.isEmpty())
        {
            s=A.dequeue();
            if(!visited[s])
            {
                cout<<s<<": ";
                vertex[s].display();
            }
            visited[s]=true;
            for(j=0;j<v && s>=0;j++)
            {
                if(adj[s][j])
                {
                    if(!visited[j])
                    {
                        A.enqueue(j);
                    }
                }
            }
        }
        for(i=0;i<v;i++)
        {
            if(!visited[i])
            {
                cout<<"\nDisconnected Graph\n\n";
                cout<<"   Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                s=i;
                goto start;
            }
        }
    }

}
#include"computer.h"
int main()
{
    int v,c,s;
    cout<<"\n*******Graph Traversal*******\n";
    cout<<"\nEnter the no.of vertices:";
    cin>>v;
    Graph A(v);
    A.getGraph();
    A.getAdjMatrix();
    while(1)
    {
        cout<<"\nPress\n1 for DFS(Depth First Search)\n2 for BFS(Breath First Search)\n3 for displaying adjacency matrix\n4 for exit\n";
        cin>>c;
        switch(c)
        {
            case 1:
            {
                cout<<"\nDFS\nEnter the start vertex:";
                cin>>s;
                if(s>v-1)
                {
                    cout<<"\nGiven start vertex is beyond the bound\n";
                }
                else
                {
                    cout<<"   Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    A.dfs(s);
                }
                break;
            }
            case 2:
            {
                cout<<"\nBFS\nEnter the start vertex:";
                cin>>s;
                if(s>v-1)
                {
                    cout<<"\nGiven start vertex is beyond the bound\n";
                }
                else
                {
                    cout<<"   Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    A.BFS(s);
                }
                break;
            }
            case 3:
            {
                cout<<"\nAdjacency Matrix\n";
                A.displayAdj();
                break;
            }
            case 4:
            {
                cout<<"\nExiting...\n";
                exit(0);
            }
            default:
            {
                cout<<"\nEnter the correct choice\n";
            }
        }
    }

}