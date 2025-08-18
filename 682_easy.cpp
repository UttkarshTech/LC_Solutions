int calPoints(vector<string>& operations) {
    stack<int> score;
    for (auto i : operations) {
        if (i == "+") {
            int a = score.top();
            score.pop();
            int b = score.top();
            score.push(a);
            score.push(a + b);
        } else if (i == "D") {
            int a = score.top();
            a <<= 1;
            score.push(a);
        } else if (i == "C")
            score.pop();
        else
            score.push(stoi(i));
    }
    int sum = 0;
    while (!score.empty()) {
        sum += score.top();
        score.pop();
    }
    return sum;
}