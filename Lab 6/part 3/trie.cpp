#include "trie.h"
#include <iostream>

Trie::Trie()
{
	root = NULL;
}

// Returns new trie node (initialized to NULLs)
struct TrieNode* Trie::getNode(void)
{
	TrieNode* node = new TrieNode;
	for(int i=0; i<ALPHABET_SIZE; i++){ node->children[i] = NULL;}
	return node;	
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void Trie::insert(struct TrieNode* root, const std::string key)
{
	TrieNode* node = root;
	int N = key.size();
	int x;
	for(int i=0; i<N; i++){
		x = CHAR_TO_INDEX(key[i]);
		if(node->children[x] == NULL){
			node->children[x] = getNode();
		}
		node = node->children[x];
	}
	node->isWordEnd = true;		
}

bool Trie::search(struct TrieNode *root, std::string key)
{
	TrieNode* node = root;
	int N = key.size();
	int x;
	for(int i=0; i<N; i++){
		x = CHAR_TO_INDEX(key[i]);
		if(node->children[x] == NULL){	// Possibility of segmentation fault
			return false;
		}
		node = node->children[x];
	}
	
	if (node->isWordEnd){ 
		return true;
	}
	else{
		return false;
	}	
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool Trie::isLastNode(struct TrieNode* root)
{
	if(root == NULL) return 1;
	for(int i=0; i<ALPHABET_SIZE; i++){
		if(root->children[i]) return 0;
	}
	return 1;
}

// Recursive function to print auto-suggestions for given
// node.
void Trie::suggestionsRec(struct TrieNode* root,
					std::string currPrefix)
{
	// found a std::string in Trie with the given prefix
	if(root == NULL) return;
	if(root->isWordEnd) std::cout<< currPrefix << '\n';
	for(int i=0; i<ALPHABET_SIZE; i++){
		std::string newPrefix = currPrefix + char('a'+i);
		if(root->children[i]) suggestionsRec(root->children[i],newPrefix);
	}
}

// print suggestions for given query prefix.
int Trie::printAutoSuggestions(TrieNode* root, const std::string query)
{
	TrieNode* node = root;
	for (int i = 0; i < query.length(); i++)
	{
		if(node->children[CHAR_TO_INDEX(query[i])]==NULL) return -1;
		node = node->children[CHAR_TO_INDEX(query[i])];
	}
	suggestionsRec(node, query);
	if(isLastNode(node)) return 0;
	return 1;	
}

// Process the file "lorem.txt" to insert the words in lorem.txt and store the relevant context as needed.
void Trie::processContext()
{

}
