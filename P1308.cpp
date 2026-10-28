#include<iostream>
using namespace std;

char getanother(char a){
	char ans;
	if('a' <= a and a <= 'z'){
		ans = 'A' + a - 'a';
	}else if('A' <= a and a <= 'Z'){
		ans =  'a' + a - 'A';
	}else{
		ans = '?';
	}
	//cout<<"getanother"<<a<<" "<<ans<<endl;
	return ans;
}

int main(){
	string target;
	cin>>target;
	string article;
	cin.ignore();
	getline(cin,article);
	char trying;
	char ft = target[0];
	char _ft = getanother(ft);
	int num = 0;
	bool first = false;
	int index = 0;
	bool new_word = true;
	for(int i = 0;i < article.length();++i){
		
		trying = article[i];
		bool p = 1;
		if(trying == ' '){new_word = 1;}
		else if((trying == ft or trying ==_ft) and new_word){
			//cout<<"匹配到1"<<endl;
			for(int j = 1;j < target.length();++j){
				if(!(target[j]==article[i+j] or target[j]==getanother(article[i+j]))){
					p = 0;
					
					
				}
			}
			if(p and (article[i + target.length()]==' ' or i+target.length()>=article.length())){
				if(!first){
					first = 1;
					index = i;
					num = 1;
				}else{
					num++;
				}
			}
		}else{
			new_word = 0;
		}
		
	}
	if(first){
		cout<<num<<" "<<index<<endl;
	}else{
		cout<<-1;
	}
}
