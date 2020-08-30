/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

*/

class Solution {
public:
    bool canFinish(int numCourse, vector<vector<int>>& prerequisites) {
        //Create a adjacency List for graph
        //Store InDegree for each vertex
        //if there is no vertex with 0 indegree means there is cycle so return false
        vector<vector<int>> adj(numCourse);
        vector<int> indegree(numCourse,0);
        for(auto v:prerequisites){
            adj[v[1]].emplace_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourse;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            //Traverse all the child and decrese all childeren's iindegree by 1
            // if anytime indegree is zero means that childeren can be visited
            //so push to the queue
            for(auto ele:adj[curr])
            {
                indegree[ele]--;
                if(indegree[ele]==0)
                    q.push(ele);
            }
            numCourse--;
        }
        if(numCourse==0)
            return true;
        return false;
    }
};
