1. Produce a report with the salaries of the employees of a company, issuing totals per branch. Each employee has a single record in the master payroll file with the following data:

• Branch code (cod_suc: integer)
• Employee code (cod_emp: integer)
• Monthly salary (salary: real)

The file is sorted in ascending order by branch code (Salary file.txt):

    EXAMPLE:

salary.txt:
01 - 15 - 50000.00
01 - 25 - 35000.00
. . . . . . . . . .
05 - 33 - 50000.00
05 - 42 - 45000.00

OUTPUT
SALARY REPORT

BRANCH 1
Code Employee    Salary
15               $ 50,000.00
25               $ 35,000.00
Total Branch     $ 85,000.00
. . . . . . . . . . . . . .

BRANCH 5
Code Employee    Salary
33               $ 50,000.00
42               $ 45,000.00
Total Branch     $ 95,000.00


2. In a banking entity, there is a transaction file, sorted by Account Number, with clients who have had movement in their accounts (there may be more than one movement per account). The record is composed of:

• Account number (n_account: integer)
• Movement ('code': integer)
• Amount (amount: real)

Where 'code' can take the following values: 1 if it is a deposit, 2 if it is a withdrawal. Each record represents a movement and contains the amount of it.

A - Make a program that prints a list with all the clients who have had movements in their accounts and the net balance of said movements. (Transaction file.txt)

    EXAMPLE:

transactions.txt:
100 - 01 - 10000.00
100 - 01 - 25000.00
100 - 02 - 15000.00
. . . . . . . . . .
585 - 02 - 15000.00
585 - 01 - 10000.00

CURRENT ACCOUNT TRANSACTIONS REPORT:

Account Number      Balance
100                 $ 20,000.00
. . . . . . . . . . . . . . . . . .
585                 $ -5,000.00


3. Produce a report with the salaries of the employees of a company, issuing subtotals by department and by branch. Each employee has a single record in the master payroll file with the following data:

• Branch code (cod_suc: integer)
• Department code (cod_department: integer)
• Employee code (cod_emp: integer)
• Monthly salary (salary: real)

The file is sorted in ascending order by branch code and, within branch, by department (Salary2 file.txt)

    EXAMPLE:

salary2.txt:
01 - 10 - 15 - 50000.00
01 - 10 - 25 - 35000.00
01 - 15 - 44 - 25000.00
. . . . . . . . . . . .
05 - 10 - 65 - 50000.00
05 - 15 - 88 - 45000.00
05 - 15 - 24 - 28000.00

OUTPUT

SALARY REPORT

BRANCH 1
Department Code     Code     Employee Salary
10                   15      $ 50,000.00
10                   25      $ 35,000.00
Total Department             $ 85,000.00

15                   44      $ 25,000.00
Total Department             $ 25,000.00

Total Branch                 $ 115,000.00
. . . . . . . . . . . . . . . . . . . . . . . . . .

BRANCH 5
Department Code     Code     Employee Salary
10                   65      $ 50,000.00
Total Department             $ 50,000.00

15                   88      $ 45,000.00
15                   24      $ 28,000.00
Total Department             $ 73,000.00

Total Branch                 $ 123,000.00




