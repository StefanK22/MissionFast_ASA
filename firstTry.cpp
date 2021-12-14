#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int algoritmo1(vector<int> list){
	int i, j, value = 1, numOflists = 0,n = list.size();
	vector<int> newList1, newList2;
	newList1.resize(n);
	newList2.resize(n);
	//memset(&newList1, 1, sizeof(int));
	//memset(&newList2, 1, sizeof(int));
	for(i = 0; i < n; i++){
		newList1[i] = 1;
		newList2[i] = 1;
	}
	for (i = 1; i < n ; i++){
		for (j = 0; j < i ; j++){
			if (list[i] > list[j]){
				if (newList1[j] + 1 > newList1[i]){
					newList1[i] = newList1[j] + 1;
					if(newList1[i] > value){
						value = newList1[i];
						numOflists = i;
					}
					newList2[i] = newList2[j];
				} else if ((newList1[j] + 1) == newList1[i])
					newList2[i] += newList2[j];
			}
		}
	}
	printf("list1\n");
	for (i = 0; i < n; i++){
		printf("%d\n", newList1[i]);
	}
	printf("list2\n");
	for (i = 0; i < n; i++){
		printf("%d\n", newList2[i]);
	}

	
	printf("%d %d\n", value , newList2[numOflists]);
	return 0;
}


int algoritmo2(vector<int> list1, vector<int> list2){
	int i, j, total = 0;
	int size1 = list1.size();
	int size2 = list2.size();
	vector<int> newList;
	if(size1 > size2)
		newList.resize(size1);
	else
		newList.resize(size2);

	for(i = 0; i < newList.size(); i++){
		newList[i] = 0;
	}

	for(j=0; i<size1; i++){
		int currSize = 0;

		for(i=0; j<size2; j++){

			if (list1[i] == list2[j] && currSize + 1 > newList[j])
                newList[j] = currSize + 1;
 
            if (list1[i] > list2[j] && newList[j] > currSize){
            	currSize = newList[j];
            	if(currSize > total)
            		total = currSize;
            }
		}
	}

	printf("%d\n",total);
	return 0;
}


int main(){
	vector<int> list;
	int c = getchar();
	if(c  == '1'){
		while (scanf("%d", &c) == 1 && getchar() != '\n'){
			list.push_back(c);
		}
		list.push_back(c);
		algoritmo1(list);
	}
	if(c == '2'){
		getchar();
		printf("algoritmo 2");
	}
	return 0;
}

