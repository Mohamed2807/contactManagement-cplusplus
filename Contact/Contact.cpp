#include<iostream>
#include<fstream>
#include<iomanip>
#include <ctime>
#include <sstream>

using namespace std;

void controller();
class Contact{
		public:
	string   Contact_name[50];
	string   Contact_number[50];
	string   Contact_email[50];
	string   Contact_address[50];
	string   Contact_all_Data[500];
	int Each_Count=0;
	int allData_Count=0;
	

	
	void Get_Contact()
	{
		string demo;
		ifstream contact("Contact.txt");
		while(getline(contact,Contact_all_Data[allData_Count]))
		{
			allData_Count++;
		}
	
		for(int i=0;i<allData_Count;i++)
		{
			Contact_all_Data[i++];
			Contact_name[Each_Count]=Contact_all_Data[i++];
			Contact_number[Each_Count]=Contact_all_Data[i++];
			Contact_email[Each_Count]=Contact_all_Data[i++];
			Contact_address[Each_Count]=Contact_all_Data[i];
			Each_Count++;
			
		}
		bool filter;
		for(int i=0;i<Each_Count;i++)
		{
			 filter=false;
			demo="";
			for(int k=0;k<Contact_name[i].size();k++)
			{
				if(filter){demo+=Contact_name[i][k];}
				if(Contact_name[i][k]==':')
				{
					filter=true;
				}
			}
			Contact_name[i]=demo;
			demo="";
			filter=false;
			for(int k=0;k<Contact_number[i].size();k++)
			{
				if(filter){demo+=Contact_number[i][k];}
				if(Contact_number[i][k]==':')
				{
					filter=true;
				}
			}
			Contact_number[i]=demo;
			demo="";
			filter=false;
			for(int k=0;k<Contact_email[i].size();k++)
			{
				if(filter){demo+=Contact_email[i][k];}
				if(Contact_email[i][k]==':')
				{
					filter=true;
				}
			}
			Contact_email[i]=demo;
			demo="";
			filter=false;
			for(int k=0;k<Contact_address[i].size();k++)
			{
				if(filter){demo+=Contact_address[i][k];}
				if(Contact_address[i][k]==':')
				{
					filter=true;
				}
			}
			Contact_address[i]=demo;
			
		}
		
		
		
		
		
		
	}
	
