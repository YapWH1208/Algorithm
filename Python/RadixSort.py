def radixSort(arr):
    max_num = max(arr):
    exp = 1

    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = arr[i] // exp
        count[index%10] += 1

    for i in range(1, 10):
        count [i] += count[i-1]

    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index%10]-1] = arr[i]
        count[index%10] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

list = [64, 34, 25, 12, 22, 11, 90]
print(radixSort(list))