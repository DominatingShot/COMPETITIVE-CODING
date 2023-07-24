class Solution {
public:
    string reverseVowels(string a) {
        int i = 0;                        // Initialize 'i' to point to the beginning of the string
        int j = a.length() - 1;           // Initialize 'j' to point to the end of the string

        while (i < j) {                   // Loop until 'i' is less than 'j'
            // Find the next vowel from the beginning of the string
            while (i < j && !isVowel(a[i])) {
                i++;
            }

            // Find the next vowel from the end of the string
            while (i < j && !isVowel(a[j])) {
                j--;
            }

            if (i >= j) {                 // If 'i' is greater than or equal to 'j', we have processed all vowels
                break;
            }

            // Swap the vowels found at positions 'i' and 'j'
            swap(a[i], a[j]);

            // Move to the next characters in the string
            i++;
            j--;
        }

        return a; // Return the string with reversed vowels
    }

private:
    bool isVowel(char c) {
        // Check if the given character 'c' is a vowel (uppercase or lowercase)
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
