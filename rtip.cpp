#include "graph.h"
#include "rtip.h"
#include <string>

using namespace std;

int rtip(Graph g1, Graph::NodeId r1, Graph g2, Graph::NodeId r2)
        //returns 0 if isomorphic, positive if not, -1 if other error
{
	const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
	vector<string> w1,w2;
	w1.resize(g1.num_nodes());
	w2.resize(g2.num_nodes());
	int h1,h2;                 //Berechnung der Höhe fehlt noch
	vector<int> f1,f2;
	int success = 0;
	return success;
}
