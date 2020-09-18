#include<iostream> 
#include<fstream> 
#include<string> 
#include<sstream> 
#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h>
using namespace std; 
class student 
{  
	public:   
		string usn;   
		string name;   
		string branch;   
		string sem;   
		string buffer;   
		void er(){buffer.erase();}   
		void read_data_student();   
		void pack_student();   
		void write_to_file_student();   
		void unpack_student();   
		int search_student(string);   
		int delete_from_file_student(string);   
		void modify_student(string);
		int main_student();  
}; 
void student::read_data_student() 
{         
	cout<<"usn:";         
	cin>>usn;         
	cout<<"name:";         
	cin>>name;         
	cout<<"branch:";         
	cin>>branch;         
	cout<<"semester:";         
	cin>>sem; 
} 
void student::pack_student() 
{  
	buffer.erase();  
	buffer+=usn+"|"+name+"|"+branch+"|"+sem+"$"+"\n"; 
} 
void student::write_to_file_student() 
{  
	fstream file;  
	file.open("univ.txt",ios::out|ios::app);  
	file<<buffer;  file.close(); 
} 
void student:: unpack_student() 
{  
	int ch=1,i=0;
	usn.erase();  
	while(buffer[i]!='|')  
	usn+=buffer[i++];  
	name.erase();  
	i++;  
	while(buffer[i]!='|')  
	name+=buffer[i++];  
	branch.erase();  
	i++;  
	while(buffer[i]!='|')  
	branch+=buffer[i++];  
	sem.erase();  
	i++;  
	while(buffer[i]!='$')  
	sem+=buffer[i++]; 
} 
int student::search_student(string key) 
{  
	ifstream file;  
	int flag=0,pos=0;  
	file.open("univ.txt",ios::in);  
	while(!file.eof())  
	{   
		buffer.erase();   
		pos=file.tellg();   
		getline(file,buffer);   
		unpack_student();   
		if(key==usn)   
		{    
			cout<<"\nfound the key .the record is...\n"<<buffer;    
			return pos;   
		}  
	}  
	file.close();  
	if(flag==0)  
	{   
		cout<<"\nnot found..\n";   
		return -1; 
	}
} 
int student::delete_from_file_student(string key) 
{  
	fstream file;
	int pos, flag=0;  
	pos=search_student(key);  
	if(pos>=0)  
	{   
		file.open("univ.txt");   
		file.seekp(pos,ios::beg);   
		file.put('*');   
		flag=1;   
		file.close();
	}
	if(flag==1) 
	return 1;  
	else   
	return 0; 
}
void student::modify_student(string key) 
{  
	int c;  
	if(delete_from_file_student(key))  
	{   
		cout<<"\nwhat to modify\n1:usn  2:name  3:branch  4:semester\n";   
		cin>>c;   
		switch(c)   
		{    
			case 1:cout<<"usn:\n";     
			cin>>usn;     
			break;    
			case 2:cout<<"name:\n";     
			cin>>name;     
			break;    
			case 3:cout<<"branch:\n";     
			cin>>branch;     
			break;    
			case 4:cout<<"semester:\n";     
			cin>>sem;     
			break; default:cout<<"wrong choice\n";   
		}   
		buffer.erase();   
		pack_student();  
		write_to_file_student();  
	} 
} 
int student::main_student() 
{  
	int count,choice,i;    
	string key;              
	while(1)          
	{   
		cout<<"\nmain menu\n1.add\n2.delete\n3.modify\n4.search\n5.exit\nEnter your choice:  ";   
		cin>>choice;
		cout<<choice;   
		switch(choice)   
		{    
			case 1:
			cout<<"\nhow many records to insert\n";         
			cin>>count;     
			er();     
			for(i=0;i<count;i++)     
			{      
				cout<<"data\n"<<i+1;      
				read_data_student();      
				pack_student();      
				write_to_file_student();     
			}     
			break;
			case 2: 
			cout<<"\nenter the key...\n";
			cin>>key;     
			i=delete_from_file_student(key);
			if(i==1)      
				cout<<"record deleted\n";                            
			else       
				cout<<"record not deleted\n";                            
			break;          
			case 3:
			cout<<"enter the key\n";     
			cin>>key;     
			modify_student(key);     
			break;    
			case 4:cout<<"enter the key\n";     
			cin>>key;     
			i=search_student(key);     
			break;    
			case 5:break;    
			default:cout<<"wrong choice....";   
		}         
	} 
return 0; 
}

