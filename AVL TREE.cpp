#include<iostream>
#include<stdlib.h>
using namespace std;
class TreeNode;
class AVL;
class Computer
{
    public:
        friend class TreeNode;
        friend class AVL;
        Computer();
        ~Computer();
        void getdetails();
        void display();
    private:
        string processor,gpu;
        int ram,hd,ATPO;    //Assembly test process order
};
class TreeNode
{
    public:
        friend class AVL;
        friend class Computer;
        TreeNode(Computer &,TreeNode *,TreeNode *);
        ~TreeNode();
    private:
        TreeNode *left;
        TreeNode *right;
        Computer data;
        int height;
};
class AVL
{
    public:
        friend class TreeNode;
        friend class Computer;
        AVL();
        ~AVL();
        int isEmpty();
        int height(TreeNode*);
        int BF(TreeNode*);
        TreeNode* LLRotate(TreeNode*);
        TreeNode* RRRotate(TreeNode*);
        TreeNode* LRRotate(TreeNode*);
        TreeNode* RLRotate(TreeNode*);
        void inorder(TreeNode*);
        void preorder(TreeNode*);
        void postorder(TreeNode*);
        TreeNode* insertObject(TreeNode *temp,TreeNode *newNode);
        void findMin(TreeNode *temp);
        void findMax(TreeNode *temp);
        TreeNode* search(TreeNode *temp,int ATPO);
        TreeNode* getRoot();
        int setRoot(TreeNode*);
        int displayT(TreeNode*);
    private:
        TreeNode *root;
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
    cout<<processor<<"\t\t"<<ATPO<<"\t\t"<<gpu<<"\t\t"<<ram<<"\t"<<hd<<"\t\t"<<endl;
}
TreeNode::TreeNode(Computer &ob,TreeNode* right,TreeNode* left)
{
    data.processor=ob.processor;
    data.ATPO=ob.ATPO;
        data.gpu=ob.gpu;
        data.ram=ob.ram;                    //In GB
        data.hd=ob.hd;              //In TB
        right=right;
        left=left;
}
TreeNode::~TreeNode()
{
    right=NULL;
        left=NULL;
}
AVL::AVL()
{
    root=NULL;
}
AVL::~AVL()
{
    root=NULL;
}
int AVL::setRoot(TreeNode* root)
{
    this->root=root;
    return 1;
}
TreeNode* AVL::getRoot()
{
    return root;
}
int AVL::isEmpty()
{
    if(root==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
TreeNode* AVL::search(TreeNode* temp,int ATPO)
{
    int i;
    if(temp==NULL || temp->data.ATPO==ATPO)
    {
        return temp;
    }
    else if(temp->data.ATPO>ATPO)
    {
        temp=search(temp->left,ATPO);
    }
    else if(temp->data.ATPO<ATPO)
    {
        temp=search(temp->right,ATPO);
    }
    return temp;
}
TreeNode* AVL::LLRotate(TreeNode* a)
{
    TreeNode* s = a->left;
    TreeNode* temp = s->right;
    s->right = a;
    a->left = temp;
    a->height = max(height(a->left),height(a->right))+1;
    s->height = max(height(s->left),height(s->right))+1;
    return s;
}
TreeNode* AVL::RRRotate(TreeNode* a)
{
    TreeNode* s = a->right;
    TreeNode* temp = s->left;
    s->left = a;
    a->right = temp;
    a->height = max(height(a->left),height(a->right))+1;
    s->height = max(height(s->left),height(s->right))+1;
    return s;
}
TreeNode* AVL::LRRotate(TreeNode* a)
{
    a->left = RRRotate(a->left);
    return LLRotate(a);
}
TreeNode* AVL::RLRotate(TreeNode* a)
{
    a->right = LLRotate(a->right);
    return RRRotate(a);
}
void AVL::findMax(TreeNode* temp)
{
    if(temp->right!=NULL)
    {
        findMax(temp->right);
    }
    else
    {
        displayT(temp);
    }
}
int AVL::height(TreeNode* node)
{
    if(node==NULL)
    {
        return -1;
    }
    return node->height;
}
int AVL::BF(TreeNode* node)
{
    if(node==NULL)
    {
        return -1;
    }
    return (height(node->left)-height(node->right));
}
void AVL::findMin(TreeNode* temp)
{
    if(temp->left!=NULL)
    {
        findMin(temp->left);
    }
    else
    {
        displayT(temp);
    }
}
void AVL::inorder(TreeNode* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->data.processor<<"\t\t"<<temp->data.ATPO<<"\t\t"<<temp->data.gpu<<"\t"<<temp->data.ram<<"\t\t"<<temp->data.hd<<"\t\t"<<endl;
        inorder(temp->right);
    }
}
void AVL::preorder(TreeNode* temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data.processor<<"\t\t"<<temp->data.ATPO<<"\t\t"<<temp->data.gpu<<"\t"<<temp->data.ram<<"\t\t"<<temp->data.hd<<"\t\t"<<endl;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void AVL::postorder(TreeNode* temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data.processor<<"\t\t"<<temp->data.ATPO<<"\t\t"<<temp->data.gpu<<"\t"<<temp->data.ram<<"\t\t"<<temp->data.hd<<"\t\t"<<endl;
    }
}
TreeNode* AVL::insertObject(TreeNode* temp,TreeNode* newNode)
{
    if(root==NULL)
    {
        setRoot(newNode);
        return getRoot();
    }
    else
    {
        if(temp->data.ATPO < newNode->data.ATPO)
        {
            if(temp->right==NULL)
            {
                temp->right=newNode;
            }
            else
            {
                temp->right=insertObject(temp->right,newNode);
            }
        }
        else if(temp->data.ATPO > newNode->data.ATPO)
        {
            if(temp->left==NULL)
            {
                temp->left=newNode;
            }
            else
            {
                temp->left=insertObject(temp->left,newNode);
            }
        }
        else
        {
            return temp;
        }
        temp->height=max(height(temp->left),height(temp->right))+1;
        int balance = BF(temp);
        if(temp==getRoot())
        {
            if(balance > 1)
            {
                if(newNode->data.ATPO < temp->left->data.ATPO)
                {
                    cout<<"\nLL Rotation\n";
                    setRoot(LLRotate(temp));
                    return getRoot();
                }
                else if(newNode->data.ATPO > temp->left->data.ATPO)
                {
                    cout<<"\nLR Rotation\n";
                    setRoot(LRRotate(temp));
                    return getRoot();
                }
            }
            else if(balance < -1)
            {
                if(newNode->data.ATPO > temp->right->data.ATPO)
                {
                    cout<<"\nRR Rotation\n";
                    setRoot(RRRotate(temp));
                    return getRoot();
                }
                else if(newNode->data.ATPO < temp->right->data.ATPO)
                {
                    cout<<"\nRL Rotation\n";
                    setRoot(RLRotate(temp));
                    return getRoot();
                }
            }
        }
        else
        {
            if(balance > 1)
            {
                if(newNode->data.ATPO < temp->left->data.ATPO)
                {
                    cout<<"\nLL Rotation\n";
                    return LLRotate(temp);
                }
                else if(newNode->data.ATPO > temp->left->data.ATPO)
                {
                    cout<<"\nLR Rotation\n";
                    return LRRotate(temp);
                }
            }
            else if(balance < -1)
            {
                if(newNode->data.ATPO > temp->right->data.ATPO)
                {
                    cout<<"\nRR Rotation\n";
                    return RRRotate(temp);
                }
                else if(newNode->data.ATPO < temp->right->data.ATPO)
                {
                    cout<<"\nRL Rotation\n";
                    return RLRotate(temp);
                }
            }
        }
    }
    return temp;
}
int AVL::displayT(TreeNode* t)
{
    if(t!=NULL)
    {
        cout<<"Processor\tATPO\t\tGPU\t\tRam\tHarddisk\t\t"<<endl;
        t->data.display();
        return 1;
    }
    return 0;
}
#include"computer.h"
int main()
{
    int ATPO,choice,i;
    AVL A;
    TreeNode* root=NULL;
    A.setRoot(root);
    Computer S;
    cout<<"\n***Computer Hardware Application***\n\n----------Using AVL----------\n";
    while(1)
    {
        cout<<"\n\nPress\n1 for Insertion\n2 for FindMin\n3 for FindMax\n4 for Search\n5 for InOrder\n6 for PreOrder\n7 for PostOrder\n8 for Exiting\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nEnter the computer hardware details that needs to be inserted\n";
                S.getdetails();
                TreeNode *newnode=new TreeNode(S,NULL,NULL);
                TreeNode* t;
                root=A.getRoot();
                t=A.insertObject(root,newnode);
                if(t!=NULL)
                {
                    cout<<"\nInserted successfully...\n";
                }
                else
                    cout<<"\nInsertion not successfull\n";
                break;
            }
            case 2:
            {
                if(!A.isEmpty())
                {
                    cout<<"\n\nMINIMUM\n\n";
                    root=A.getRoot();
                    A.findMin(root);
                }
                else
                {
                    cout<<"\nAVL is Empty\n"<<endl;
                }
                break;
            }
            case 3:
            {
                if(!A.isEmpty())
                {
                    cout<<"\n\nMAXIMUM\n\n";
                    root=A.getRoot();
                    A.findMax(root);
                }
                else
                {
                    cout<<"\nAVL is Empty\n"<<endl;
                }
                break;
            }
            case 4:
            {
                if(!A.isEmpty())
                {
                    cout<<"\nEnter the ATPO number for searching\n";
                    cin>>ATPO;
                    root=A.getRoot();
                    TreeNode* t;
                    t=A.search(root,ATPO);
                    if(t!=NULL)
                    {
                        A.displayT(t);
                        cout<<"\n\nATPO Number found\n\n";
                    }
                    else
                    {
                        cout<<"\n\nATPO Number not found\n\n";
                    }
                }
                else
                {
                    cout<<"\nAVL is Empty\n"<<endl;
                }
                break;
            }
            case 5:
            {
                if(!A.isEmpty())
                {
                    cout<<"\n\nINORDER\n\n";
                    cout<<"Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    root=A.getRoot();
                    A.inorder(root);
                }
                else
                {
                    cout<<"\nAVL is Empty\n"<<endl;
                }
                break;
            }
            case 6:
            {
                if(!A.isEmpty())
                {
                    cout<<"\n\nPREORDER\n\n";
                    cout<<"Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    root=A.getRoot();
                    A.preorder(root);
                }
                else
                {
                    cout<<"\nAVL is Empty\n"<<endl;
                }
                break;
            }
            case 7:
            {
                if(!A.isEmpty())
                {
                    cout<<"\n\nPOSTORDER\n\n";
                    cout<<"Processor\tATPO\t\tGPU\tRam\tHarddisk\t\t"<<endl;
                    root=A.getRoot();
                    A.postorder(root);
                }
                else
                {
                    cout<<"\nAVL is Empty\n"<<endl;
                }
                break;
            }
            case 8:
            {
                cout<<"Exiting...";
                exit(0);
            }
            default:
                cout<<"\nEnter the correct choice:";
        }
    }
}