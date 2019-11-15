// bfs.cpp (Breadth First Search)

#include "graph.h"
#include "queue.h"
using namespace std;

int bfs_height(const Graph & graph, Graph::NodeId start_node, vector<vector<int>> &h)
{
    std::vector<bool> visited(graph.num_nodes(), false);
    std::vector<int> dist(graph.num_nodes(), -1);
    int height = 0;
    Graph bfs_tree(graph.num_nodes(), graph.dirtype);
    Queue<Graph::NodeId> queue;
    queue.push_back(start_node);
    visited[start_node] = true;
    dist[start_node] = 0;

    while (not queue.is_empty()) {
        auto cur_nodeid = queue.pop_front();
	if(dist[cur_nodeid]>height){
	    height = dist[cur_nodeid];
            h.resize(height);
	}
	h[dist[cur_nodeid]].push_back(cur_nodeid);
        for (auto neighbor: graph.get_node(cur_nodeid).adjacent_nodes()) {
            if (not visited[neighbor.id()]) {
                visited[neighbor.id()] = true;
                dist[neighbor.id()] = dist[cur_nodeid] + 1;
                bfs_tree.add_edge(cur_nodeid, neighbor.id());
                queue.push_back(neighbor.id());
            }
        }
    }
    return height;
}

