#include<iostream>
#include<string>
using namespace std;
void Displayinfo(string coursename, double grade, int credits) {
	cout << "Course Name:" << coursename << endl;
	cout << "Grade: " << grade << endl;
	cout << "Credits: " << credits << endl;
}
double GPAConverter(double grade) {
	if (grade >= 93)  //A+ 
		return 4.0;
	else if (grade >= 89) //A
		return 4.0;
	else if (grade >= 84) //A-
		return 3.7;
	else if (grade >= 80) //B+
		return 3.3;
	else if (grade >= 76) //B
		return 3.0;
	else if (grade >= 73) //B-
		return 2.7;
	else if (grade >= 70) //C+
		return 2.3;
	else if (grade >= 67) //C
		return 2.0;
	else if (grade >= 60) //D
		return 1.0;
	else                   //F
		return 0.0;
}
int main() {
	int numcourses=0, credits[10];
	double totalgradepoints = 0;   //initialization of total grade points
	double totalcredits = 0;       //initialization of total credits
	double grade[10];
	string coursename[10];

	cout << "Enter Number of courses:";
	cin >> numcourses;

	for (int i = 0; i < numcourses; i++) {

		cout << "Course no." << i+1 << ":" << endl;

		cout << "Course Name:";
		cin.ignore();       //for buffering issue
		getline(cin, coursename[i]);  //taking course name input with spaces
		

		cout << "Enter Your Grade:";
		cin >> grade[i];

		cout << "Enter Your Credits: ";
		cin >> credits[i];
		cout << "--------------------------------------" << endl;

		double gpa_points = GPAConverter(grade[i]); //converting grade to GPA points
		totalgradepoints += gpa_points * credits[i];  //calculating total grade points
		totalcredits += credits[i];              //calculating total credits :)
		
	}
	double gpa = totalgradepoints / totalcredits; //calculating GPA
	double cgpa = gpa; //calculate CGPA for only one semester

	cout << "\n Your Courses Information: " << endl;
	for (int i = 0; i < numcourses; i++) {
		Displayinfo(coursename[i], grade[i], credits[i]);
	}
	cout << "---------Results---------" << endl;
	cout << "Total hour credits:" << totalcredits << endl;
	cout << "GPA: " << gpa << endl;
	cout << "CGPA: " << cgpa << endl;
	return 0;

}