/* This programs shows the concept of virtual functions

There is a class named Person.
It is being inherited by child class : Student and Teacher.
Suppose there is a function addCourse () which should be implemented 
for both student and teacher but the implementation is naturally different.

In this case, we define a virtaul function in the Parent class.
After that the implementation by both child and parent can be different and 
is left for the child classes to implement.

Virtual functions give way to virtual destructors.
That also is demostrated below.

*/

#include <iostream>
using namespace std;

#define NAME_SIZE 50


class Person {

	int id;
	char name[NAME_SIZE];

	public:
		virtual bool addCourse(string course) = 0;  // virtual function syntax
		virtual ~Person(){
			cout << "Deleting person \n";
		}


};

class Student : public Person {

public:

	bool addCourse(string course){
		std::cout << "Added course " << course << " to student " << endl;
		return true;
	}
	~Student(){
		cout << " Student deleted ";

	}
};

class Teacher : public Person{

public:

	bool addCourse(string course){
		std::cout <<"Added course "<< course << " to teacher " << endl;
		return true;

	}
	~Teacher(){
		cout << "Teacher deleted " <<endl;
	}
};


int main(){

	Person *p = new Student();
	p->addCourse("Statistics");
	Person *pp = new Teacher();
	pp->addCourse("Mathematics");
	delete p, p ;

	return 0;




}