#include<iostream>
#include<string>
#include<algorithm> 
#include<windows.h> 
using namespace std;
void setColor(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void resetColor() 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
}

void SuggestedMedicines()
{
	setColor(3); 
    cout<<"Suggested Medicines: ";
    resetColor();
}
void PreventiveMeasures()
{
	setColor(3); 
    cout<<"Preventive Measures: ";
    resetColor();
}
void TeleMedication()
{
    string name, disease;
    int age;
    HANDLE oConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(oConsole, 3);
    cout<<"---------------------------------------------Welcome to TeleMedication-----------------------------------------------\n";
	cout<<" "<<endl;
	SetConsoleTextAttribute(oConsole, 7);
    cout<<"Enter your Name: ";
    getline(cin, name);
    do {
        cout<<"Enter your age: ";
        cin>>age;
        if (age <= 0) {
            setColor(4); 
            cout<<"Invalid age entered! Age must be greater than 0."<<endl;
            resetColor();
        }
    } while (age <= 0); 
    cin.ignore();
    cout<<"Enter disease: ";
    getline(cin, disease);
    transform(disease.begin(), disease.end(), disease.begin(), ::tolower);
    
    setColor(14);
    cout<<"\nTeleMedication for "<<name<<"!\n"<<endl;
    resetColor();
    if (age < 18)
	{
        setColor(2); 
        cout<<"You are under 18, please consult a pediatrician for more accurate diagnosis.\n"<<endl;
        resetColor();
    } 
	    else if (age > 65)
	    {
        setColor(2); 
        cout<<"You are over 65, consider seeing a doctor for regular health checks.\n"<<endl;
        resetColor();
        }
    bool diseaseFound = false;
    if (disease == "fever") 
	{
        cout<<"It seems like you have a fever."<<endl;
        SuggestedMedicines();
        cout<<"Paracetamol, Ibuprofen."<<endl;
        PreventiveMeasures();
        cout<<"Stay hydrated, avoid cold environments, and rest."<<endl;
        diseaseFound = true;
    }
    else if (disease == "cough") 
	{
        cout<<"It seems like you have a cough."<<endl;
        SuggestedMedicines();
        cout<<"Cough syrup, Menthol lozenges."<<endl;
        PreventiveMeasures();
        cout<<"Avoid cold air, drink warm liquids, and avoid smoking."<<endl;
        diseaseFound = true;
    }
    else if (disease == "headache") 
	{
        cout<<"It seems like you have a headache."<<endl;
        SuggestedMedicines();
        cout<<"Acetaminophen, Aspirin."<<endl;
        PreventiveMeasures();
        cout<<"Rest in a quiet, dark room, stay hydrated, and avoid loud noises."<<endl;
        diseaseFound = true;
    }
    else if (disease == "cold")
	{
        cout<<"It seems like you have a common cold."<<endl;
        SuggestedMedicines();
        cout<<"Decongestants, Vitamin C tablets."<<endl;
        PreventiveMeasures();
        cout<<"Wash hands frequently, avoid close contact with others, and rest."<<endl;
        diseaseFound = true;
    }
    else if (disease == "stomach") 
	{
        cout<<"It seems like you have stomach discomfort."<<endl;
        SuggestedMedicines();
        cout<<"Antacids, Loperamide."<<endl;
        PreventiveMeasures();
        cout<<"Avoid spicy or greasy food, drink plenty of water, and avoid stress."<<endl;
        diseaseFound = true;
    }
    else if (disease == "diabetes") 
	{
        cout<<"It seems like you have diabetes."<<endl;
        SuggestedMedicines();
        cout<<"Insulin, Metformin."<<endl;
        PreventiveMeasures();
        cout<<"Maintain a healthy diet, monitor blood sugar levels, and exercise regularly."<<endl;
        diseaseFound = true;
    }
    else if (disease == "asthma")
	{
        cout << "It seems like you have asthma."<<endl;
        SuggestedMedicines();
        cout << "Inhalers (Salbutamol), Corticosteroids."<<endl;
        PreventiveMeasures();
        cout << "Avoid triggers, keep inhalers with you, and avoid cold air."<<endl;
        diseaseFound = true;
    }
    else if (disease == "hypertension")
	{
        cout<<"It seems like you have hypertension (high blood pressure)."<<endl;
        SuggestedMedicines();
        cout<<"ACE inhibitors, Beta blockers, Diuretics."<<endl;
        PreventiveMeasures();
        cout<<"Reduce salt intake, exercise regularly, avoid stress, and monitor blood pressure."<<endl;
        diseaseFound = true;
    }

    else if (disease == "insomnia") 
	{
       cout<<"It seems like you have insomnia."<<endl;
       SuggestedMedicines();
        cout<<"Melatonin, Zolpidem."<<endl;
        PreventiveMeasures();
       cout<<"Create a regular sleep schedule, avoid caffeine, and relax before bedtime."<<endl;
        diseaseFound = true;
    }
    else if (disease == "depression") 
	{
        cout<<"It seems like you have depression."<<endl;
        SuggestedMedicines();
        cout<<"Antidepressants (SSRIs, SNRIs), Counseling."<<endl;
        PreventiveMeasures();
        cout<<"Regular exercise, socializing, and seeking professional mental health support."<<endl;
        diseaseFound = true;
    }
    else if (disease == "allergy") 
	{
        cout<<"It seems like you have an allergy."<<endl;
        SuggestedMedicines();
        cout<<"Antihistamines (Loratadine, Cetirizine)."<<endl;
        PreventiveMeasures();
        cout<<"Avoid allergens, keep windows closed during pollen seasons, and wash hands frequently."<<endl;
        diseaseFound = true;
    }
    else if (disease == "migraine") 
	{
        cout<<"It seems like you have a migraine."<<endl;
        SuggestedMedicines();
        cout<<"Triptans, Ibuprofen."<<endl;
        PreventiveMeasures();
        cout<<"Avoid triggers like bright lights and strong smells, maintain a regular sleep schedule."<<endl;
        diseaseFound = true;
    }
    if (!diseaseFound)
	{
        setColor(12);
        cout<<"Invalid disease! We couldn't identify your condition."<<endl;
        resetColor();
    }
    cout<<"\nWould you like to try another TeleMedication? (yes/no): ";
    string choice;
    cin>>choice;
    cin.ignore(); 
    if (choice == "yes" || choice == "Yes") 
	{
        system("CLS");
        TeleMedication();
    } 
	  else 
	  {
    	setColor(14);
        cout<<"Thank you for using TeleMedication! Stay safe!"<<endl;
         resetColor();
      }
}



