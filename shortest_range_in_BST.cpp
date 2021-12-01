class pqElement{
public:
	int value,index,listNum;
	pqElement(int val,int idx,int listNum){
		this->val=val;
		this->index=idx;
		this->listNum=listNum;
	}
};

class compare{
public:
	inline bool operator()(pqElement &p,pqElement &q){
		return p.value > q.value;
	}
}

class Solution{
public:
	pair<int,int>getPair(vector<vector<int>>lists){
		priority_queue<pqElement,vector<pqElement>,compare>pq;
		const int inf=1e9+7;
		pair<int,int>res=make_pair(0,inf);
		int n=lists.size();
		int maxValue=0;
		int minValue=inf;
		for(int i=0;i<n;i++){
			pq.push(pqElement(nums[i][0],0,i));
			maxValue=maxValue(maxValue,nums[i][0]);
		}

		while(true){
			pqElement curr=pq.top();
			minValue=curr.value;
			int index=curr.index;
			int listNum=curr.listNum;
			if((res.second-res.first) > (maxValue-minValue)){
				res={minValue,maxValue};
			}
			if(index==(int)lists[listNum].size()-1){
				break;
			}
			pq.push(pqElement[listNum][index+1],index+1,listNum);
			maxValue=max(maxValue,lists[listNum][index]);
		}
		return res;
	}
	pair<int, int> shortestRange(Node *root) {
		vector<vector<int>>lists;
		queue<Node*>q;
		if(!root) q.push(root);

		while(!q.empty()){
			int q_size=q.size();
			vector<int>presentLevel;
			while(q_size>0){
				Node *node=q.front();
				q.pop();
				presentLevel.push_back(node->data);
				if(node->left){
					q.push(root->left);
				}
				if(node->right){
					q.push(root->right);
				}
				q_size-=1;
			}
			lists.push_back(presentLevel);
		}
		return getPair(lists);
	}
};

class Solution{
    
    public:

    // void levelList(Node *root,int level,vector<vector<int>>&lists){ 
    //     if(root==NULL) return;
    //     if(level >= lists.size()) lists.push_back(vector<int>());
    //     lists[level].push_back(root->data);
        
    //     levelList(root->left,level+1,lists);
    //     levelList(root->right,level+1,lists);
    // }
    int findDepth(Node *root)
    {
        if(root==NULL)
        return 0;
        return 1 + max(findDepth(root->left), findDepth(root->right));
        
    }
    pair<int, int> shortestRange(Node *root) {
        // Your code goes here
        queue<Node*> q;
        q.push(root);
        int l = root->data, r = root->data;
        int d = findDepth(root);
        
        vector<vector<int>> nums(d);
        int i = 0 ;
        while(!q.empty())
        {
            int size = q.size();
   
            
            
            while(size--)
            {
            
                Node* x = q.front();
                q.pop();
                nums[i].push_back(x->data);
                
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
                
            }
         ++i;
         
        }
     
        pair<int, int> ans;
        int gap = INT_MAX;
        set<pair<int, pair<int, int>>> st;
        for (int i = 0; i < nums.size(); ++i)
        {
            st.insert({nums[i][0], {i, 0}});
        }
        while (1)
        {
            pair<int, pair<int, int>> mini = *st.begin();
            auto it = st.end();
            --it;
            pair<int, pair<int, int>> maxi = *it;

            st.erase(st.begin());
            if (maxi.first - mini.first < gap)
            {
                gap = maxi.first - mini.first;
                ans.first = mini.first;
                ans.second = maxi.first;
            }
            if (mini.second.second + 1 >= nums[mini.second.first].size())
                break;
            st.insert({nums[mini.second.first][mini.second.second + 1], {mini.second.first, mini.second.second + 1}});
            
        }
        return ans;
    }
};


//Another getPair dunction
#defind pr pair<int,pair<int,int>>
pair<int,int>getPair(unordered_map<int,vector<int>>&arr){
	priority_queue<pr,vector<pr>,greater<pr>>pq;
	int mn=INT_MAX;
	int mx=INT_MIN;
	int range=INT_MAX;
	int low=0,high=0;
	for(int i=0;i<arr.size();i++){
		pq.push({arr[i][0],{i,0}});
		mn=min(arr[i][0],mn);
		mx=max(arr[i][0],mx);
	}
	while(true){
		auto curr=pq.top();
		pq.pop();
		int min_temp=curr.first;
		if(mx-min_temp < range){
			mn=min_temp;
			low=mn;
			high=mx;
			range=mx-mn;
		}
		int x=curr.second.first;
		int y=curr.second.second;
		if(y==arr[x].size()-1) break;

		pq.push({arr[x][y+1],{x,y+1}});
		if(mx < arr[x][y+1]){
			mx=arr[x][y+1];
		}
	}
	return {low,high};
}