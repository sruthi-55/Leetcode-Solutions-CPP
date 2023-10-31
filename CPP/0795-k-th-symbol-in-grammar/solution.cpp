class Solution {
public:
    //based on simple observations by looking at examples
    int kthGrammar(int N, int K) {
        if(N == 1 && K == 1)
            return 0;

        int mid = pow(2, N-1)/2;
        if(K <= mid)
            return kthGrammar(N-1, K);
        
        return !kthGrammar(N-1, K-mid);
    }
};
