# Insertion Sort using function in Python

def insertion_sort(arr, n):
    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))

    arr = []
    print("Enter the elements:")
    for i in range(n):
        arr.append(int(input()))

    insertion_sort(arr, n)

    print("Sorted array is:")
    print(arr)
