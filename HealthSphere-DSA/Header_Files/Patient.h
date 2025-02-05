#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Patient 
{
private:
    int ID;
    int DrID;
    string name;
    string Drname;
    string disease;
    string gender;
    int age;
    string contact;
    Patient* Next;
public:
    Patient();
    void SetID(int);
    int GetID();
    void SetDrID(int);
    int GetDrID();
    void SetName(string);
    string GetName();
    void SetDrName(string);
    string GetDrName();
    void SetDisease(string);
    string GetDisease();
    void SetGender(string);
    string GetGender();
    void SetAge(int);
    int GetAge();
    void SetContact(string);
    string GetContact();
    void SetNext(Patient*);
    Patient* GetNext();
};
Patient::Patient() 
{
    ID=0;
    DrID=0;
    name="NULL";
    Drname="NULL";
    disease="NULL";
    gender="NULL";
    age=0;
    contact="NULL";
    Next=NULL;
}
void Patient::SetID(int ID)
{
	this->ID=ID;
}
int Patient::GetID()
{
	return ID;
}
void Patient::SetDrID(int DrID)
{
	this->DrID=DrID;
}
int Patient::GetDrID()
{
	return DrID;
}
void Patient::SetName(string name)
{
	this->name=name;
}
string Patient::GetName()
{
	return name;
}
void Patient::SetDrName(string Drname)
{
	this->Drname=Drname;
}
string Patient::GetDrName()
{
	return Drname;
}
void Patient::SetDisease(string disease)
{
	this->disease=disease;
}	
string Patient::GetDisease()
{
	return disease;
}
void Patient::SetGender(string gender)
{
	this->gender=gender;
}
string Patient::GetGender()
{
	return gender;
}
void Patient::SetAge(int age)
{
	this->age=age;
}
int Patient::GetAge()
{
	return age;
}
void Patient::SetContact(string contact)
{
	this->contact=contact;
}
string Patient::GetContact()
{
	return contact;
}
void Patient::SetNext(Patient* Next)
{
	this->Next=Next;
}
Patient* Patient::GetNext()
{
	return Next;
} 
class PatientQueue {
private:
    Patient* Front;
    Patient* Rear;
public:
    PatientQueue();
    void Enqueue(int, int, string, string, string, string, int, string);
    void Dequeue();
    void PrintQueue();
    void SavePatientsToFile();
    void AppendToPermanentFile(Patient* patient);
    void LoadPatientsFromFile();
    bool IsEmpty();
    void ViewAllPatients();
    void SearchPatientByID(int);
};
PatientQueue::PatientQueue() 
{
    Front=NULL;
    Rear=NULL;
}

void PatientQueue::Enqueue(int ID, int DrID, string name, string Drname, string disease, string gender, int age, string contact)
{
    Patient* newPatient = new Patient();
    newPatient->SetID(ID);
    newPatient->SetDrID(DrID);
    newPatient->SetName(name);
    newPatient->SetDrName(Drname);
    newPatient->SetDisease(disease);
    newPatient->SetGender(gender);
    newPatient->SetAge(age);
    newPatient->SetContact(contact);
    if (IsEmpty()) 
	{
        Front=newPatient;
    } 
	else 
	{
        Rear->SetNext(newPatient);
    }
    Rear=newPatient;
    SavePatientsToFile();
}
void PatientQueue::Dequeue()
{
    if (IsEmpty()) 
	{
		HANDLE avConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(avConsole, 12);	
        cout<<"The waiting list is empty. No patients to attend.\n";
        SetConsoleTextAttribute(avConsole, 7);	
        cout<<endl;
        return;
    }
    Patient* temp = Front;
    AppendToPermanentFile(temp);
    HANDLE avConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(avConsole, 12);	
    cout<<"Patient with ID "<<temp->GetID()<<" has been attended to and record saved permanently.\n";
    SetConsoleTextAttribute(avConsole, 7);	
	delete temp;
    SavePatientsToFile();
}
void PatientQueue::AppendToPermanentFile(Patient* patient) 
{
    ofstream myfile("Text_Files/PermanentRecords.txt", ios::app);
    if (myfile.is_open()) 
	{
        myfile<<patient->GetID()<<" "<<patient->GetDrID()<<" " <<patient->GetName()<<" "<<patient->GetDrName()<<" "<<patient->GetDisease()<<" "<<patient->GetGender()<<" "<<patient->GetAge()<<" "<<patient->GetContact()<<"\n";
        myfile.close();
    } 
	else 
	{
        cout<<"Error: Unable to open PermanentRecords.txt for saving.\n";
    }
}
void PatientQueue::PrintQueue()
{
    Patient* temp = Front;
    if (IsEmpty()) 
	{
        cout<<"The waiting list is empty.\n";
        return;
    }
    while (temp != NULL) 
	{
        cout<<"ID: "<<temp->GetID()<<", Name: "<<temp->GetName()<<", Age: "<<temp->GetAge()<<"\n";
        temp = temp->GetNext();
    }
}