	void Add_Contact(){
		
		string name;
		string number;
		string email;
		string Address;
		
		
		ofstream contact("Contact.txt",ios::app);
		
		cout<<"Enter the name of Contact = ";
		getline(cin,name);
		getline(cin,name);
		
		
		repeat:
		cout<<"Enter the Number of the Contact = ";
		//cin.ignore();
		cin>>number;
		try{
		if(number.size()!=10){throw("The phone Number length should be 10 digit!!\n");}
		}catch(char const* c){cout<<c;goto repeat;}
		
		
		cout<<"Enter the email of the Contact ="<<endl;
		bool check=false;
		repeat1:
		cin.ignore();
		cin>>email;
		try{
		for(int i=0;i<email.size();i++){
			
			if(email[i]=='@'){ check=true;}
		}
	
		if(!check){throw("Invalid Email \n\ntry Again");}
		}
		catch(char const* c){cout<<c;goto repeat1;}
		
		
		
		cout<<"Enter the Address of the Contact ="<<endl;
		cin.ignore();
		getline(cin,Address);
		
		
		contact<<endl;
		contact<<setw(10)<<"Name:"<<name<<endl;
		contact<<setw(10)<<"Number:"<<number<<endl;
		contact<<setw(10)<<"Email:"<<email<<endl;
		contact<<setw(10)<<"Address:"<<Address<<endl;
		
		 controller();
		}
	void show_Contact()
	{
		Get_Contact();
		
		cout<<"Name List :\n";
		for(int i=0;i<Each_Count;i++)
		{
		
			cout<<i+1<<"."<<Contact_name[i]<<"\n"<<endl;
			
			}
		
	}
	void search_Contact()
	{
		show_Contact();
		cout<<"Type the index of Name to view Details=";
		cin.ignore();
		int select;cin>>select;
		for(int i=0;i<Each_Count;i++)
		{
			//if(Contact_name[i]==select||Contact_number[i]==select){
				if(i==select-1){
				cout<<Contact_name[i]<<"\n"<<endl;
				cout<<Contact_number[i]<<"\n"<<endl;
				cout<<Contact_email[i]<<"\n"<<endl;
				cout<<Contact_address[i]<<"\n"<<endl;
			}
		}
			 controller();
	}
	void DELETE_Contact(){
		show_Contact();
		ofstream contact("Contact.txt");
		cout<<"Type the index of Name to Delete=";
		int select;cin>>select;--select;
	
	//	for(int i=0;i<allData_Count-2;i++)
	//{
	//		if(i==(select)*5){i+=5;}
	//		contact<<Contact_all_Data[i]<<endl;
	//	}
		for(int i=0;i<Each_Count;i++)
		{
			if(i==select){i++;}
			contact<<endl;
			contact<<setw(10)<<"Name:"<<Contact_name[i]<<endl;
			contact<<setw(10)<<"Number:"<<Contact_number[i]<<endl;
			contact<<setw(10)<<"Email:"<<Contact_email[i]<<endl;
			contact<<setw(10)<<"Address:"<<Contact_address[i]<<endl;
			
		
		}
		cout<<"The contact Number Deleted!!!!!!!!!!!!!!!!\n";
			 controller();
	}
	void UPDATE_Contact(){
		show_Contact();
		ofstream contact("Contact.txt");
		cout<<"Type the index of Name to Update =";
		int select;cin>>select;--select;
		//---------------------------
		string name="";
		string number="";
		string email="";
		string Address="";
		
		
	for(int i=0;i<allData_Count;i++)
		{
			if(i==select){
			cout<<setw(20)<<"Name: "<<Contact_name[i]<<endl;
			cout<<setw(20)<<"Number: "<<Contact_number[i]<<endl;
			cout<<setw(20)<<"Email: "<<Contact_email[i]<<endl;
			cout<<setw(20)<<"Address: "<<Contact_address[i]<<endl;
			}
			
		}
		
		cout<<"update the name of Contact = ";
		getline(cin,name);
		getline(cin,name);
	
		
		repeat:
		cout<<"update the Number of the Contact = ";
		
		cin>>number;
	
		try{
			if(number!="null"){
			if(number.size()!=10){throw("The phone Number length should be 10 digit!!\n");}}
		}catch(char const* c){cout<<c;goto repeat;}
		
		
		cout<<"update the email of the Contact"<<endl;
		bool check=false;
		repeat1:
		cin.ignore();
		cin>>email;
		try{
		for(int i=0;i<email.size();i++){
			
			if(email[i]=='@'||email==""){ check=true;}
		}
	
		if(number!="null"){
		if(!check){throw("Invalid Email \n\ntry Again");}}
		}
		catch(char const* c){cout<<c;goto repeat1;}
		
		
		
		cout<<"update the Address of the Contact"<<endl;
		cin.ignore();
		getline(cin,Address);
		
		
		
		//------------------------------
		for(int i=0;i<allData_Count;i++)
		{
			if(i==select){
				if(name!="null")
				Contact_name[i]=name;
			if(number!="null")
				Contact_number[i]=number;
			if(email!="null")
				Contact_email[i]=email;
			if(Address!="null")
				Contact_address[i]=Address;
		
				
			}
			
		}
		for(int i=0;i<Each_Count;i++)
		{
			contact<<endl;
			contact<<setw(10)<<"Name:"<<Contact_name[i]<<endl;
			contact<<setw(10)<<"Number:"<<Contact_number[i]<<endl;
			contact<<setw(10)<<"Email:"<<Contact_email[i]<<endl;
			contact<<setw(10)<<"Address:"<<Contact_address[i]<<endl;
			
		
		}
		
			 controller();
	}
	
	
	
	
	
};





