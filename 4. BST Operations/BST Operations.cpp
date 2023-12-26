#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

class BST
{
public:
    node *root, *temp;

    BST()
    {
        root = NULL;
    }

    void create();
    void insert(node *root,node *temp);
    void inorder(node *root);
    void minnode(node *root);
    void maxnode(node *root);
    node* mirror(node *root);
    int height(node *root);
    int leafnode(node *root);
    void search(node *root, int);
};

void BST::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}

void BST::create()
{
    char ch;
    do{
        temp = new node;
        cout<<"Enter the Data : ";
        cin>>temp->data;
        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL)
        {
            root = temp;
        }
        else{
            insert(root,temp);
        }
        cout<<"Do you want to continue adding new nodes? (Y/n)";
        cin>>ch;
    }while(ch=='Y'|| ch=='y');
}

void BST::insert(node *root, node *temp)
{
    if(temp->data < root->data)
    {
        if(root->left==NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else if (temp->data > root->data)
    {
        if(root->right==NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}

void BST::minnode(node *root)
{
    temp = root;
    while(temp->left!=NULL)
    {
        temp = temp->left;
    }
    cout<<"Minimum Value is "<<temp->data<<endl;
}

void BST::maxnode(node *root)
{
    temp = root;
    while(temp->right!=NULL)
    {
        temp = temp->right;
    }
    cout<<"Maximum Value is "<<temp->data<<endl;
}
node* BST::mirror(node* root){
    if(root==NULL)
        return NULL;
    else
    {
        node *temp1 = root->left;
        root->left = mirror(root->right);
        root->right = mirror(temp1);
        return root;
    }
}

int BST::height(node *root)
{
    if(root==NULL)
        return(0);
    if (root->left == NULL && root->right)
        return(0);
    return(max(height(root->left),height(root->right))+1);
}

int BST::leafnode(node *root)
{
    if(root==NULL)
        return(0);
    if(root->left==NULL && root->right==NULL)
    {
        cout<<" "<<root->data;
        return(1);
    }
    return(leafnode(root->left)+leafnode(root->right));
}

int main()
{
    BST tree;

    tree.create();

    tree.inorder(tree.root);

    tree.minnode(tree.root);
    tree.maxnode(tree.root);
    tree.root = tree.mirror(tree.root);
    tree.inorder(tree.root);

    cout<<"Height :"<<tree.height(tree.root)<<endl;
    int i = tree.leafnode(tree.root);

}