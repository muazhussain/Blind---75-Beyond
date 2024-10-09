// Problem link: https://www.naukri.com/code360/problems/1062679
// Time: O(log(m + n))
// Space: O(1)

int checker(int num, int n, int m) {
    long long res = 1;
    while(n--) {
        res *= num;
        if(res > m) {
            return 2;
        }
    }
    if(res == m) {
        return 1;
    }
    return 0;
}

int NthRoot(int n, int m) {
    int low = 1, high = m;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int check = checker(mid, n, m);
        if(check == 1) {
            return mid;
        } else if(check == 2) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}