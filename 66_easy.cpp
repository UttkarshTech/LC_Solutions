vector<int> plusOne(vector<int>& digits) {
    int i = digits.size();
    bool carry = false;
    if (i == 0)
        return digits;
    if (digits[i-1] == 9){
        digits[i-1] = 0;
        carry = true;
    } else 
        digits[i-1]++;
    i--;
    while (i && carry){
        if (digits[i-1] == 9){
            digits[i-1] = 0;
            carry = true;
        } else{
            digits[i-1]++;
            carry = false;
        }
        i--;
    }
    if (carry)
        digits.insert(digits.begin(), 1);
    return digits;
}