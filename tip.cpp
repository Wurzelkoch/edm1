#include "graph.h"
#include "tip.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    if (argc > 1) {
        std::cout << "Lies Graph g1" << std::endl;
        Graph g1(argv[1], Graph::undirected);              // read graph from file
	g1.print();
	std::cout << "Lies Graph g2" << std::endl;
        Graph g2(argv[2], Graph::undirected);              // read graph from file
	g2.print();
	int success = tip(g1, g2);
        std::cout << "Die Bäume sind" << (success?"nicht":"") << "isomorph" << std::endl;
    }
}


int tip(Graph & g1, Graph & g2){         //returns 0 if isomorphic, positive if not, -1 if other error
	int success = 0;
	std::cout << "Ermittle Zentrum Z(g1)…" << std::endl;
	Graph z1 = center(g1);
	z1.print();
	std::cout << "Ermittle Zentrum Z(g2)…" << std::endl;
	Graph z2 = center(g2);
	z2.print();
	std::cout << "Probiere Rooted Tree Isomorphism…" << std::endl;
	if(z1.num_nodes() != z2.num_nodes()) return 1;
	if(z1.num_nodes() == 1) success = rtip(g1,0,g2,0);
	if(z1.num_nodes() == 2){
		success = 0;
		success += rtip(g1,0,g2,0);
		success += rtip(g1,1,g2,0);
	}
	if(z2.num_nodes() > 2) return -1;
	return success;
}
