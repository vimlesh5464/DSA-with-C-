# Selection Sort using function in Python

def selection_sort(arr, n):
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))

    arr = []
    print("Enter the elements:")
    for i in range(n):
        arr.append(int(input()))

    selection_sort(arr, n)

    print("Sorted array is:")
    print(arr)
