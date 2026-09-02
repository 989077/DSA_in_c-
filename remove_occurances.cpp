#include<iostream>
#include<string>
using namespace std;
class Solution{
	public:
		string remove_occurance(string s, string part){
			while(s.length() >0 && s.find(part) < s.length()){
				s.erase(s.find(part), part.length());
			}
			return s;
		}
};
int main(){
	string s = "abbcbcabcbbc";
	string part = "abc";
	Solution Sol;
	string result =  Sol.remove_occurance(s,part);
	cout<<"output:-"<<result<<endl;

	return 0;
}

