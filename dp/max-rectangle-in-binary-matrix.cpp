/*Solved using max area in a histogram approach for every row array in the 2d matrix
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
A : [  1 1 1
       0 1 1
       1 0 0
    ]

Output : 4

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
*/

int findMaxArea(vector<int> &A){
    stack<int> S;

    S.push(0);

    int i = 0,maxarea = 0;
    int areawithtop;
    int tp;
    while(i<A.size()){
        if(S.empty() || A.at(i) >= A.at(S.top()) ){
            S.push(i);
            i++;
        }
        else{
            tp = S.top();
            S.pop();

            if(S.empty()){
                areawithtop = A[tp]*i;
            }
            else{
                areawithtop = A[tp]*(i-S.top()-1);
            }

            maxarea = max(maxarea,areawithtop);
        }
    }

    while(!S.empty()){
        tp = S.top();
        S.pop();

            if(S.empty()){
                areawithtop = A[tp]*i;
            }
            else{
                areawithtop = A[tp]*(i-S.top()-1);
            }

        maxarea = max(maxarea,areawithtop);
    }

    return maxarea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    vector<int> hist;
    for(int j=0;j<A.at(0).size();j++){
        hist.push_back(0);
    }

    int maxArea = 0;
    for(int i=0;i<A.size();i++){

        for(int j=0;j<A.at(0).size();j++){
            if(A.at(i).at(j) == 0)
                hist.at(j) = 0;
            else
                hist.at(j)++;
        }

        maxArea = max(maxArea,findMaxArea(hist));

    }

    return maxArea;
}
