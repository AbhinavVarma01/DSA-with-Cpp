class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        int l=0;
        int r=people.size()-1;
        while(l<r){
            if(people[r]==limit){
                r--;
                count++;
            }
            else{
                int s = people[l]+people[r];
                if(s==limit){
                    l++;
                    r--;
                    count++;
                }
                else if(s>limit){
                    r--;
                    count++;
                }
                else{
                    l++;
                    r--;
                    count++;
                }
            }

            if(l==r && people[r]<=limit) count++;
        }
        return count;
    }
};