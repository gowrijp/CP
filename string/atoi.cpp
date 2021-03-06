/*Implement atoi to convert a string to an integer.

Example :

Input : "9 2704" (space in bw is garbage)
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise.*/

int Solution::atoi(const string A) {
  int i = 0;

  bool negative = false;
  while(A[i] == ' ') i++;
  if(A[i] == '-'){
      negative = true;
      i++;
  }
  else if(A[i] == '+') i++;
  long num = 0;
  for(int j=i;j<A.size();j++){
  if(A[j]<='9' and A[j]>='0'){
      num = num*10 + A[j] - '0';
      if(num>INT_MAX) return negative ? INT_MIN : INT_MAX;
  }
    else
     return negative ? -1 * num : num;
  }
  if(num>INT_MAX) return negative ? INT_MIN : INT_MAX;
  return negative ? -1 * num : num;
}
