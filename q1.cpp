#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
namespace fs = std::filesystem;

// Cau truc chinh
struct Node {
	string path;
	vector<Node*> child;
};

Node* newNode(string path){
	Node* temp = new Node();
	temp->path = path;
	temp->child = {NULL};
	return temp;
}
// Sau nay se thay bang Hash Function
// Day van la do tuyen tinh
int getIndex(string key, vector<Node*> v){
	if(v.size() == 1) return -1;
	else{
	    for(int i = 1; i < v.size(); i++){
		    if(v[i]->path == key) return i; //  v[0] dang la null khong co path
	    }
	}
}


void insert(Node* &root, queue<string> &q) {
	// Insert thu muc goc
	if(root == NULL) {
		root = newNode(q.front());
		int index = getIndex(q.front(), root->child);
		q.pop();
		root->child.push_back(newNode(q.front()));
		q.pop();
		insert(root->child[1], q);
	}
	// Insert cac thu muc con
	while(!q.empty()){
		int index = getIndex(q.front(), root->child);
		if (index <= 0 || index >= root->child.size()) {
			root->child.push_back(newNode(q.front()));
			int new_index = getIndex(q.front(), root->child);
			q.pop();
			insert(root->child[new_index], q);
		}
		else {
			q.pop();
			insert(root->child[index], q);
		}
	}
	
}

Node* createTrie(string path) {
	Node* root = new Node();
	root = NULL;
	int i = 0;
	for (const auto& entry : fs::recursive_directory_iterator(path)) {
		queue<string> q;
		for (const auto& part : entry.path()) {
			string part_string = part.generic_string();
			q.push(part_string);
		}
		// Doi voi dong thu 2 tro di thi khong bao gom thu muc goc
		if (i != 0) {
			q.pop();
		}
		insert(root, q);
		i++;
		//break;
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
	}
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
	}

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


	// Goi ham chinh
	cout << "--------------MAIN-------------" << endl;
	Node* main_root = createTrie("D:\\Test");
	printTrie("",main_root, false);


	return 0;
}