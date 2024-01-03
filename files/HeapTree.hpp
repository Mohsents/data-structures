#include <iostream>
using namespace std;

class HeapTree {

	private:
		int *minTree;
		int *maxTree;
		int minHSize;
		int maxHSize;
		int minCapacity;
		int maxCapacity;

	public:
		void createMinHeapTree(int capacity) {
			this -> minCapacity = capacity;
			minTree = new int[minCapacity];
			minHSize = 0;
		}

		void createMaxHeapTree(int capacity) {
			this -> maxCapacity = capacity;
			maxTree = new int[maxCapacity];
			maxHSize = 0;
		}

		void swap(int *a, int *b) {
			int temp = *a;
			*a = *b;
			*b = temp;
		}

		int getParent(int index) {
			return(index - 1) / 2;
		}

		void addMin(int item) {
			if(minHSize == minCapacity) return;

			minHSize++;
			int i = minHSize - 1;
			minTree[i] = item;

			while(i != 0 && minTree[i] < minTree[getParent(i)]) {
				swap(&minTree[i], &minTree[getParent(i)]);
				i = getParent(i);
			}
		}

		void addMax(int item) {
			if(maxHSize == maxCapacity) return;

			maxHSize++;
			int i = maxHSize - 1;
			maxTree[i] = item;

			while(i != 0 && maxTree[i] > maxTree[getParent(i)]) {
				swap(&maxTree[i], &maxTree[getParent(i)]);
				i = getParent(i);
			}
		}

		void showMinTree() {
			for(int i = 0; i < minHSize; i++)
				cout << minTree[i] << " ";
		}

		void showMaxTree() {
			for(int i = 0; i < maxHSize; i++)
				cout << maxTree[i] << " ";
		}

		void minHeapify(int i) {
			int left = 2 * i + 1;
			int rigth = 2 * i + 2;
			int smallest = i;

			if(left < minHSize && minTree[left] < minTree[i])
				smallest = left;

			if(rigth < minHSize && minTree[rigth] < minTree[smallest])
				smallest = rigth;

			if(smallest != i) {
				swap(&minTree[i], &minTree[smallest]);
				minHeapify(smallest);
			}
	}

		int minRootRemove() {
			int root;
			if(minHSize <= 0) return INT_MIN;

			if(minHSize == 1) {
				minHSize--;
				return minTree[0];
			}

			root = minTree[0];
			minTree[0] = minTree[minHSize - 1];
			minHSize--;
			minHeapify(0);

			return root;
		}

		void maxHeapify(int i) {
			int left = 2 * i + 1;
			int rigth = 2 * i + 2;
			int largest = i;

			if(left < maxHSize && maxTree[left] > maxTree[i])
				largest = left;

			if(rigth < maxHSize && maxTree[rigth] > maxTree[largest])
				largest = rigth;

			if(largest != i) {
				swap(&maxTree[i], &maxTree[largest]);
				maxHeapify(largest);
			}
	}

		void heapSort() {
    		int i;
			for (i = maxHSize / 2 - 1; i >= 0; i--)
        		maxHeapify(i);
  
    		for (i = maxHSize - 1; i >= 0; i--) {
        		swap(&maxTree[0], &maxTree[i]);
        		maxHeapify(0);
    		}
	}

		int maxRootRemove() {
			int root;
			if(maxHSize <= 0) return INT_MAX;

			if(maxHSize == 1) {
				maxHSize--;
				return maxTree[0];
			}

			root = maxTree[0];
			maxTree[0] = maxTree[maxHSize - 1];
			maxHSize--;
			maxHeapify(0);

			return root;
		}
};
