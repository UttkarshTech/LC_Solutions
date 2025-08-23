class MKAverage {
public:
    deque<int> ipStream;
    multiset<int> mid;
    multiset<int> smallestK;
    multiset<int> largestK;
    int m, k, sumMid;
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        sumMid = 0;
    }

    void addElement(int num) {
        ipStream.push_back(num);
        if (ipStream.size() == m) { // one time operation
            for (auto i : ipStream)
                mid.insert(i);
            for (int i=0; i<k; i++){
                int temp = *mid.begin();
                int temp2 = *mid.rbegin();
                smallestK.insert(temp);
                largestK.insert(temp2);
                mid.erase(mid.begin());
                mid.erase(--mid.end());
            }
            for (auto i : mid){
                sumMid += i;
            }
        } else if (ipStream.size() > m) { // m+1
            
            if (num < *smallestK.rbegin()) {
                int temp = *smallestK.rbegin();
                smallestK.erase(--smallestK.end());
                smallestK.insert(num);
                mid.insert(temp);
                sumMid += temp;
            } else if (num > *largestK.begin()) {
                int temp = *largestK.begin();
                largestK.erase(largestK.begin());
                largestK.insert(num);
                mid.insert(temp);
                sumMid += temp;
            } else{
                mid.insert(num);
                sumMid += num;
            }

            int temp = ipStream.front();
            ipStream.pop_front();
            if (smallestK.find(temp) != smallestK.end()){
                smallestK.erase(smallestK.find(temp));
                int temp2 = *mid.begin();
                mid.erase(mid.begin());
                smallestK.insert(temp2);
                sumMid -= temp2;
            } else if (largestK.find(temp) != largestK.end()){
                largestK.erase(largestK.find(temp));
                int temp2 = *mid.rbegin();
                mid.erase(--mid.end());
                largestK.insert(temp2);
                sumMid -= temp2;
            } else {
                mid.erase(mid.find(temp));
                sumMid -= temp;
            }
        }
    }

    int calculateMKAverage() {
        if (ipStream.size() < m)
            return -1;
        return (int)floor(sumMid/mid.size());
    }
};