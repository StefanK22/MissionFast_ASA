#include <vector>
#include <algorithm>

using namespace std;


int algoritm(vector<int> list){
	int i=0, j=1;
	vector<int> newList;
	newList.resize(5);
	while(i<list.size()){
		newList[i]=1;
		i++;
	}
	while(j<list.size()){
		i=0;
		while(j>i){
			if(list[i]<list[j]){
				newList[j]=max(newList[i]+1,newList[j]);
			}
			i++;

		}
		j++;
		
	}
	i=0;
	while(i<newList.size()){
		printf("%d\n",newList[i]);
		i++;
	}
	return 0;
}

int main(){
	vector<int> list;
	list.resize(5);
	for(int i=0;i<5;i++){
		scanf("%d", &list[i]);
	}
	algoritm(list);
	return 0;
}