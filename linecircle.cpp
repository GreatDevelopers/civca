#include<iostream>
#include<fstream>
#include<string>
using namespace std;
float p1,p2,p3,p4;
int p5,p6,p7;
int newline()
{
	ofstream li("line.txt");
	if(li.is_open())
	{
		li<<"LINE\n 5\n43\n100\nAcDbEntity\n100\nAcDbLine\n 8\n"<<p5<<"\n 62\n"<<p6<<"\n256\n370\n-1\n  6\nByLayer\n 10\n"<<p1<<"\n20\n"<<p2<<"\n30\n0.0\n11\n"<<p3<<"\n21\n"<<p4<<"\n31\n0.0\n0";
	li.close();
	}
	return 0;
}
int newcircle()
{
	ofstream cir("cir.txt");
	if(cir.is_open())
	{
		cir<<"CIRCLE\n 5\n43\n100\nAcDbEntity\n100\nAcDbCircle\n 8\n0\n 62\n256\n370\n-1\n  6\nByLayer\n 10\n"<<p2<<"\n 20\n"<<p3<<"\n 30\n0.0\n 40\n"<<p1<<"\n  0";
		cir.close();
	}
return 0;
}
int main()
{
	cout<<"\n\t\t\t****    Draw	****\n\tPress 1 for Line\n\tPress 2 for circle\n\tEnter your choice: ";
	cin>>p7;
	if(p7==1)
	{
		cout<<"\nEnter one point(x,y): ";
		cin>>p1>>p2;
		cout<<"\nEnter second point: ";
		cin>>p3>>p4;
		cout<<"\nChoose style\nPress 0 for dot\nPress 5 for dashed ";
		cin>>p5;
		cout<<"\nChoose color of a line\nPress 1 for red\nPress 2 for yellow\n Press 3 for green ";
		cin>>p6; 
		newline();
	}
	else if(p7==2)
	{
		cout<<"\nEnter the radius of circle: ";
		cin>>p1;
		cout<<"Enter the centre coordinates: ";
		cin>>p2>>p2;
		newcircle();
	}
	else
	{
		cout<<"\n You entered wrong choice";
	}
	if(p7==1||p7==2)
	{	
		string line,line1,line2;
		ifstream head("header.txt");
		ifstream foot("footer.txt");
		ifstream lin("line.txt");
		ifstream circ("cir.txt");
		ofstream myfile("linecircle.dxf");
		while(getline(head,line,'\n'))
		{
			myfile<<line<<endl;
		}
		if(p7==1)
		{
			while(getline(lin,line1,'\n'))
			{
				myfile<<line1<<endl;
			}
		}
		else if(p7==2)
		{
			while(getline(circ,line1,'\n'))
			{
				myfile<<line1<<endl;
			}
		}
		else
			cout<<"\n Not write\n ";
		while(getline(foot,line2,'\n'))
		{
			myfile<<line2<<endl;
		}
		head.close();
		lin.close();
		circ.close();
		foot.close();
		myfile.close();
	}
	else
		cout<<"\nNothing draw\n";
return 0;
}
