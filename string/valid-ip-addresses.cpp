/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.
Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

void backtrack(vector<string>& v, string s, string ip ,int idx, int depth){

    // depth means blocks covered depth(2.5.5.2.5511135) = 5
    if (depth > 4)
        return;

    // depth must be 4 and full string must be covered
    if ((depth == 4) && (idx == s.size())){
        ip.erase(ip.end()-1);
        v.push_back(ip);
        return;
    }


    for (int len=1; len<=3; len++){

        //cout << ip << endl;

        // only 0 is valid but 00, 01, 000, 001 is not valid
        if(s[idx] == '0' && len>1)
            return;

        // out of index => invalid
        if(idx+len > s.size())
            return;

        string sub = s.substr(idx, len);
        if (stoi(sub) < 256)
            backtrack(v, s, ip+ sub+".", idx+len, depth + 1);
        else
            return;
    }
}

vector<string> Solution::restoreIpAddresses(string s) {
    vector<string>v;
    string ip;
    backtrack(v, s, ip, 0, 0); //result, orignal string, temp id strin g,  starting index, depth covered
    return v;
}
