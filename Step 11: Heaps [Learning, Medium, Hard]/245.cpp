// https://www.naukri.com/code360/problems/convert-min-heap-to-max-heap_1381084

void heapify(int n, vector<int>& arr, int currId){
	int left = 2 * currId + 1;
    int right = 2 * currId + 2;

	int maxId = currId;
	if (left < n && arr[left] > arr[maxId])
        maxId = left;

    if (right < n && arr[right] > arr[maxId])
        maxId = right;
	
	if(maxId != currId){
		swap(arr[currId], arr[maxId]);
		heapify(n, arr, maxId);
	}
	
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, arr, i);
	return arr;
}