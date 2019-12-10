#include "Trie.h"

using namespace std;

string arr[10000000];

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - '!';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - '!';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main()
{
	ifstream is;
	string keys;
	string fileName;
	int size = 0;
	int wordcount = 0;

	cout << "input file name > ";
	cin >> fileName;

	is.open(fileName);
	if (is.is_open()) {

		while (true) {
			wordcount = 0;
			cout << "input > ";
			cin >> keys;

			for (size; !is.eof(); size++) {
				is >> arr[size];
			}

			struct TrieNode *root = getNode();

			for (int i = 0; i < size; i++) {
				if (keys == arr[i]) wordcount++;
				insert(root, arr[i]);
			}
			search(root, keys) ? cout << wordcount << endl : cout << "No Exist" << endl;
		}
	}
	else {
		cout << "File Not found" << endl;
	}

	system("pause");

	return 0;
}