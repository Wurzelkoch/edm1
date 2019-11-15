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

	cout << "Bestimme Höhen der Bäume…\n";
	int h1,h2;                 //Berechnung der Höhe fehlt noch
	h1 = bfs_height(g1,r1,dist_r1);
	cout << "Baum 1 hat Höhe " << h1 << "\n";
	h2 = bfs_height(g2,r2,dist_r2);
	cout << "Baum 2 hat Höhe " << h2 << "\n";
	if(h1 != h2) return 1;     //Bei ungleicher Höhe der Bäume sind sie nicht isomorph.

	vector<int> f1(g1.num_nodes(),0),f2(g2.num_nodes(),0); //f-Werte
	int fmax=0;  //maximaler bisher erreichter f-Wert
	
	for(int h=max(h1,h2);h>=1;h--){  //arbeite von den Blättern zur Wurzel
	    vector<Graph::NodeId> L1,L2;
	    //Sortiere x aus V(Gi) mit Höhe h nach f-Werten:
	    for(int fi=0;fi<=fmax;fi++){
                for(auto i=dist_r1[h].begin(); i!=dist_r1[h].end(); i++){
	            if(f1[*i]==fi) w1[g1.get_node(*i).parent()] += f1[*i];
		}
                for(auto i=dist_r2[h].begin(); i!=dist_r2[h].end(); i++){
	            if(f2[*i]==fi) w2[g2.get_node(*i).parent()] += f2[*i];
		}
	    }


	}

	int success = 0;
	return success;
}
