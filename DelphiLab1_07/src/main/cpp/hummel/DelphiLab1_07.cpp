#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

bool contains(set<char> myset, char x){
	return myset.find(x) != myset.end();
}
int main() {
	set<char> sogl = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z'};
	set<char> glas = {'a', 'e', 'i', 'o', 'u', 'y'};

	cout << "Enter the string: \n";
	string str;
    getline(cin, str);

	while (str.find("  ") != string::npos) {
		str.erase(str.find("  "), 1);
	}

	while (str.find(",") != string::npos) {
		str.erase(str.find(","), 1);
	}

	while (str.find(".") != string::npos) {
		str.erase(str.find("."), 1);
	}

	int q = 1;
	while (str.find(" ") != string::npos) {
		str.replace(str.find(" "), 1, "_");
		q++;
	}

    str = str + "_";
	string strList[q];

	for (int i = 0; i < 3; i++) {
		strList[i] = str.substr(0, str.find("_"));
		str.erase(0, str.find("_") + 1);
	}

	for (string s: strList) {
		if (s != strList[q] && contains(glas, s[0]) && contains(sogl, s[s.length() - 1]) ) {
			cout << s << " ";
		}
	}
}
