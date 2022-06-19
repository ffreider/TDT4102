#include "std_lib_facilities.h"
#include "CourseCatalog.h"


void CourseCatalog::addCourse(string kode, string navn) {
    CourseCatalog::emnekoder.insert({kode, navn}); 
}

void CourseCatalog::removeCourse(string emne) {
    CourseCatalog::emnekoder.erase(emne); 
}

string CourseCatalog::getCourse(string kode) {
    return CourseCatalog::emnekoder.at(kode);
}

ostream& operator<<(ostream& os, const CourseCatalog& c) {
    for (auto&& item : c.emnekoder) {
        os << item.first << ": " << item.second << endl;
    }
    return os;
}

CourseCatalog testClass() {
    CourseCatalog one;
    one.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    one.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    one.addCourse("TMA4100", "Matematikk 1");
    one.addCourse("C++", "Prosedyre- og objektorientert programmering");
    cout << one;
    return one;
}

void CourseCatalog::saveData() {
    fstream readFrom;
    readFrom.open("txt_files/emnekoder.txt", ios::in);
    fstream writeTo;
    writeTo.open("txt_files/kopi_emnekoder.txt", ios::out);
    string line;
    while (getline(readFrom, line)) {
        writeTo << line << endl;
    }
    readFrom.close();
    writeTo.close();
}



