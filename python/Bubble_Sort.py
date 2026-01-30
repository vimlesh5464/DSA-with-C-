# Bubble Sort using function in Python

def bubble_sort(arr, n):
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]




if __name__ == "__main__":
    n = int(input("Enter number of elements: "))

    arr = []
    print("Enter the elements:")
    for i in range(n):
        arr.append(int(input()))

    bubble_sort(arr, n)

    print("Sorted array is:")
    print(arr)
