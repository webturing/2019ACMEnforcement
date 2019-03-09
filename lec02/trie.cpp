#include<bits/stdc++.h>
using namespace std;
const int SIZE = 26;
struct Node{
	int sum;
	bool isEnd;
	char val;
	vector<Node*>son;
	Node(char val):val(val),sum(0),isEnd(false){
		son.resize(SIZE);
		for(int i = 0; i < SIZE; i++){
			son[i] = NULL;
		}
	}
};
struct Trie{
	Node* root = new Node('a');
	void insert(string s){
		if(s.size()<=0 || s == "")return;
		Node* node = root;
		for(char c : s){
			int p = c - 'a';
			if(NULL == node->son[p]){
				node->son[p] = new Node(c);
			}
			node->son[p]->sum++;
			node = node->son[p];
		}
		node->isEnd = true;
	}
	bool search(string s){
		if(s.size() <= 0 || s == "")return false;
		Node *node = root;
		for(char c: s){
			int p = c - 'a';
			if(node->son[p] == NULL){
				return false;
			}
			node = node->son[p];
		}
		return node->isEnd;
	}
	int countPrefix(string s){
		if(s.size() <= 0 || s == "")return 0;
		Node* node = root;
		for(char c: s){
			int p = c - 'a';
			if(node->son[p] == NULL){
				return 0;
			}
			node = node->son[p];
		}
		return node->sum;
	}
	void deleteString(string s){
		if(s.size() <= 0 || s == "")return;
		Node* node = root;
		for(char c: s){
			int p = c - 'a';
			if(node->son[p] == NULL)return;
			if(node->son[p]->sum-- <= 1){
				node->son[p] = NULL;
				return;
			}
			node = node->son[p]; 
		}
		node->isEnd = false;
	}
	Node* getPrefixNode(string s){
		if(s.size() <= 0 || s == "")return NULL;
		Node* node = root;
		for(char c: s){
			int p = c - 'a';
			if(node->son[p] == NULL){
				return NULL;
			}
			node = node->son[p];
		}
		return node;
	}
	void preTraverse(Node*root){//先序遍历树 
		if(root==NULL)return;
		cout << root->val;
		for(int i = 0; i < SIZE; i++){
			preTraverse(root->son[i]);
		}
	}
	void printStringByPrefix(string s){
		if(search(s)){
			cout << s << endl;
		} 
		Node* node = getPrefixNode(s);
		for(int i = 0; i < SIZE; i++){
			if(node->son[i] != NULL){
				cout << s;
				preTraverse(node->son[i]);
				cout << endl;
			}
		}
	}
};
int main(){
	Trie trie;
	trie.insert("jiailing");
	trie.insert("zhaojing");
	trie.insert("jisuanji");
	trie.insert("ji");
	trie.insert("ji ai ling");
	trie.insert("ji ailing");
//	cout << trie.search("jiailing") << endl;
//	cout << trie.search("zhaojing") << endl;
//	cout << trie.search("cathy") << endl;
//	cout << trie.countPrefix("ji") << endl;
//	trie.deleteString("jisuanji");
	cout << trie.countPrefix("ji") << endl;
	trie.printStringByPrefix("ji");
	return 0;
}
