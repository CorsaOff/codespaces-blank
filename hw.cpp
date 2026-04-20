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
    
 Graph g1 (6 , true);
    g1.addEdge (0 , 1);
    g1.addEdge (1 , 2);
    g1.addEdge (1 , 3);
    g1.addEdge (0 , 4);
    g1.addEdge (4 , 5);
    
    g1.BFS(0);



     Graph g2 (7 , true);
    g2.addEdge (0 , 1);
    g2.addEdge (1 , 3);
    g2.addEdge (1 , 4);
    g2.addEdge (0 , 2);
    g2.addEdge (2 , 5);
    g2.addEdge (2 , 6);

    g2.BFS(0);

 

  Graph g3 (6 , true);
    g3.addEdge (0 , 1);
    g3.addEdge (0 , 2);
    g3.addEdge (1 , 3);
    g3.addEdge (3 , 4);
    g3.addEdge (2 , 4);
    g3.addEdge (1 , 2);


    g3.BFS(0);


    

  Graph g4 (4 , true);
    g4.addEdge (0 , 1);
    g4.addEdge (1 , 2);
    g4.addEdge (2 , 3);


    g4.BFS(0);


 
   

    Graph g5 (5 , true);
    g5.addEdge (0 , 1);
    g5.addEdge (0 , 2);
    g5.addEdge (0 , 3);
    g5.addEdge (0 , 4);

    g5.BFS(0);





      Graph g6 (12 , true);
    g6.addEdge (0 , 1);
    g6.addEdge (0 , 6);
    g6.addEdge (1 , 2);
    g6.addEdge (1 , 4);
    g6.addEdge (1 , 5);
    g6.addEdge (2 , 3);
    g6.addEdge (2 , 4);
    g6.addEdge (3 , 10);
    g6.addEdge (3 , 8);
    g6.addEdge (4 , 5);
    g6.addEdge (4 , 7);
    g6.addEdge (4 , 8);
    g6.addEdge (5 , 6);
    g6.addEdge (5 , 7);
    g6.addEdge (6 , 11);
    g6.addEdge (6 , 7);
    g6.addEdge (7 , 11);
    g6.addEdge (7 , 9);
    g6.addEdge (8 , 9);
    g6.addEdge (9 , 10);
    g6.addEdge (9 , 11);
    g6.addEdge (10 , 11);

    g6.BFS(0);


    return 0;
}