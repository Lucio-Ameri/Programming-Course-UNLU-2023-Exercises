Below are the instructions for the exercises that will be solved in this folder:

1. Given a matrix of 3 rows by 4 columns, calculate the sum of its elements: ΣM(i,j)
Example:
M ={5, 7, 3, 9,
2, 3, 4, 1,
8, 6, 4, 2 }

Sum_M = 5 + 7 + 3 + 9 + 2 + 3 +… + 4 + 2.

2. Read a matrix of three rows by three columns and calculate the sum of each row and column, placing the results in two vectors, one for the row sums and another for the column sums.
Example:
M ={5, 7, 3,
2, 3, 4,
8, 6, 4}

RowSums = {(5 + 7 + 3),( 2 + 3 + 4),(8 + 6 + 4 )}; ColumnSums = {(5 + 2 + 8),( 7 + 3 + 6),(3 + 4 + 4 )}

3. Implement a program that, given a square matrix with integer values between 1 and 50 (randomly generated), displays it and obtains its transpose (permutation of rows and columns using a procedure that swaps two elements), and then displays it again.
Example:
M ={5, 7, 3,
2, 3, 4,
8, 6, 4}

Result:
M ={5, 2, 8,
7, 3, 6,
3, 4, 4}

4. Create a program that randomly generates minimum and maximum temperatures for the 30 days of a month. Calculate and display:

Average temperature for the month.
Day with the highest temperature and its corresponding temperature.
Day with the lowest temperature and its corresponding temperature.
5. Develop a program that generates a matrix of 20 rows by 3 columns where the first column stores the name, the second the last name, and the third the ID. Then, given an ID, iterate through the matrix, and if found, display the corresponding name and last name. Otherwise, show an error message.

6. In an array M(3, 4, 20) where the first index indicates the study center number, the second the course number, and the third the student number, grades are stored for each cell. Provide:

The average grade per course.
The average grade per center.
The overall average grade.
The position of the best student for each course with their corresponding grade.
7. Given a matrix storing data related to a population: P(sex, marital status, age) where sex can take values 1 or 2 (male or female); marital status can take values from 1 to 3 (single, married, widowed); age a value between 1 and 70. Generate a function that loads the aforementioned array with random data, respecting the domains of each group. Write a function that, given this matrix, sex, marital status, and age as arguments, returns the number of people in those conditions.