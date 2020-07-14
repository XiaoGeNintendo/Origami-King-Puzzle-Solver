#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)

bool debug=true;

/*    *************************************
	  * Written in New Computer           *
	  * The following code belongs to     *
	  * XiaoGeNintendo of HellHoleStudios *
	  *************************************
*/
template<typename T1,typename T2>ostream& operator<<(ostream& os,pair<T1,T2> ptt){
	os<<ptt.first<<","<<ptt.second;
	return os;
}
template<typename T>ostream& operator<<(ostream& os,vector<T> vt){
	os<<"{";
	for(int i=0;i<vt.size();i++){
		os<<vt[i]<<" ";
	}
	os<<"}";
	return os;
}

int cir[5][13];

const int DEPTH=3;

struct Move{
	int mode;
	int target;
	int count;
};
vector<Move> mvs;

vector<vector<Move>> ans;

Move make_move(int mode,int target,int count){
	Move mv;
	mv.mode=mode;
	mv.target=target;
	mv.count=count;
	
	return mv;
}

const int ROTATE=0,MOVE=1;

void printWay(vector<Move>& mvs){
	cout<<"============================================"<<endl;
	cout<<"Solved in "<<mvs.size()<<" steps"<<endl;
	for(Move x:mvs){
		if(x.mode==ROTATE){
			if(x.count+1<=6){
				cout<<"Rotate Circle "<<x.target+1<<" Clockwise "<<x.count+1<<" times"<<endl;	
			}else{
				cout<<"Rotate Circle "<<x.target+1<<" Counterclockwise "<<12-(x.count+1)<<" times"<<endl;
			}
			
		}else{
			if(x.count+1<=4){
				cout<<"Swap Line "<<x.target+1<<" Innerwise "<<x.count+1<<" times"<<endl;	
			}else{
				cout<<"Swap Line "<<x.target+1<<" Outerwise "<<8-(x.count+1)<<" times"<<endl;
			}
			
		}
	}
	cout<<"============================================"<<endl;
} 

int tmp[5][13];

//function related to validating
#include "valid.h"

void dfs(int step,int last,int move){
//	cout<<"Current Status:"<<endl;
//	printWay();
//	for(int i=3;i>=0;i--){
//		for(int j=0;j<12;j++){
//			cout<<cir[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	//check current way
	if(checkValid()){
		ans.push_back(mvs);
		return;
	}
	if(step==0){
		return;
	}
	
	//rotate
	for(int i=0;i<4;i++){
		if(last==0 && move==i){
			continue;
		}
		
		for(int j=0;j<12;j++){
			//move by right
			//0 1 2 3 4
			//
			int first=cir[i][11];
			for(int k=11;k>=1;k--){
				cir[i][k]=cir[i][k-1];
			}
			cir[i][0]=first;
			
			mvs.push_back(make_move(ROTATE,i,j));
			dfs(step-1,0,i);
			mvs.pop_back();
		}
	}
	
	//swap
	for(int i=0;i<6;i++){
		if(last==1 && move==i){
			continue;
		}
		
		for(int j=0;j<8;j++){
			int par=(i+6)%12;
			int first=cir[3][par];
			/*
			0
			0
			1
			1
			--
			1
			1
			0
			0
			*/
			
			cir[3][par]=cir[2][par];
			cir[2][par]=cir[1][par];
			cir[1][par]=cir[0][par];
			cir[0][par]=cir[0][i];
			cir[0][i]=cir[1][i];
			cir[1][i]=cir[2][i];
			cir[2][i]=cir[3][i];
			cir[3][i]=first;
			
			mvs.push_back(make_move(MOVE,i,j));
			dfs(step-1,1,i);
			mvs.pop_back();
		}
	}
}

bool cmp(vector<Move>& a,vector<Move>& b){
	return a.size()<b.size();
}

int main(int argc,char* argv[]){
	cout<<"Origami King puzzle solver"<<endl;
	cout<<"File format: 4 lines 12 columns of 0 and 1. lower=inner circles. upper= outer circles. circles in clockwise."<<endl;
	 
	if(argc<2){
		cout<<"Reading from puzzle.txt. Give me file name to use next time."<<endl;
		freopen("puzzle.txt","r",stdin);
	}else{
		freopen(argv[1],"r",stdin);
	}
	
	
	for(int i=3;i>=0;i--){
		string s;
		cin>>s;
		for(int j=0;j<12;j++){
			cir[i][j]=s[j]-'0';
		}
	}
	
//	cout<<checkValid()<<endl;
	
	freopen("CON","r",stdin);
	
	dfs(DEPTH,-1,-1);
	
	cout<<"Found "<<ans.size()<<" Solutions"<<endl;
	sort(ans.begin(),ans.end(),cmp);
	
	for(int i=0;i<ans.size();i++){
		printWay(ans[i]);
		char c=getch();
		if(c=='e' || c=='E'){
			break;
		}
	}
	return 0;
}


