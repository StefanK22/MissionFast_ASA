#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getindex(vector<int> list, int value){
	int i=0;
	while(i<list.size()){
		if(list[i]==value)
			return i;
		i++;
	}
	return -1;
}

int max_element(vector<int> list){
	int i=0,max=0;
	while(i<list.size()){
		if(list[i]>max){
			max = list[i];
		}
		i++;
	}
	return max;
}

int howMany(vector<int> list, int value){
	int i=0,total=0;
	while(i<list.size()){
		if(list[i]==value){
			total++;
		}
		i++;
	}
	return total;
}

int algoritmo1(vector<int> list){
	int i=0, j=1;
	vector<int> newList;
	newList.resize(list.size());
	while(i<list.size()){
		newList[i]=1;
		i++;
	}
	while(j<list.size()){
		i=0;
		while(j>i){
			printf("%d<%d\n",list[i],list[j]);
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
	int value = max_element(newList);
	printf("%d %d\n",value,howMany(newList, value));
	return 0;
}


int main(){
	vector<int> list;
	int i = 0, c = getchar();
	if(c  == '1'){
		getchar();
		while ((c = getchar()) != '\n'){
			list.resize(i+1);
			list[i++] = c - '0';
			if ((c = getchar()) == '\n') // ignora o espaço
				break;
		}	
		algoritmo1(list);
	}
	if(c == '2'){
		getchar();
		printf("algoritmo 2");
	}
	return 0;
}

