#include<iostream>
#include<stdlib.h>
using namespace std;
class TreeNode;
class BST;
class Computer
{
    public:
        friend class TreeNode;
        friend class BST;
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
        friend class BST;
        friend class Computer;
        TreeNode(Computer &,TreeNode *,TreeNode *);
        ~TreeNode();
    private:
        TreeNode *left;
        TreeNode *right;
        Computer data;
};
class BST
{
    public:
        friend class TreeNode;
        friend class Computer;
        BST();
        ~BST();
        int isEmpty();
        void inorder(TreeNode*);
        void preorder(TreeNode*);
        void postorder(TreeNode*);
        int insertObject(TreeNode *temp,TreeNode *newNode);
        TreeNode* deleteObject(TreeNode *temp,int ATPO);
        TreeNode* min(TreeNode*);
        TreeNode* minValueNode(TreeNode*);
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
BST::BST()
{
    root=NULL;
}
BST::~BST()
{
    root=NULL;
}
int BST::setRoot(TreeNode* root)
{
    this->root=root;
    return 1;
}
TreeNode* BST::getRoot()
{
    return root;
}
int BST::isEmpty()
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
TreeNode* BST::search(TreeNode* temp,int ATPO)
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
void BST::findMax(TreeNode* temp)
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
void BST::findMin(TreeNode* temp)
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
void BST::inorder(TreeNode* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->data.processor<<"\t\t"<<temp->data.ATPO<<"\t\t"<<temp->data.gpu<<"\t"<<temp->data.ram<<"\t\t"<<temp->data.hd<<"\t\t"<<endl;
        inorder(temp->right);
    }
}
void BST::preorder(TreeNode* temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data.processor<<"\t\t"<<temp->data.ATPO<<"\t\t"<<temp->data.gpu<<"\t"<<temp->data.ram<<"\t\t"<<temp->data.hd<<"\t\t"<<endl;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void BST::postorder(TreeNode* temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data.processor<<"\t\t"<<temp->data.ATPO<<"\t\t"<<temp->data.gpu<<"\t"<<temp->data.ram<<"\t\t"<<temp->data.hd<<"\t\t"<<endl;
    }
}
int BST::insertObject(TreeNode* temp,TreeNode* newNode)
{
    if(root==NULL)
    {
        setRoot(newNode);
        return 1;
    }
    else
    {
        if(temp->data.ATPO < newNode->data.ATPO)
        {
            if(temp->right==NULL)
            {
                temp->right=newNode;
                return 1;
            }
            else
            {
                insertObject(temp->right,newNode);
            }
        }
        else if(temp->data.ATPO > newNode->data.ATPO)
        {
            if(temp->left==NULL)
            {
                temp->left=newNode;
                return 1;
            }
            else
            {
                insertObject(temp->left,newNode);
            }
        }
        else
        {
            return 0;
        }
        return 1;
    }
}
TreeNode* BST::min(TreeNode* temp)
{
    if(temp->left!=NULL)
    {
        temp=min(temp->left);
    }
    else
    {
        return temp;
    }
    return temp;
}
TreeNode* BST::deleteObject(TreeNode* temp,int ATPO)
{
    if(temp==NULL)
    {
        return NULL;
    }
    else
    {
        if(temp->data.ATPO < ATPO)
        {
            temp->right=deleteObject(temp->right,ATPO);
        }
        else if(temp->data.ATPO > ATPO)
        {
            temp->left=deleteObject(temp->left,ATPO);
        }
        else
        {
            if(getRoot()->data.ATPO == ATPO)
            {
                if(temp->left==NULL && temp->right==NULL)
                {
                    setRoot(NULL);
                    return getRoot();
                }
                else if(temp->left == NULL && temp-> right != NULL)
                {
                    TreeNode *a = temp->right;
                    temp=NULL;
                    setRoot(a);
                    return getRoot();
                }
                else if(temp->right == NULL)
                {
                    TreeNode *a = temp->left;
                    temp=NULL;
                    setRoot(a);
                    return getRoot();
                }
                else if(temp->left!=NULL && temp->right!=NULL)
                {
                    TreeNode* t = min(temp->right);
                    temp->right = deleteObject(temp->right,t->data.ATPO);
                    temp->data = t->data;
                    setRoot(temp);
                    return getRoot();
                }
            }
            else if(temp->left==NULL && temp->right==NULL)
            {
                return NULL;
            }
            else if(temp->left == NULL && temp-> right != NULL)
            {
                TreeNode *a = temp->right;
                temp=NULL;
                return a;
            }
            else if(temp->right == NULL)
            {
                TreeNode *a = temp->left;
                temp=NULL;
                return a;
            }
            else if(temp->left!=NULL && temp->right!=NULL)
            {
                TreeNode* t = min(temp->right);
                temp->right = deleteObject(temp->right , t->data.ATPO);
                temp->data =t->data;
                return temp;
            }
        }
        return temp;
    }
}
int BST::displayT(TreeNode* t)
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
    BST A;
    TreeNode* root=NULL;
    A.setRoot(root);
    Computer S;
    cout<<"\n***Computer Hardware Application***\n\n----------Using BST----------\n";
    while(1)
    {
        cout<<"\n\nPress\n1 for Insertion\n2 for Deletion\n3 for FindMin\n4 for FindMax\n5 for Search\n6 for InOrder\n7 for PreOrder\n8 for PostOrder\n9 for Exiting\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nEnter the computer hardware details that needs to be inserted\n";
                S.getdetails();
                TreeNode *newnode=new TreeNode(S,NULL,NULL);
                root=A.getRoot();
                i=A.insertObject(root,newnode);
                if(i==1)
                {
                    cout<<"\nInserted successfully...\n";
                }
                else
                    cout<<"\nInsertion not successfull\n";
                break;
            }
            case 2:
            {
                cout<<"\nEnter the ATPO number for deletion\n";
                cin>>ATPO;
                root=A.getRoot();
                TreeNode* t;
                t=A.search(root,ATPO);
                if(t!=NULL)
                {
                    A.deleteObject(root,ATPO);
                    cout<<"\nDeleted successfully...\n";
                }
                else
                {
                    cout<<"\nDeletion not successfull...\n";
                }
                break;
            }
            case 3:
            {
                if(!A.isEmpty())
                {
                    cout<<"\n\nMINIMUM\n\n";
                    root=A.getRoot();
                    A.findMin(root);
                }
                else
                {
                    cout<<"\nBST is Empty\n"<<endl;
                }
                break;
            }
            case 4:
            {
                if(!A.isEmpty())
                {
                    cout<<"\n\nMAXIMUM\n\n";
                    root=A.getRoot();
                    A.findMax(root);
                }
                else
                {
                    cout<<"\nBST is Empty\n"<<endl;
                }
                break;
            }
            case 5:
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
                    cout<<"\nBST is Empty\n"<<endl;
                }
                break;
            }
            case 6:
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
                    cout<<"\nBST is Empty\n"<<endl;
                }
                break;
            }
            case 7:
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
                    cout<<"\nBST is Empty\n"<<endl;
                }
                break;
            }
            case 8:
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
                    cout<<"\nBST is Empty\n"<<endl;
                }
                break;
            }
            case 9:
            {
                cout<<"Exiting...";
                exit(0);
            }
            default:
                cout<<"\nEnter the correct choice:";
        }
    }
}