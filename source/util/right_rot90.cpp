vector<string> right_rot90(vector<string>S){
	int N = S.size();
	vector<string>ret(N, string(N,'.'));
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)ret[i][j]=S[N-1-j][i];
	return ret;
}