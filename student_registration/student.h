#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <regex>

using namespace std;

class Student
{
	 private:
      string FirstName;
      string LastName;
      string Id;
      static int myId;

public:
    Student() {
        myId = 1000;
    }

    Student(string firstName, string lastName) {
        FirstName = firstName;
        LastName = lastName;
        Id = random_string(20);
    }

    Student(string name) {
        string regex_str = " ";
        vector<string> names = split(name, regex_str);
        FirstName = names[0];
        LastName = names.size() > 1 ? names[1] : "";
        Id = random_string(20);
    }

    ~Student() {

    }

    void setFirstName(string firstName) {
        FirstName = firstName;
    }

    void setLastName(string lastName) {
        LastName = lastName;
    }

    string getLastName() {
        return LastName;
    }

    string getFirstName() {
        return FirstName;
    }

    string getId() {
        return Id;
    }

    void print() {
        cout << LastName << ", " << FirstName << endl;
    }

    string random_string(string::size_type length)
    {
        static auto& chrs = "0123456789"
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        thread_local static std::mt19937 rg{random_device{}() };
        thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

        std::string s;

        s.reserve(length);

        while (length--)
            s += chrs[pick(rg)];

        return s;
    }

    std::vector<std::string> split(const std::string str, const std::string regex_str)
    {
        std::regex regexz(regex_str);
        std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
            std::sregex_token_iterator());
        return list;
    }

    // for string delimiter
    vector<string> splito(string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }

};

#endif 

