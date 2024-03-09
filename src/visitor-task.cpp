#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <fstream>

/// @brief Compares time in HH:MM format, 
/// @param time1 : String in HH:MM format
/// @param time2 : String in HH:MM format
/// @return if time1<=time2 returns true else returns false
bool isTime1LessThanTime2(const std::string& time1, const std::string& time2) {
    std::istringstream ss1(time1);
    std::istringstream ss2(time2);

    int hours1, minutes1, hours2, minutes2;
    char colon1, colon2;

    ss1 >> hours1 >> colon1 >> minutes1;
    ss2 >> hours2 >> colon2 >> minutes2;

    return (hours1 < hours2) || ((hours1 == hours2) && (minutes1 <= minutes2));
}


/// @brief Actual alogrithm that finds the max visitors in particular interval
/// @param arrival : Vector that contains arrival time in HH:MM format string
/// @param departure : Vector that contains departure time in HH:MM format string
void findMaxVisitors(std::vector<std::string>& arrival,std::vector<std::string>& departure) {

    //Size of both the vectors is same
    int n = arrival.size();

    // Sort vectors using the custom comparator
    std::sort(arrival.begin(), arrival.end(), isTime1LessThanTime2);    
    std::sort(departure.begin(), departure.end(), isTime1LessThanTime2);
  
    // guests_in indicates the number of guests at a time
    int guests_in = 1, max_guests = 1;
    std::string time = arrival[0];
    std::string endTime = departure[0];
    int i = 1, j = 0;

    // Similar to merge in merge sort to process
    // all events in sorted order
    while (i < n && j < n) {
        // If the next event in sorted order is arrival,
        // increment the count of guests
        if (isTime1LessThanTime2( arrival[i],departure[j])) {
            guests_in++; 
            // Update max_guests if needed
            if (guests_in > max_guests) {
                max_guests = guests_in;
                time = arrival[i];
                endTime = departure[j];
            }
            i++; // increment the index of the arrival array
        } else { 
            // If the event is an exit, decrement the count of guests.   
            guests_in--;
            j++;
        }
    }

    std::cout<< time << "-" << endTime << ";"<< max_guests <<std::endl;
}

/// @brief Get file contents and populate arrival and departure vector
/// @param filename : Which was provided while running application
/// @param arrival : Arrival time will be fetched from file and populated in this vector
/// @param departure : Departure time will be fetched from file and populated in this vector
void readFileToVector(const std::string& filename,std::vector<std::string>& arrival,std::vector<std::string>& departure){
    std::ifstream r_file;
    r_file.open(filename);
    std::string line;
    while(std::getline(r_file,line)){
        std::string subs_str;
        std::stringstream ss(line);
        std::getline(ss,subs_str,',');
        arrival.emplace_back(subs_str);
        std::getline(ss,subs_str,',');
        departure.emplace_back(subs_str);    
    }
    
    r_file.close();

}

/// @brief Get the record count to reseve vector size to avoid resizing of vector
/// @param filename : Which was provided while running application
/// @return integer count : Number of lines preent in file
int GetRecordCount(const std::string& filename)
{
    std::ifstream r_file;
    r_file.open(filename);
    std::string line;
    int count =0;
    while(std::getline(r_file,line)){
        count++;       
    }
    
    r_file.close();
    return count;
}


/// @brief Application driver main fuction which takes input file from command line
/// @param argc 
/// @param argv : Input file with complete path
/// @return integer value 
int main(int argc,  char **argv) {

    std::vector<std::string> arrival,departure;
    //Only when file name is given in the argument read and process data
    if(argv[1])
    {
        int max_record = GetRecordCount(argv[1]);
        if(max_record == 0){
            std::cout << "Visitor entries not found" << std::endl;
            return 0;
        }
        arrival.reserve(++max_record);
        departure.reserve(++max_record);
        readFileToVector(argv[1],arrival,departure);
        findMaxVisitors(arrival,departure);

    }else{
        std::cout << "Visitor entry file not found" << std::endl;
    }

    return 0;
}
