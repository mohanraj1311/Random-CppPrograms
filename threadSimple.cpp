/*
This is a simple thread program.
To compile this on linux : g++ -std=c++11 -pthread threadSimple.cpp

*/




#include <iostream>
#include <thread>
using namespace std;


void printfun(){
	std::cout << "beauty is skin-deep!!" << endl;
}

int main() {

	std::thread t1(printfun); 
	t1.join();             // By join we make the main thread to wait till the child thread t1 completes.
	//t1.detach();           // By detach we imply that the main thread shall not wait for the child thread t1 to complete.

	return 0;
}


/*

if we use detach() instead of the join() then we will not see the print statement,
its because the main thread will get executed before the child thread.

Here the child thread t1 is using the resource std:: cout which is the part of the main thread.
if the main thread expires before the child thread, the resouce in above std::cout will not be available for the child thread t1.

If we use join () after detach() , the program crashes.
ONCE DETACHED is ALWAYS DETACHED (exactly as in life!)

But there is functionality which helps to prevent the crash.

if(t1.joinable)
	t1.join();
	


*/