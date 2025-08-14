vector<int> asteroidCollision(vector<int>& asteroids) {
    bool collision;
    stack<int> s;
    vector<int> res;

    collision = asteroids[0] > 0;

    for (auto i : asteroids){
        if (collision){
            if (s.empty()){
                if (i > 0){
                    s.push(i);
                    collision = true;
                } else {
                    s.push(i);
                    collision = false;
                }
            }
            else if (i > 0)
                s.push(i);
            else {
                if (s.top() < -1*i){
                    while (!s.empty() && s.top()>0 && s.top() < -1*i)
                        s.pop();
                    if (s.empty() || s.top() < 0){
                        s.push(i);
                        collision = false;
                    } else if (s.top() == -1*i)
                        s.pop();
                } else if (s.top() == -1*i)
                    s.pop();
            }
        } else {
            if (s.empty()){
                if (i > 0){
                    s.push(i);
                    collision = true;
                } else {
                    s.push(i);
                    collision = false;
                }
            }
            else if (i < 0)
                s.push(i);
            else {
                s.push(i);
                collision = true;
            }
        }
    }
    if (s.empty())
        return res;
    else {
        while (!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
    }
    reverse(res.begin(), res.end());
    return res;
}