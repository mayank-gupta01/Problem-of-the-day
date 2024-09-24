/*
Given a string s, find the length of the longest substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int ans = 0;
    int n = s.size();
    int i = 0, j = 0;
    unordered_map<char, int> mp;
    while (j < n)
    {
        char ch = s[j];
        mp[ch]++;
        if (mp[ch] <= 1)
        {
            ans = max(ans, (j - i + 1));
        }
        else
        {
            while (i < j && mp[ch] > 1)
            {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, (j - i + 1));
        }
        j++;
    }

    return ans;
}

int main(){
    string s = "abcdauskbs";
    cout<< lengthOfLongestSubstring(s)<<endl;
}