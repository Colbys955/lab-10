/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
// question 1
void circle(double rad) {
	double area = M_PI * rad * rad;
	double circum = 2 * M_PI * rad;
	cout << fixed << setprecision(2);
	cout << "Area: " << area << endl;
	cout << "Circumference: " << circum << endl;
}
// question 2
void access() {
	string cit;
	int age;
	cout << "Enter your citizenship (N for Non American, A for American) and your age." << endl;
	cin >> cit >> age;
	if (cit == "A" && age >= 21) {
		cout << "You can access to all amentities and the casino." << endl;
	}
	else if (cit == "A" && age < 21) {
		cout << "You can access all amentities except the casino." << endl;
	}
	else if (cit == "N" && age >= 21) {
		cout << "You can access all amentities and the casino with a 15$ fee." << endl;
	}
	else if (cit == "N" && age >= 18 && age <= 20) {
		cout << "You can access all amentities except the casino." << endl;
	}
	else if (age < 18) {
		cout << "You are not allowed inside." << endl;
	}
}
// question 3
string tolowers(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}
// question 8
float tempatures(const vector<float>& readings) {
	if (readings.empty()) {
		cout << "Error" << endl;
		return 0.0f;
	}
	float highest = *max_element(readings.begin(), readings.end());
	float lowest = *min_element(readings.begin(), readings.end());
	float sum = accumulate(readings.begin(), readings.end(), 0.0f);
	float average = sum / readings.size();
	cout << "Highest: " << highest << endl;
	cout << "Lowest: " << lowest << endl;
	cout << "Average: " << average << endl;
	return average;
}
// question 9
void convertBinary(int n) {
	if (n == 0) {
		cout << "Binary: 0" << endl;
		return;
	}
	string binaryString = " ";
	int temp = n;
	while (temp > 0) {
		int remainder = temp % 2;
		binaryString += (remainder == 0 ? '0' : '1');
		temp /= 2;
	}
	reverse(binaryString.begin(), binaryString.end());
	cout << "Binary: " << binaryString << endl;
}
// question 10
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	// question 1
	double a;
	cout << "Enter radius." << endl;
	cin >> a;
	circle(a);
	// question 2
	access();
	// questin 3
	vector<string> pets = {"Bella", "Max", "bella", "RoCkY", "BELLA", "BELLa"};
	string sname;
	cout << "Search Name: ";
	cin >> sname;
	int count = 0;
	for (string name : pets) {
		if (tolowers(name) == tolowers(sname)) {
			count ++;
		}
	}
	cout << sname << " appears " << count << " times" << endl;
	// question 4
	float width, height, radius;
	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;
	cout << "Enter circle radius: ";
	cin >> radius;
	float diag = sqrt(width * width + height * height);
	bool fits = (diag <= 2 * radius);
	cout << boolalpha;
	cout << "Rectangle fits: " << fits << endl;
	// question 5
	double hours;
	cout << "Enter hours: ";
	cin >> hours;
	double seconds = hours * 3600.0;
	cout << "Seconds(rounded): " << llround(seconds) << endl;
	// question 6
	int n;
	cout << "Enter an integer: ";
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			cout << "*";
		}
		cout << endl;
	}
	// question 7
	int e;
	cout << "Enter an integer: ";
	cin >> e;
	for (int i = 1; i <= e; ++i) {
		for (int j = 1; j <= (e - 1); ++j) {
			cout << " ";
		}
		for (int k = 1; k <= i; ++k) {
			cout << "*";
		}
		cout << endl;
	}
	// question 8
	vector<float> temps = {72.5f, 67.0f, 65.6f, 90.8f, 76.8f};
	cout << "Tempatures" << endl;
	float avg_temp = tempatures(temps);
	cout << "Function reuturned: " << avg_temp << endl;
	// question 9
	int num;
	cout << "Enter an integer to convert to binary";
	cin >> num;
	convertBinary(num);
	cout << "converting.." << endl;
	cout << "Enter another integer" << endl;
	cin >> num;
	convertBinary(num);
	// question 10
	int int1 = 2;
	int int2 = 4;
	cout << "Before: int1 = " << int1 << ", int2 = " << int2 << endl;
	swap(int1, int2);
	cout << "After int1 = " << int1 << ", int2 = " << int2 << endl;


	return 0;
}