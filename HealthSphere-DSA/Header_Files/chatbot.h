using namespace std;
#include <iostream>
#include <string>
#include <map>
#include<windows.h>
struct Symptom 
{
    string name;
    string possibleCauses;
};
void symptomChecker() 
{
    map<string, Symptom> symptoms;
    symptoms["headache"] = {"Headache", "Migraine, tension, sinus pressure, dehydration"};
    symptoms["fever"] = {"Fever", "Infection, flu, virus, pneumonia"};
    symptoms["cough"] = {"Cough", "Cold, flu, bronchitis, asthma"};
    symptoms["fatigue"] = {"Fatigue", "Anemia, diabetes, hypothyroidism, sleep apnea"};
    symptoms["nausea"] = {"Nausea", "Food poisoning, motion sickness, pregnancy, migraines"};
    symptoms["diarrhea"] = {"Diarrhea", "Food poisoning, viral infection, bacterial infection, lactose intolerance"};
    symptoms["abdominal pain"] = {"Abdominal pain", "Appendicitis, kidney stones, ulcers, inflammatory bowel disease"};
    symptoms["chest pain"] = {"Chest pain", "Heart attack, angina, pneumonia, pulmonary embolism"};
    symptoms["shortness of breath"] = {"Shortness of breath", "Asthma, chronic obstructive pulmonary disease (COPD), pneumonia, heart failure"};
    symptoms["rash"] = {"Rash", "Allergic reaction, eczema, psoriasis, skin infection"};
    symptoms["sore throat"] = {"Sore throat", "Cold, flu, mononucleosis, strep throat"};
    symptoms["vomiting"] = {"Vomiting", "Food poisoning, viral infection, motion sickness, pregnancy"};
    symptoms["dizziness"] = {"Dizziness", "Inner ear infection, dehydration, low blood pressure, anxiety"};
    symptoms["weakness"] = {"Weakness", "Anemia, diabetes, hypothyroidism, sleep apnea"};
    symptoms["weight loss"] = {"Weight loss", "Cancer, diabetes, hyperthyroidism, eating disorder"};
    symptoms["mood swings"] = {"Mood swings", "Depression, anxiety, bipolar disorder, hormonal changes"};
    HANDLE qConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(qConsole, 3);
	cout<<"---------------------------------------------Disease Detector Chatbot--------------------------------------------------";
	cout<<" "<<endl;
	cout<<endl;
	SetConsoleTextAttribute(qConsole, 8);
	cout<<"Hey! I'm Disease Detector Chatbot, ready to assist you with your health concerns.\nTo get started, select two options\n";
	cout<<endl;
	SetConsoleTextAttribute(qConsole, 7);
    cout << "1. Enter symptom" << endl;
    cout << "2. View symptoms of diseases" << endl;
    int choice;
    cout << endl;
    cout << "Make your choice: ";
    cin >> choice;
    cin.ignore(); 
    system("cls");
    switch (choice) 
	{
        case 1: {
            string input;
            cout << "Enter your symptom: ";
            getline(cin, input);
            map<string, Symptom>::iterator it = symptoms.find(input);
             HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            if (it != symptoms.end()) {
                Symptom symptom = it->second;
                Sleep(1000);
                cout<<endl;
        		SetConsoleTextAttribute(hConsole, 10);
                cout<<"Response from chatbot\n";
                SetConsoleTextAttribute(hConsole, 11);
                cout << "Possible causes: ";
                SetConsoleTextAttribute(hConsole, 7);
				cout << symptom.possibleCauses << endl;
				SetConsoleTextAttribute(hConsole, 14);
            	cout<<"Thank You! It was pleasure assisting you.\n";
            	SetConsoleTextAttribute(hConsole, 7);
            } else {
            	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 12);
                cout << "Sorry! I couldn't identify your symptom." << endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
            break;
        }
        case 2:
            
            for (map<string, Symptom>::iterator it = symptoms.begin(); it != symptoms.end(); ++it) {
                cout << "Symptom: " << it->first << endl;
                cout << "Possible causes: " << it->second.possibleCauses << endl;
                cout << endl;
            }
            break;
        	default:
        	{
            cout << "Invalid choice. Please select a different option." << endl;
            Sleep(1000);
            system("cls");
            symptomChecker();
            break;
        }
    }
    string start;
    HANDLE zConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(zConsole, 10);
    cout<<endl;
    cout<<"Re-initiate Disease Detection Process (yes/no): ";
    SetConsoleTextAttribute(zConsole, 7);
    cin>>start;
    if(start=="yes")
    {
    	system("cls");
    	symptomChecker();
	}
}

