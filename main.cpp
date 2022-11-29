#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
using namespace std;
namespace fs = std::filesystem;

struct Node {
	string path;
	vector<Node*> next;
};

Node* insert(Node* root, string path, int level) {
	if (root == NULL) {
		Node* p = new Node();
		p->path = path;
		// Insert sao cho cac path co cung level thi cung mot muc
	}
	return root;
}

Node* createTrie(string path) {
	Node* root = new Node();
	root = NULL;
	for (const auto& entry : fs::recursive_directory_iterator(path)) {
		int i = 0;
		for (const auto& part : entry.path()) {

		}
	}
	return root;
}

void printTrie(const string& prefix, const Node* node, bool isEnd) {
	if (node != NULL) {
		cout << prefix;
		cout << (isEnd ? "|---" : "----");

		cout << node->path << endl;
	}
}
int main() {
	// List files in a directory
	string path = "D:\\Test";
	fstream out;
	out.open("output.txt", ios::out);
	int j = 0;
	for (const auto& entry : filesystem::recursive_directory_iterator(path)) {
		int i = 0;
		j++;
		out << "Display path info for: " << entry.path() << endl;
		
		cout << "Display path info for: " << entry.path() << endl;
		for (const auto& part : entry.path()) {
			//out << "Path part: " << i++ << " = " << part << endl;

			string part_string = part.generic_string();
			cout << "Path part: " << i++ << " = " << part << endl;
		}
		if(j == 10) break;
		// .path().filename() : chi lay ra filename
	}
	 //List files in all subdirectories
	//cout << "Subdirectories\n";
	//string subpath = "D:\\Visual studio code";
	//for (const auto& entry : filesystem::recursive_directory_iterator(subpath)) {
	//	cout << entry.path() << endl;
	//	// Liet ke thu muc va cac file trong thu muc do
	//}

	
	return 0;
}