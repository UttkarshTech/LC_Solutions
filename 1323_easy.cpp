int maximum69Number (int num) {
    int c = 0, mc = 0, temp = num;
    while (temp){
        c++;
        if (temp%10 == 6 && c > mc)
            mc = c;
        temp /= 10;
    }
    if (!mc)
        return num;
    return num + 3 * pow(10, mc-1);
}