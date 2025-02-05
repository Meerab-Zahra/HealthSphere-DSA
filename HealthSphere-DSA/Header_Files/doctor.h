#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;
class Doctor {
private:
    int ID;
    string name;
    string speciality;
    string gender;
    string fee;
    string email;
    string contact;
    string hrs;
    Doctor* Next;
public:
    Doctor();
    void SetID(int);
    int GetID();
    void SetName(string);
    string GetName();
    void SetSpeciality(string);
    string GetSpeciality();
    void SetGender(string);
    string GetGender();
    void SetFee(string);
    string GetFee();
    void SetEmail(string);
    string GetEmail();
    void SetContact(string);
    string GetContact();
    void SetHrs(string);
    string GetHrs();
    void SetNext(Doctor*);
    Doctor* GetNext();
};
Doctor::Doctor() 
{
    ID = 0;
    name = "NULL";
    speciality = "NULL";
    gender = "NULL";
    fee = "NULL";
    email = "NULL";
    contact = "NULL";
    hrs = "NULL";
    Next = NULL;
}
void Doctor::SetID(int ID) 
{
    this->ID = ID;
}
int Doctor::GetID() 
{
    return ID;
}
void Doctor::SetName(string name) 
{
    this->name = name;
}
string Doctor::GetName() 
{
    return name;
}
void Doctor::SetSpeciality(string speciality) 
{
    this->speciality = speciality;
}
string Doctor::GetSpeciality() {
    return speciality;
}
void Doctor::SetGender(string gender) 
{
    this->gender = gender;
}
string Doctor::GetGender() 
{
    return gender;
}
void Doctor::SetFee(string fee) 
{
    this->fee = fee;
}
string Doctor::GetFee() 
{
    return fee;
}
void Doctor::SetEmail(string email) 
{
    this->email = email;
}
string Doctor::GetEmail() 
{
    return email;
}
void Doctor::SetContact(string contact) 
{
    this->contact = contact;
}
string Doctor::GetContact() 
{
    return contact;
}
void Doctor::SetHrs(string hrs) 
{
    this->hrs = hrs;
}
string Doctor::GetHrs() 
{
    return hrs;
}
void Doctor::SetNext(Doctor* Next) 
{
    this->Next = Next;
}
Doctor* Doctor::GetNext() 
{
    return Next;
}
class DoctorList {
private:
    Doctor* head;
    Doctor* tail;
public:
    DoctorList();
    void InsertDoctor(int, string, string, string, string, string, string, string);
    void DeleteDoctor(int);
    void SaveDoctorsToFile();
    void LoadDoctorsFromFile();
    void Print();
    void UpdateDoctor(int);
    Doctor* GetHead();
};
DoctorList::DoctorList() 
{
    head = NULL;
    tail = NULL;
}
Doctor* DoctorList::GetHead()
{
	return head;
}
void DoctorList::InsertDoctor(int ID, string name, string speciality, string gender, string fee, string email, string contact, string hrs) 
{
    Doctor* newDoctor = new Doctor();
    newDoctor->SetID(ID);
    newDoctor->SetName(name);
    newDoctor->SetSpeciality(speciality);
    newDoctor->SetGender(gender);
    newDoctor->SetFee(fee);
    newDoctor->SetEmail(email);
    newDoctor->SetContact(contact);
    newDoctor->SetHrs(hrs);
    if (head == NULL) 
	{
        head = newDoctor;
    } else 
	{
        tail->SetNext(newDoctor);
    }
    tail = newDoctor;
    SaveDoctorsToFile();
}
void DoctorList::DeleteDoctor(int ID) 
{
    if(head==NULL) 
	{
        cout<<"Nothing to delete. Empty list.\n";
        return;
    }
    Doctor* temp=head;
    Doctor* prev=NULL;
    if(head->GetID()==ID) 
	{
        head=head->GetNext();
        if(head==NULL) 
		{
			tail=NULL; 
		}
        delete temp;
        SaveDoctorsToFile();
        return;
    }
    while(temp!=NULL&&temp->GetID()!=ID) 
	{
        prev=temp;
        temp=temp->GetNext();
    }
    if(temp==NULL) 
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"Physician with ID "<<ID<<" does not exist!\n";
        SetConsoleTextAttribute(hConsole, 7);
        return;
    }
    prev->SetNext(temp->GetNext());
    if(temp==tail) 
	{
	tail=prev; 
	} 
		HANDLE aConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(aConsole, 3);
		cout<<"Physician Record Deleted Successfully!\n";
		SetConsoleTextAttribute(aConsole, 7);
    	delete temp;
    	SaveDoctorsToFile();
}
void DoctorList::Print() 
{
    Doctor* temp=head;
   while(temp!=NULL)
	{
		cout<<temp->GetID()<<" , "<<temp->GetName()<<" , "<<temp->GetSpeciality()<<" , "<<temp->GetGender()<<" , "<<temp->GetFee()<<" , "<<temp->GetEmail()<<" , "<<temp->GetContact()<<" , "<<temp->GetHrs()<<endl;
		temp=temp->GetNext();
	}
}
void DoctorList::LoadDoctorsFromFile() {
    ifstream myfile("Text_Files/Doctor.txt");
    int ID;
    string name,speciality,gender,fee,email,contact,hrs;

    if(myfile.is_open()) 
	{
        while(myfile>>ID>>name>>speciality>>gender>>fee>>email>>contact>>hrs) 
		{
            InsertDoctor(ID,name,speciality,gender,fee,email,contact,hrs);
        }
        myfile.close();
    } 
	else 
	{
        cout<<"Unable to open file.\n";
    }
}
void DoctorList::SaveDoctorsToFile() {
    ofstream myfile("Text_Files/Doctor.txt",ios::trunc);  
    if (myfile.is_open()) {
        Doctor* temp=head;
        while(temp!=NULL) 
		{
            myfile<<temp->GetID()<<" "<<temp->GetName()<<" "<<temp->GetSpeciality()<<" "<<temp->GetGender()<<" "<<temp->GetFee()<<" " <<temp->GetEmail()<<" "<< temp->GetContact()<<" " << temp->GetHrs()<<endl;
            temp=temp->GetNext();
        }
        myfile.close();
    } 
	else 
	{
        cout<<"Unable to open file for saving.\n";
    }
}
class TreeNode 
{
	private:
    	Doctor* Data;
    	TreeNode* Left;
    	TreeNode* Right;
	public:
    	TreeNode();
    	void SetData(Doctor*);
    	Doctor* GetData();
    	void SetLeft(TreeNode*);
    	TreeNode* GetLeft();
    	void SetRight(TreeNode*);
    	TreeNode* GetRight();
};
TreeNode::TreeNode() 
{
    Data = NULL;
    Left = NULL;
    Right = NULL;
}
void TreeNode::SetData(Doctor* Data) 
{
    this->Data = Data;
}
Doctor* TreeNode::GetData() 
{
    return this->Data;
}
void TreeNode::SetLeft(TreeNode* Left) 
{
    this->Left = Left;
}
TreeNode* TreeNode::GetLeft() 
{
    return Left;
}
void TreeNode::SetRight(TreeNode* Right) 
{
    this->Right = Right;
}
TreeNode* TreeNode::GetRight() 
{
    return Right;
}
class Tree 
{
	public:
    	void Insert(TreeNode* &root, Doctor* doctor);
    	void Inorder(TreeNode*);
    	Doctor* Search(TreeNode*,int);
};
void Tree::Insert(TreeNode*& root, Doctor* doctor) 
{
    TreeNode* node=new TreeNode();
    node->SetData(doctor);
    if(root==NULL) 
	{  
        root=node;
        return;
    }
    TreeNode* p=root;
    TreeNode* q=NULL;
    while(p!=NULL) 
	{
        q=p;  
        if(doctor->GetID()<p->GetData()->GetID()) 
		{
            p=p->GetLeft(); 
        } 
		else 
		{
            p=p->GetRight();  
        }
    }
    if (doctor->GetID()<q->GetData()->GetID()) 
	{
        q->SetLeft(node); 
    } 
	else 
	{
        q->SetRight(node); 
    }
}
Doctor* Tree::Search(TreeNode* root,int id)
{
	 if (root==NULL) 
    {
    	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
    	cout<<"Physician with ID "<<id<<" not found!\n";
    	SetConsoleTextAttribute(hConsole, 7);
        return NULL;
    }
    if (root->GetData()->GetID()==id) 
    {
        Doctor* doctor=root->GetData();
    	cout<<"Name: "<< doctor->GetName()<<"\n";
    	cout<<"Speciality: "<< doctor->GetSpeciality()<<"\n";
    	cout<<"Gender: "<< doctor->GetGender()<<"\n";
    	cout<<"Fee: "<< doctor->GetFee()<<"\n";
    	cout<<"Email: "<< doctor->GetEmail()<<"\n";
    	cout<<"Contact: "<< doctor->GetContact()<<"\n";
    	cout<<"Hours: "<< doctor->GetHrs()<<endl;
    	return doctor;
    } 
    if (id<root->GetData()->GetID()) 
    {
        return Search(root->GetLeft(),id);
    }
    else 
    {
        return Search(root->GetRight(),id);
    }
}
void Tree::Inorder(TreeNode* root) 
{
    if (root==NULL) 
	{
        return;  
    }
    Inorder(root->GetLeft());
    Doctor* doctor=root->GetData();
    cout<<"ID: "<< doctor->GetID()<<", ";
    cout<<"Name: "<< doctor->GetName()<<", ";
    cout<<"Speciality: "<< doctor->GetSpeciality()<<", ";
    cout<<"Gender: "<< doctor->GetGender()<<", ";
    cout<<"Fee: "<< doctor->GetFee()<<", ";
    cout<<"Email: "<< doctor->GetEmail()<<", ";
    cout<<"Contact: "<< doctor->GetContact()<<", ";
    cout<<"Hours: "<< doctor->GetHrs()<<endl;
    Inorder(root->GetRight());
}
void BuildBSTFromList(DoctorList& doctorList,TreeNode*& root) 
{
    Doctor* current=doctorList.GetHead();
    while (current!=NULL) 
	{
        Tree tree;
        tree.Insert(root, current); 
        current = current->GetNext();
    }
}
void DoctorList::UpdateDoctor(int ID) 
{
    Doctor* temp=head;
    while(temp!=NULL) {
        if (temp->GetID()==ID) 
		{
            string fee, email, contact, hrs;
            cin.ignore();
            cout<<"Enter updated Fee: ";
            getline(cin,fee);
            cout<<"Enter updated Email: ";
            getline(cin,email);
            cout<<"Enter updated Contact No: ";
            getline(cin,contact);
            cout<<"Enter updated Contact Hours: ";
            getline(cin,hrs);
            temp->SetFee(fee);
            temp->SetEmail(email);
            temp->SetContact(contact);
            temp->SetHrs(hrs);
            cout<<"Physician record updated successfully\n";
            SaveDoctorsToFile();
            return;
        }
        temp = temp->GetNext();
    }
    HANDLE yConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(yConsole, 12);
    cout << "Physician with ID "<<ID<<" not found\n";
    SetConsoleTextAttribute(yConsole, 7);
}

