bool v1(){
	memcpy(tmp,cir,sizeof(cir));
	
	int enemy=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<12;j++){
			if(tmp[i][j]){
				enemy++;
			}
		}
	}
	
	int move=0;
	
	for(int i=0;i<12;i++){
		if(tmp[2][i] || tmp[3][i]){
			for(int j=0;j<4;j++){
				tmp[j][i]=0;
			}
			
			move++;
		}
	}
	
	int hammer=0;
	//situation one, zero follow left
	for(int i=1;i<12;i++){
		int nxt=(i+1)%12;
		if(tmp[0][i] || tmp[1][i]){
			tmp[0][i]=tmp[1][i]=tmp[0][nxt]=tmp[1][nxt]=0;
			
//			cout<<" at "<<i<<endl;
			hammer++;
		}
	}
	
	int i=0;
	int nxt=(i+1)%12;
	if(tmp[0][i] || tmp[1][i]){
		tmp[0][i]=tmp[1][i]=tmp[0][nxt]=tmp[1][nxt]=0;
		
//		cout<<" at "<<i<<endl;
		hammer++;
	}
//	cout<<"Function 1:"<<move<<" "<<hammer<<endl;
	return move+hammer<=(enemy+3)/4;
	
}

bool v2(){
	memcpy(tmp,cir,sizeof(cir));
	
	int enemy=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<12;j++){
			if(tmp[i][j]){
				enemy++;
			}
		}
	}
	
	int move=0;
	
	for(int i=0;i<12;i++){
		if(tmp[2][i] || tmp[3][i]){
			for(int j=0;j<4;j++){
				tmp[j][i]=0;
			}
			
			move++;
		}
	}
	
	//situation two, zero follow right
	int hammer=0;
	for(int i=0;i<12;i++){
		if(tmp[0][i] || tmp[1][i]){
			int nxt=(i+1)%12;
			tmp[0][i]=tmp[1][i]=tmp[0][nxt]=tmp[1][nxt]=0;
			
			hammer++;
		}
	}
	
//	cout<<"Function 2:"<<move<<" "<<hammer<<endl;
	return move+hammer<=(enemy+3)/4;
}


bool checkValid(){
	return v1() || v2();
}
