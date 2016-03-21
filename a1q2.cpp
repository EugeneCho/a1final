#include <iostream>
#include "a1q2.h"
using namespace std;
bool candidate(int array[], int& _candidate, int sz){
	//int counter;
	int arr1[25];
	int count = 0;
    
    _candidate = 0;

	if (sz % 2 != 0)
		_candidate = array[sz - 1];

	for (int i = 0; i < sz; i += 2){
		if (array[i] == array[i + 1])
			arr1[count++] = array[i];
	}


	if (count > 1)
		return candidate(arr1, _candidate, count);
	/*
    else if (count == 1){
		_candidate = arr1[0];
		return true;
	}
    */
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
	for (int i = 0; i < sz; i++)
		arr1[i] = arr[i];

	bool isCandidate = candidate(arr1, candi, sz);

	// 
	if (isCandidate == true){

		for (int i = 0; i < sz; i++){
			if (candi == arr[i]){
				counter++;
			}
		}

		if (counter > minimum){
			majority = candi;
			flag = true;
		}
	}
    //여기 else 필요없음, candidate 쪽에서 다 해결되면 여기 없이도 잘 돌아가야함.
    /*
	else{
		for (int i = 0; i < sz; i++){
			counter = 0;
			for (int j = 0; j < sz; j++){
				if (arr[i] == arr[j]){
					counter++;
				}
			}
			if (counter > minimum){
				majority = arr[i];
				flag = true;
				break;
			}

		}
	}*/

	return flag;
}