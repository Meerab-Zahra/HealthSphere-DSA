using namespace std;
#include<iostream>
#include<string>
#include<curl/curl.h>
size_t WriteCallback(void* contents,size_t size,size_t nmemb,string* output) 
{
    size_t total_size =size*nmemb;
    output->append((char*)contents,total_size);
    return total_size;
}
void sendAppointmentMessage() 
{
    string p_name,dr_name,disease,ph,date;
    cout<<"Enter patient name: ";
    getline(cin,p_name);
    cout<<"Enter doctor name: ";
    getline(cin,dr_name);
    cout<<"Enter patient's ailment: ";
    getline(cin,disease);
    cout<<"Enter contact No: ";
    cin>>ph;
    cin.ignore();
    cout<<"Input appointment date: ";
    getline(cin,date);
    string account_sid="Your account_sid here";  
    string auth_token="Your auth_token here";  
    string from_number="Write number allocated by twilio here";  
    string to_number=ph; 
    string message="Dear "+ p_name+",\nYour appointment has been scheduled with "+ dr_name+ " on "+date +" for "+disease+".";
    string url="https://api.twilio.com/2010-04-01/Accounts/"+ account_sid+"/Messages.json";
    CURL* curl;
    CURLcode res;
    string response_string;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) 
	{
        curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
        curl_easy_setopt(curl,CURLOPT_USERNAME,account_sid.c_str());
        curl_easy_setopt(curl,CURLOPT_PASSWORD,auth_token.c_str());
        string post_data="From="+from_number+"&To="+to_number+"&Body="+message;
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,post_data.c_str());
        curl_easy_setopt(curl,CURLOPT_CAINFO,"Path of cacert.pem here");
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,&response_string);
        res=curl_easy_perform(curl);
        if(res!=CURLE_OK) 
		{
            cerr<<"cURL Error: "<< curl_easy_strerror(res)<<endl;
        } 
		else 
		{
            cout<<" "<<endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

