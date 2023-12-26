// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// class Graph
// {
// private:
//     vector<vector<int>> adjMatrix;
//     int numVertices;
//     vector<int> visited;

// public:
//     Graph(int numVertices)
//     {
//         this->numVertices = numVertices;
//         adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
//         visited.resize(numVertices, 0);
//     }

//     void addEdge(int src, int dest)
//     {
//         if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
//         {
//             adjMatrix[src][dest] = 1;
//             adjMatrix[dest][src] = 1;
//         }
//         else
//         {
//             cout << "Invalid vertices. Please try again." << endl;
//         }
//     }

//     void dfs(int startVertex, vector<string> &nodes)
//     {
//         visited[startVertex] = 1;
//         cout << nodes[startVertex] << " ";

//         for (int i = 0; i < numVertices; i++)
//         {
//             if (adjMatrix[startVertex][i] && !visited[i])
//             {
//                 dfs(i, nodes);
//             }
//         }
//     }

//     void bfs(int startVertex, vector<string> &nodes)
//     {
//         vector<int> visited(numVertices, 0);
//         queue<int> bfsQueue;
//         bfsQueue.push(startVertex);
//         visited[startVertex] = 1;

//         while (!bfsQueue.empty())
//         {
//             int currentVertex = bfsQueue.front();
//             bfsQueue.pop();
//             cout << nodes[currentVertex] << " ";

//             for (int i = 0; i < numVertices; i++)
//             {
//                 if (adjMatrix[currentVertex][i] && !visited[i])
//                 {
//                     bfsQueue.push(i);
//                     visited[i] = 1;
//                 }
//             }
//         }
//     }
// };

// int main()
// {
//     int numVertices;
//     cout << "Enter the number of vertices: ";
//     cin >> numVertices;

//     if (numVertices <= 0 || numVertices > 50)
//     {
//         cout << "Invalid number of vertices. Please try again." << endl;
//         return 0;
//     }

//     vector<string> nodes(numVertices);
//     for (int i = 0; i < numVertices; i++)
//     {
//         cout << "Enter node " << i + 1 << " (name): ";
//         cin >> nodes[i];
//     }

//     Graph graph(numVertices);

//     int choice;
//     int src, dest;
//     int startVertex;

//     do
//     {
//         cout << "\nGraph Menu\n";
//         cout << "1. Add Edge\n";
//         cout << "2. Depth First Search (DFS)\n";
//         cout << "3. Breadth First Search (BFS)\n";
//         cout << "4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             cout << "Enter source vertex: ";
//             cin >> src;
//             cout << "Enter destination vertex: ";
//             cin >> dest;
//             graph.addEdge(src - 1, dest - 1);
//             break;
//         case 2:
//             cout << "Enter the starting vertex: ";
//             cin >> startVertex;
//             cout << "DFS: ";
//             graph.dfs(startVertex - 1, nodes);
//             cout << endl;
//             break;
//         case 3:
//             cout << "Enter the starting vertex: ";
//             cin >> startVertex;
//             cout << "BFS: ";
//             graph.bfs(startVertex - 1, nodes);
//             cout << endl;
//             break;
//         case 4:
//             cout << "Exiting..." << endl;
//             break;
//         default:
//             cout << "Invalid choice. Please try again." << endl;
//             break;
//         }
//     } while (choice != 4);

//     return 0;
// }







#include<iostream>
using namespace std;
class graph
{int G[10][10],n;
int visit[10];
	public:
		void create();
		void bfs();
		void dfs(int);
		void dfs1();
};
class stack
{
	int st[10];
	
	public:
		int top,v1;
	stack()
	{
		top=-1;
	}
	void push(int v1)
	{
		st[++top]=v1;
	}
	int pop()
	{
		v1=st[top];
		top--;
		return v1;
	}
};
class queue
{
	
	public:
		int Q[10],v;
	int f,r;
		queue()
		{
			f=-1;
			r=-1;
		}
		void insert(int v)
		{
		if(f==-1&&r==-1)
		{
			f=0;r=0;
			Q[r]=v;
		}
			else{
				r++;
				Q[r]=v;
			}
			
		}
		int del()
		{
			v=Q[f];
			f++;
			return v;
		}
};
void graph::create()
{int e,i,j,v1,v2;
	cout<<"enter the no.of vertices";
	cin>>n;
	cout<<"enter the no.of edges";
	cin>>e;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
	
	G[i][j]=0;
	visit[i]=0;
}
	for(i=1;i<=e;i++)
	{
	
	cout<<"enter the edge";
	cin>>v1>>v2;
	G[v1][v2]=G[v2][v1]=1;
}
	
}
void graph::bfs()
{
int v1;
cout<<"enter the starting vertex";
	cin>>v1;
int v2,temp;
visit[v1]=1;
queue q;
	q.insert(v1);
	while(q.f<=q.r)
	{
		v1=q.del();
		cout<<v1;
		for(v2=1;v2<=n;v2++)
		{
			if(G[v1][v2]==1&&visit[v2]==0)
			{
			
				q.insert(v2);
				visit[v2]=1;
		}}
		
	}
}
void graph::dfs(int v1)
{int v2;
cout<<v1;
visit[v1]=1;
for(v2=1;v2<=n;v2++)
if(G[v1][v2]==1&&visit[v2]==0)
dfs(v2);
	
}
void graph::dfs1()
{
int v1;
cout<<"enter the starting vertex";
	cin>>v1;
	stack s;//
	int v2;
	s.push(v1);
	
	while(s.top!=-1)
	{
		v1=s.pop();
		if(visit[v1]==0)
		{
		
		cout<<v1;
		visit[v1]=1;
		}	
		for(v2=1;v2<=n;v2++)
		    if(G[v1][v2]==1&&visit[v2]==0)
		        s.push(v2);
}
}
int main()
{
	graph g; int v;
	g.create();
	
	//g.bfs();
	//cout<<"enter the starting vetex";
	//cin>>v;
	// g.dfs(v);
	g.dfs1();
	
}
