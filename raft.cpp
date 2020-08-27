#include <iostream>

void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void sortBackwards(int arr[], int n) {
    int max;
    
    for (int i = 0; i < n - 1; i++) {
        max = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        
        swap(arr[i], arr[max]);
   }
}

int getMinCapacity(int arr[], int n, int k) {
    bool passed[n];

    for(int i = 0; i < n; i++) {
        passed[i] = false;
    }

    int init = arr[0];

    while(true) {
        for(int i = 0; i < n; i++) {
            passed[i] = false;
        }

        for(int i = 0; i < k; i++) {
            int sum = 0;

            for(int j = 0; j < n; j++) {
                if(sum + arr[j] <= init && !passed[j]) {
                    sum += arr[j];
                    passed[j] = true;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(!passed[i]) {
                break;
            }
            if(i == n-1 && passed[i]) {
                return init;
            }
        }

        init++;
    }

    return 0;
}

int main() {
    int n, k;
    std::cin >> n;
    std::cin >> k;

    int* a = new int[n];

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    sortBackwards(a, n);

    int result = getMinCapacity(a, n, k);

    std::cout<<"Result is: " << result;

    return 0;
}