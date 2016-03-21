#include <iostream>
#include "a1q2.h"
using namespace std;


bool candidate(int array[], int& _candidate, int sz){
	//int counter;
	int arr1[25];
	int count = 0;
    
    // If there are more than two data
	if (sz > 1){
		if (sz % 2 != 0)
			_candidate = array[sz - 1];

		for (int i = 0; i < sz-1; i += 2){
			if (array[i] == array[i + 1]){
				arr1[count] = array[i];
				count++;
			}
		} 
	}
    // If an array has only one value, which is a candidate
	else if(sz == 1){
		count = 1;
	}
    

	if (count > 1){
		return candidate(arr1, _candidate, count);
	}
	// If only one leave as the last
	else if (count == 1){
		// If there is a candidate
		_candidate = arr1[0];

		return true;
	}
	// No number left but there is candidate previously..
	else if (count == 0 && _candidate != 0){
		return true;
	}
	// There is no candidate to return
	else{
		return false;
	}

}
bool majorityElement(const int arr[], int& majority, int sz){
	bool flag = false;
	int counter = 0;
	int minimum = sz / 2;
	int candi;
	int arr1[25];

    // Copying to a new array
	for (int i = 0; i < sz; i++)
		arr1[i] = arr[i];

    // Set them 0 as a default
	candi = 0;
	majority = 0;

	bool isCandidate = candidate(arr1, candi, sz);

	//cout << isCandidate << "\n";

    
	if (isCandidate == true){
		// For Checking Candidate has more than half of the size
		for (int i = 0; i < sz; i++){
			if (candi == arr[i]){
				counter++;
			}
		}

        // If only candidates are more than half of the size
		if (counter > minimum){
			majority = candi;
			flag = true;
		}

	}
	
	return flag;
}