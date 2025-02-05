using namespace std;
#include<iostream>
#include<string>
#include<curl/curl.h>
#include<fstream>
#include "Header_Files/doctor.h"
#include "Header_Files/Patient.h"
#include "Header_Files/chatbot.h"
#include "Header_Files/Appointment.h"
#include "Header_Files/Feedback.h"
#include "Header_Files/TeleMedication.h"
#include "Header_Files/Developer.h"
void loading()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING DATA...";
	cout<<"\n"<<endl;
	char a=176;
	char b=219;
	for(int i=0;i<60;i++)
	{
		cout<<b<<a;
		Sleep(4.5);
	}
	system("cls");
} 
void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ResetColor() 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
}
void Title() 
{
				char m=176;
	            SetColor(14);
	            cout<<"\n";
    	        cout<<"\t\t\t\t";
    	        for(int i=0;i<53;i++)
    	        {
    	        	cout<<m;
				}
    			SetColor(3);
    			cout<<endl;
    			cout<<"\n\t\t\t\t\t\t  HEALTHSPHERE "<<endl;
                cout<<"\t\t\t\t\tGateway to Better Health & Care!"<<endl;
                SetColor(14);
    			cout << "\n";
    			cout<<"\t\t\t\t";
    		    for(int i=0;i<53;i++)
    	        {
    	        	cout<<m;
				}
                ResetColor();
                cout<<"\n\n\n";
}
int main() 
{ 
	loading();
	main_menu:
	Title();
	int choice;
	cout<<"\t\t\t\t\t     1. Physician Dashboard\n";
	cout<<"\t\t\t\t\t     2. Patient Dashboard\n";
	cout<<"\t\t\t\t\t     3. Appointment Console\n";
	cout<<"\t\t\t\t\t     4. TeleMedication\n";
	cout<<"\t\t\t\t\t     5. Disease Detector Chatbot\n";
	cout<<"\t\t\t\t\t     6. Rating and Reviews\n";
	cout<<"\t\t\t\t\t     7. Developer Credentials\n";
	cout<<"\t\t\t\t\t     8. Exit\n";
	cout<<endl;
	cout<<"\t\t\t\t\t     Make your choice: ";
	cin>>choice;
	system("cls");
	if(choice==1)
	{
		return_dashboard:
		int a;
		DoctorList dl;
		Tree dt;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 3);	
		cout<<"---------------------------------------------------Physician Dashboard--------------------------------------------------\n";
    	cout<<"  "<<endl;
    	SetConsoleTextAttribute(hConsole, 7);	
		cout<<"1.Create Physician Profile\n";
		cout<<"2.View Physician Directory \n";
		cout<<"3.Search Physician Profile\n";
		cout<<"4.Deactivate Physician Profile\n";
		cout<<"5.Update Record\n";
		cout<<"6.Return to Main Menu\n";
		cout<<endl;
		cout<<"Choose a numbered option: ";
		cin>>a;
		system("cls");
		cout<<endl;
		if(a==1)
		{
		dl.LoadDoctorsFromFile();
    	int id;
    	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hConsole, 10);	
		cout<<"-------------------------------------------------Physician Onboarding---------------------------------------------------\n";
    	cout<<"  "<<endl;
    	SetConsoleTextAttribute(hConsole, 7);
    	string name,speciality,gender,fee,email,contact,hrs;
    	cout<<"Enter ID: ";
    	cin>>id;
    	cin.ignore();
   	 	cout<<"Enter Name: ";
    	getline(cin,name);
    	cout<<"Enter Speciality: ";
    	getline(cin,speciality);
    	cout<<"Enter Gender: ";
    	getline(cin,gender);
    	cout<<"Enter Fee: ";
    	getline(cin,fee);
    	cout<<"Enter Email: ";
    	getline(cin,email);
    	cout<<"Enter Contact No: ";
    	getline(cin,contact);
    	cout<<"Enter Contact Hours: ";
   	    getline(cin,hrs);
    	dl.InsertDoctor(id,name,speciality,gender,fee,email,contact,hrs);
        SetConsoleTextAttribute(hConsole, 14);
    	cout<<"Physician inserted successfully!\n";
    	SetConsoleTextAttribute(hConsole, 7);
    	cout<<endl;
    	string ret;
    	HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(bConsole, 10);
    	cout<<"Return to Physician Dashboard? (yes/no): ";
    	SetConsoleTextAttribute(bConsole, 7);
    	cin>>ret;
    	if(ret=="yes")
    	{
    		system("cls");
    		goto return_dashboard;
		}
		}
		else if(a==2)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(hConsole, 10);
			cout<<"--------------------------------------------Available Physicians--------------------------------------------------------";
			cout<<" "<<endl;
			SetConsoleTextAttribute(hConsole, 7);
			Tree tree;
    		dl.LoadDoctorsFromFile();
    		TreeNode* root=NULL;  
    		BuildBSTFromList(dl,root); 
    		tree.Inorder(root);
    		cout<<endl;
    		string ret;
    		HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(bConsole, 10);
    		cout<<"Return to Physician Dashboard? (yes/no): ";		
        	SetConsoleTextAttribute(bConsole, 7);
    		cin>>ret;
    		if(ret=="yes")
    	{
    		system("cls");
    		goto return_dashboard;
		}
	}
		else if(a==3)
		{
			int searchID;
    		Tree tree;
    		DoctorList doctorList;
    		doctorList.LoadDoctorsFromFile();
    		TreeNode* root=NULL;  
   			BuildBSTFromList(doctorList,root);  
    		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(hConsole, 10);
    		cout<<"------------------------------------------Data of Physician with entered ID--------------------------------------------";
    		cout<<"  "<<endl;
    		SetConsoleTextAttribute(hConsole, 7);
    		cout<<"Enter ID of physician to be searched: ";
    		cin>>searchID;
    		cout<<"  "<<endl;
			tree.Search(root,searchID);
			cout<<endl;
			string ret;
			HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(bConsole, 10);
    		cout<<"Return to Physician Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(bConsole, 7);
    		cin>>ret;
    		if(ret=="yes")
    	{
    		system("cls");
    		goto return_dashboard;
		}
		}
		else if(a==4)
		{
			dl.LoadDoctorsFromFile();
			int delID;
    		cout<<"Enter ID of Physician to be deleted: ";
    		cin>>delID;
    		dl.DeleteDoctor(delID);
    		cout<<endl;
    		string ret;
    		HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(bConsole, 10);
    		cout<<"Return to Physician Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(bConsole, 7);
    		cin>>ret;
    		if(ret=="yes")
    	{
    		system("cls");
    		goto return_dashboard;
		}
		}
		else if(a==5)
		{
			dl.LoadDoctorsFromFile();
			int updateID;
			cout<<"Input physician ID to update record: ";
			cin>>updateID;
			dl.UpdateDoctor(updateID);
			cout<<endl;
			string ret;
			HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(bConsole, 10);
    		cout<<"Return to Physician Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(bConsole, 7);
    		cin>>ret;
    		if(ret=="yes")
    	{
    		system("cls");
    		goto return_dashboard;
		}
		}
		else if(a==6)
		{
			system("cls");
			goto main_menu;
		}
		else
		{
			cout<<"Enter a valid choice\n";
			Sleep(1000);
			system("cls");
    		goto return_dashboard;
		}
		}
	else if(choice==2)
	{
		patient:
		PatientQueue list;
		int x;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 3);	
		cout<<"---------------------------------------------------Patient Dashboard----------------------------------------------------\n";
    	cout<<"  "<<endl;
    	SetConsoleTextAttribute(hConsole, 7);	
		 cout<<"1.Admit a Patient\n";
        cout<<"2.Attend to (dequeue) a patient\n";
        cout<<"3.View Waiting list\n";
        cout<<"4.View all Patients (waiting and attended)\n";
        cout<<"5.Search Patient Record\n";
        cout<<"6.Return to Main Menu\n";
        cout<<"\n";
        cout<<"Choose a numbered option: ";
        cin>>x;
        system("cls");
        if(x==1)
        {
        	list.LoadPatientsFromFile();
        	HANDLE tConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(hConsole, 10);	
			cout<<"--------------------------------------------------Registeration Desk----------------------------------------------------\n";
    		cout<<"  "<<endl;
    		SetConsoleTextAttribute(hConsole, 7);
        	int ID, DrID, age;
            string name, Drname, disease, gender, contact;
            cout<<"Enter Patient ID: ";
            cin>>ID;
            cout<<"Enter Doctor ID: ";
            cin>>DrID;
            cin.ignore();
            cout<<"Enter Patient Name: ";
            getline(cin, name);
            cout<<"Enter Doctor's Name: ";
            getline(cin, Drname);
            cout<<"Enter Disease: ";
            getline(cin, disease);
            cout<<"Enter Gender: ";
            getline(cin, gender);
            cout<<"Enter Age: ";
            cin>>age;
            cin.ignore();
            cout<<"Enter Contact No: ";
            getline(cin, contact);
            list.Enqueue(ID, DrID, name, Drname, disease, gender, age, contact);
            cout<<endl;
       		SetConsoleTextAttribute(tConsole, 14);
    		cout<<"Patient inserted successfully!\n";
            cout<<endl;
    		string back;
        	SetConsoleTextAttribute(tConsole, 10);
    		cout<<"Return to Patient Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(tConsole, 7);
    		cin>>back;
    		if(back=="yes")
    		{
    		system("cls");
    		goto patient;
			}
		}
		else if(x==2)
		{
			string back;
			list.LoadPatientsFromFile();
			HANDLE tConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(tConsole, 10);	
			cout<<"--------------------------------------------------Patient Discharge----------------------------------------------------\n";
    		cout<<"  "<<endl;
    		SetConsoleTextAttribute(hConsole, 7);
			list.Dequeue();
        	SetConsoleTextAttribute(tConsole, 10);
    		cout<<"Return to Patient Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(tConsole, 7);
    		cin>>back;
    		if(back=="yes")
    		{
    		system("cls");
    		goto patient;
		}
	}
		else if(x==3)
		{
			list.LoadPatientsFromFile();
			HANDLE tConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 10);	
			cout<<"--------------------------------------------------Waiting List-------------------------------------------------------\n";
    		cout<<"  "<<endl;
    		SetConsoleTextAttribute(hConsole, 7);
			list.PrintQueue();
			cout<<endl;
    		string back;
        	SetConsoleTextAttribute(tConsole, 10);
    		cout<<"Return to Patient Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(tConsole, 7);
    		cin>>back;
    		if(back=="yes")
    		{
    		system("cls");
    		goto patient;
		}
		}
		else if(x==4)
		{
			list.LoadPatientsFromFile();
			HANDLE tConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 10);	
			cout<<"--------------------------------------------------Patient Directory----------------------------------------------------\n";
    		cout<<"  "<<endl;
    		SetConsoleTextAttribute(tConsole, 7);
			list.ViewAllPatients();
			cout<<endl;
    		string back;
        	SetConsoleTextAttribute(tConsole, 10);
    		cout<<"Return to Patient Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(tConsole, 7);
    		cin>>back;
    		if(back=="yes")
    		{
    		system("cls");
    		goto patient;
		}
		}
		else if(x==5)
		{
			HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(lConsole, 10);	
			cout<<"-----------------------------------------Data of Patient with entered ID------------------------------------------------\n";
    		cout<<"  "<<endl;
    		SetConsoleTextAttribute(lConsole, 7);	
			int ID;
            cout<<"Enter the Patient ID to search: ";
            cin>>ID;
            list.SearchPatientByID(ID);
            cout<<endl;
    		string back;
    		SetConsoleTextAttribute(lConsole, 10);
    		cout<<"Return to Patient Dashboard? (yes/no): ";
    		SetConsoleTextAttribute(lConsole, 7);
    		cin>>back;
    		if(back=="yes")
    		{
    		system("cls");
    		goto patient;
			}
		}
		else if(x==6)
		{
			system("cls");
			goto main_menu;
		}
		else 
		{
			cout<<"Enter a valid choice\n";
			Sleep(1000);
			system("cls");
    		goto patient;
		}
	}
	else if(choice==3)
	{
		HANDLE yConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   		SetConsoleTextAttribute(yConsole, 3);
		cout<<"--------------------------------------------Schedule your Appointment now----------------------------------------------\n";
		cout<<" "<<endl;
		SetConsoleTextAttribute(yConsole, 7);
		cin.ignore();
		sendAppointmentMessage();
		string ret;
		HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(bConsole, 3);
    	cout<<"Return to Main Menu? (yes/no): ";
    	SetConsoleTextAttribute(bConsole, 7);
    	cin>>ret;
    	if(ret=="yes")
    	{
    		system("cls");
    		goto main_menu;
		}
	}
	else if(choice==4)
	{
		cin.ignore();
		TeleMedication();
		cout<<endl;
		string ret;
		HANDLE pConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(pConsole, 3);
    	cout<<"Return to Main Menu? (yes/no): ";
    	SetConsoleTextAttribute(pConsole, 7);
    	cin>>ret;
    	if(ret=="yes")
    	{
    		system("cls");
    		goto main_menu;
		}
	}
	else if(choice==5)
	{
		cin.ignore();
		symptomChecker();
		cout<<endl;
		string ret;
		HANDLE cConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(cConsole, 3);
    	cout<<"Return to Main Menu? (yes/no): ";
    	SetConsoleTextAttribute(cConsole, 7);
    	cin>>ret;
    	if(ret=="yes")
    	{
    		system("cls");
    		goto main_menu;
		}
	}
	else if(choice==6)
	{
		review_menu:
		int b;
		HANDLE yConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   		SetConsoleTextAttribute(yConsole, 3);
		cout<<"---------------------------------------------------Feedback Forum------------------------------------------------------\n";
		cout<<" "<<endl;
		SetConsoleTextAttribute(yConsole, 7);
		cin.ignore();
		cout<<"1. Rate your experience\n";
		cout<<"2. Drop your review\n";
		cout<<"3. Check out reviews\n";
		cout<<"4. Return to Main Menu\n";
		cout<<endl;
		cout<<"Input your choice: ";
		cin>>b;
		system("cls");
		if(b==1)
		{
			HANDLE fConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   			SetConsoleTextAttribute(fConsole, 10);
			cout<<"------------------------------------------------------Rating Zone------------------------------------------------------\n";
			cout<<" "<<endl;
			SetConsoleTextAttribute(fConsole, 7);
			Rating();
		}
		else if(b==2)
		{
			HANDLE fConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   			SetConsoleTextAttribute(fConsole, 10);
			cout<<"-----------------------------------------------------Share Your Thoughts------------------------------------------------\n";
			cout<<" "<<endl;
			SetConsoleTextAttribute(fConsole, 7);
			cin.ignore();
			addReview();
		}
		else if(b==3)
		{
			HANDLE fConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   			SetConsoleTextAttribute(fConsole, 10);
			cout<<"-----------------------------------------------------See What Others Say------------------------------------------------\n";
			cout<<" "<<endl;
			SetConsoleTextAttribute(fConsole, 7);
			displayReview();
		}
		else if(b==4)
		{
			system("cls");
			goto main_menu;
		}
		else
		{
			cout<<"Enter a valid option\n";
			Sleep(1000);
			system("cls");
			goto review_menu;
		}
		cout<<endl;
		string restart;
    	HANDLE wConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(wConsole, 10);
    	cout<<"Back to Feedback Forum (yes/no): ";
    	SetConsoleTextAttribute(wConsole, 7);
    	cin>>restart;
    	if(restart=="yes")
    	{
    	system("cls");
    	goto review_menu;
		}
		cout<<endl;
		string ret;
		HANDLE dConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(dConsole, 3);
    	cout<<"Return to Main Menu? (yes/no): ";
    	SetConsoleTextAttribute(dConsole, 7);
    	cin>>ret;
    	if(ret=="yes")
    	{
    		system("cls");
    		goto main_menu;
		}
	}
	else if(choice==7)
	{
		displayDeveloperDetails();
		cout<<endl;
		string ret;
		HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(bConsole, 3);
    	cout<<"Return to Main Menu? (yes/no): ";
    	SetConsoleTextAttribute(bConsole, 7);
    	cin>>ret;
    	if(ret=="yes")
    	{
    		system("cls");
    		goto main_menu;
		}
	}
	else if(choice==8)
	{
		HANDLE bConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(bConsole, 11);
		cout<<"Program Terminated Successfully!See you next time.\n";
		SetConsoleTextAttribute(bConsole, 7);
	}
	else
	{
		cout<<"Enter a valid option\n";
		Sleep(1000);
		system("cls");
		goto main_menu;
	}	
    return 0;
}


