
//!st one
void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()) return -1;
        // Your Code   
    while(!s1.empty()){
        int val = s1.top();
        s1.pop();
        s2.push(val);
    }
    int ans = s2.top();
    s2.pop();
    while(!s2.empty()){
        int val = s2.top();
        s2.pop();
        s1.push(val);
    }
    return ans;
}


//2nd one
void StackQueue :: push(int x)
{
    // Your Code
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()) return -1;
    int c = s1.top();
    s1.pop();
    return c;
}