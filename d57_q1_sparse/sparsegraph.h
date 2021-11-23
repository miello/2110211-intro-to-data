#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here

#include <vector>
#include <set>
#include <map>
using namespace std;

class SparseGraph{
public:
    SparseGraph(): n(3), edges(), isT(false) {}

    SparseGraph(int n_in): n(n_in), edges(), isT(false) {}

    SparseGraph(const SparseGraph& G): n(G.n), edges(G.edges), isT(G.isT) {}

    void AddEdge(int a, int b) {
        edges.insert(make_pair(a, b));
    }

    void RemoveEdge(int a, int b) {
        edges.erase(make_pair(a, b));
    }

    bool DoesEdgeExist(int a, int b) const {
        if(isT) swap(a, b);
        return edges.find(make_pair(a, b)) != edges.end();
    }

    SparseGraph Transpose() const {
        SparseGraph newGraph = SparseGraph(*this);
        newGraph.isT = !newGraph.isT;
        return newGraph;
    }

protected:
    int n;
    bool isT;
    set<pair<int, int>> edges;
};
#endif // __SPARSE_GRAPH_H__