class faculty 
{  
	public:   
		string faculty_id;   
		string name_faculty;   
		string branch_faculty;      
		string buffer;   
		void er(){buffer.erase();}   
		void read_data_faculty();   
		void pack_faculty();   
		void write_to_file_faculty();   
		void unpack_faculty();   
		int search_faculty(string);   
		int delete_from_file_faculty(string);   
		void modify_faculty(string); 
		int main_faculty();
}; 
void faculty::read_data_faculty() 
{         
	cout<<"faculty_id:";         
	cin>>faculty_id;         
	cout<<"name:";         
	cin>>name_faculty;         
	cout<<"branch:";         
	cin>>branch_faculty;          
} 
void faculty::pack_faculty() 
{  
	buffer.erase();  
	buffer+=faculty_id+"|"+name_faculty+"|"+branch_faculty+"$"+"\n"; 
} 
void faculty::write_to_file_faculty() 
{  
	fstream file;  
	file.open("univ.txt",ios::out|ios::app);  
	file<<buffer;  file.close(); 
} 
void faculty:: unpack_faculty() 
{  
	int ch=1,i=0;
	faculty_id.erase();  
	while(buffer[i]!='|')  
	faculty_id+=buffer[i++];  
	name_faculty.erase();  
	i++;  
	while(buffer[i]!='|')  
	name_faculty+=buffer[i++];  
	branch_faculty.erase();  
	i++;  
	while(buffer[i]!='|')  
	branch_faculty+=buffer[i++];   
} 
int faculty::search_faculty(string key) 
{  
	ifstream file;  
	int flag=0,pos=0;  
	file.open("univ.txt",ios::in);  
	while(!file.eof())  
	{   
		buffer.erase();   
		pos=file.tellg();   
		getline(file,buffer);   
		unpack_faculty();   
		if(key==faculty_id)   
		{    
			cout<<"\nfound the key .the record is...\n"<<buffer;    
			return pos;   
		}  
	}  
	file.close();  
	if(flag==0)  
	{   
		cout<<"\nnot found..\n";   
		return -1; 
	}
} 
int faculty::delete_from_file_faculty(string key) 
{  
	fstream file;
	int pos, flag=0;  
	pos=search_faculty(key);  
	if(pos>=0)  
	{   
		file.open("univ.txt");   
		file.seekp(pos,ios::beg);   
		file.put('*');   
		flag=1;   
		file.close();
	}
	if(flag==1) 
	return 1;  
	else   
	return 0; 
}
void faculty::modify_faculty(string key) 
{  
	int c;  
	if(delete_from_file_faculty(key))  
	{   
		cout<<"\nwhat to modify\n1:faculty_id  2:name  3:branch  4:semester\n";   
		cin>>c;   
		switch(c)   
		{    
			case 1:cout<<"faculty_id:\n";     
			cin>>faculty_id;     
			break;    
			case 2:cout<<"name:\n";     
			cin>>name_faculty;     
			break;    
			case 3:cout<<"branch:\n";     
			cin>>branch_faculty;         
			break; 
			default:cout<<"wrong choice\n";   
		}   
		buffer.erase();   
		pack_faculty();  
		write_to_file_faculty();  
	} 
} 
int faculty::main_faculty() 
{  
	int count,choice,i;    
	string key;  
	system("clear");             
	while(1)          
	{   
		cout<<"\nmain menu\n1.add\n2.delete\n3.modify\n4.search\n5.exit ";   
		cin>>choice;   
		switch(choice)   
		{    
			case 1:
			cout<<"\nhow many records to insert\n";         
			cin>>count;     
			er();     
			for(i=0;i<count;i++)     
			{      
				cout<<"data\n"<<count+1;      
				read_data_faculty();      
				pack_faculty();      
				write_to_file_faculty();     
			}     
			break;
			case 2: 
			cout<<"\nenter the key...\n";
			cin>>key;     
			i=delete_from_file_faculty(key);
			if(i==1)      
					cout<<"record deleted\n";                            
			else       
				cout<<"record not deleted\n";                            
			break;          
			case 3:
			cout<<"enter the key\n";     
			cin>>key;     
			modify_faculty(key);     
			break;    
			case 4:cout<<"enter the key\n";     
			cin>>key;     
			i=search_faculty(key);     
			break;    
			case 5:return 0;    
			default:cout<<"wrong choice....";   
		}         
	} 
return 0; 
}

