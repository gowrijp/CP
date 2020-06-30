/* Scramble string dp
https://www.youtube.com/watch?v=2uiUgK_gvgQ
*/

int Solution::isScramble(const string s1, const string s2) {
    // If they are equal
    if(s1==s2)
            return 1;

    int len = s1.length();
    int count[26] = {0};
    // array to check count of each character
    for(int i=0; i<len; i++)
    {
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
    }
    // checking if its an anagram or not
    for(int i=0; i<26; i++)
    {
        if(count[i]!=0)
            return 0;
    }

    for(int i=1; i<=len-1; i++)
    {
        if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
            return 1;
        if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
            return 1;
    }
    return 0;
}
