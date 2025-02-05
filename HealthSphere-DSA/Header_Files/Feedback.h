using namespace std;
#include<iostream>
#include<fstream>
#include<string>
void Rating()
{
	int rating;
	cout<<"Enter rating from 1 to 5: ";
	cin>>rating;
	if(rating<1)
	{
		rating=1;
	}
	if(rating>5)
	{
		rating=5;
	}
	const char filled_Heart=3;
	HANDLE gConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(gConsole, 14);
	cout<<"\nYour rating is: ";
	for(int i=0;i<rating;i++)
	{
   		SetConsoleTextAttribute(gConsole, 7);
		cout<<filled_Heart<<" ";
	}
		cout<<endl;
}
void addReview()
{
	ofstream outFile;
	outFile.open("Text_Files/Feedback.txt",ios::app);
	if(!outFile.is_open())
	{
		cout<<"Error opening file\n";
	}
	string username,comment;
	cout<<"Reviewer's Name: ";
	getline(cin,username);
	cout<<"Drop your review: ";
	getline(cin,comment);
	outFile<<username<<"    "<<comment<<endl;
	HANDLE abConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(abConsole, 14);
	cout<<"\nThank you for contributing your thoughts!"<<endl;
	SetConsoleTextAttribute(abConsole, 7);
	outFile.close();
}
void displayReview()
{
	ifstream inFile;
	inFile.open("Text_Files/Feedback.txt",ios::in);
	if(!inFile.is_open())
	{
		cout<<"Error opening file\n";
	}
	string a;
	while(getline(inFile,a))
	{
		cout<<a<<endl;
	}
	inFile.close();
}

