// Uygur Kiran - 2021/05/25

#include <iostream>
#include <list>
using namespace std;

////////////////////////
// Directed Graph
////////////////////////
class DiGraph {
private:
    int verCount;
    list<int> *adjList;
    void handleDFS(bool *visited, int q);

public:
    DiGraph(int verCount) {
        this->verCount = verCount;
        adjList = new list<int>[verCount];
    }

    void addEdge(int from, int to) {
        adjList[to].push_back(from);
    }

    void breadthFS(int q);
    void depthFS(int q);

};

void DiGraph::breadthFS(int q) {
    bool *visited = new bool[verCount];

    // mark all as unvisited
    for(int i = 0; i < verCount; i++) {
        visited[i] = false;
    }

    // init a queue
    list<int> queue;

    // current node visited
    visited[q] = true;
    queue.push_back(q);

    // get all adjacent vertices
    list<int>::iterator i;
    while(!queue.empty()) {
        // dequeue and print
        q = queue.front();
        cout << q << " ";
        queue.pop_front();

        // visit and enqueue (if not already visited)
        for(i = adjList[q].begin(); i != adjList[q].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    } //: LOOP
}

void DiGraph::handleDFS(bool *visited, int q) {
    visited[q] = true;
    cout << q << " ";

    list<int>::iterator i;
    for (i = adjList[q].begin(); i != adjList[q].end(); ++i) {
        if (!visited[*i]) {
            handleDFS(visited, *i);
        }
    }
}

void DiGraph::depthFS(int q) {
    bool *visited = new bool[verCount];
    handleDFS(visited, q);
}


////////////////////////
// Weighted DiGraph
////////////////////////
struct WDGNode {
    int val;
    int weight;
    WDGNode* next;
};

struct WDGEdge {
    int src, dest, weight;
};

class WghDiGraph {
private:
    int nodeCount;
    WDGNode **head;

    WDGNode* getAdjListNode(int value, int weight, WDGNode* head) {
        WDGNode* newNode = new WDGNode;
        newNode->val = value;
        newNode->weight = weight;
        // point new node to current head
        newNode->next = head;
        return newNode;
    }
public:
    WghDiGraph(WDGEdge edges[], int edgeCount, int nodeCount) {
        nodeCount--; // to start from idx 0
        this->nodeCount = nodeCount;
        head = new WDGNode*[nodeCount]();

        // init head ptr for all vertices
        for(int i = 0; i < nodeCount; i++) {
            head[i] = nullptr;
        }

        // add edges
        for(unsigned i = 0; i < edgeCount; i++) {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            // insert at beginning
            WDGNode* newNode = getAdjListNode(dest, weight, head[src]);

            // point head to new node
            head[src] = newNode;
        } //: LOOP
    }
    ~WghDiGraph() {
        for(int i = 0; i < nodeCount; i++) {
            delete[] head[i];
        }
        delete[] head;
    }

    void printList(WDGNode* p, int idx);
    void print();
};

void WghDiGraph::printList(WDGNode* p, int idx) {
    while (p != nullptr) {
        cout << "(" << idx << ", " << p->val << ", " << p->weight << ") ";
        p = p->next;
    }
    cout << endl;
}

void WghDiGraph::print() {
    for(int i = 0; i < nodeCount; i++) {
        // print all neighbor vertices of vertex 'i'
        printList(head[i], i);
    }
}



// run /////////////////
int main() {
    DiGraph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,1);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.addEdge(5,4);
    g.depthFS(1);

    cout << "\n\n";

    WDGEdge edges[] = {
                { 0, 1, 6 }, { 1, 2, 7 },
                { 2, 0, 5 }, { 2, 1, 4 },
                { 3, 2, 10 }, { 4, 5, 1 },
                { 5, 4, 3 }
            };
    int edgeCount = sizeof(edges)/sizeof(edges[0]);
    WghDiGraph wdg(edges, edgeCount, 7);
    wdg.print();

    return 0;
}

