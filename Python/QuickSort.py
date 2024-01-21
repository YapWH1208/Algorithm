def quickSort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [i for i in arr[1:] if x <= pivot]
        great = [i for i in arr[1:] if x > pivot]
        return quickSort(less) + [pivot] + quickSort(great)

list = [64, 34, 25, 12, 22, 11, 90]
print(quickSort(list))