#ifndef TARGET_H
#define TARGET_H
#include "dataStructures.hpp"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>


class Target
{
private:
	friend class boost::serialization::access;
	
	int testVal;
	Address home;
	Address work;
	//Date_Time birthday;
	Name name;
	PassInfo pinfo;	//Password Information

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
	    ar & home;
	    ar & work;
	    //ar & birthday;
	    ar & name;
	    ar & pinfo;
	    ar & testVal;
	}
public:
	Target();
	void generateList();
	void enterData();
	void parseFile();
	int getTestVal() { return testVal; }
};

#endif