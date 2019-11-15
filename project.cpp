#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;

int get_lowest_diff(vector<string> afile, string password) {
	// take a vector of string which have all the password compare them with
	// the user's password and return the lowest diffirent.

	string str;
	int lowest = 10000;
	for (vector<string>::size_type j = 0; j != afile.size();j++) {
		str = afile[j];
		int diff = std::abs((int)str.size() - (int)password.size());
		for (string::size_type i = 0; i < str.size() && i < password.size(); i++) {
			if (str[i] != password[i]) {
				diff++;
			}
		}
		if (diff < lowest) {
			lowest = diff;
		}
	}
	return lowest;
}

vector<string> get__similar_password(vector<string> all_password, string password,int lowest) {
	//take a vector of string which have all the password, a user's password and the lowest diffrent
	//add the password to a new vector if the password have same diffrent as the lowest diffrent
	//return a sorted vector of string.
	vector<string> similar_password;
	string str;
	for (vector<string>::size_type j = 0; j != all_password.size(); j++) {
		str = all_password[j];
		int diff = std::abs((int)str.size() - (int)password.size());
		for (string::size_type i = 0; i < str.size() && i < password.size(); i++) {
			if (str[i] != password[i]) {
				diff++;
			}
		}
		if (diff == lowest) {
			similar_password.push_back(str);
		}

	}
	sort(similar_password.begin(), similar_password.end());
	return similar_password;
}



int main()
{
	//prompts the user to provide a password,
	//and then print out the common passwords most similar to the password the user provided.
	ifstream inFile;
	string x;
	string y;
	int lowest;
	vector <string> all_password;
	vector <string> similar_password;
	cout << "Give me a password:" << endl;
	cin >> y;
	cout << "You provided a password of " << y << endl;
	cout << "The most similar passwords to " << y << " are:" << endl;
	inFile.open("common_passwords.txt");
	while (inFile >> x) {
		all_password.push_back(x);
	}
	lowest = get_lowest_diff(all_password, y);
	similar_password = get__similar_password(all_password, y, lowest);
	for (vector<string>::size_type i = 0; i != similar_password.size(); i++) {
		cout << similar_password[i] << ", ";
	}
	cout << endl;
	cout << "All of which are "<< lowest <<" character(s) different." << endl;

}
