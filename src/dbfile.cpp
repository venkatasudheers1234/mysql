#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;
struct student
{
    char name[20],id[20];
    char dob[20],address[30],phone[20];
    char course[20],mail[20],branch[20];
}st;

void insertion();
void deletion();
void update();
void display();


void insertion()
{
    char ch1;
    fstream tfile("student.dat",ios::in|ios::out|ios::binary);
    tfile.seekp(0,ios::end); //seek put sets position in output stream
    do{
        cout<<"\n student"<<":\n id:";
        cin>>st.id;
        cout<<"name:";
        cin>>st.name;
        cout<<"D.O.B:";
        cin>>st.dob;
        cout<<"mail:";
        cin>>st.mail;
        cout<<"address:";
        cin>>st.address;
        cout<<"Phone no.";
        cin>>st.phone;
        cout<<"Course:";
        cin>>st.course;
        cout<<"Branch:";
        cin>>st.branch;
        tfile.write((char*)&st,(sizeof(st)));
        cout<<"countinue....(y/n):";
        cin>>ch1;
    }while(ch1=='y'||ch1=='Y');
    tfile.close();
}


void search()
{
   char n1[20],n2[20];int f=0,ch;
   fstream file("student.dat",ios::in|ios::binary);
   cout<<"\n1.search by ID\n"<<"\n2.search by name"<<"enter your choice";
   cin>>ch; 
   switch(ch)
   {
       case 1:
       cout<<"\n Enter Id:";
       cin>>n1;
       while(file.read((char*)&st,sizeof(st)))
       {
           if((strcmp(st.id,n1))==0)
           {
               cout<<"\n student"<<"\nid:"<<st.id;
               cout<<"\nName:"<<(st.name)<<endl;
             cout<<"\nD.O.B:"<<(st.dob)<<endl;
            cout<<"\nmail:"<<(st.mail)<<endl;
               cout<<"\naddress:"<<(st.address)<<endl;
               cout<<"\nphone:"<<(st.phone)<<endl;
               cout<<"\ncourse:"<<(st.course)<<endl;
               cout<<"\nbranch:"<<(st.branch)<<endl;
      cout<<"\n..........."; 
      f=1;
           }
       }
       if(f==0){
           cout<<"\n **Record doesnot exit.**\n\n";
       }
       break;


       case 2:       cout<<"\n Enter name:";
                     cin>>n2;
                    while(file.read((char*)&st,sizeof(st)))
                    {
                   if(((strcmp(st.name,n2))==0))
                    {
               cout<<"\n student"<<"\nid:"<<st.id;
               cout<<"\nName:"<<(st.name)<<endl;
             cout<<"\nD.O.B:"<<(st.dob)<<endl;
            cout<<"\nmail:"<<(st.mail)<<endl;
               cout<<"\naddress:"<<(st.address)<<endl;
               cout<<"\nphone:"<<(st.phone)<<endl;
               cout<<"\ncourse:"<<(st.course)<<endl;
               cout<<"\nbranch:"<<(st.branch)<<endl;
      cout<<"\n..........."; 
      f=1;
   }
}
 if(f==0){
     cout<<"\n **Record doesnot exit.**\n\n";
 }
 break;
   }
}



void deletion()
{
    int f=1; char n1[20];
    cout<<"\nEnter id:";
    cin>>n1;
    fstream file("student.dat",ios::in|ios::binary);
    fstream tfile;
    tfile.open("temp.dat",ios::out|ios::binary);
    while(file.read((char*)&st,(sizeof(st))))
    {
     if(strcmp(st.id,n1)==0)
     {
         f=0;
     }else
     {
         tfile.write((char*)&st,sizeof(st));
     }
    }
     file.close();
     tfile.close();
     if(f==1)
     {
         cout<<"**RECORD DOESNOT EXIT..\n";
     }else{
         cout<<"**RECORD deleted successufully**\n";
     }
     remove("student.dat");
     rename("temp.dat","student.dat");
}

void update()
{
    int f=1,ch;  char n1[20],n[20];
    fstream file("student.dat",ios::in|ios::binary);
    fstream tfile;
    tfile.open("temp.dat",ios::out|ios::binary);
    cout<<"enter the student id whose data to be modified/updated:\n";
    cin>>n1;
    while(file.read((char*)&st,sizeof(st)))
    {
        if(strcmp(st.id,n1) == 0)
        {
            cout<<"\n MODIFY:"<<"\n 1:Name"<<"\n 2:Email id"<<"\n 3:address"<<"\n 4:phone no."<<"\n 5:DOB"<<"\n 6:course"<<"\n 7:branch"<<"\n enter your choice to update:";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"\nenter name:";
                       scanf("%s",n1);
                       strcpy(st.name,n1);
                       break;
                case 2:cout<<"\nenter email:";
                       scanf("%s",n);
                       strcpy(st.mail,n);
                       break;
                 case 3:cout<<"\nenter address:";
                        scanf("%s",n);
                        strcpy(st.address,n);
                        break;   
                 case 4:cout<<"\nenter phone no.:";
                        scanf("%s",n);
                         strcpy(st.phone,n);
                         break;
                 case 5:cout<<"\nenter DOB:";
                         scanf("%s",n);
                         strcpy(st.dob,n);  
                         break;  
                case 6:cout<<"\nenter course:";
                         scanf("%s",n);
                         strcpy(st.course,n);  
                         break;  
                case 7:cout<<"\nenter branch:";
                       scanf("%s",n);
                       strcpy(st.branch,n);  
                       break;          

                             }
                             f=0;
                             tfile.write((char*)&st,sizeof(st));
        }
        else 
        {
             tfile.write((char*)&st,sizeof(st));
        }
    }
    file.close();
    tfile.close();
    if(f==1)
    {
        cout<<"\n RECORD DOESNOT EXIST**\n\n";
    }
    else {
        cout<<"\n Record is modified/updated successfully**\n";
    }
    remove("student.dat");
    rename("temp.dat","student.dat");
}


void display()
{
     fstream file("student.dat",ios::in|ios::binary);
   while(file.read((char*)&st,sizeof(st)))
    {
  cout<<"\n student"<<":\n id:"<<st.id<<endl;
  cout<<"name:"<<st.name<<endl;
  cout<<"D.O.B"<<st.dob<<endl;
  cout<<"mail:"<<st.mail<<endl;
  cout<<"address:"<<st.address<<endl;
  cout<<"Phone no."<<st.phone<<endl;
  cout<<"Course:"<<st.course<<endl;
  cout<<"Branch:"<<st.branch<<endl;
  cout<<"**..................***"<<endl;
    }
}



int main()
{
    cout<<"STUDENT RECORDS\n";
    for(;;)
    {  int ch;
    cout<<"enter choice 1:insertion 2:search 3:deletion 4:update 5:display 6:exit"<<endl;
    cin>>ch;
        switch(ch)
        {
      case 1:insertion();break;
      case 2:search();break;
      case 3:deletion();break;
      case 4:update();break;
      case 5:display();break;
      case 6:cout<<"thank u";exit(0);
        }
    }
    return 0;
}











