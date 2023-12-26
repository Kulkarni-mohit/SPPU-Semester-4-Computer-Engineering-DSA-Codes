// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// struct node {
//     string name;
//     vector<int> neighbors;
// };

// vector<node> adj_list;

// int visited[50] = {0};

// void dfs(int s, string arr[]) {
//     visited[s] = 1;
//     cout << arr[s] << " ";
//     for (int neighbor : adj_list[s].neighbors) {
//         if (!visited[neighbor])
//             dfs(neighbor, arr);
//     }
// }

// void bfs(int s, string arr[]) {
//     bool visited[50] = {false};
//     queue<int> bfsq;
//     bfsq.push(s);
//     visited[s] = true;
//     while (!bfsq.empty()) {
//         int v = bfsq.front();
//         bfsq.pop();
//         cout << arr[v] << " ";
//         for (int neighbor : adj_list[v].neighbors) {
//             if (!visited[neighbor]) {
//                 bfsq.push(neighbor);
//                 visited[neighbor] = true;
//             }
//         }
//     }
// }

// // Function to display the city name


// int main() {
//     cout << "Enter the number of vertices : ";
//     int n, u;
//     cin >> n;

//     if (n <= 0 || n > 50) {
//         cout << "Invalid number of vertices. Please try again." << endl;
//         return 0;
//     }

//     string nodes[50];
//     for (int i = 0; i < n; i++) {
//         cout << "Enter node " << i + 1 << " (name): ";
//         cin >> nodes[i];
//     }
//     cout << "\nYour Nodes are: " << endl;
//     for (int i = 0; i < n; i++)
//         cout << "Node " << i + 1 << ": " << nodes[i] << endl;

//     adj_list.resize(n);
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             int yes;
//             cout << "Enter the Edges (0/1) " << nodes[i] << " and " << nodes[j] << ": ";
//             cin  >> yes;
//             if(yes == 1){
//                 adj_list[i].neighbors.push_back(j);
//                 adj_list[j].neighbors.push_back(i);
//             }
//         }
//     }
//     cout << endl;

//     for (int i = 0; i < n; i++) {
//         cout << nodes[i] << ": ";
//         for (int neighbor : adj_list[i].neighbors) {
//             cout << nodes[neighbor] << " ";
//         }
//         cout << endl;
//     }

//     cout << "Enter the starting vertex: ";
//     cin >> u;
//     cout << "DFS: ";
//     dfs(u - 1, nodes);
//     cout << endl;
//     cout << "BFS: ";
//     bfs(u - 1, nodes);
//     cout << endl;

//     return 0;
// }


// #include<iostream>
// #define MAX 10
// using namespace std;
// /* **************************** */
// class queue
// {

// public:
// int q[10],v;
// int f,r;
// queue()
// {
// f=-1;
// r=-1;
// }
// void insert(int v)
// {
// if(f==-1&&r==-1)
// {
// f=0;r=0;
// q[r]=v;
// }
// else{
// r++;
// q[r]=v;

// }

// }
// int del()
// {
// v=q[f];
// f++;
// return v;
// }

// };

// /* ******************************** */

// class Graph
// {
// struct node
// {
// int vertex;
// node *next;
// };
// node *head[MAX];
// public:

// int visit[10];
// void create();

// void bfs(int);

// };

// void Graph::create()
// {
// int v1,v2,i,ans;
// node *temp,*temp1;
// for(i=1;i<=MAX;i++)
// {

// head[i]=NULL;
// visit[i]=0;

// }
// do
// {

// cout<<"Enter 2 Vertices: <";
// cin>>v1>>v2;
// temp=new node;
// temp->vertex = v2;
// temp->next=NULL;

// if(head[v1] == NULL)
// head[v1] = temp;
// else

// { temp1=head[v1];
// while(temp1->next != NULL)
// {
// temp1=temp1->next;
// }
// temp1->next = temp;

// }
// cout<<"Do u want to enter more edges: <";
// cin>>ans;
// }while(ans == 1);
// }

// void Graph::bfs(int v1)
// {
//     int i;
//     queue Q;

//     node *temp;
//     Q.insert(v1);
//     visit[v1]= 1;

//     while(Q.f<=Q.r)
//     {

//         i = Q.del();

//         cout<<i<<" ";
//         temp = head[i];

