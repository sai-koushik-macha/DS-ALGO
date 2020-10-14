
//Source : https://www.geeksforgeeks.org/print-all-possible-combinations-of-words-from-dictionary-using-trie/




//Print all possible combinations of words from Dictionary using Trie


/*

Input: arr[] = ["sam", "sung", "samsung"]
Output:
sam: 
    sam
sung: 
    sung
samsung: 
    sam sung
    samsung
String 'samsung' can be formed using two different 
strings from the array i.e. 'sam' and 'sung' whereas 
'samsung' itself is also a string in the array.

*/

// C++ implementation of the approach 

#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

// Trie node 
struct TrieNode { 
	struct TrieNode* children[ALPHABET_SIZE]; 

	// isEndOfWord is true if node 
	// represents the end of the word 
	bool isEndOfWord; 
}; 

// Returns new trie node 
struct TrieNode* 
getNode(void) 
{ 
	struct TrieNode* pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, 
// marks the node as leaf node 
void insert(struct TrieNode* root, string key) 
{ 
	struct TrieNode* pCrawl = root; 

	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// Mark node as leaf 
	pCrawl->isEndOfWord = true; 
} 

// Returns true if the key is present in the trie 
bool search(struct TrieNode* root, string key) 
{ 
	struct TrieNode* pCrawl = root; 

	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

// Result stores the current prefix with 
// spaces between words 
void wordBreakAll(TrieNode* root, 
				string word, int n, string result) 
{ 
	// Process all prefixes one by one 
	for (int i = 1; i <= n; i++) { 

		// Extract substring from 0 to i in prefix 
		string prefix = word.substr(0, i); 

		// If trie conatins this prefix then check 
		// for the remaining string. 
		// Otherwise ignore this prefix 
		if (search(root, prefix)) { 

			// If no more elements are there then print 
			if (i == n) { 

				// Add this element to the previous prefix 
				result += prefix; 

				// If(result == word) then return 
				// If you don't want to print last word 
				cout << "\t" << result << endl; 
				return; 
			} 
			wordBreakAll(root, word.substr(i, n - i), n - i, 
						result + prefix + " "); 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	struct TrieNode* root = getNode(); 

	string dictionary[] = { 
		"sam", "sung", 
		"samsung"
	}; 
	int n = sizeof(dictionary) / sizeof(string); 

	for (int i = 0; i < n; i++) { 
		insert(root, dictionary[i]); 
	} 

	for (int i = 0; i < n; i++) { 
		cout << dictionary[i] << ": \n"; 
		wordBreakAll(root, dictionary[i], 
					dictionary[i].length(), ""); 
	} 

	return 0; 
} 
