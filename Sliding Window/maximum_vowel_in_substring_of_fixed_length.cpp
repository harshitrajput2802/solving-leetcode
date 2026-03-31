/*
Problem: 1456. Maximum Number of Vowels in a Substring of Given Length

Problem Description:
Given a string `s` and an integer `k`, return the maximum number of vowel letters in any substring of s with length k.
`s` consists of lowercase English letters only.

Our Approach(Sliding Window):
- Calculate the number of vowels in first k elements => This will be our window
- Keep this count as maxVowel
- Use a loop starting from index k to the end of the array,
    check if the new incoming element(at index 'i') is a vowel or not
        if it is a vowel we will increase the vowel count
    similarly, check outgoing element(at index 'i - k') was a vowel or not
        if it is a vowel we will decrease the vowel count
- after each slide, store the maximum of vowel and maxVowel
- At the end we will have the maximum number of vowels so it will be returned

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowel = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                vowel++;
        }
        int maxVowel = vowel;
        for (int i = k; i < n; i++) {
            if (isVowel(s[i]))
                vowel++;
            if (isVowel(s[i - k]))
                vowel--;
            maxVowel = std::max(maxVowel, vowel);
        }
        return maxVowel;
    }
};