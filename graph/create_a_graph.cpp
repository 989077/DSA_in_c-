#include<iostream>
#include<list>
using namespace std;

class graph{
	int V;
	list<int> *l;
	
	public: 
	graph(int V){
		this->V = V;
		l = new list<int> [V];
	}
	void addedge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	void printlist(){
		for(int i=0; i< V; i++){
			cout<<i<<" : ";
			for(int neigh : l[i]){
				cout<<neigh<<" ";
			}
			cout<<endl;
		}
	}
};

int main(){
	graph g(5);
	
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(1,3);
	g.addedge(2,3);
	g.addedge(2,4);
	
	 g.printlist();
	 return 0;
}
