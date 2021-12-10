#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getindex(vector<int> list, int value,int i){
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

int getNumberOfsub(vector<int> list, vector<int> len ,int value){
	int i = 0, index, total = 0;
	while((index = getindex(list, value, i)) != -1){
		total = total + len[index];
		i = index + 1;
	}
	return total;
}


int algoritmo1(vector<int> list){
	int i, j, n = list.size();
	vector<int> newList1, newList2;
	newList1.resize(n);
	newList2.resize(n);
	memset(&newList1, 1, sizeof(int));
	memset(&newList2, 1, sizeof(int));
	for (i = 1; i < n - 1; i++){
		for (j = 0; j < i - 1; j++){
			if (list[i] > list[j]){
				if (newList1[j] + 1 > newList1[i]){
					newList1[i] = newList1[j] + 1;
					newList2[i] = newList2[j];
				} else if (newList1[j] + 1 == newList1[i])
					newList2[i] += newList2[j];
			}
		}
	}
	for (i = 0; i < n; i++){
		printf("%d\n", newList1[i]);
	}
	printf("próxima\n");
	for (i = 0; i < n; i++){
		printf("%d\n", newList2[i]);
	}

	int value = max_element(newList1);
	int numOflists = getNumberOfsub(newList1 , newList2, value);
	printf("%d %d\n", value , numOflists);
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

