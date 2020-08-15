/*
interviewbit.com/problems/hotel-bookings-possible/

Very similar to meeting rooms https://www.interviewbit.com/problems/meeting-rooms/

*/

bool comp(vector<int> &A, vector<int> &B){
    return A[0]<B[0];
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n=arrive.size();
    vector<vector<int>> A;
    for(int i=0;i<n;i++){
        if(arrive[i]!=depart[i])
            A.push_back({arrive[i],depart[i]});
    }
    sort(A.begin(),A.end(),comp);
    int ans=1;
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(A[0][1]);
    for(int i=1;i<A.size();i++){
        if(A[i][0]>=pq.top()){
            pq.pop();
        }
        else{
            ans++;
        }
        pq.push(A[i][1]);
    }
    if(ans<=K) return true;
    else return false;
}
