# findMaxVisitors function explaination

This algorithm is designed to find the time period with the maximum number of visitors given two vectors, arrival and departure representing the arrival and departure times of visitors. 
Here's a step-by-step explanation of the algorithm:

# Initialization:

Get the size of both vectors, considering they have the same size.
Initialize variables: n (size of vectors), guests_in (number of guests at a given time), max_guests (maximum number of guests), time (start time of the maximum guests period), and endTime (end time of the maximum guests period).
Set initial values for guests_in, max_guests, time, and endTime based on the first elements of the arrival and departure vectors.

# Sorting:

Sort both arrival and departure vectors using the custom comparator isTime1LessThanTime2. This ensures that the events (arrivals and departures) are in ascending order based on time.
Main Loop:

Initialize indices i and j to 1 and 0, respectively.
Use a while loop to iterate through the sorted vectors until one of them are exhausted.
Inside the loop:
If the next event in sorted order is an arrival, increment the count of guests_in.
Update max_guests, time, and endTime if the current number of guests is greater than the previous maximum.
Increment the index i to move to the next arrival event.
If the event is a departure, decrement the count of guests_in and increment the index j to move to the next departure event.

# Output:

Print the result, which includes the time period with the maximum number of guests (time to endTime) and the maximum number of guests (max_guests).

# Time Complexity:

The time complexity of this algorithm is O(n log n) where n is the number of events (size of the vectors). The main loop has a linear time complexity of O(n).
Overall, the algorithm efficiently finds the time period with the maximum number of visitors by processing the arrival and departure events in sorted order.

# Space Complexity:

Overall space complexity of the algorithm is O(n) as I have used input vectors, with additional constant space requirements.
