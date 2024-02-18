/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting 
will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. 
The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, 
return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.
*/
#define ll long long
#define pi pair<ll,ll>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& A) {
        vector<int> roomcnt(n,0);
        set<int> s;
        priority_queue<pi,vector<pi>,greater<pi>> q;
        sort(A.begin(),A.end());
        int m=A.size();
        // store available rooms
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        for(int i=0;i<m;i++){
            ll start=A[i][0];
            ll end=A[i][1];
            // storing available room in set 
            while(q.size()>0 && q.top().first<=start){
                int room=q.top().second;
                q.pop();
                s.insert(room);
            }
            // delaying the current meeting
            if(s.size()==0){
                pair<ll,ll> p=q.top();
                q.pop();
                ll dif=end-start;
                start=p.first;
                end=start+dif;
                s.insert(p.second);
            }
            // lowest number of unsed room available
            auto it=s.begin(); 
            roomcnt[*it]++;
            // assign meeting to lowest avaible room
            q.push({end,*it});
            s.erase(*it);
        }
        int ans=0;
        int maxi=0;
        // find room with maximum meetings
        for(int i=0;i<n;i++){
            if(maxi<roomcnt[i]){
                maxi=roomcnt[i];
                ans=i;
            }
        }
        return ans;
    }
};