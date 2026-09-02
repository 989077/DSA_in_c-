#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] ={0};
        for(int i=0; i<s1.length(); i++){
            freq[s1[i] - 'a']++;
        }
        int windSize = s1.length();
        for(int i=0; i<s2.length(); i++){
            int windIdx = 0, Idx =i;
            int windFreq[26] ={0};
            while(windIdx < windSize && Idx < s2.length()){
                windFreq[s2[Idx] - 'a']++;
                windIdx++;
                Idx++;

            }
            if(isFreqSame(freq, windFreq)){
                return true;
            }
        }
        return false;
    }
};
int main(){
	string s1 = "ab" ;
	string s2 = "eidbaooo" ;
	Solution Sol;
	bool result =  Sol.checkInclusion(s1,  s2);
	cout<<"output:-"<<result<<endl;

	return 0;
}

