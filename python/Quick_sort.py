# Quick Sort using function in Python

def partition(arr, low, high):
    pivot = arr[high]   # Pivot element
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        # Recursive calls
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))

    arr = []
    print("Enter the elements:")
    for i in range(n):
        arr.append(int(input()))

    quick_sort(arr, 0, n - 1)

    print("Sorted array is:")
    print(arr)
