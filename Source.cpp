#include <iostream>
using namespace std;

//Creatin a recursive binary search function.
int BST(int arr[], int left, int right, int x)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		
		//if the number is present in the middle
		if (arr[mid] == x)
		{
			return mid;
		}

		//if the number is smaller than the middle then it is present 
		//in the left subarray
		if (arr[mid] > x)
		{
			return BST(arr, left, mid - 1, x);
		}

		//Or the elements can only be present in the right subtree
		return BST(arr, mid + 1, right, x);
	}

	//Element not present in the array
	return -1;
}

int main(void)
{	
	int searchNum = 0;
	int newArr[20];

	//Promt the user for the total number of inputs they wish to enter
	cout << "Please enter 20 integers to add to the array: " << endl;

	for (int i = 0; i < 20; i++)
	{
		cout << "\tnewArr [" << i << "] = \t";
		cin >> newArr[i];
	}

	cout << "\nPrinting newArray:" << endl;
	//Print array
	for (int i = 0; i < 20; i++)
	{
		cout <<"["<< i<<"] =" << newArr[i] << " ";
	}
	cout << "\n*************************************************\n" << endl;

	//Promt the user for an integer to conduct a binary search
	cout << "\n What integer would you like to search for? " << endl;
	//Get user input
	cin >> searchNum;
	
	//Find the middle point of the array
	int n = sizeof(newArr) / sizeof(newArr[0]);

	//Calculate the result
	int result = BST(newArr, 0, n - 1, searchNum);

	//If statement to determine the position of the number,
	//if the number exist in the array
	if (result == -1)
	{
		cout << "Integer " << searchNum << " is not present in the Array!!" << endl;
	}
	else
	{
		cout << "Integer " << searchNum << " is found at Index [" << result << "] in the array" << endl;
	}

	cout << "\nTHANK YOU!!\n\n" << endl;
}