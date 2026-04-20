#include <iostream>
#include <vector>
#include <stack>


void printStack(std::stack<int>s, const std::string & label )
{

std::cout<<label<< " [ ";
std::vector<int> temp;
while (!s.empty())
{
    temp.push_back (s.top());
    s.pop();
}
for (int i = temp.size()-1; i >= 0; i--)
{
std::cout << temp[i];

if (i > 0)
{
    std::cout << " ";
}

}
std::cout << " ] " << std::endl;
}

class Graph 
{
int numVertices;
std::vector<std::vector<int>> adj;    
std::vector<bool> visited;    
bool verbose;

public:
Graph(int v, bool verboseMode = false)
{
    numVertices = v;
    adj.resize(v);
    visited.resize(v, false);
    verbose = verboseMode;
}  

    void addEdge (int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    void DFS (int startVertex)
    {
    std::fill(visited.begin() , visited.end(), false);
    std::stack<int>stack;
    visited [startVertex] = true;
    stack.push (startVertex);
    if (verbose)
    {
        printStack (stack, " начало ");
    }
    int step = 1;

    while (!stack.empty())
    {

    if (verbose)
    {
    ;
    }

    int currentVertex = stack.top();
    stack.pop();

    if (verbose)
    {
    ;
    }

    std::cout << currentVertex << " ";
    
    if (verbose)
    {
    std::cout << " Ищем относительно " << currentVertex << " : ";
    bool hasUnvisited = false;
    for (int neighbor : adj[currentVertex])
    {
        std::cout << neighbor;
        if (visited[neighbor])
        {
            std::cout << " посещена "; 
        }
        else 
        {
            std::cout << " новая ";
            hasUnvisited = true;
        }
    } 
    std::cout << std::endl;
    }
    
    std::vector<int>neighbors;
    for (int neighbor : adj[currentVertex])
    {
        neighbors.push_back(neighbor);
        for(int i = neighbors.size()-1; i >= 0; i-- )
        {
            int neighbor = neighbors[i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                stack.push(neighbor);
                if(verbose)
                {
                ;
                }
            }
        }
    }
}
step++;
std::cout << std::endl;
std::cout << " обход завершён ";
    }  


void DFSRecursive (int Vertex)
{
visited[Vertex] = true;
std::cout << Vertex << " ";
for (int neighbor : adj[Vertex])
{
    if (!visited[neighbor])
    {
        DFSRecursive(neighbor);
    }
}
}

void DFSREcursiveWrapper (int startVertex) 
{
std::fill(visited.begin(), visited.end(), false);
std::cout << "DFS recursive";
DFSRecursive (startVertex);
std::cout << std:: endl;
} 

};


int main()
{
        Graph g1(6, true);
        g1.addEdge(0, 1);
        g1.addEdge(1, 3); 
        g1.addEdge(1, 4);
        g1.addEdge(0, 4); 
        g1.addEdge(4, 5); 

        g1.DFS(0);


             Graph g2 (7 , true);
    g2.addEdge (0 , 1);
    g2.addEdge (1 , 3);
    g2.addEdge (1 , 4);
    g2.addEdge (0 , 2);
    g2.addEdge (2 , 5);
    g2.addEdge (2 , 6);

    g2.DFS(0);

 

  Graph g3 (6 , true);
    g3.addEdge (0 , 1);
    g3.addEdge (0 , 2);
    g3.addEdge (1 , 3);
    g3.addEdge (3 , 4);
    g3.addEdge (2 , 4);
    g3.addEdge (1 , 2);


    g3.DFS(0);


    

  Graph g4 (4 , true);
    g4.addEdge (0 , 1);
    g4.addEdge (1 , 2);
    g4.addEdge (2 , 3);


    g4.DFS(0);


 
   

    Graph g5 (5 , true);
    g5.addEdge (0 , 1);
    g5.addEdge (0 , 2);
    g5.addEdge (0 , 3);
    g5.addEdge (0 , 4);

    g5.DFS(0);





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

    g6.DFS(0);


    return 0;

}