#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
    private:
        map<string, string> emnekoder;
    public:
        void addCourse(string kode, string navn);
        void removeCourse(string kode);
        string getCourse(string emne);
        friend ostream& operator<<(ostream& os, const CourseCatalog&);
        void saveData();
};


CourseCatalog testClass();