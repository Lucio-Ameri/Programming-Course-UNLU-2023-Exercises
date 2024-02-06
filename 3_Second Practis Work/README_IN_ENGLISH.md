Below are the instructions for the exercises that will be solved in this folder:

1. Write a function that receives a character array and indicates whether the elements are ordered from smallest to largest or not.
Example:
A = {'c', 'a', 'j', 't', 'p', 'g'} Result = "NO"
A = {'a', 'c', 'g', 'j', 'p', 'z'} Result = "YES"

2. Create a function that receives two ordered arrays A(n) and B(m) and returns a new array C containing elements from A and B in a sorted manner, with duplicate elements appearing only once.
Example:
n=6 ; m=7 ; A = {2, 5, 8, 10, 11, 25}; B = {1, 2, 6, 7, 9, 11, 13}; C={1, 2, 5, 6, 7, 8, 9, 10, 11, 13, 25}

3. Develop a program that, through a function, updates a sorted array of n elements. This function receives four parameters: the array to update, the number of elements, the action to be performed (I, D, or U), and an integer value. If the action is I, it should add the value at the last position. If it is D, it should find the value within the array and delete it (return an error message if not found). If it is U, it should insert a new value at the specified position.
Example:
n=6; If the array is ={5, 7, 9, 11, 19, 24 }, action is "D", and value is 19.
update_array(array, count, action, value) will return {5, 7, 9, 11, 24}

4. Two arrays of integers, ordered from highest to lowest, are given: A(n) and B(n). Develop an algorithm to obtain a new array C, containing only the elements that exist in both arrays and are not repeated.

5. Write an algorithm to process two sorted arrays of n elements: Student IDs (n) and Grades (n * 3) since, for each student ID, there are three consecutive grades. Obtain a list with the average of each student.