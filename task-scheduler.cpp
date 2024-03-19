/*
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

 
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_freq=0, sz=tasks.size();
        int freq[26]={0};
        for(char c: tasks){
            int f=++freq[c-'A'];
            max_freq=max(max_freq, f);
        }
        int num_maxFreq=count(freq, freq+26, max_freq);
        
        int time=(max_freq-1)*(n+1)+num_maxFreq;
        return max(time, sz);
    }
};