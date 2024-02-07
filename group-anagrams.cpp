/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        unordered_map<string, vector<string>> anagramGroups;
        for (const string& word : words) {
            string key = word;
            sort(key.begin(), key.end());
            if (anagramGroups.find(key) == anagramGroups.end()) {
                anagramGroups[key] = {word};
            }
            else {
                anagramGroups[key].push_back(word);
            }
        }
        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};