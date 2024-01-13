/* There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105

*/
//code
struct Meeting {
    int s;
    int e;
    int pos;
};
bool cmp(Meeting a, Meeting b) {
    return (a.e<b.e);
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct Meeting meet[n];//creating a struct data structure
        for(int i = 0; i<n; i++){ //feeling meet
            meet[i].s = start[i];
            meet[i].e = end[i];
            meet[i].pos = i+1;
        }
        
        sort(meet, meet+n, cmp);//sorting on the basis of meeting end time
        
        int countMeetings = 1; //for counting the meetings, initialize with 1 as meet[0] is included
        int limit = meet[0].e; //this will store the current meeting end time
        for(int i = 1; i<n; i++){
            if(meet[i].s>limit){// if the meeting start time is greater then only we can organize it
                limit = meet[i].e;
                countMeetings++;
            }
        }
        return countMeetings;
        
    }
};
