#include<iostream>
#include <string>
using namespace std;

//heige number conditions//这个函数要可以判断某个数字黑格旁边的灯数量对不对
bool Black_Cell_Number_Constraint(int*D,bool**C,int count,int row,int column){
	//for(int t=0;t<count;t++){
		int i=D[0];//row
		int j=D[1];//column
		int k=D[2];//number
		int num=0;//数字旁边的灯的个数
		if(i==0){//数字要是在第一行
			if(j==0){//同时在第一列
				if(C[0][1]==true) num++;//bool **C是放没放灯的数组
				if(C[1][0]==true) num++;
			}
			else if(j==column-1){//灯在最后一列
				if(C[0][column-2]==true) num++;
				if(C[1][column-1]==true) num++;
			}
			else{//灯不在首尾两列
				if(C[0][j-1]==true) num++;
				if(C[0][j+1]==true) num++;
				if(C[1][j]==true) num++;
			}
		}
		else if(i==row-1){//数字要是在最后一行
			if(j==0){
				if(C[row-2][0]==true) num++;
				if(C[row-1][1]==true) num++;
			}
			else if(j==column-1){
				if(C[row-1][column-2]==true) num++;
				if(C[row-2][column-1]==true) num++;
			}
			else{
				if(C[row-1][j-1]==true) num++;
				if(C[row-1][j+1]==true) num++;
				if(C[row-2][j]==true) num++;
			}
		}
		else{
			if(j==0){
				if(C[i-1][0]==true) num++;
				if(C[i+1][0]==true) num++;
				if(C[i][1]==true) num++;
			}
			else if(j==column-1){
				if(C[i-1][j]==true) num++;
				if(C[i+1][j]==true) num++;
				if(C[i][j-1]==true) num++;
			}
			else{
				if(C[i][j-1]==true) num++;
				if(C[i][j+1]==true) num++;
				if(C[i-1][j]==true) num++;
				if(C[i+1][j]==true) num++;
			}
		}
		if(num!=k){//判断黑格数字旁边四个格子里放了灯的个数是否等于数字
			return false;
		}
	return true;
}

//当数字黑格3在矩阵内部时，放能放的灯
void Number_three(int**D,bool**C,bool**B,bool**F,int count,int row,int column){
	for(int m=0;m<count;m++){
		if(D[m][2]==3){
			int i=D[m][0];
			int j=D[m][1];
			if(i!=0&&i!=row-1&&j!=0&&j!=column-1){
				if(B[i][j-1]==false||F[i][j-1]==false){
					C[i][j+1]=true;
					C[i-1][j]=true;
					C[i+1][j]=true;
				}
				if(B[i][j+1]==false||F[i][j+1]==false){
					C[i][j-1]=true;
					C[i-1][j]=true;
					C[i+1][j]=true;
				}
				if(B[i-1][j]==false||F[i-1][j]==false){
					C[i][j-1]=true;
					C[i][j+1]=true;
					C[i+1][j]=true;
				}
				if(B[i+1][j]==false||F[i+1][j]==false){
					C[i][j-1]=true;
					C[i][j+1]=true;
					C[i-1][j]=true;
				}
			}
		}
	}
}

