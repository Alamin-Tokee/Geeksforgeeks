class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool isPal(string s)
{
	int i = 0;
	int j = s.size() - 1;
	
	while (i < j)
	{
		if (s[i ++] != s[j --])
			return false;
	}
	
	return true;
}

bool palindromepair(int N, string arr[]) {
	map<char, vector<int>> endWith;
	
	for (int i = 0; i < N; ++i)
	{
		endWith[arr[i].back()].push_back(i);
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j : endWith[arr[i][0]])
		{
			if (i == j)
				continue;
				
			if (isPal(arr[i] + arr[j]))
				return true;
		}
	}
	
	return false;
}

};
