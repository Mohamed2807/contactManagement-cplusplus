#include"Contact.cpp"

class time_Manage{
	
	public:
	time_Manage()
	{
		
	}
int getYear(){
	 time_t now = time(0); 
	 tm* ltm = localtime(&now); 
	int year;
	stringstream ss;
	ss<<ltm->tm_year ;
	ss>>year;
	return year+1900;
}
	int getMonth(){
		 time_t now = time(0); 
	 tm* ltm = localtime(&now); 
		int Month;
	stringstream ss;
	ss<<ltm->tm_mon  ;
	ss>>Month;
	return Month;
	}
	int getDay(){
		 time_t now = time(0); 
	 tm* ltm = localtime(&now); 
		
		int Day;
	stringstream ss;
	ss<<ltm->tm_mday   ;
	ss>>Day;
	return Day;
	}
	
int getMinutes()
{
	 time_t now = time(0); 
	 tm* ltm = localtime(&now); 
	 int minutes;
	 
	stringstream ss;
	ss<<ltm->tm_min;
	ss>>minutes;	

return minutes;
}

int getSeconds()
{
	 time_t now = time(0); 
	 tm* ltm = localtime(&now); 
	int seconds;
		
	stringstream ss;
	ss<<ltm->tm_sec ;   ;
	ss>>seconds;
	return seconds;
}
};

class Call{
	int duration;
	Contact c;
	time_Manage timee;
	public:
	string callHistoryData[100];
		string callHistory[100];
		int callhistoryCount=0;
	Call()
	{
		c.Get_Contact();
	}
	
	void record(int initial_minutes,int end_minutes,int initial_seconds,int end_seconds,string name)
	{
		int minutes;
		if(end_minutes>initial_minutes)
		 minutes=end_minutes-initial_minutes;
	else
		 minutes=initial_minutes-end_minutes;
		int seconds;
		if(end_seconds>initial_seconds)
		seconds=end_seconds-initial_seconds;
	else
		seconds=initial_seconds-end_seconds;
		int day,month,year;
		day=timee.getDay();
		month=timee.getMonth();
		year=timee.getYear();
		ofstream Call_Log("C:/Users/Administrator/Desktop/C++/Application/Show/CallLog.txt",ios::app);
		Call_Log<<endl;
		Call_Log<<setw(15)<<"Name:"<<name<<endl;
		Call_Log<<setw(15)<<"Call :"<<"Out Going"<<endl;
        Call_Log<<setw(15)<<"Date :"<<day<<"/"<<month<<"/"<<year<<endl;
		Call_Log<<setw(15)<<"Duration  :"<<minutes<<":"<<seconds<<endl;
		
		Call_Log.close();

	}
	void start()
	{
		int initial_minutes;
		int initial_seconds;
		int end_minutes;
		int end_seconds;
		
		bool check=true;
		string Numbers;
		string copy;
		cout<<"Enter the Phone Numbers";
		cin>>Numbers;
		for(int i=0;i<c.Each_Count;i++)
		{
			if(Numbers==c.Contact_number[i])
			{check=false;
				system("cls");
				copy=c.Contact_name[i];
				cout<<"Calling to\t"<<c.Contact_name[i]<<".....";
			}
			
			
			
		}
		
		if(check){system("cls");
		cout<<"Calling to\t"<<Numbers<<".....";copy=Numbers;}
		
		cout<<"\n\n\n\n\n Speaking to "<<copy;
		initial_minutes=timee.getMinutes();
		initial_seconds=timee.getSeconds();
		
		cout<<"\nStarted time is "<<initial_minutes<<":"<<initial_seconds;
		
		cout<<"\nPress any key to end the conversation";
		char c;cin>>c;
		end_minutes=timee.getMinutes();
		end_seconds=timee.getSeconds();
		cout<<"\nEnd time is "<<end_minutes<<":"<<end_seconds;
		
		record(initial_minutes,end_minutes,initial_seconds,end_seconds,copy);
		controller();
		
	}
	
	void viewCallLog()
	{
		string getData;
	    ifstream callLog("C:/Users/Administrator/Desktop/C++/Application/Show/CallLog.txt");
		while(getline(callLog,callHistory[callhistoryCount]))
		{
			
			callhistoryCount++;
		}
		
		for(int i=0;i<callhistoryCount;i++)
		{     getData="";
			for(int k=0;k<callHistory[i].size();k++)
			{
				if(callHistory[i][k]==':')
				{
					for(int j=k+1;j<callHistory[i].size();j++){
					getData+=callHistory[i][j];
					}
					callHistoryData[i]=getData;
				}
			}
			
		}
		for(int i=0;i<callhistoryCount;i++)
		{
			cout<<callHistory[i]<<endl;
		}
		
		
		
		
		
	}
	
	void searchCallLog()
	{
		viewCallLog();
		cout<<"\n\nEnter 1 for search\n\nEnter 2 for exit Call Log ";
		cout<<"Enter the Number =";
		int get;cin>>get;
		if(get==1){
			cout<<"\n Enter the Name of the Contact";
			string name;cin>>name;
			
			for(int i=0;i<callhistoryCount;i++)
			{
				if(callHistoryData[i]==name)
				{
					for(int j=i+1;j<i+4;j++)
					{
						cout<<callHistory[j]<<endl;
					}
					cout<<endl;
				}
			}
		
		}else{cout<<"You exited Call log";}
		controller();
	}
	
	
	
};

void controller()
{
	Contact contact;
	Call call;
	int get;
	repeat:
	cout<<"\n\t\t--------------------\n";
	cout<<"\t\tContact Management\n";
	cout<<"\t\t--------------------\n";
	
	cout<<"Choose the options!!!!!\n";
	cout<<"\n\n 1.Call \n2.Search Contact\n3.delete Contact\n4.update Contact\n5.Add Contact\n6.Call log\n7.Exit";
	cout<<"\nEnter the Number =";
	cin>>get;
	switch(get)
	{
		case 1:call.start();break;
		case 2:contact.search_Contact();break;
		case 3:contact.DELETE_Contact();break;
		case 4:contact.UPDATE_Contact();break;
		case 5:contact.Add_Contact();break;
		case 6:call.searchCallLog();break;
		case 7:cout<<"Contact Exited";break;
	
	}
	
	

	
}




						