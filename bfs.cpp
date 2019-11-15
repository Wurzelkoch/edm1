// bfs.cpp (Breadth First Search)

#include "graph.h"
#include "queue.h"
using namespace std;

int bfs_height(const Graph & graph, Graph::NodeId start_node, vector<vector<Graph::NodeId>> &h)
{
    std::vector<bool> visited(graph.num_nodes(), false);
    std::vector<int> dist(graph.num_nodes(), -1);
    int height = 0;
    h.resize(1);  //Create Bucket for h==0
    Graph bfs_tree(graph.num_nodes(), graph.dirtype);
    Queue<Graph::NodeId> queue;
    queue.push_back(start_node);
    visited[start_node] = true;
    dist[start_node] = 0;

    cout << "starte BFS in " << start_node << " of " << graph.num_nodes() << "\n"; 

    while (not queue.is_empty()) {
        auto cur_nodeid = queue.pop_front();
		cout << cur_nodeid << " hat Höhe " << dist[cur_nodeid] << "\n";
	if(dist[cur_nodeid] > height){
//		cout << "Setting height from " << height << " to " << dist[cur_nodeid] << "\n";
	    height = dist[cur_nodeid];
            h.resize(height+1);
	}
//	cout << "Height ist OK\n";
//	cout << "h has size " << h.size() << " of " << h[dist[cur_nodeid]].size() << "\n";
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