//         while(temp != NULL)
//         {
//             if(visit[temp->vertex] == 0)
//             {
//                 Q.insert(temp->vertex);
//                 visit[temp->vertex] = 1;
//             }
//             temp = temp->next;
//         }

//     }
// }

// int main()
// {
// int v1;
// Graph g;

// g.create();
// cout<<"Enter Starting Vertex: ";
// cin>>v1;
// g.bfs(v1);

// return 1;
// }




// #include<iostream>
// #define MAX 10
// using namespace std;
// /* **************************** */
// class queue
// {
// public:
// int q[10],v;
// int f,r;
// queue()
// {
// f=-1;
// r=-1;
// }
// void insert(int v)
// {
// if(f==-1&&r==-1)
// {
// f=0;r=0;
// q[r]=v;
// }
// else{
// r++;
// q[r]=v;
// }
// }
// int del()
// {
// v=q[f];
// f++;
// return v;
// }
// };
// /* ******************************** */
// class Graph
// {
// struct node
// {
// int vertex;
// node *next;
// };
// node *head[MAX];
// public:
// int visit[10];
// void create();
// void bfs(int);
// };
// void Graph::create()
// {
// int v1,v2,i,ans;
// node *temp,*temp1;
// for(i=1;i<=MAX;i++)
// {
// head[i]=NULL;
// visit[i]=0;
// }
// do
// {
// cout<<"Enter 2 Vertices: ";
// cin>>v1>>v2;
// temp=new node;
// temp->vertex = v2;
// temp->next=NULL;
// if(head[v1] == NULL)
// head[v1] = temp;
// else
// {
// temp1=head[v1];
// while(temp1->next != NULL)
// {
// temp1=temp1->next;
// }
// temp1->next = temp;
// }
// cout<<"Do u want to enter more edges: ";
// cin>>ans;
// }while(ans == 1);
// }
// void Graph::bfs(int v1)
// {
// int i;
// queue Q;
// node *first;
// Q.insert(v1);
// visit[v1]= 1;
// while(Q.f<=Q.r)
// {
// i = Q.del();
// cout<<i<<" ";
// first = head[i];
// while(first != NULL)
// {
// if(visit[first->vertex] == 0)
// {
// Q.insert(first->vertex);
// visit[first->vertex] = 1;
// }
// first = first->next;
// }
// }
// }
// int main()
// {
// int v1;
// Graph g;
// g.create();
// cout<<"Enter Starting Vertex: ";
// cin>>v1;
// g.bfs(v1);
// return 1;
// }

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    string name;
    vector<int> neighbors;
};

vector<node> adj_list;

int visited[50] = {0};

void dfs(int s, string arr[]) {
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int neighbor : adj_list[s].neighbors) {
        if (!visited[neighbor])
            dfs(neighbor, arr);
    }
}

void bfs(int s, string arr[]) {
    bool visited[50] = {false};
    queue<int> bfsq;
    bfsq.push(s);
    visited[s] = true;
    while (!bfsq.empty()) {
        int v = bfsq.front();
        bfsq.pop();
        cout << arr[v] << " ";
        for (int neighbor : adj_list[v].neighbors) {
            if (!visited[neighbor]) {
                bfsq.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// Function to display the city name


int main() {
    cout << "Enter the number of vertices : ";
    int n, u;
    cin >> n;

    if (n <= 0 || n > 50) {
        cout << "Invalid number of vertices. Please try again." << endl;
        return 0;
    }

    string nodes[50];
    for (int i = 0; i < n; i++) {
        cout << "Enter node " << i + 1 << " (name): ";
        cin >> nodes[i];
    }
    cout << "\nYour Nodes are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "Node " << i + 1 << ": " << nodes[i] << endl;

    adj_list.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int yes;
            cout << "Enter the Edges (0/1) " << nodes[i] << " and " << nodes[j] << ": ";
            cin  >> yes;
            if(yes == 1){
                adj_list[i].neighbors.push_back(j);
                adj_list[j].neighbors.push_back(i);
            }
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << nodes[i] << ": ";
        for (int neighbor : adj_list[i].neighbors) {
            cout << nodes[neighbor] << " ";
        }
        cout << endl;
    }

    cout << "Enter the starting vertex: ";
    cin >> u;
    cout << "DFS: ";
    dfs(u - 1, nodes);
    cout << endl;
    cout << "BFS: ";
    bfs(u - 1, nodes);
    cout << endl;

    return 0;
}