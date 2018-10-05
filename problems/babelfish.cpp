//Statement: UVA - 10282

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

string line, en, fo;
stringstream ss;
bool rdict = true;
map<string, string> dict;
map<string, string>::iterator tr;

int main() {
	while (getline(cin, line)) {
		if (line.compare("") == 0) rdict = false;
		if (rdict) {
			ss.clear();
			ss << line;
			ss >> en >> fo;
			dict.insert(make_pair(fo, en));
		} else if(line.compare("") != 0) {
		 	tr = dict.find(line);
		 	if (tr == dict.end()) cout << "eh" << endl;
		 	else cout << tr->second << endl;
		}
	}
}
