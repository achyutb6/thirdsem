
#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int roll_no;
    int usn;
    int marks1;
    int marks2;
    int marks3;
    float avg;
public:
    Student(string Sname,int Sroll_no,int Susn,int Smarks1,int Smarks2,int Smarks3,float Savg);
    Student(){}
    string getname();
    int getroll_no();
    int getusn();
    int getmarks1();
    int getmarks2();
    int getmarks3();
    float getavg();
    static void updateavgmarks(Student s[]);
    Student highavg(Student s[]);
    void Display_students(Student s[]);
    void Display_student(Student s);
};

Student::Student(string Sname,int Sroll_no,int Susn,int Smarks1,int Smarks2,int Smarks3,float Savg)
{
    name=Sname;roll_no=Sroll_no;usn=Susn;marks1=Smarks1;marks2=Smarks2;marks3=Smarks3;avg=Savg;
}
string Student::getname(){return name;}
int Student::getroll_no(){return roll_no;}
int Student::getusn(){return usn;}
int Student::getmarks1(){return marks1;}
int Student::getmarks2(){return marks2;}
int Student::getmarks3(){return marks3;}
float Student::getavg(){return avg;}
void Student::updateavgmarks(Student s[])
{
    for (int i=0;i<6;i++)
    {
        s[i].avg=((s[i].marks1+s[i].marks2+s[i].marks3)/3);
    }
}
Student Student::highavg(Student s[])
{
    float high=s[0].avg;
    int pos;
    for(int i=0;i<6;i++)
    {
        if(high<s[i].avg)
        {
			high=s[i].avg;
			pos=i;
		}
    }
    return s[pos];
}
void Student::Display_students(Student s[])
{
    for(int i=0;i<6;i++)
    {
        cout<<s[i].name<<":"<<s[i].roll_no<<":"<<s[i].usn<<":"<<s[i].marks1<<":"<<s[i].marks2<<":"<<s[i].marks3<<":"<<s[i].avg<<endl;
    }
}
/*void Student::Display_student(Student s[])
{int r;
    cout<<"Enter student roll number"<<endl;
    cin>>r;
    r=r-1;
        cout<<s[r].name<<":"<<s[r].roll_no<<":"<<s[r].usn<<":"<<s[r].marks1<<":"<<s[r].marks2<<":"<<s[r].marks3<<":"<<s[r].avg<<endl;
}*/
void Student::Display_student(Student s)
{
	cout<<s.name<<":"<<s.roll_no<<":"<<s.usn<<":"<<s.marks1<<":"<<s.marks2<<":"<<s.marks3<<":"<<s.avg<<endl;
}

int main()
{
    Student s1("Karthik.M",1,45,1,2,3,0);
    Student s2("Karthik.K",2,44,2,3,4,0);
    Student s3("Karthik.B",3,43,3,4,5,0);
    Student s4("Ashik",4,20,4,5,6,0);
    Student s5("Achyut",5,7,5,6,7,0);
    Student s6("Abhinav",6,4,6,7,8,0);
    Student s[6]={s1,s2,s3,s4,s5,s6};
    Student stud;
    stud.updateavgmarks(s);
    //float avg=stud.highavg(s);
    cout<<"Student with Highest average is :"<<endl;
    stud.Display_student(stud.highavg(s));
    cout<<"Deatils of all students"<<endl;
    stud.Display_students(s);
}