class college 
{  
	public:   
		string college_id;   
		string college_name;   
		string place;      
		string buffer;   
		void er(){buffer.erase();}   
		void read_data_college();   
		void pack_college();   
		void write_to_file_college();   
		void unpack_college();   
		int search_college(string);   
		int delete_from_file_college(string);   
		void modify_college(string);
		int main_college();  
}; 
void college::read_data_college() 
{         
	cout<<"college_id:";         
	cin>>college_id;         
	cout<<"college_name:";         
	cin>>college_name;         
	cout<<"place:";         
	cin>>place;          
} 
void college::pack_college() 
{  
	buffer.erase();  
	buffer+=college_id+"|"+college_name+"|"+place+"$"+"\n"; 
} 
void college::write_to_file_college() 
{  
	fstream file;  
	file.open("univ.txt",ios::out|ios::app);  
	file<<buffer;  file.close(); 
} 
void college:: unpack_college() 
{  
	int ch=1,i=0;
	college_id.erase();  
	while(buffer[i]!='|')  
	college_id+=buffer[i++];  
	college_name.erase();  
	i++;  
	while(buffer[i]!='|')  
	college_name+=buffer[i++];  
	place.erase();  
	i++;  
	while(buffer[i]!='|')  
	place+=buffer[i++];  
	i++;  
} 
int college::search_college(string key) 
{  
	ifstream file;  
	int flag=0,pos=0;  
	file.open("univ.txt",ios::in);  
	while(!file.eof())  
	{   
		buffer.erase();   
		pos=file.tellg();   
		getline(file,buffer);   
		unpack_college();   
		if(key==college_id)   
		{    
			cout<<"\nfound the key .the record is...\n"<<buffer;    
			return pos;   
		}  
	}  
	file.close();  
	if(flag==0)  
	{   
		cout<<"\nnot found..\n";   
		return -1; 
	}
} 
int college::delete_from_file_college(string key) 
{  
	fstream file;
	int pos, flag=0;  
	pos=search_college(key);  
	if(pos>=0)  
	{   
		file.open("univ.txt");   
		file.seekp(pos,ios::beg);   
		file.put('*');   
		flag=1;   
		file.close();
	}
	if(flag==1) 
	return 1;  
	else   
	return 0; 
}
void college::modify_college(string key) 
{  
	int c;  
	if(delete_from_file_college(key))  
	{   
		cout<<"\nwhat to modify\n1:college_id  2:college_name  3:place \n";   
		cin>>c;   
		switch(c)   
		{    
			case 1:cout<<"college_id:\n";     
			cin>>college_id;     
			break;    
			case 2:cout<<"college_name:\n";     
			cin>>college_name;     
			break;    
			case 3:cout<<"place:\n";     
			cin>>place;          
			break; default:cout<<"wrong choice\n";   
		}   
		buffer.erase();   
		pack_college();  
		write_to_file_college();  
	} 
} 
int college::main_college() 
{  
	int count,choice,i;    
	string key;              
	while(1)          
	{   
		cout<<"\nmain menu\n1.add\n2.delete\n3.modify\n4.search\n5.exit ";   
		cin>>choice;   
		switch(choice)   
		{    
			case 1:
			cout<<"\nhow many records to insert\n";         
			cin>>count;     
			er();     
			for(i=0;i<count;i++)     
			{      
				cout<<"data\n"<<count+1;      
				read_data_college();      
				pack_college();      
				write_to_file_college();     
			}     
			break;
			case 2: 
			cout<<"\nenter the key...\n";
			cin>>key;     
			i=delete_from_file_college(key);
			if(i==1)      
				cout<<"record deleted\n";                            
			else       
				cout<<"record not deleted\n";                            
			break;          
			case 3:
			cout<<"enter the key\n";     
			cin>>key;     
			modify_college(key);     
			break;    
			case 4:cout<<"enter the key\n";     
			cin>>key;     
			i=search_college(key);     
			break;    
			case 5:break;    
			default:cout<<"wrong choice....";   
		}         
	} 
return 0; 
}

