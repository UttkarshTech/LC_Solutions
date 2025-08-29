int convertTime(string time){
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3));
    return hours*60 + minutes;
}

int findMinDifference(vector<string>& timePoints) {
    if (timePoints.size() > 1440)
        return 0;
    vector<int> minutes;
    for (auto i : timePoints)
        minutes.push_back(convertTime(i));
    sort(minutes.begin(), minutes.end());
    int minDiff = INT_MAX;
    for (int i=1; i<minutes.size(); i++)
        minDiff = min(minDiff, minutes[i]-minutes[i-1]);
    minDiff = min(minDiff, minutes[0]+1440-minutes.back());
    return minDiff;
}