//给数字为2的黑格放能放的灯,不考虑黑格在四个角的情况
void Number_two(int**D,bool**C,bool**B,bool**F,int count,int row,int column){
	for(int m=0;m<count;m++){
		if(D[m][2]==2){//只考虑数字2
			int i=D[m][0];//row
			int j=D[m][1];//column
			if(i==0){
				if(j>0&&j<row-1){
					if(B[i][j-1]==false||F[i][j-1]==false){
						C[i][j+1]=true;
						C[i+1][j]=true;
					}
					if(B[i][j+1]==false||F[i][j+1]==false){
						C[i][j-1]=true;
						C[i][j]=true;
					}
					if(B[i+1][j]==false||F[i+1][j]==false){
						C[i][j-1]=true;
						C[i][j+1]=true;
					}
				}
			}
			else if(i==row-1){
				if(j>0&&j<row-1){
					if(B[i][j-1]==false||F[i][j-1]==false){
						C[i][j+1]=true;
						C[i-1][j]=true;
					}
					if(B[i][j+1]==false||F[i][j+1]==false){
						C[i][j-1]=true;
						C[i-1][j]=true;
					}
					if(B[i-1][j]==false||F[i-1][j]==false){
						C[i][j-1]=true;
						C[i][j+1]=true;
					}
				}
			}
			else{
				if(j==0){
					if(B[i-1][j]==false||F[i-1][j]==false){
						C[i][j+1]=true;
						C[i+1][j]=true;
					}
					if(B[i][j+1]==false||F[i][j+1]==false){
						C[i-1][j]=true;
						C[i+1][j]=true;
					}
					if(B[i+1][j]==false||F[i+1][j]==false){
						C[i-1][j]=true;
						C[i][j+1]=true;
					}
				}
				else if(j==column-1){
					if(B[i-1][j]==false||F[i-1][j]==false){
						C[i][j-1]=true;
						C[i+1][j]=true;
					}
					if(B[i][j-1]==false||F[i][j-1]==false){
						C[i-1][j]=true;
						C[i+1][j]=true;
					}
					if(B[i+1][j]==false||F[i+1][j]==false){
						C[i-1][j]=true;
						C[i][j-1]=true;
					}
				}
				else{//不在矩阵边界
					if(B[i][j-1]==false||F[i][j-1]==false){//left can't 放灯
						if(B[i-1][j]==false||F[i-1][j]==false){//top can't放灯
							C[i][j+1]=true;
							C[i+1][j]=true;
						}
						if(B[i][j+1]==false||F[i][j+1]==false){//right can't
							C[i-1][j]=true;
							C[i+1][j]=true;
						}
						if(B[i+1][j]==false||F[i+1][j]==false){//down can't
							C[i-1][j]=true;
							C[i][j+1]=true;
						}
					}
					else{ //left can
					    if(B[i-1][j]==false||F[i-1][j]==false){//top can't
						  if(B[i][j+1]==false||F[i][j+1]==false){//right can't
							C[i+1][j]=true;
							C[i][j-1]=true;
						  }
						  if(B[i+1][j]==false||F[i+1][j]==false){//down can't
							C[i][j+1]=true;
							C[i][j-1]=true;
						  }
					    }
					    else{//top can
					    	if((B[i][j+1]==false||F[i][j+1]==false)&&(B[i+1][j]==false||F[i+1][j]==false)){//right and down can't
					    		C[i][j-1]=true;
					    		C[i-1][j]=true;
							}
						}
			    	}
			    }
			}
		}
	}
}

//此函数用处是给数字黑格放一定要放的灯
void Black_Cell_Number_Putlight(int**D,bool**C,bool**B,bool**F,int count,int row,int column){
	for(int m=0;m<count;m++){
		//number==0
		if(D[m][2]==0){
			int ii=D[m][0];//数字黑格行数
			int jj=D[m][1];//数字列数
			if(ii==0){//数字要是在第一行
			    if(jj==0){//灯在第一列
			       F[0][1]==false;
			       F[1][0]==false;
				}
			    else if(jj==column-1){//灯在最后一列
			        F[0][jj-1]==false;
			        F[1][jj]==false;
			    }
			    else{//灯不在首尾两列
			         F[0][jj-1]==false;
			         F[0][jj+1]==false;
			         F[1][jj]==false;
			        }
		    }
		    else if(ii==row-1){//数字要是在最后一行
			        if(jj==0){
			        	F[ii-1][0]==false;
			        	F[ii][1]==false;
			        }
			        else if(jj==column-1){
			        	F[ii][jj-1]==false;
			        	F[ii-1][jj]==false;
			        }
			        else{
			        	F[ii][jj-1]==false;
			        	F[ii][jj+1]==false;
			        	F[ii+1][jj]==false;
		        	}
		        }
		    else{
			    if(jj==0){
			    	F[ii-1][jj]==false;
			    	F[ii+1][jj]==false;
			    	F[ii][jj+1]==false;
			      }
			    else if(jj==column-1){
			    	F[ii-1][jj]==false;
			    	F[ii+1][jj]==false;
			    	F[ii][jj-1]==false;
		        }
		    	else{
		    		F[ii][jj-1]==false;
		    		F[ii][jj+1]==false;
		    		F[ii-1][jj]==false;
		    		F[ii+1][jj]==false;
			     }
	     	}
		}
		//number==4
		if(D[m][2]==4){
			int ii=D[m][0];//数字黑格行数
			int jj=D[m][1];//数字列数
			C[ii-1][jj]=true;
			C[ii+1][jj]=true;
			C[ii][jj-1]=true;
			C[ii][jj+1]=true;
		}
		//number==3
		if(D[m][2]==3){
			int ii=D[m][0];//row
			int jj=D[m][1];//column
			if(ii==0){
				C[ii][jj-1]=true;
				C[ii][jj+1]=true;
				C[ii+1][jj]=true;
			}
			else if(ii==row-1){
				C[ii][jj-1]=true;
				C[ii][jj+1]=true;
				C[ii-1][jj]=true;
			}
			else{
				if(jj==0){
					C[ii-1][jj]=true;
					C[ii+1][jj]=true;
					C[ii][jj+1]=true;
				}
				else if(jj=column-1){
					C[ii][jj-1]=true;
					C[ii-1][jj]=true;
					C[ii+1][jj]=true;
				}
				//以上都是黑格在矩阵的边界，旁边只有三个位置可以放灯，则必须放灯
				else{
					//此时黑格在矩阵内部//设计一个函数Number_3，当黑格旁边是黑格或者不能放灯的情形
					Number_three(D,C,B,F,count,row,column);
				}
			}
		}
		//number==2
		if(D[m][2]==2){
			int i=D[m][0];//row
			int j=D[m][1];//column
			//i==0
				if(i==0&&j==0){
					C[0][1]=true;
					C[1][0]=true;
				}
				else if(i=00&&j==column-1){
					C[i][j-1]=true;
					C[i+1][j]=true;
				}
			//i==row-1
				else if(i==row-1&&j==0){
					C[i-1][j]=true;
					C[i][j+1]=true;
				}
				else if(i==row-1&&j==column-1){
					C[i][j-1]=true;
					C[i-1][j]=true;
				}
			    else{
			    	Number_two(D,C,B,F,count,row,column);
			    }
		}
	}
}

