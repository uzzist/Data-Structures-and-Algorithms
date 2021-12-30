#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void frequent(string);

int main()
{
	string input;
	cout << "Enter a string: ";
	cin >> input;
	frequent(input);
	return 0;	
}
void frequent(string input)
{
	int max = 0;
	int length = input.length();
	int count = 0;
	for(int i = 0;i < length; i++)
	{
		count = 1;
		for(int j = i+1; j < length; j++)
		{
			if(input[i] == input[j])
			{
				count++;
			}	
		}
		if(count > max)
		{
			max = count;
		}	
	}
	count = 0;
	cout << "Most frequent element: ";
	for (int i=0;i<length;i++)
  	{
   		count=1;
   		for(int j = i+1;j < length;j++)
       	if(input[i] == input[j])
       	{
       		count++;
		}
   		if(count == max)
   		{
   			cout << input[i] << endl;
		}
  	}
}
