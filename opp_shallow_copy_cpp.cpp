#include<iostream>
#include<string>
using namespace std;
class student{
	public:
		string name;
		double* cgpaptr;
		
		student(string name, double cgpa){
			this-> name = name;
			cgpaptr = new double;
			*cgpaptr =  cgpa;
		}
		student(student &obj){
			this-> name = obj.name;
			this->cgpaptr = obj.cgpaptr;
		}
		getinfor(){
			cout<<"name:-"<<name<<endl;
			cout<<"cgpa:-"<<*cgpaptr<<endl;
		
		}
};


int main(){
	
	student S1("waghchaur om", 9.1);
	student S2(S1);
	S1.getinfor();
	*(S2.cgpaptr) =7.1;
	S1.getinfor();
	return 0;
}
