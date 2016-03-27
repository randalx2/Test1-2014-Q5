#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

/*void inKeyboard(int arr[], int n);
void inTest(int arr[], int n);

float average(void*func(int arr[], int n), int length);

int main()
{
	//Get average from keyboard
	int tempArray1[5] = { 0, 0, 0, 0, 0 };
	int tempArray2[5] = { 0, 0, 0, 0, 0 };

	inKeyboard(tempArray1, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << tempArray1[i] << "\t";
	}
	cout << endl;

	inTest(tempArray2, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << tempArray2[i] << "\t";
	}
	cout << endl;

	//Getting average
	cout << "Averge from keyboard: " << average(inKeyboard, 5) << endl;

	system("PAUSE");
	return 0;
}

void inKeyboard(int arr[], int n)
{
	//fill out array from keyboard
	cout << "Fill out your array with " << n << " values now" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void inTest(int arr[], int n)
{
	srand((unsigned)time(NULL));
	rand(); rand(); rand();
	cout << "Filling our array with random numbers now" << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;  //fill it with numbers from 0 to 99
	}
}

float average(void(*getfunc)(int arr[], int n), int length)
{
	float ave = 0;
	int sum = 0;

	int *arr = new int[length];
	getfunc(arr, length); //Call the function in the parameter

	for (int i = 0; i < length; i++)
	{
		sum = sum + arr[i];
	}
	ave = (float)sum / (float)length;

	delete[] arr;
	return ave;	
}*/


// read from keyboard and store in array 
void inKeyboard(int input[], const int numElements) {
	cout << "Please enter " << numElements << "integers: ";
	for (int i = 0; i <= numElements - 1; i++)
		cin >> input[i];
}

// generate random integers and store in array
void inTest(int input[], const int numElements) {
	srand(time(NULL));								// seed random number generator - not necessary for test)
	for (int i = 0; i <= numElements - 1; i++)
		input[i] = rand() % 100;					// generate and store integers between 0 and 99
}

// calculate the average number n integers where the souce 
// of the integers is determined by the 
float average(void(*getNum)(int numArray[], int numInts), int numInts){
	int sum = 0;										// initialise running sum to zero
	int * const numArray = new int[numInts];		// one way to declare a dynamic array 	

	getNum(numArray, numInts);						// get our array of integers using inKeyboard() or 
	// inTest depending on which was passed

	for (int i = 0; i < numInts; i++)					// calculate the sum of all integers in array 
		sum += numArray[i];

	delete[] numArray;								// release the memory allocated to our array

	return (1.0 * sum) / numInts;					// (1.0 * sum) is a way to cast an integer value 
}


// main program to demonstrate the use of the use of average(), inKeyboard() and inTest()
int main() {
	const int numInts = 10;

	cout << "The average from the keyboard is: " << average(inKeyboard, numInts) << endl;
	cout << "The average of randomly generated intergers is: " << average(inTest, numInts) << endl;
	cout << endl;

	system("PAUSE");
	return 0;
}