//放灯的约束条件，不能相互照射，注意要考虑黑格遮挡
bool Light_Bulb_Constraint(bool**C,bool**B,bool**E,int row,int column){
	bool judge=true;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(C[i][j]==true){//此位置是light
			    int ii=i-1;
	            int jj=j;
	            while(ii>=0&&B[ii][jj]==true){
		            if(C[ii][jj]){//同一行有灯泡
		            	judge=false;
		            	break;
					}
		            ii--;//left
	            }
	
	            ii=i+1;
	            jj=j;
	            while(ii<row&&B[ii][jj]==true){//同上，往右判断
		            if(C[ii][jj]){//同一行有灯泡
		            	judge=false;
		            	break;
					}
		            ii++;//向右
	            }
	
	            ii=i;
	            jj=j-1;
	            while(jj>=0&&B[ii][jj]==true){//同上，判断列数
		            if(C[ii][jj]){//同一列有灯泡
		            	judge=false;
		            	break;
					}
		            jj--;
	            }
	   
	            ii=i;
	            jj=j+1;
	            while(jj<column&&B[ii][jj]==true){
		            if(C[ii][jj]){//同一列有灯泡
		            	judge=false;
		            	break;
					}
		            jj++;
	            }
			    
			}
		}
	}
	
	return judge;
}
//这个函数用来判断是否成功解题————数字黑格旁边要有相应数字的灯，灯不能相互照亮，所有空格都要被点亮
bool Success_Conditions(int**D,bool**C,bool**B,bool**E,int count,int row,int column){
	bool heige_number=true;
	for(int i=0;i<count;i++){
		if(Black_Cell_Number_Constraint(D[i],C,count,row,column)==false){
			heige_number=false;
			break;
		}
	}
	bool light=Light_Bulb_Constraint(C,B,E,row,column);
	bool a=true;
	if(heige_number==false) a=false;
	if(light==false) a=false;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(B[i][j]==true){//这个位置不是黑格，需要被点亮
				if(E[i][j]==false){//没有被点亮，则还没有成功解出
					a=false;
					break;
				}
			}
		}
	}
	return a;
}

