def counting_sort(arr, n):
    # Find maximum element
    max_element = arr[0]
    for i in range(1, n):
        if arr[i] > max_element:
            max_element = arr[i]

    # Create count array
    count = [0] * (max_element + 1)

    # Store frequency of each element
    for i in range(n):
        count[arr[i]] += 1

    # Reconstruct the sorted array
    index = 0
    for i in range(max_element + 1):
        while count[i] > 0:
            arr[index] = i
            index += 1
            count[i] -= 1


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))

    arr = []
    print("Enter the elements (non-negative integers):")
    for i in range(n):
        arr.append(int(input()))

    counting_sort(arr, n)

    print("Sorted array:", arr)
