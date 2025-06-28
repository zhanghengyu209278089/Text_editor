#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
void pause(){
	cout<<"Press any key to continue . . .";
	getch();
	return;
}
int main(){
	system("chcp 65001");
	system("cls");
	string psg;
	while(1){
		cout<<"| Ctrl + Save | Ctrl + Open |"<<endl;
		cout<<"`````````~`````````````~`````"<<endl;
		int cnt=1;
		cout<<setw(10)<<cnt<<"|  ";
		for (int i=0;i<psg.size();i++){
			if(psg[i]=='\n'){
				cout<<endl;
				cnt++;
				cout<<setw(10)<<cnt<<"|  ";
			}
			else cout<<psg[i];
		}
		cout<<endl;
		char ch=getch();
		if(ch=='\r') psg+='\n';
		else if(ch=='\b'&&!psg.empty()) psg.pop_back();
		else if(ch=='s'-'a'+1){
			cout<<"```````````````````````````"<<endl;
			cout<<"Save as :[";
			string fname;
			getline(cin,fname);
			ofstream fout(fname.c_str());
			if(!fout.good()){
				cout<<"Error saving file!"<<endl;
				pause();
			}
			fout<<psg;
			fout.close();
		}
		else if(ch=='o'-'a'+1){
			cout<<"```````````````````````````"<<endl;
			cout<<"Open file :[";
			string fname;
			getline(cin,fname);
			ifstream fin(fname.c_str());
			if(!fin.good()){
				cout<<"Error opening file!"<<endl;
				pause();
			}
			psg.clear();
			string tmp;
			while(getline(fin,tmp))
				psg+=tmp+"\n";
			if(!psg.empty()) psg.pop_back();
		}
		else if(isprint(ch)||ch=='\t') psg+=ch;
		system("cls");
	} 
	return 0;
}
