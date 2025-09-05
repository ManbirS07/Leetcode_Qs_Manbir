class Solution {
public:
    typedef pair<double,int> p;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)     {
    int n = classes.size();
    priority_queue<p> pq;

    for (int i = 0; i < n; i++) {
        double currPR = (double)classes[i][0] / classes[i][1];
        double newPR = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        double diff = newPR - currPR;
        pq.push({diff, i});
    }

    while (extraStudents--) {
        auto curr = pq.top();
        pq.pop();
        int idx = curr.second;

        classes[idx][0]++; //incrementing total passing students in the class
        classes[idx][1]++; //incrementing total students in the class

        double currPR = (double)classes[idx][0] / classes[idx][1];
        double newPR = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1); //this is for the next of adding a student
        double diff = newPR - currPR; //only the diff of current class would change as we have added one student here
        //if this diff is not effective we can take another class to add a student and then we wpuld find this diff for the new class and so on
        pq.push({diff, idx});
    }

    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += (double)classes[i][0] / classes[i][1];
    }

    res /= n;
    return res;
    }
};