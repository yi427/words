#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

const std::string path = "/home/troubilll/etc/words.val";

int main() {
	ifstream fin(path);
	vector<string> data;
	while (fin.is_open()) {
		string t;
		while (getline(fin, t)) {
			data.emplace_back(t);
		}
		fin.close();
	}
	random_shuffle(begin(data), end(data));
	while (!data.empty()) {
		auto& line = data.front();
		auto pos = line.find_last_of(" ");
		cout << line.substr(0, pos) << "\n";
		char ch; cin >> ch;
		if (ch == 'y') {
			;
		} else {
			data.emplace_back(line);
			cout << line.substr(pos) << "\n";
		}
		data.erase(begin(data));
	}
	return 0;
}
