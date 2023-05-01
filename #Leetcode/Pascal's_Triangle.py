# Question:-

# Given an integer numRows, return the first numRows of Pascal's triangle.
# Example 1:

# Input: numRows = 5
# Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

# Solution:-

def generate_pascals_triangle(numRows):
    result = []
    for i in range(numRows):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = result[i - 1][j - 1] + result[i - 1][j]
        result.append(row)
    return result

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    numRows = int(input("Enter the number of rows to generate in Pascal's triangle: "))
    pascals_triangle = generate_pascals_triangle(numRows)

    for row in pascals_triangle:
        print(row)
