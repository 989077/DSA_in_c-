#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class edge {
public:
    int v;
    int wt;

    edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};
  void bellmanford(int src, vector<vector<edge>> g, int v ){
  	vector<int> dist(v, INT_MAX);
  	dist[src] = 0;
  	
  	for(int i=0; i < v-1; i++){
  		for(int  u =0; u < v; u++){
  			for(edge e : g[u]){
  				if(dist[e.v] > dist[u] + e.wt){
  				    dist[e.v] = dist[u] + e.wt;
				  }
			  }
		  }
	  }
	  for(int  i=0; i<v; i++){
	  	cout<< dist[i] << " ";
	  }
	  cout<< endl;
  }

   


int main() {
    int v = 6;
    vector<vector<edge>> g(v);

    // Edges from 0
    g[0].push_back(edge(1, 2));
    g[0].push_back(edge(2, 4));

    // Edges from 1
    g[1].push_back(edge(2, -4));
    g[1].push_back(edge(4, -1));

    // Edges from 2
    g[2].push_back(edge(3, 2));

    // Edges from 3
    g[3].push_back(edge(4, 4));

   
    bellmanford(0, g, v);

    return 0;
}
