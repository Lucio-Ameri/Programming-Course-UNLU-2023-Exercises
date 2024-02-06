Below are the instructions for the exercises that will be solved in this folder:

1. Create a function with four parameters (array, N, min, max) that loads and returns a vector of N elements randomly filled with numbers between min and max.

2. Given two vectors A and B with the same number of elements loaded using the function from point 1, obtain the dot product: Σ A(i) * B(i).
Example:
A = {5, 7, 3}; B = {9, 2, 1}; dot_product = (5 x 9) + (7 x 2) + (3 x 1)

3. Create a function that receives two vectors A and B with n number of integer elements, where n is an even number, and returns the sum of elements at even positions in the first vector with elements at odd positions in the second vector. Remember that in C, array positions start from zero, and zero is considered an even number.
Example:
A = {13, 2, 1, 6}; B = {5, 7, 3, 9}; sum_result = 13 + 7 + 1 + 9

4. Given an array of N elements, write a program that shifts the elements of the array one position to the right, such that the first element moves to the second position, the second to the third, and so on.
Example:
A = {5, 7, 4, 9, 3}; result = {3, 5, 7, 4, 9}

5. Create a function that loads a vector of 30 elements with the letter "x" and places an "A" in a random location and a "B" in another random location that is not the same as the one with the letter "A".
Example:
A = {"x", ..., "x", "A", "x", ..., "B"}

6. Implement a function that returns the distance between the positions of the letters "A" and "B" in the vector loaded in the previous exercise.
Example:
A = {"x", "x", "A", "x", "B"} distance = 1; A = {"x", "x", "B", "A"} distance = 0

7. Enter 1000 ages into a vector and indicate the age with the highest frequency (the most repeated).

8. Implement a function to determine if two vectors loaded with natural numbers, having the same number of elements, are identical.

9. Write a function that takes a vector containing positive numbers as a parameter, which may contain duplicate values, and replaces each repeated element with -1. The procedure should return the modified vector and the number of times it was modified.

10. Create a function that receives a vector with n numeric elements and returns the number of negative numbers in the vector.

11. Implement a function that receives a vector with n numeric elements and returns the number of zeros in the vector.

12. Create a function that receives a vector with n numeric elements and returns the number of negative numbers in the vector.

13. Develop a function that receives a vector with n numeric elements and, by calling the functions from the previous 3 items, displays on the screen the number of positive, zero, and negative numbers in the vector.

14. Create a program that takes a vector with n numeric elements and displays the largest value in the vector on the screen. Create an auxiliary function to test the correctness of the program.

15. Print and sum the elements occupying odd positions in a vector of 50 numeric elements.

16. Write a function that takes an array of N integer elements and an integer X as arguments and does the following:
a. Search for all elements that match X and return the number of matches found.
b. Search for the first occurrence of the element in the list and return its position. If X does not exist in the array, it should return -1.
c. Using the previous function, search for all elements that match X and return an array with the positions occupied by these elements in the original array. If there are no matching elements, it will return an empty array.
Example:
For N=7, the array could be A ={5, 7, 3, 9, 2, 3, 8 }

With X=3, the results would be:
a) matching_elements(x) = 2
b) first_occurrence_position(x) = 2
c) matching_positions(x) = {2, 5 }

With X=4, the results would be:
a) matching_elements(x) = 0
b) first_occurrence_position(x) = -1
c) matching_positions(x) = {}







