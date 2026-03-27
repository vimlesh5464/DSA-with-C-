# Function to merge two subarrays
def merge(arr, left, mid, right):
    list = []
    i = left
    j = mid+1

    while i <= mid and j <=right:
        if arr[i] <= arr[j]:
            list.append(arr[i])
            i += 1
        else:
            list.append(arr[j])
            j += 1
        

    while i <=mid:
        list.append(arr[i])
        i += 1
        

    while j <=right:
        list.append(arr[j])
        j += 1
        

    for i in range(len(list)):
        arr[i+left] = list[i]


# Merge Sort function
def merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2

        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    arr = []

    print("Enter the elements:")
    for i in range(n):
        arr.append(int(input()))

    merge_sort(arr, 0, n - 1)

    print("Sorted array:", arr)
