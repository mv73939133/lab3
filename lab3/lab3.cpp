#include<iostream>
using namespace std;
int  removeElement(int arr[100], int elements, int index)
{	
	arr[index] = arr[elements-1];
	elements = elements-1;
	return elements;
}

int removeDuplicates(int arr[100],int elements)
{

	int t;
	int l,m;
	for(int i=0;i<elements;i++)
	{
		for(int j=(i+1);j<elements;j++)
		{
			if(arr[i] == arr[j])
			{
				t = removeElement(arr,elements,j);
				elements = elements-1;
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		for(int j =(i+1); j<t;j++)
		{
			if(arr[i] == arr[j])
			{
				t = removeDuplicates(arr,t);
			}
		}
	}
	
	return t;
}


void printOutput(int arr[100],int t)
{
	for(int i=0;i<t;i++)
	{
		cout << arr[i] << endl;
	}
	cout<< endl;

}


int main()
{
	int firstArray[5] = {10,20,50,30,4};
	int firstCount = 5,t;
	int userEntry;
	int testArray[100];
	t =  removeElement(firstArray,firstCount,2);
    printOutput(firstArray,t);	
	int secondArray[10]= {10,20,50,30,4,20,60,10,43,88};
	int secondCount=10;
	t =removeDuplicates(secondArray,secondCount);
     printOutput(secondArray,t);	
	 do
	 {
cout << "Press -1 for exit or 1 for continuing" << endl;
cin >> userEntry;
 if(userEntry!=-1)
   {
	   cout << "enter the number of elements and number less than 100" << endl;
	   cin >> firstCount;
	   cout<< "please enter the elements into the array" << endl;
	   for(int i=0;i<firstCount;i++)
	   {

       cin >> testArray[i];

   }
	   t = removeDuplicates(testArray,firstCount);
	   cout<< endl;
	   printOutput(testArray,t);
	
	 } 
	 }while(userEntry!=-1);
	return 0;
}