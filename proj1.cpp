/*
 * 1º Projeto ASA 2021/2022 - Tecnico de Lisboa
 * Grupo: TP022, Stefan Knutsen 99123, Tomás Nascimento 99128.
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 
 * Funtion that returns the index of the value (int value) from the list (vector<int> list) than starts from a given position (int i). 
 * Returns -1 if the value doesn't exists from the given position. 
 */
int getindex(vector<int> list, int value, int i){

	while(i < (int) list.size()){
		if(list[i] == value)
			return i;
		i++;
	}
	return -1;
}

/* 
 * Function that returns the sum of all the elements equal to a given value.
 */
int getNumberOfsub(vector<int> lensList, vector<int> numberOfSubs, int value){	
	int i = 0, index = 0, total = 0;
	while((index = getindex(lensList, value, i)) != -1){
		total = total + numberOfSubs[index];
		i = index + 1;
	}
	return total;
}

/*
 * Algorthm that receives a list and prints the number and lenght of the longest increasing subsequence.
 */
void algorithm1(vector<int> list){
	int i, j, n = list.size();
	int maxLen = 1; /* Stores the lenght of the longest increasing subsequence. */

	/* List that stores the lenght of each increasing subsequences. */
	vector<int> lensList(n, 1);

	/* List that stores the number of longest increasing subsequence. */
	vector<int> numberOfSubs(n , 1);
	/* Both lists are inicialized with ones. */
	
	for (i = 1; i < n ; i++){         
		for (j = 0; j < i ; j++){
			if (list[i] > list[j]){
				/* 
				 * If the current element of the lensList plus the 
				 * new element is bigger than the lenght of the subsequence 
				 * until the position i, then update the lenght of the subsequence 
				 * until the position i to the sum of the position j and one.
				 */ 
				if (lensList[j] + 1 > lensList[i]){
					lensList[i] = lensList[j] + 1;
					/* 
					 * Updates the biggest element of the lensList 
					 * (size of the longest increasing subsequence) 
					 */
					if(lensList[i] > maxLen)
						maxLen = lensList[i];
					/* 
					 * The number of subsequences until the position j will equal 
					 * to the number of subsequences until the position i, 
					 * because the element in i is bigger than the element in j. 
					 */
					numberOfSubs[i] = numberOfSubs[j];

				/* 
				 * If the current element of the lensList plus the 
				 * new element is equal to the lenght of the subsequence 
				 * until the position i, than the number of subsequence 
				 * until i is increased with the number of subsequences until j. 
				 */
				} else if ((lensList[j] + 1) == lensList[i])
					numberOfSubs[i] += numberOfSubs[j];
			}
		}
	}

	/* Obtains the number of longest increasing subsequence. */
	int numOflists = getNumberOfsub(lensList , numberOfSubs, maxLen);
	
	printf("%d %d\n", maxLen , numOflists);
}

/*
 * Algorthm that receives two lists and prints the lenght of the longest common increasing subsequence.
 */
void algorithm2(vector<int> list1, vector<int> list2){
	int i, j;
	int maxLen = 0; /* Stores the lenght of the longest increasing subsequence. */

	int sizeList1 = list1.size(); /* Size of the first list */
	int sizeList2 = list2.size(); /* Size of the second list */

	/* List that stores the lenght of each common increasing subsequences. */
	vector<int> lensList(max(sizeList1, sizeList2), 0);
	/* Initializes the lensList with zeros */


	for(i = 0; i < sizeList1; i++){
		int currSize = 0; /* Stores the size of the current subsequence. */
		for(j = 0; j < sizeList2; j++){
			/* 
			 * If the elements from the two lists are equal 
			 * and the lenght of the current subsequence plus the new 
			 * element is bigger than the lenght of the subsequence until j,
			 * then update the lenght of the subsequence until j. 
			 */
			if (list1[i] == list2[j] && currSize + 1 > lensList[j]){
                lensList[j] = currSize + 1;
					/* Updates the biggest element of the lensList 
					 * (size of the longest subsequence) 
					 */
				if(lensList[j] > maxLen)
            		maxLen = lensList[j];
			}

			/* Update the currSize to the lenght of the previous possible subsequence. */
            if (list1[i] > list2[j] && lensList[j] > currSize){
            	currSize = lensList[j];
				/* Updates the biggest element of the lensList 
				 * (size of the longest subsequence) 
				 */
            	if(currSize > maxLen)
            		maxLen = currSize;
            }
		}
	}

	printf("%d\n",maxLen);
}

/* Receive and process the input. */ 
int main(){
	
	/* Stores the elements of the first list */
	vector<int> list;

	int c = getchar();

	/* Algorithm 1 */
	if(c  == '1'){
		while (scanf("%d", &c) == 1 && getchar() != '\n'){
			list.push_back(c);
		}
		list.push_back(c);
		algorithm1(list);
	}
	if(c == '2'){
		/* Stores the elements of the second list */
		vector<int> list2;
		getchar();
		while (scanf("%d", &c) == 1 && getchar() != '\n'){ 
			list.push_back(c);
		}
		list.push_back(c);
		while (scanf("%d", &c) == 1 && getchar() != '\n'){
			list2.push_back(c);
		}
		list2.push_back(c);

		algorithm2(list, list2);
	}
	return 0;
}

