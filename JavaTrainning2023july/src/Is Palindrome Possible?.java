#include <bits/stdc++.h>
using namespace std;

/*
* function to check whether characters of
a string can form a palindrome
*/
bool canFormPalindrome(string str)
{

	// Create a list
	vector<char> list;

	// For each character in input strings,
	// remove character if list contains
	// else add character to list
	for (int i = 0; i < str.length(); i++)
	{
		auto pos = find(list.begin(),
						list.end(), str[i]);
		if (pos != list.end()) {
			auto posi
				= find(list.begin(),
					list.end(), str[i]);
			list.erase(posi);
		}
		else
			list.push_back(str[i]);
	}

	// if character length is even list is
	// expected to be empty or if character
	// length is odd list size is expected to be 1

	// if string length is even

	if (str.length() % 2 == 0
			&& list.empty()
		|| (str.length() % 2 == 1
			&& list.size() == 1))
		return 2;

	// if string length is odd
	else
		return 1;
}



// This code is contributed by Rajput-Ji
