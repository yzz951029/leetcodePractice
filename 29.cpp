class Solution {
public:
    int divide(int dividend, int divisor) {
        long long d1 = abs((long long) dividend);
        long long d2 = abs((long long) divisor);
        bool positive = true;
        /*if(d1 < 0 )
        {
             positive = !positive;
             d1 = -d1;
        }
        if(d2 < 0 )
        {
            positive = !positive;
            d2 = -d2;
        }*/
        long long res = 0;
        //int base = 1;
        long long temp[100];
        long long sum[100];
        sum[0] = 1;
        temp[0] = d2;
        int i = 0;
        for(;temp[i] <= d1;i++)
        {
            temp[i+1] = temp[i] + temp[i];
            sum[i+1] = sum[i] + sum[i];
        }
        --i;
        while(d1 >= d2)
        {
            if(d1 - temp[i] >= 0)
            {
                d1 -= temp[i];
                res +=sum[i];
            }
            i--;
        }
        if(res >= 2147483648)
            return ((dividend^divisor)>>31) ? (INT_MIN) : (INT_MAX);
        return ((dividend^divisor)>>31) ? (-res) : (res);
    }
};