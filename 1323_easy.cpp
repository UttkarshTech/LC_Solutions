int maximum69Number (int num) {
    int temp = num, div=10, x=9;
    while (temp%div != temp){
        x = x*10 + 9;
        div *= 10;
    }
    int diff = x - num, digits = 0;
    if (!diff)
        return num;
    cout<<diff;
    div = 10;
    while (diff%div != diff){
        digits++;
        div *= 10;
    }
    return num + 3*pow(10,digits);
}