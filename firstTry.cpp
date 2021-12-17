#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int getindex(vector<int> list, int value,int i){
	while(i < list.size()){      /*O(n)*/
		if(list[i] == value)
			return i;
		i++;
	}
	return -1;
}


int getNumberOfsub(vector<int> list, vector<int> len ,int value){
	int i = 0, index, total = 0;
	while((index = getindex(list, value, i)) != -1){      /*O(n*n)*/
		total = total + len[index];
		i = index + 1;
	}
	return total;
}


int algorithm1(vector<int> list){
	int i, j, maxLen = 1 ,n = list.size();
	vector<int> lensList, numberOfSubs;
	lensList.resize(n);
	numberOfSubs.resize(n);
	for(i = 0; i < n; i++){     /*O(n)*/
		lensList[i] = 1;
		numberOfSubs[i] = 1;
	}
	for (i = 1; i < n ; i++){         
		for (j = 0; j < i ; j++){	/*O(n*n)*/
			if (list[i] > list[j]){
				if (lensList[j] + 1 > lensList[i]){
					lensList[i] = lensList[j] + 1;
					if(lensList[i] > maxLen)
						maxLen = lensList[i];
					numberOfSubs[i] = numberOfSubs[j];
				} else if ((lensList[j] + 1) == lensList[i])
					numberOfSubs[i] += numberOfSubs[j];
			}
		}
	}

	int numOflists = getNumberOfsub(lensList , numberOfSubs, maxLen); /*O(n*n)*/
	printf("%d %d\n", maxLen , numOflists);
	return 0;
}


int algorithm2(vector<int> list1, vector<int> list2){
	int i, j, maxLen = 0;
	int sizeList1 = list1.size();
	int sizeList2 = list2.size();
	vector<int> lensList;

	if(sizeList1 > sizeList2)
		lensList.resize(sizeList1);
	else
		lensList.resize(sizeList2);

	for(i = 0; i < lensList.size(); i++){     /*O(n)*/
		lensList[i] = 0;
	}

	for(i = 0; i < sizeList1; i++){
		int currSize = 0;

		for(j = 0; j < sizeList2; j++){        /*O(n*n)*/

			if (list1[i] == list2[j] && currSize + 1 > lensList[j])
                lensList[j] = currSize + 1;
 
            if (list1[i] > list2[j] && lensList[j] > currSize){
            	currSize = lensList[j];
            	if(currSize > maxLen)
            		maxLen = currSize;
            }
		}
	}

	printf("%d\n",maxLen);
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
		algorithm1(list);
	}
	if(c == '2'){
		vector<int> list2;
		getchar();
		while (scanf("%d", &c) == 1 && getchar() != '\n'){      /*O(n)*/
			list.push_back(c);
		}
		list.push_back(c);
		while (scanf("%d", &c) == 1 && getchar() != '\n'){      /*O(n)*/
			list2.push_back(c);
		}
		list2.push_back(c);

		algorithm2(list,list2);
	}
	return 0;
}

