#include <iostream>

using namespace std;

struct node
{
    string name;
    int c_count;
    struct node *child[10];
};

class GT
{
public:
    node *root;
    GT()
    {
        root=NULL;
    };

    void create();
    void display();

};

void GT::create()
{
    int i,j,k, tbooks, tchap;
    root = new node;
    cout<<"Enter Name of Book:";
    cin>>root->name;
    cout<<endl<<"Enter no. of Chapters: ";
    cin>>tchap;
    root->c_count = tchap;

    for(i = 0; i<tchap; i++)
    {
        root->child[i] = new node;
        cout<<"Enter "<<i<<"th chapter name: ";
        cin>>root->child[i]->name;
        cout<<"Enter number of sections: ";
        cin>>j;
        root->child[i]->c_count = j;

        for(j=0; j<root->child[i]->c_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout<<"Enter the Name of Section "<<j<<" : ";
            cin>> root->child[i]->child[j]->name;
            cout<<"Enter the no. of sub section: ";
            cin>>k;
            root->child[i]->child[j]->c_count = k;

            for (k = 0; k<root->child[i]->child[j]->c_count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout<<"Enter the Name of Sub Section "<<k<<" : ";
                cin>> root->child[i]->child[j]->child[k]->name;

            }
        }
    }
}

void GT::display()
{
    int i,j,k;
    //root = new node;
    //cout<<"Enter Name of Book:";
    cout<<root->name<<endl;
    //cout<<endl<<"Enter no. of Chapters: ";
    //cout<<tchap;
    //root->c_count = tchap;

    for(i = 0; i<root->c_count; i++)
    {
      //  root->child[i] = new node;
        //cout<<"Enter "<<i<<"th chapter name: ";
        cout<<root->child[i]->name<<endl;
        //cout<<"Enter number of sections: ";
        //cin>>j;
        //root->child[i]->c_count = j;

        for(j=0; j<root->child[i]->c_count; j++)
        {
          //  root->child[i]->child[j] = new node;
            //cout<<"Enter the Name of Section "<<j<<" : ";
            cout<< root->child[i]->child[j]->name<<endl;
           // cout<<"Enter the no. of sub section: ";
            //cin>>k;
           // root->child[i]->child[j]->c_count = k;

            for (k = 0; k<root->child[i]->child[j]->c_count; k++)
            {
             //   root->child[i]->child[j]->child[k] = new node;
               // cout<<"Enter the Name of Sub Section "<<k<<" : ";
                cout<< root->child[i]->child[j]->child[k]->name<<endl;

            }
        }
    }
}


int main()
{
    GT g;
    g.create();

    g.display();

    return 0;
}