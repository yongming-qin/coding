
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using std::string, std::vector, std::map, std::set;
using std::priority_queue, std::greater;

class Solution {
public:
    string alienOrder(vector<string> &words) {
        map<char,set<char>> relations;
        int s = words.size();
        for (auto ww : words) {
            for (auto ch : ww) {
                if (relations.count(ch) == 0) {relations[ch] = set<char>();}
            }
        }
        for (int i = 0; i < s - 1; ++i) {
            for (int j = i + 1; j < s; ++j) {
                if (!computeRelations(words[i], words[j], relations)) {
                    return ""; // the relations are invalid
                }
            }
        }

        // how to iterate the keys and vals of a map
        map<char,int> indegrees; // will the int be default initialized as 0?
        for (auto &re : relations) {
            if (indegrees.count(re.first) == 0) {
                indegrees[re.first] = 0;
            }
            for (char next : re.second) {
                indegrees[next]++; // assume default initialization
            }
        }
        return topologicalSorting(relations, indegrees);
    }


    bool computeRelations(string a, string b, map<char,set<char>> &relations) {
        int k = 0;
        while (k < a.size() && k < b.size()) {
            if (a[k] != b[k]) {
                relations[a[k]].insert(b[k]); // todo
                break; // Import
            }
            k++;
        }
        if (k == b.size() && a.size() > b.size()) {return false;}
        return true;
    }

    string topologicalSorting(map<char,set<char>> &relations,
        map<char,int> &indegrees)
    {
        priority_queue<char, vector<char>, greater<char>> pq;
        for (auto degree : indegrees) {
            if (degree.second = 0) {
                pq.push(degree.first);
            }
        }
        string s = "";
        while (pq.size()) {
            char head = pq.top(); pq.top();
            s += head;
            for (char next : relations[head]) {
                indegrees[next]--;
                if (indegrees[next] == 0) {
                    pq.push(next);
                }
            }
        }
        if (s.size() != indegrees.size()) return "";
        return s;
    }

};