bool PatientQueue::IsEmpty()
{
    return Front == NULL;
}
void PatientQueue::SavePatientsToFile()
{
    ofstream myfile("Text_Files/Patient.txt", ios::trunc);
    if (myfile.is_open()) 
	{
        Patient* temp = Front;
        while (temp != NULL) 
		{
            myfile<<temp->GetID()<<" "<<temp->GetDrID()<<" "<<temp->GetName()<<" "<<temp->GetDrName()<<" "<<temp->GetDisease()<<" "<<temp->GetGender()<<" "<<temp->GetAge()<<" "<<temp->GetContact()<<"\n";
            temp = temp->GetNext();
        }
        myfile.close();
    } 
	else 
	{
        cout<<"Error: Unable to open Patient.txt for saving.\n";
    }
}
void PatientQueue::LoadPatientsFromFile()
{
    ifstream myfile("Text_Files/Patient.txt");
    int ID, DrID, age;
    string name, Drname, disease, gender, contact;
    if (myfile.is_open())
	 {
        while (myfile>>ID>>DrID>>name>>Drname>>disease>>gender>>age>>contact) 
		{
            Enqueue(ID, DrID, name, Drname, disease, gender, age, contact);
        }
        myfile.close();
    } 
	else
	{
        cout<<"Unable to open Patient.txt.\n";
    }
}
void PatientQueue::ViewAllPatients() 
{
	HANDLE amConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(amConsole, 14);	
    cout<<"\nPatients in waiting list: \n";
    SetConsoleTextAttribute(amConsole, 7);	
    PrintQueue();
    SetConsoleTextAttribute(amConsole, 14);	
    cout<<"\nPatients in Permanent Records: \n";
    SetConsoleTextAttribute(amConsole, 7);	
    ifstream myfile("Text_Files/PermanentRecords.txt");
    string line;
    if (myfile.is_open()) 
	{
        while (getline(myfile, line))
		{
            cout<<line << endl;
        }
        myfile.close();
    } 
	else 
	{
        cout<<"No permanent records found.\n";
    }
}
void PatientQueue::SearchPatientByID(int ID) 
{
    bool found = false;
    LoadPatientsFromFile();
    if (!IsEmpty()) 
	{
        Patient* temp = Front;
        while (temp != NULL) 
		{
            if (temp->GetID() == ID) 
			{
                cout<<"\nPatient Found in Waiting List!\n";
                cout<<"ID: "<<temp->GetID()<<"\n";
                cout<<"Name: "<<temp->GetName()<<"\n";
                cout<<"Doctor ID: "<<temp->GetDrID()<<"\n";
                cout<<"Doctor Name: "<<temp->GetDrName()<<"\n";
                cout<<"Disease: "<<temp->GetDisease()<<"\n";
                cout<<"Gender: "<<temp->GetGender()<<"\n";
                cout<<"Age: "<<temp->GetAge()<<"\n";
                cout<<"Contact: "<<temp->GetContact()<<"\n";
                found=true;
                break;
            }
            temp = temp->GetNext();
        }
    }
    ifstream myfile("Text_Files/PermanentRecords.txt");
    if (myfile.is_open())
	 {
        int pID, DrID, age;
        string name, Drname, disease, gender, contact;
        while (myfile >> pID >> DrID >> name >> Drname >> disease >> gender >> age >> contact) 
		{
            if (pID == ID) 
			{
                cout<<"\nPatient Found in Permanent Records!\n";
                cout<<"ID: "<<pID<<"\n";
                cout<<"Name: "<<name<<"\n";
                cout<<"Doctor ID: "<<DrID<<"\n";
                cout<<"Doctor Name: "<<Drname<<"\n";
                cout<<"Disease: "<<disease<<"\n";
                cout<<"Gender: "<<gender<<"\n";
                cout<<"Age: " << age << "\n";
                cout<<"Contact: " << contact << "\n";
                found = true;
                break;
            }
        }
        myfile.close();
    } 
	else 
	{
        cout<<"Error! Unable to open PermanentRecords.\n";
    }
    	HANDLE avConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(avConsole, 12);	
		if (!found) {
        cout<<"No patient with ID "<<ID<<" found in the waiting list or permanent records!\n";
    }
    	SetConsoleTextAttribute(avConsole, 7);
}

