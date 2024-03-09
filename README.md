# visitors-task

# Actual Problem stament:
At a museum the entering and leaving times of all the visitors were registered during a day with a
one minute accuracy. A list of time value pairs was collected, where the first time value shows the
entering time of a visitor and the second time value shows the leaving time. Find the time period
when there were the most number of visitors in the museum and how many visitors there were.
Entering and leaving times are inclusive meaning that, for example, if one visitor entered at 11:10
and another left also at 11:10, then at 11:10 there were 2 visitors.
# Expected solution
1. Write a program in C++ that:
a. Reads visiting times from an input file. The path of the input file is given as an argument
to the program. Input file is a text file, where every line is the entering and leaving time
values of one visitor separated with commas. For example:
10:15,14:20
11:10,15:22
Visiting times can be in a random order and not sorted by entering or leaving time
values. The file visitors.txt can be used for testing.
b. Using the data from the input file find the time period, when there were the most number
of visitors and how many visitors were in the museum in that time period.
c. Outputs the results found in the previous step to the standard output in the form <start
time>-<end time>;<number of visitors>. For example:
11:10-14:20;2
2. The source code must be stored in the “src” subdirectory.
3. Describe the algorithm of finding the time period and number of visitors in a separate
document “Finding the time period.md”.
4. Document public classes and their methods according to the Doxygen rules and generate
documentation in the separate subdirectory “doc” using the Doxygen tool.

# Assumptions:
1. Input file always contains data in proper format - HH:MM,HH:MM
2. Time range 00:00-24:00 will be maintained in the input file,
 so no validation of time range in currently added
3. Entering time in the input time will always be less than out time.