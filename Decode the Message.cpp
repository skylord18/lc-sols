#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string decodeMessage(string key, string message) {
		vector<char>v(26, ' ');
		for (int i = 0, j = 0; i < key.size(); i++)
			if (key[i] != ' ' && v[key[i] - 'a'] == ' ')
			{
				v[key[i] - 'a'] = (char)(j + 97);
				j++;
			}
		for (int i = 0; i < message.size(); i++)
			if (message[i] != ' ')
				message[i] = v[message[i] - 'a'];
		return message;
	}
};