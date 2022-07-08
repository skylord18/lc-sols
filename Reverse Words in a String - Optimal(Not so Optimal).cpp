#include<bits/stdc++.h>
using namespace std;
class Solution {
	void removeSpaces(string &str)
	{
		// n is length of the original string
		int n = str.length();

		// i points to next position to be filled in
		// output string/ j points to next character
		// in the original string
		int i = 0, j = -1;

		// flag that sets to true is space is found
		bool spaceFound = false;

		// Handles leading spaces
		while (++j < n && str[j] == ' ');

		// read all characters of original string
		while (j < n)
		{
			// if current characters is non-space
			if (str[j] != ' ')
			{
				// remove preceding spaces before dot,
				// comma & question mark
				if ((str[j] == '.' || str[j] == ',' ||
				        str[j] == '?') && i - 1 >= 0 &&
				        str[i - 1] == ' ')
					str[i - 1] = str[j++];

				else
					// copy current character at index i
					// and increment both i and j
					str[i++] = str[j++];

				// set space flag to false when any
				// non-space character is found
				spaceFound = false;
			}
			// if current character is a space
			else if (str[j++] == ' ')
			{
				// If space is encountered for the first
				// time after a word, put one space in the
				// output and set space flag to true
				if (!spaceFound)
				{
					str[i++] = ' ';
					spaceFound = true;
				}
			}
		}

		// Remove trailing spaces
		if (i <= 1)
			str.erase(str.begin() + i, str.end());
		else
			str.erase(str.begin() + i - 1, str.end());
	}

public:
	string reverseWords(string s) {
		int  l = 0, r = s.length() - 1;
		string temp = "", ans = "";
		while (l < r) {
			char ch = s[l];
			if (ch != ' ')
				temp += ch;
			else {
				if (ans == "") {
					ans == temp;
				} else {
					ans = temp + " " + ans;
					temp = "";
				}
			}
			l++;
		}
		if (temp != "")
			if (ans != "")
				ans = temp + " " + ans;
			else
				ans = temp;

		removeSpaces(ans);
		return ans;
	}
};