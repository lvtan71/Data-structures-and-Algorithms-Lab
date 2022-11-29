#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
#include<vector>
using namespace std;
namespace fs = std::filesystem;

struct Node {
	string path;
	vector<Node*> child;
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
		cout << "|___";

		cout << node->path << endl;
		
		for(int i = 0; i < node->child.size() ; i++){
			if(i == node->child.size() - 1) printTrie(prefix + (isEnd ? "|    " : "     "), node->child[i], false);
			else printTrie(prefix + (isEnd ? "|    " : "     "), node->child[i], true);
		}
		// Su dung DFS, de quy de tim duong dan, cay con trai sang phai
		// Duyet cay khi den node la thi luu node la = key, value = duong dan tuyet doi -> luu vao map 
	}
}

Node* newNode(string path){
	Node* temp = new Node();
	temp->path = path;
	temp->child = {NULL};
	return temp;
}

// TEST
struct sNode{
	string path;
	sNode *left;
	sNode *right;
};

sNode* insert(sNode* &root, string path, bool a){
	sNode* temp = new sNode();
	temp->path = path;
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL) root = temp;
	else if(a){
		root->left = temp;
	}
	else{
		root->right = temp;
	}
	return root;
}


void printBT(const string& prefix, const sNode* node, bool isLeft) {
	int i = 0;
	if (node != NULL) {
		cout << prefix;
		cout << (isLeft ? "|___ " : "|___ ");

		cout << node->path << endl;

		printBT(prefix + (isLeft ? "|    " : "     "), node->left, !isLeft);
		printBT(prefix + (isLeft ? "|    " : "     "), node->right, false);
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

	//TEST
	sNode *root = new sNode();
	root = NULL;
	root = insert(root, "D:\\",0);
	root = insert(root, "F1",0);
	root = insert(root, "F2",1);
	root->left = insert(root->left,"F3",1);
	root->left->left = insert(root->left->left,"file.txt",1);
	root->right = insert(root->right,"null.txt",0);
	root->right = insert(root->right,"notnull.txt",1);
	printBT("",root,false);
	
	///

	Node* nroot = new Node();
	nroot->path = "D:\\";
	nroot->child.push_back(newNode("F1"));
	nroot->child.push_back(newNode("F2"));
	nroot->child.push_back(newNode("F3"));
	nroot->child.push_back(newNode("F4"));
	nroot->child.push_back(newNode("F5"));
	nroot->child[0]->child.push_back(newNode("F6"));
	nroot->child[0]->child.push_back(newNode("F7"));
	nroot->child[0]->child.push_back(newNode("F8"));
	nroot->child[0]->child.push_back(newNode("F9"));
	nroot->child[0]->child[1]->child.push_back(newNode("F10"));
	nroot->child[0]->child[3]->child.push_back(newNode("F11"));
	nroot->child[0]->child[4]->child.push_back(newNode("F12"));
	nroot->child[1]->child.push_back(newNode("a.txt"));
	nroot->child[1]->child.push_back(newNode("b.txt"));
	nroot->child[3]->child.push_back(newNode("c.txt"));
	nroot->child[4]->child.push_back(newNode("d.txt"));
	nroot->child[4]->child.push_back(newNode("e.txt"));
	nroot->child[4]->child.push_back(newNode("f.txt"));

	printTrie("",nroot,false);

	return 0;
}