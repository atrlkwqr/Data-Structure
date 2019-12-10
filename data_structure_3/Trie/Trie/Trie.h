#pragma once
#define Trie

#include <iostream>
#include <fstream>
#include <string>

const int ALPHABET_SIGN_SIZE = 143;

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIGN_SIZE];

	bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIGN_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}