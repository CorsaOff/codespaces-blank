#include <iostream>
#include <vector>
#include <queue>

void printQueue (std::queue <int> q , const std::string& label)
{
    std::cout<<label<<" [";
    bool first = true;
    while (!q.empty())
    {
        if (!first){std::cout << " " ; }
        std::cout << q.front();
        q.pop ();
        first = false;
        std::cout << " ]";
    }
}

class Graph 
{
    int numVertices;
    std::vector < std::vector < int >> adj;
    std::vector < bool > visited;
    bool verbose;

    public:
    Graph (int V, bool verboseMode = false)
    {
        numVertices = V,
        adj.resize(V);
        visited.resize (V , false);
        verbose = verboseMode;
    }

    void addEdge (int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    void BFS(int startVertex)
    {
        std::fill(visited.begin() , visited.end(), false);
        std::queue<int>q;
        visited [startVertex] = true;
        q.push (startVertex);
        if (verbose) 
        {
            printQueue (q,"asdasd");
        }
        std::cout << "посещенные вершины";
        int step = 1;
        int level = 0;

        while(!q.empty())
        {
            if(verbose) { ; }
            int currentVertex = q.front();
            q.pop();
            if (verbose) { ; }
            std::cout << currentVertex << " ";
            if (verbose){ ; } // *
            for (int neighbor:adj[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push (neighbor);
                    if (verbose) {;}
                }
            }
            if (verbose) { printQueue (q,"sdfsdf") ; }
            step++;
        } // while
        std::cout << std::endl;
        std::cout << "END \n";

    }//BFS
};//Graph

int main(){
    return 0;
}