class course 
{  
	public:   
		string course_code;   
		string course_duration;   
		string course_name;      
		string buffer;   
		void er(){buffer.erase();}   
		void read_data_course();   
		void pack_course();   
		void write_to_file_course();   
		void unpack_course();   
		int search_course(string);   
		int delete_from_file_course(string);   
		void modify_course(string);
		int main_course();  
}; 
void course::read_data_course() 
{         
	cout<<"course_code:";         
	cin>>course_code;         
	cout<<"course_duration:";         
	cin>>course_duration;         
	cout<<"course_name:";         
	cin>>course_name;         
} 
void course::pack_course() 
{  
	buffer.erase();  
	buffer+=course_code+"|"+course_duration+"|"+course_name+"$"+"\n"; 
} 
void course::write_to_file_course() 
{  
	fstream file;  
	file.open("univ.txt",ios::out|ios::app);  
	file<<buffer;  file.close(); 
} 
void course:: unpack_course() 
{  
	int ch=1,i=0;
	course_code.erase();  
	while(buffer[i]!='|')  
	course_code+=buffer[i++];  
	course_duration.erase();  
	i++;  
	while(buffer[i]!='|')  
	course_duration+=buffer[i++];  
	course_name.erase();  
	i++;  
	while(buffer[i]!='|')  
	course_name+=buffer[i++];   
} 
int course::search_course(string key) 
{  
	ifstream file;  
	int flag=0,pos=0;  
	file.open("univ.txt",ios::in);  
	while(!file.eof())  
	{   
		buffer.erase();   
		pos=file.tellg();   
		getline(file,buffer);   
		unpack_course();   
		if(key==course_code)   
		{    
			cout<<"\nfound the key .the record is...\n"<<buffer;    
			return pos;   
		}  
	}  
	file.close();  
	if(flag==0)  
	{   
		cout<<"\nnot found..\n";   
		return -1; 
	}
} 
int course::delete_from_file_course(string key) 
{  
	fstream file;
	int pos, flag=0;  
	pos=search_course(key);  
	if(pos>=0)  
	{   
		file.open("univ.txt");   
		file.seekp(pos,ios::beg);   
		file.put('*');   
		flag=1;   
		file.close();
	}
	if(flag==1) 
	return 1;  
	else   
	return 0; 
}
void course::modify_course(string key) 
{  
	int c;  
	if(delete_from_file_course(key))  
	{   
		cout<<"\nwhat to modify\n1:course_code  2:course_duration  3:course_name\n";   
		cin>>c;   
		switch(c)   
		{    
			case 1:cout<<"course_code:\n";     
			cin>>course_code;     
			break;    
			case 2:cout<<"course_duration:\n";     
			cin>>course_duration;     
			break;    
			case 3:cout<<"course_name:\n";     
			cin>>course_name;     
			break; default:cout<<"wrong choice\n";   
		}   
		buffer.erase();   
		pack_course();  
		write_to_file_course();  
	} 
} 
int course ::main_course() 
{  
	int count,choice,i;    
	string key;              
	while(1)          
	{   
		cout<<"\nmain menu\n1.add\n2.delete\n3.modify\n4.search\n5.exit\n ";   
		cin>>choice;   
		switch(choice)   
		{    
			case 1:
			cout<<"\nhow many records to insert\n";         
			cin>>count;     
			er();     
			for(i=0;i<count;i++)     
			{      
				cout<<"data\n"<<count+1;      
				read_data_course();      
				pack_course();      
				write_to_file_course();     
			}     
			break;
			case 2: 
			cout<<"\nenter the key...\n";
			cin>>key;     
			i=delete_from_file_course(key);
			if(i==1)      
				cout<<"record deleted\n";                            
			else       
				cout<<"record not deleted\n";                            
			break;          
			case 3:
			cout<<"enter the key\n";     
			cin>>key;     
			modify_course(key);     
			break;    
			case 4:cout<<"enter the key\n";     
			cin>>key;     
			i=search_course(key);     
			break;    
			case 5:break;    
			default:cout<<"wrong choice....";   
		}         
	} 
return 0; 
}
 main()
{
    string username="manju",pass="4CB17IS018";
	int feild;
	student s1;
	faculty f1; 
	college c1;
	course d1;
	cout<<"LOGIN PAGE\n";
	cout<<"Enter the username\n";
	cin>>username;
	cout<<"Enter the password\n";
	cin>>pass;
	if(pass!="4CB17IS018" || username!="manju")
	{
		cout<<"\nEntered username or password is wrong";
	exit(0);
 	}
	cout<<"*************************  UNIVERSITY MANAGEMENT SYSTEM  ************************\n";
	cout<<"1.student\n2.faculty\n3.college\n4.course\nEnter the field of interaction\nEnter your choice: ";
	cin>>feild;
	cout<<feild;
	switch(feild)
	{
		case 1:cout<<"student database\n";
			s1.main_student();
		break;
		case 2:cout<<"faculty database\n";
			f1.main_faculty();
		break;
		case 3:cout<<"college database\n";
		c1.main_college();
		case 4:cout<<"course database\n";
		d1.main_course();
		break;
		default:cout<<"error";
	}
}
