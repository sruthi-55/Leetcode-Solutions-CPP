class Solution {
public:
    int scoreOfParentheses(string s) {
        //stack -- []
        // "(() (()))"
        // "((" -->  [-1,-1]
        // ")"  -->  [-1,1]
        // "((" -->  [-1,1,-1,-1]
        // ")"  -->  [-1,1,-1,1]
        // ")"  -->  [-1,1,2]
        // ")"  -->  [6]

        // -1 represents ( 
        //if "("    push -1 to stack
        //else: 
        //      if top==-1  pop(),push(1)
        //      else, pop() until -1 and add values 
        //              and then push(2*val)
        stack<int> st;
        for(auto i:s){
            if(i=='(')  st.push(-1);
            else{
                if(st.top()==-1){
                    st.pop();st.push(1);
                }
                else{
                    int val=0;
                    while(st.top()!=-1){
                        val+=st.top();st.pop();
                    }
                    st.pop();
                    st.push(2*val);
                }
            }
        }
        // "()()"
        // [1,1]
        int val=0;
        while(!st.empty())
            val+=st.top(),st.pop();
        return val;
    }
};
