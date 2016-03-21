/*********************************************************************/
/*                                                                   */
/* Tester for DSA555-w16 assignment 1, question 2                    */
/* Version 1.0                                                      */
/* To compile:                                                       */
/*                                                                   */
/*      g++ a1q2.cpp a1q2main.cpp                                    */
/*                                                                   */
/*********************************************************************/

#include <iostream>
#include "a1q2.h"

using namespace std;

int main(void){
	//10 arrays of testing data
	int data[10][25]={{5,5, 5,5, 3,2, 5,5, 5,5, 6,6, 7,7, 6,6, 8,8, 8,8, 5,5},
					  {5,5, 5,5, 3,2, 5,5, 4,5, 6,6, 7,7, 6,6, 8,8, 8,8, 5,5},
					  {5,1, 5,5, 3,2, 4,5, 4,5, 6,6, 7,7, 6,6, 8,8, 8,8, 5,5},
					  {5,5, 5,5, 5,5, 5,5, 5,5, 4,4, 4,4, 4,4, 4,4, 4,4},
					  {5,5, 5,5, 5,5, 5,5, 5,5, 4,4, 4,4, 4,4, 4,4, 4,4, 5},
					  {5,5, 5,5, 5,5, 5,5, 5,5, 4,4, 4,4, 4,4, 4,4, 4,4, 4},
					  {3,3, 3,3, 3,3, 3,3, 3,3, 3,4, 4,4, 4,4, 4,4, 4,4, 4},
					  {5,5, 5,5, 5,5, 5,5, 5,4, 4,5, 4,5, 4,4, 4,4, 4,4, 4},
					  {4,5, 5,5, 5,5, 5,5, 5,5, 4,4, 4,4, 4,4, 4,4, 4,4},
					  {5,5, 5,5, 5,5, 5,5, 4,4, 4,4, 4,4, 4,4, 4,4, 5,5, 3}
					};
    //size of each of the arrays above
	int sz[10]={22,22,22,20,21,21,21,21,20,21};

	//the majority element in each array.  If it is 0, it means the array has no majority
	int majority[10]={0,0,0,0,5,4,3,5,4,0} ;

	//correct return value from majority element for each of the above arrays
	bool hasMajority[10]={false,false,false,false,true,true,true,true,true,false};

	bool rc;
	int majorElem;
	bool correct=true;
	for(int i=0;i<10;i++){
		rc=majorityElement(data[i],majorElem,sz[i]);
		if(rc!=hasMajority[i]){
			cout << "Your majority element is not returning the correct value" << endl;
			cout << "On data[" << i << "], return value should be: "<< ((hasMajority[i])?"true":"false")<< endl;
			cout << "your function is returning: " << ((rc)?"true":"false") << endl;
			correct=false;
		}
		else{
			if(rc==true && majority[i] !=majorElem){
				cout << "Your majority element return value was correct." << endl;
				cout << "However the majorityElement found is not the correct value." << endl;
				cout << "for data[" << i << "], the majority elemnt is: " << majority[i] << endl;
				cout << "Your function is passing back: " << majorElem << endl;
				correct=false;
			}
		}
	}
	if(correct){
		cout << "Congratulations!  It looks like you have passed all the tests for question 2." << endl;
	}
	return 0;
}

