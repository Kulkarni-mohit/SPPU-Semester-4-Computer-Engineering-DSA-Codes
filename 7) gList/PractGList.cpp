#include <iostream>
#include <queue>
using namespace std;

// Node for linked list
struct Node {
    int vertex;
    Node* next;
};

// Graph class
class Graph {
    int numVertices;
    Node** adjList;

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjList = new Node*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjList[i] = nullptr;
        }
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        // Add edge from src to dest
        Node* newNode = new Node;
        newNode->vertex = dest;
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // Uncomment the following lines for an undirected graph

        // Add edge from dest to src
        Node* newNode2 = new Node;
        newNode2->vertex = src;
        newNode2->next = adjList[dest];
        adjList[dest] = newNode2;
    }

    // BFS traversal of the graph
    void BFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            Node* temp = adjList[currentVertex];
            while (temp != nullptr) {
                int adjVertex = temp->vertex;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }

    // DFS traversal of the graph
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";

        Node* temp = adjList[vertex];
        while (temp != nullptr) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited);
            }
            temp = temp->next;
        }
    }

    void DFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        DFSUtil(startVertex, visited);

        delete[] visited;
    }
};

// Example usage
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    cout << "BFS Traversal: ";
    g.BFS(0);
    cout << endl;

    cout << "DFS Traversal: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
