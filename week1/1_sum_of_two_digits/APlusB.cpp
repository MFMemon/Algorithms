// A O(n) C++ program to find maximum product pair in an array
#include <iostream>
#include <cstdlib>
using namespace std;

// Function to find maximum product pair in arr[0..n-1]
void maxProduct(int arr[], int n)
{
	if (n < 2)
	{
		cout << "No pairs exists\n";
		return;
	}

	if (n == 2)
	{
		cout << arr[0] << " " << arr[1] << endl;
		return;
	}

	// Iniitialize maximum and second maximum
	int posa = 0, posb = 0;

	// Iniitialize minimum and second minimum
	int nega = 0, negb = 0;

	// Traverse given array
	for (int i = 0; i < n; i++)
	{
		// Update maximum and second maximum if needed
		if (arr[i] > posa)
		{
			posb = posa;
			posa = arr[i];
		}
		else if (arr[i] > posb)
			posb = arr[i];

		// Update minimum and second minimum if needed
		if (arr[i] < 0 && abs(arr[i]) > abs(nega))
		{
			negb = nega;
			nega = arr[i];
		}
		else if(arr[i] < 0 && abs(arr[i]) > abs(negb))
			negb = arr[i];
	}

	if (nega*negb > posa*posb)
		cout << "Max product pair is {" << nega << ", "
			<< negb << "}";
	else
		cout << "Max product pair is {" << posa << ", "
			<< posb << "}";
}

// Driver program to test above function
int main()
{

	int n;
	std::cin >> n;
	int arr[n];
	for (int i=0; i<n; i++){
	    arr[i] = rand()*rand() % 12321544;
      std::cout << arr[i] << " " ;
	}
  std::cout << std::endl;
	maxProduct(arr, n);
	return 0;

}