//放置灯泡,点亮
void place_light(bool**C,int i,int j,bool**E,bool**B,int row,int column){
	C[i][j]=true;
	int ii=i;
	int jj=j;
	while(ii>=0&&B[ii][jj]==true){
		E[ii][jj]=true;
		ii--;//向左
	}
	
	ii=i;
	while(ii<row&&B[ii][jj]==true){//同上，往右判断
		E[ii][jj]=true;
		ii++;//向右
	}
	
	ii=i;
	while(jj>=0&&B[ii][jj]==true){//同上，判断列数
		E[ii][jj]=true;
		jj--;
	}
	
	jj=j;
	while(jj<column&&B[ii][jj]==true){
		E[ii][jj]=true;
		jj++;
	}
}
//撤销灯泡
void remove_light(bool**C,int i,int j,bool**E,bool**B,int row,int column){
	C[i][j]=false;
	int ii=i;
	int jj=j;
	while(ii>=0&&B[ii][jj]==true){
		E[ii][jj]=false;
		ii--;//向左
	}
	
	ii=i;
	while(ii<row&&B[ii][jj]==true){//同上，往右判断
		E[ii][jj]=false;
		ii++;//向右
	}
	
	ii=i;
	while(jj>=0&&B[ii][jj]==true){//同上，判断列数
		E[ii][jj]=false;
		jj--;
	}
	
	jj=j;
	while(jj<column&&B[ii][jj]==true){
		E[ii][jj]=false;
		jj++;
	}
}

//回溯函数
bool Backtrace(int**D,bool**C,bool**B,bool**E,bool**F,int count,int row,int column){
	//若已经解决，返回成功
	if(Success_Conditions(D,C,B,E,count,row,column)) return true;
	
	//找到第一个未确定的空白格（非黑格、非禁止、非灯泡、未照亮）
	int x=-1;//row
	int y=-1;//column
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(B[i][j]==true&&F[i][j]==true&&C[i][j]==false&&E[i][j]==false){
				x=i;
				y=i;
				break;
			}
		}
	}
	
	//没有找到上述点，但是问题未解决，说明无解
	if(x==-1) return false;
	
	//尝试1：在（x,y）放置灯泡
	place_light(C,x,y,E,B,row,column);
	if(Light_Bulb_Constraint(C,B,E,row,column)){
		if(Backtrace(D,C,B,E,F,count,row,column)) return true;
	}
	else remove_light(C,x,y,E,B,row,column);
	
	//尝试2，不在（x,y）放置灯泡
	F[x][y]=false;
	if(Backtrace(D,C,B,E,F,count,row,column)) return true;
	
	return false;
}

void Akari_solve(int row,int column,string s){
	//1.read input
	char**Akari = new char*[row];//put in char
	bool**B = new bool*[row];//B==TRUE ,not heige,B==false, is heige
	bool**C = new bool*[row];//had or hadn't put light
	bool**E = new bool*[row];//is or isn't be lighted
	bool**F = new bool*[row];//can or can't put light
	int len;
	int count=0;
	int**D = new int*[len];// heige number and site
	for(int i=0;i<len;i++){
		D[i]=new int[3];
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			Akari[i][j]=s[i*column+j];
			C[i][j]=false;
			E[i][j]=false;
			if(Akari[i][j]=='.'){
				B[i][j]=true;
				F[i][j]=true;
			}
			else if(Akari[i][j]=='X'){
				B[i][j]=false;
				F[i][j]=false;
			}
			else{
				B[i][j]=false;
				F[i][j]=false;
				int num=int(Akari[i][j]);
				D[count][0]=i;//number's row
				D[count][1]=j;//number's column
				D[count][2]=num;
				count++;//totall
			}
			cout<<Akari[i][j]<<" ";
		}
		cout<<endl;
	}
	//2. initial constraint conditions
	 //number//Black_Cell_Number_Constraint()
	 //light//Light_Bulb_Constraint()
	 
	//3.logical把能一定能放灯的放灯，不能的别放
	Black_Cell_Number_Putlight(D,C,B,F,count,row,column);//把数字黑格旁边能放灯的位置都放了
	
	//4.again and again回溯，逐个尝试，直到点亮所有点,以及输出
	if(Backtrace(D,C,B,E,F,count,row,column)){//回溯函数
	//ouput//"string ss;cout<<ss;"is right.
	    for(int i=0;i<row;i++){
		    for(int j=0;j<column;j++){
			    if(C[i][j]==true) Akari[i][j]='L';
			   // cout<<Akari[i][j];
		    }
	    }
    }
    else cout<<"No answer!";
}

int main(){
	int row,column;
	string input;
	cin>>row>>column;
	cin>>input;
	Akari_solve(row,column,input);
	return 0;
}