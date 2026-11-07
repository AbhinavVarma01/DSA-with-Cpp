class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        vector<int> ans;

        set<pair<int,int>> available;
        set<pair<long long,int>> busy;

        for(int i = 0; i < n; i++) {
            available.insert({servers[i], i});
        }

        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {

            if(time < i)
                time = i;
            while(!busy.empty()) {
                long long freeTime = busy.begin()->first;

                if(freeTime <= time) {
                    int index = busy.begin()->second;

                    busy.erase(busy.begin());
                    available.insert({servers[index], index});
                }
                else {
                    break;
                }
            }
            if(available.empty()) {
                time = busy.begin()->first;

                while(!busy.empty() && busy.begin()->first == time) {
                    int index = busy.begin()->second;

                    busy.erase(busy.begin());
                    available.insert({servers[index], index});
                }
            }
            int index = available.begin()->second;
            available.erase(available.begin());
            ans.push_back(index);
            busy.insert({time + tasks[i], index});
        }

        return ans;
    }
};