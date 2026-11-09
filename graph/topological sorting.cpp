#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
 class graph{
 	int v;
 	list<int> *l;
 	
 	public:
 		graph(int V){
 			this->v = V;
 			l = new list<int> [V];
		 }
		 
		 void addedge(int u, int v){
		 	l[u].push_back(v);
		 }
		 void dfs(int curr, vector<bool> &vis, stack<int> &s){
		 	vis[curr] = true;
		 	
		 	for(int v : l[curr]){
		 		if(!vis[v]){
		 			dfs(v, vis, s);
				 }
			 }
			 s.push(curr);
		 }
		 
		 void topsort(){
		 	vector<bool> vis(v, false);
		 	stack<int> s;
		 	
		 	for(int i =0; i < v; i++){
		 		if(!vis[i]){
		 			dfs(i, vis, s);
				 }
			 }
		while(s.size() > 0){
			cout<<s.top()<<" ";
			s.pop();
		}
		cout<<endl;	 
	}
 };
 int main(){
  graph g(6);
  
  g.addedge(3,1);
  g.addedge(2,3);
  g.addedge(4,0);
  g.addedge(4,1);
  g.addedge(5,0);
  g.addedge(5,3);
  g.topsort();
  return 0;
 }
