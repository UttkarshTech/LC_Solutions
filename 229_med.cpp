vector<int> majorityElement(vector<int>& nums) {
    int key1, key2, count1=0, count2=0;
    int tarFreq = floor(nums.size()/3) + 1;
    for (auto i : nums){
        if (!count1 && key2 != i){
            key1 = i; 
            count1++;
        }
        else if (!count2 && key1 != i){
            key2 = i;
            count2++;
        }
        else if (i == key1)
            count1++;
        else if (i == key2)
            count2++;
        else {
            count1--;
            count2--;
            if (count1 == 0)
                key1 = i;
            else if (count2 == 0)
                key2 = i;
        }
    }
    count1 = count2 = 0;
    vector<int> res;
    for (auto i : nums){
        if (i == key1)
            count1++;
        if (i == key2)
            count2++;
    }

    if (count1 >= tarFreq)
        res.push_back(key1);
    if (count2 >= tarFreq)
        res.push_back(key2);
    return res;
}