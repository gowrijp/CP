/*
https://codeforces.com/problemset/problem/39/J

Petya has noticed that when he types using a keyboard, he often presses extra buttons and adds extra letters to the words. Of course, the spell-checking system underlines the words for him and he has to click every word and choose the right variant. Petya got fed up with correcting his mistakes himself, that’s why he decided to invent the function that will correct the words itself. Petya started from analyzing the case that happens to him most of the time, when all one needs is to delete one letter for the word to match a word from the dictionary. Thus, Petya faces one mini-task: he has a printed word and a word from the dictionary, and he should delete one letter from the first word to get the second one. And now the very non-trivial question that Petya faces is: which letter should he delete?

Input
The input data contains two strings, consisting of lower-case Latin letters. The length of each string is from 1 to 106 symbols inclusive, the first string contains exactly 1 symbol more than the second one.

Output
In the first line output the number of positions of the symbols in the first string, after the deleting of which the first string becomes identical to the second one. In the second line output space-separated positions of these symbols in increasing order. The positions are numbered starting from 1. If it is impossible to make the first string identical to the second string by deleting one symbol, output one number 0.

Examples

Input:
abdrakadabra
abrakadabra

Output:
1
3

input:
aa
a

output:
2
1 2

input:
competition
codeforces

output:
0
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string a, b;
	int l, r;

	cin >> a >> b;
	if (a.length() != b.length() + 1) {
		l = 0;
		r = -1;
	} else {
		r = 0;
		while (r < (int)b.length() && a[r] == b[r]) {
			++r;
		}
		l = (int)b.length() - 1;
		while (l >= 0 && a[l + 1] == b[l]) {
			--l;
		}
		cout << max(0, r - l) << endl;
		for (int i = 0; i <= (int)b.length(); ++i) {
			if (l < i && i <= r) {
				cout << i + 1 << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}
