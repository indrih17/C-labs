#ifndef DATE_H
#define DATE_H 

struct Date {
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

Date createDate();

Date calculateCurrentDate();
bool compareDate(Date);
bool compareDate(unsigned short, unsigned short, unsigned short);
bool compareDate(unsigned short, unsigned short);

#endif