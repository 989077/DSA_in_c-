#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class graph{
	private:
		int V;
		list<int> *l;
	public:
		graph(int V){
			this-> V = V;
			l = new list<int> [V];
		}
	void addedge(int u , int v){
		l[u].push_back(v);
		l[v].push_back(u);
	} 
	bool isCycledfs(int src, int par, vector<bool> &vis){
		vis[src] = true;
		list<int> neighbours = l[src];
		
		for(int v: neighbours){
			if(!vis[v]){
				if( isCycledfs(v, src, vis)){
					return true;
				}
			}else if(v != par){
				return true;
			}
		}
		return false;
		
	}
	bool iscycle(){
		vector<bool> vis(V, false);
	
		
		for(int i=0; i<V; i++){
			if(!vis[i]){
				if(isCycledfs(i, -1, vis)){
					return true;
				}
			}
		}
		return false;
	}
};
int main(){
	graph g(5);
	
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(0,2);
	
	g.addedge(3,4);
	
	
	return 0;
}
