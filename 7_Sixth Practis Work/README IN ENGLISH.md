1. In a sequential file (text file, for example "rain.txt"), data about the rainfall during a certain period is stored. Each line corresponds to a day and contains the following data: Day-Month-Year-Precipitation (0 if it did not rain). Prepare an algorithm with the necessary procedures to:

A _ load the data corresponding to the 30 days of September of the current year.
B _ read the file and report on the screen: how many days had no rainfall, how many days had less than 50 mm of rainfall, and how many days had 50 mm or more of rainfall.

   EXAMPLE:
   rain.txt:

   01 - 09 - 2021 - 25
   02 - 09 - 2021 - 95
   03 - 09 - 2021 - 0
   .      .      .
   29 - 09 - 2021 - 15
   30 - 09 - 2021 - 0

   Output:
   
   Days without rain: 2
   Days with less than 50mm of rain: 2
   Days with 50mm or more of rain: 1

2. In a meteorological station, the maximum and minimum temperature are recorded daily for an entire year with the following design: Day-Month-Year-Maximum_Temperature-Minimum_Temperature (the last two can be generated randomly). Prepare an algorithm with the necessary procedures to:

A _ load the data corresponding to all the days of the current year into a file named "temperatures.txt".
B _ print a report on the screen as follows:
               TEMPERATURE: ANNUAL REPORT

Minimum Temperature of the Year: xx
Recorded on Day: xx
Of Month: xx

Maximum Temperature of the Year: xx
Recorded on Day: xx
Of Month: xx

       Maximum Thermal Amplitude
Registered: xx
On Day: xx
Of Month: xx

   EXAMPLE:
   temperatures.txt:
   
01 -01 - 2021 - 18 - 31
02 -01 - 2021 - 16 - 28
03 - 06 - 2021 - 1 - 9
30 - 12 - 2021 - 20 - 34
31 - 12 - 2021 - 20 - 36

   TEMPERATURE: ANNUAL REPORT

Minimum Temperature of the Year: 1
Recorded on Day: 3
Of Month: 6

Maximum Temperature of the Year: 36
Recorded on Day: 31
Of Month: 12

Maximum Thermal Amplitude: 16
Recorded on Day: 31
Of Month: 12

3. Using the same file generated in the previous point, prepare a procedure that allows reading the data and generating another file ("average_temp.txt"), which contains the daily average temperatures in the following format: Day-Month-Year-Average_Temperature

    EXAMPLE:
    Output:
   
01 -01 - 2021 - 24.5
02 -01 - 2021 - 22
03 - 06 - 2021 - 5
30 - 12 - 2021 - 20.
31 - 12 - 2021 - 20.28

4. A survey is conducted to determine the employment status of the inhabitants of a city. The respondents answered the following items:
   
a. - Gender (1 male; 2 female).
b. - Age.
c. - Marital status (1 single; 2 married; 3 others).
d. - Works (0 no; 1 yes).
e. - Studies (0 no; 1 yes).

A _ Generate a sequential file with all validated data.
B _ Using the file, print a report as follows:

PERCENTAGES:

• males xx •
• females xx •
• under 18 years old who work xx •
• singles xx •
• married xx •
• respondents who work and study xx •
• women who work xx •