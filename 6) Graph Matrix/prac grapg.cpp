#include <iostream>
#include<stack>
#include<queue>

using namespace std;

class Gmat
{
    int G[10][10], visit[10], n;

    public:
    void create();
    void dfs();
    void bfs();
};

void Gmat:: create()
{
    int e,v1,v2;

    cout<<"Enter no. of vertex: ";
    cin>>n;

    cout<<"\nEnter no. of edges: ";
    cin>>e;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            G[i][j] = 0;
            visit[i]=0;
        }
    }

    for(int i=1; i<=e; i++)
    {
        cout<<"Enter edge: ";
        cin>>v1>>v2;

        G[v1][v2] = G[v2][v1] = 1;
    }
}

void Gmat::bfs()
{
    queue <int> q;
    int v1,v2;

    cout<<"Enter from where you want to start: ";
    cin>>v1;
    visit[v1] = 1;

    q.push(v1);

    while(!q.empty())
    {
        v1 = q.front();
        q.pop();
        cout<<v1;

        for(v2 = 1; v2<=n; v2++)
        {
            if( G[v1][v2] == 1 && visit[v2] == 0)
            {
                q.push(v2);
                visit[v2] = 1;
            }
        }
    }
}

void Gmat::dfs()
{
    stack <int> s;
    int v1,v2;
    cout<<"Where to start: ";
    cin>>v1;

    s.push(v1);
    while(!s.empty())
    {
        v1 = s.top();
        s.pop();
        if (visit[v1] == 0)
        {
            cout<<v1;
            visit[v1] = 1;
        }

        for(v2 = 1; v2<=n; v2++)
        {
            if(G[v1][v2] == 1 && visit[v2] == 0)
                s.push(v2);
        }
    }
}

int main()
{
    Gmat g;

    g.create();

    //g.bfs();

    g.dfs();

    return 0;
}