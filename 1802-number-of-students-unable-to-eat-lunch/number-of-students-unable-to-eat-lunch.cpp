class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circle = 0;
        int square = 0;
        for(int x : students){
            if(x==1) square++;
            else circle++;
        }

        for(int s : sandwiches){
            if(s==0){
                if(circle==0) break;
                circle--;
            }
            else{
                if(square==0) break;
                square--;
            }
        }
        return circle + square;
    }

};