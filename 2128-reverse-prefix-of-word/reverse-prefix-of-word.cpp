class Solution {
public:
    string reversePrefix(string word, char ch) {

        // Find the first occurrence of ch
        int index = word.find(ch);

        // Reverse from 0 to index
        reverse(word.begin(), word.begin() + index + 1);

        return word;
    }
};