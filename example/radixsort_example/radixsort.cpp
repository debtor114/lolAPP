// C++ implementation of Radix Sort 
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 

vector <int> arr(10);
int n;


void countSort(int exp) { 
	vector <int> output(100, 0);
	vector <int> count(10, 0); 

	for (int i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 

    // 오름차순, 내림차순 여기서 결정
	for (int i = 9; i > 0; i--) 
		count[i-1] += count[i]; 

	// Build the output array 
	for (int i = n - 1; i >= 0; i--) { 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 

	arr = output; 
} 


void radixsort() {  
	int m = *max_element(arr.begin(), arr.end());

	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(exp); 
} 


int main() { 
	for (int i = 0; i < 10; i++)
        cin >> arr[i];

    n = arr.size();
    
	radixsort(); 
    for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 

	return 0; 
} 
