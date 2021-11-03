#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        this->n = 3;
        this->edges = vector<vector<int>>(3, vector<int>(3, 0));
    }

    DenseGraph(int n_in) {
        this->n = n_in;
        this->edges = vector<vector<int>>(n_in, vector<int>(n_in, 0));
    }

    DenseGraph(const DenseGraph& G) {
        this->n = G.n;
        this->edges = vector<vector<int>>(G.edges);
    }

    void AddEdge(int a, int b) {
        this->edges[a][b] = 1;
    }

    void RemoveEdge(int a, int b) {
        this->edges[a][b] = 0;        
    }

    bool DoesEdgeExist(int a, int b) const {
        return edges[a][b];
    }

    DenseGraph Transpose() const {
        DenseGraph copyGraph = DenseGraph(this->n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                copyGraph.edges[j][i] = this->edges[i][j];
            }
        }

        return copyGraph;
    }

protected:
    int n;
    vector<vector<int>> edges; 
};
#endif // __DENSE_GRAPH_H__
