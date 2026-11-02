#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph{
	int V;
	list<int> *l;
	public:
	graph(int V ){
		this->V = V;
		l = new list<int> [V];
	}
	
	void addedge(int u,int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	//bsf traversal
	static void bsf(){
		queue<int> Q;
		vector<int>nis(V, false);
		
		Q.push(0);
		vis[0] = true;
		
		while(Q.size()>0){
			int u = q.front();
			Q.pop();
			
			cout<<u<<" ";
			
			for(int v : l(u)){
				if(!vis[v]){
					vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
	// DFS traversal 
	void dfshelper(int u, vector<bool>& vis){
		cout<<u<<" ";
		vis[u] = true;
		
		for(V: l[u]){
			if(!vis[v]){
				dfshelper(v, vis);
			}
		}
	}
	void dfs(){
		int src = 0;
		vector<bool> vis(V, false);
		dfshelper(src,vis);
	}
	
};

int main(){
	graph g(5);
	
	g.addedge(0,1);
	g.addedge(1,0);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(2,0);
	g.addedge(3,2);
    
    g.dfs();
	return 0;
	
}
