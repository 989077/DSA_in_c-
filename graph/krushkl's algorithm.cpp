#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class edge{
	public:
	int u, v, wt;
	
	edge(int u, int v, int wt){
		this->u = u;
		this->v = v;
		this->wt = wt; 
	}
	
	bool operator<(const edge &other) const{
	return this->wt < other.wt;
	}
};
class graph{
	public:
	int v ;
	vector<edge> edges;
	vector<int> par, rank;
	
	graph(int v){
		this->v = v;
		for(int i=0; i<v; i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}
	void addedge(int u , int v, int wt){
		edges.push_back(edge(u, v, wt));
		
	}
	int find(int x){
		if(par[x] == x){
			return x;
		}
		return par[x] = find(par[x]);
	}
	void unionbyrank(int a, int b){
		int parA = find(a);
		int parB = find(b);
		rank[parA]++;
	if(rank[parA] == rank[parB]){
		par[parB] = parA;
		rank[parB]++;
	}else if(rank[parA] > rank[parB]){
		par[parB] = parA;
	}else{
		par[parA] = parB;
	}
}
	//krushkal algo
	void krushkl(){
		sort(edges.begin(), edges.end());
		int mstcost = 0;
		
		for(int i =0; i<edges.size(); i++){
			edge e =edges[i];
			
			int parU = find(e.u);
			int parV = find(e.v);
			
			if(parU != parV){
				unionbyrank(e.u, e.v);
				mstcost += e.wt;
			}
		}
		cout<<" mst cost -:"<<mstcost<<endl;
	}
	
};

int main(){
	 graph g(4);
	
	g.addedge(0,1, 10);
	g.addedge(0,2, 6);
	g.addedge(0,3, 5);
	g.addedge(1,3, 15);
	g.addedge(2,3, 4);
	
	g.krushkl();
   return 0;
}
