
#include<iostream>
using namespace std;
#define SIZE 10
class OBST
{
int p[SIZE]; // Probabilities with which we search for an element
int q[SIZE];//Probabilities that an element is not found
int a[SIZE];//Elements from which OBST is to be built
int w[SIZE][SIZE];//Weight ‘w[i][j]’ of a tree having root
//’r[i][j]’
int c[SIZE][SIZE];//Cost ‘c[i][j] of a tree having root ‘r[i][j]
int r[SIZE][SIZE];//represents root
int n; // number of nodes
public:
/* This function accepts the input data */
void get_data()
{
int i;
cout<<"\n Optimal Binary Search Tree \n";
cout<<"\n Enter the number of nodes";
cin>>n;
cout<<"\n Enter the data as…\n";
for(i=1;i<=n;i++)
{
cout<<"\n a["<<i<<"]";
cin>>a[i];
}
for(i=1;i<=n;i++)
{
cout<<"\n p["<<i<<"]";
cin>>p[i];
}
for(i=0;i<=n;i++)
{
cout<<"\n q["<<i<<"]";
cin>>q[i];
}
}
void build_OBST()
{
      int i,j,k,l,min;
      for(i=0;i<n;i++)
      { //Initialisation
            c[i][i]=0.0;
            r[i][i]=0;
            w[i][i]=q[i];
         // for j-i=1 can be j=i+1
            w[i][i+1]=q[i]+q[i+1]+p[i+1];
            c[i][i+1]=q[i]+q[i+1]+p[i+1];
            r[i][i+1]=i+1;
      }
      c[n][n]=0;
      r[n][n]=0;
      w[n][n]=q[n];
      //for j-i=2,3,4....,n
      for(i=2;i<=n;i++)
      {
            for(j=0;j<=n-i;j++)
            {
                  w[j][j+i]=q[j+i]+p[j+i]+w[j][j+i-1];
                  c[j][j+i]=9999;
                  for(k=j+1;k<=j+i;k++)
                  {
                        if(c[j][j+i]>(c[j][k-1]+c[k][j+i]))
                        {
                              c[j][j+i]=c[j][k-1]+c[k][j+i];
                              r[j][j+i]=k;
                        }
                  }
                  c[j][j+i]+=w[j][j+i];
            }
        //	cout<<endl;
      }
     cout<<"\n\nOptimal BST is :: ";
      cout<<"\nw="<<w[0][n];
      cout<<"\nc="<<c[0][n];
      cout<<"\nr="<<r[0][n];

}
/* This function builds the tree from the tables made by the OBST function */
void build_tree()
{
 int i,j,k;
 int queue[20],front=-1,rear=-1;
 cout<<"The Optimal Binary Search Tree For the Given Node Is…\n";
 cout<<"\n The Root of this OBST is ::"<<r[0][n];
 cout<<"\nThe Cost of this OBST is::"<<c[0][n];
 cout<<"\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD ";
 cout<<"\n";
 queue[++rear]=0;
 queue[++rear]=n;
 while(front!=rear)
 {
i=queue[++front];
j=queue[++front];
 k=r[i][j];
 cout<<"\n\t"<<k;
if(r[i][k-1]!=0)
{
cout<<"\t\t"<<r[i][k-1];
queue[++rear]=i;
queue[++rear]=k-1;
}
else
cout<<"\t\t";
if(r[k][j]!=0)
{
cout<<"\t"<<r[k][j];
queue[++rear]=k;
queue[++rear]=j;
}
else
cout<<"\t";
 }//end of while
 cout<<"\n";
}
};//end of the class
/*This is the main function */
int main()
{
OBST obj;
obj.get_data();
obj.build_OBST();
obj.build_tree();
return 0;
}
/*-------------output---------------
Optimal Binary Search Tree
Enter the number of nodes 4
Enter the data as…
a[1] 1
a[2] 2
a[3] 3
a[4] 4
p[1] 3
p[2]3
p[3]1
p[4]1
q[0]2
q[1]3
q[2]1
q[3]1
q[4]1
The Optimal Binary Search Tree For the Given Node Is…
The Root of this OBST is ::2
The Cost of this OBST is::32
NODE LEFT CHILD RIGHT CHILD
2 1 3
1
3 4
4
--------------------*/


