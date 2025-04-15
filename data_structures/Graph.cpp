#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphNode {
public:
    GraphNode(int d) : data(d), visited(false), children({}) {}

    int data;
    bool visited;
    vector<GraphNode*> children;
};

class Graph {
public:
    Graph(vector<GraphNode*> n) : nodes(n) {}

    // Reset Visited States.
    void ResetVisitedState() {
        for (auto node : nodes) {
            node->visited = false;
        }
    }

    // Breadth-First Search Traversal.
    void BFS(GraphNode& start) {
        queue<GraphNode*> node_queue;
        node_queue.push(&start);
        while (!node_queue.empty()) {
            GraphNode* current = node_queue.front();
            node_queue.pop();
            cout << current->data << " ";
            current->visited = true;
            for (auto child : current->children) {
                if (!child->visited) {
                    node_queue.push(child);
                }
            }
        }
    }

    // Depth-First Search Traversal.
    void DFS(GraphNode& start) {
        start.visited = true;
        cout << start.data << " ";
        start.visited = true;
        for (auto child : start.children) {
            if (!child->visited) {
                DFS(*child);
            }
        }
    }

    // List of all nodes in the graph.
    vector<GraphNode*> nodes;
};

void PrettyPrintGraph (Graph& graph) {
    for (auto node : graph.nodes) {
        cout << node->data << " visited:" << node->visited << " -> ";
        for (auto child : node->children) {
            cout << child->data << " ";
        }
        cout << "\n";
    }
}

int main() {
    GraphNode a(0);
    GraphNode b(1);
    GraphNode c(2);
    GraphNode d(3);
    GraphNode e(4);
    GraphNode f(5);
    GraphNode g(6);

    a.children = {&b, &d, &c};
    b.children = {&a};
    c.children = {&a};
    d.children = {&a, &e};
    e.children = {&d, &f};
    f.children = {&e};

    // Create a graph with the above nodes and edges.
    Graph graph({&a, &b, &c, &d, &e, &f, &g});

    PrettyPrintGraph(graph);

    cout << "\n --- BFS --- \n";
    graph.BFS(a);
    graph.ResetVisitedState();

    cout << "\n --- DFS --- \n";
    graph.DFS(a);
    graph.ResetVisitedState();

    return 0;
}
