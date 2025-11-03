#include <bits/stdc++.h>
using namespace std; 

//An adjaceny list is essentially using an array of linked lists. 

//steps
/**
 * 1. Define the number of vectices V in the graph 
 * 2. Create an array of linked lists adjList of size V. 
 * 3. Initialize each element of adjList to an empty list
 * 4. Define a function addEdge(u,v) to add an edge between two vertices: 
 * - Check if u and v are valid vertices (0 <= u, v < V)
 * - If valid, add v to the linked list of u 
 * - Also add u to the linked list of v as this is an undirected graph
 * 5. Define a function printAdjList() to print the adjaceny list 
 * - Iterate through the array using a loop and print the linked list for each vertex. 
 */


class Graph { 
    private: 
    vector<vector<int>> adjList; 

    bool isDirected; 


    public: 

    Graph(int vertices, bool directed = false){
        adjList.resize(vertices);
        isDirected = directed; 
    }

    //Function to add an edge to the graph 
    //Parameters: src --> source vertex 
    //dest --> destination vertex
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest); //so for undirected and directed we add the destination vertex to the list of the source vertex
        if (!isDirected) {
            adjList[dest].push_back(src); //if it's undirected we do the same the other way because it goes both ways.
        }
    }

    void printGraph() {
        for (int i = 0; i < adjList.size(); i++) { 
            cout << i << ": "; //this is just printing the vertex and a colon

            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " -> "; //this is the main body that prints everything out 
            }
            cout << "Null" << endl;  //before it goes back to i we want to send a null out to end each list. Not necessary but good. 
        }
    }
};





int main() {              
    return 0; 
}
