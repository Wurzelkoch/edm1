#include "graph.h"
#include "rtip.h"
#include "bfs.h"
#include <string>

using namespace std;

int rtip(Graph g1, Graph::NodeId r1, Graph g2, Graph::NodeId r2)
        //returns 0 if isomorphic, positive if not, -1 if other error
{
	const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
	vector<string> w1,w2;
	vector<vector<Graph::NodeId>> dist_r1, dist_r2;
	w1.resize(g1.num_nodes()); //vorerst leere Wörter
	w2.resize(g2.num_nodes());
	int h1,h2;                 //Berechnung der Höhe fehlt noch
	h1 = bfs_height(g1,r1,dist_r1);
	h2 = bfs_height(g2,r2,dist_r2);
	vector<int> f1(g1.num_nodes(),0),f2(g2.num_nodes(),0); //f-Werte
	
	for(int h=max(h1,h2);h>=1;h--){
	}

	int success = 0;
	return success;
}
