#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>
using std::string;
struct Address
{
	string country;
	string state;
	string city;
	int zipCode;
	string street;
	int streetNumber;
	string buildingName;
	int apartmentNum;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & country;
			ar & state;
			ar & city;
			ar & zipCode;
			ar & street;
			ar & streetNumber;
			ar & buildingName;
			ar & apartmentNum;
		}
};

struct School
{
	string elementary;
	string middle;
	string high;
	string college;
	string grad;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & elementary;
			ar & middle;
			ar & high;
			ar & college;
			ar & grad;
		}
};

/*struct Date_Time
{
	int year;
	int month;
	string monthName;	//Maybe later I'll autoconvert this...
	int day;
	string dayoftheweek;
	int hour;		//24 hour timescale\
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & year;
			ar & month;
			ar & monthName;
			ar & day;
			ar & dayoftheweek;
			ar & hour;
		}
};*/

struct Name
{
	string first;
	string midInitial;
	string middle;
	string last;
	string title;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & first;
			ar & midInitial;
			ar & middle;
			ar & last;
			ar & title;
		}
};

struct PassInfo
{
	int length;
	bool containsAlpha;
	bool containsNumeric;
	bool containsSymbols;
	bool containsWhitespace;
	bool containsCaps;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & length;
			ar & containsAlpha;
			ar & containsNumeric;
			ar & containsSymbols;
			ar & containsWhitespace;
			ar & containsCaps;
		}
};

#endif