public class Sort{
    public static void bubbleSort(int[] arr){
        int n = arr.length;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-i-1; j++){
                if(arr[j] > arr[j+1]){
                    // swap arr[j+1] and arr[j]
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    public static void mergeSort(int[] arr, int l, int r){
        if(l < r){
            int m = (l+r)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }

    static void merge(int[] arr, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for(int i = 0; i < n1; i++){
            L[i] = arr[l+i];
        }
        for(int j = 0; j < n2; j++){
            R[j] = arr[m+1+j];
        }

        int i = 0, j = 0;
        int k = l;

        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }

            k++;
        }

        while(i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void quickSort(int[] arr, int low, int high){
        if(low < high){
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }

    static int partition(int[] arr, int low, int high){
        int pivot = arr[high];
        int i = low-1;

        for(int j = low; j < high; j++){
            if(arr[j] < pivot){
                i++;

                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap arr[i+1] and arr[high]
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }

    public static void selectionSort(int[] arr){
        int n = arr.length;

        for(int i = 0; i < n-1; i++){
            int min_idx = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[min_idx]){
                    min_idx = j;
                }
            }

            // swap arr[min_idx] and arr[i]
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void radixSort(int[] arr){
        int n = arr.length;
        int m = getMax(arr, n);

        for(int exp = 1; m/exp > 0; exp *= 10){
            countSort(arr, n, exp);
        }
    }

    static int getMax(int[] arr, int n){
        int max = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }

        return max;
    }

    static void countSort(int[] arr, int n, int exp){
        int[] output = new int[n];
        int[] count = new int[10];

        for(int i = 0; i < n; i++){
            count[(arr[i]/exp)%10]++;
        }

        for(int i = 1; i < 10; i++){
            count[i] += count[i-1];
        }

        for(int i = n-1; i >= 0; i--){
            output[count[(arr[i]/exp)%10]-1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }

        for(int i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }
}