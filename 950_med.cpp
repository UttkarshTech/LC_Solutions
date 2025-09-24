vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end(), greater<int>());
    deque<int> dq;
    dq.push_front(deck[0]);
    for (int i=1; i<deck.size(); i++){
        int x = dq.back();
        dq.pop_back();
        dq.push_front(x);
        dq.push_front(deck[i]);
    }
    vector<int> res;
    for (auto i : dq)
        res.push_back(i);
    return res;
}