#include<iostream>
#include<fstream>
#include<string>
using namespace std;

float point1,point2,point3,point4,radius; // variables for line
int style,color,choose;            // and circle
int newline()   // This function create and writes a line.txt file that draws line.
{
	ofstream li("line.txt");
	if(li.is_open())
	{
		li<<"LINE\n 5\n43\n100\nAcDbEntity\n100\nAcDbLine\n 8\n"<<style<<"\n 62\n"<<color<<"\n256\n370\n-1\n  6\nByLayer\n 10\n"<<point1<<"\n20\n"<<point2<<"\n30\n0.0\n11\n"<<point3<<"\n21\n"<<point4<<"\n31\n0.0\n0";
	li.close();
	}
	return 0;
}     // newline() closed
int newcircle()         //This function create and writes a cir.txt file that draws circle.
{
	ofstream cir("cir.txt");
	if(cir.is_open())
	{
		cir<<"CIRCLE\n 5\n43\n100\nAcDbEntity\n100\nAcDbCircle\n 8\n0\n 62\n256\n370\n-1\n  6\nByLayer\n 10\n"<<point1<<"\n 20\n"<<point2<<"\n 30\n0.0\n 40\n"<<radius<<"\n  0";
		cir.close();
	}
return 0;
}          // newcircle() closed
int main()  // main() function
{
	cout<<"\n\t\t\t****    Draw	****\n\tPress 1 for Line\n\tPress 2 for circle\n\tEnter your choice: "; //Menu to draw line or circle
	cin>>choose;
	if(choose==1) //getting input for line
	{
		cout<<"\nEnter one point(x,y): ";
		cin>>point1>>point2;
		cout<<"\nEnter second point: ";
		cin>>point3>>point4;
		cout<<"\nChoose style\nPress 0 for dot\nPress 5 for dashed ";
		cin>>style;
		cout<<"\nChoose color of a line\nPress 1 for red\nPress 2 for yellow\n Press 3 for green ";
		cin>>color; 
		newline();
	}
	else if(choose==2) // getting input for circle
	{
		cout<<"\nEnter the radius of circle: ";
		cin>>radius;
		cout<<"Enter the centre coordinates: ";
		cin>>point1>>point2;
		newcircle();
	}
	else  // if user enters other than 1 and 2, then it displays the following message. 
	{
		cout<<"\n You entered wrong choice";
	}
	if(choose==1||choose==2) //if user enters 1 or 2 then only it will read header.txt,footer.txt,line.txt/cir.txt and write to linecircle.dxf .
	{	                                //file otherwise jump to else part
		string line,line1,line2;
		ifstream head("header.txt");
		ifstream foot("footer.txt");
		ifstream lin("line.txt");
		ifstream circ("cir.txt");
		ofstream myfile("linecircle.dxf");
		while(getline(head,line,'\n'))  
		{
			myfile<<line<<endl;  // write header.txt to linecircle.dxf
		}
		if(choose==1)                               //if user enters 1 then line.txt will write to linecircle.dxf
		{
			while(getline(lin,line1,'\n')) 
			{
				myfile<<line1<<endl;
			}
		}
		else                                   //if user enters 2 then cir.txt will write to linecircle.dxf
		{
			while(getline(circ,line1,'\n'))
			{
				myfile<<line1<<endl;
			}
		}
		
		while(getline(foot,line2,'\n'))       //write footer.txt to linecircle.dxf
		{
			myfile<<line2<<endl;
		}
		head.close();         // files are closed after reading and writing
		lin.close();
		circ.close();
		foot.close();
		myfile.close();
	}
	else                          //if user enter other than 1 and 2 then this else part will run
		cout<<"\nNothing draw\n";
return 0;
}   //finish
