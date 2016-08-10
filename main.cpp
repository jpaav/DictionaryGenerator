#include "Target.hpp"
#include "dataStructures.hpp"
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <boost/archive/tmpdir.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp> 
#include <boost/serialization/optional.hpp> 
#include <boost/serialization/map.hpp> 
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>

//BOOST_CLASS_VERSION(Target, 0)

void save_profile(Target &t, std::string filename){
    // make an archive
    std::ofstream ofs(filename.c_str());
    boost::archive::text_oarchive oa(ofs);
    oa << t;
    std::cout << "Profile saved at " << filename << std::endl;
}

void load_profile(Target &t, std::string filename)
{
	std::ifstream ifs(filename.c_str());
	boost::archive::text_iarchive ia(ifs);
	ia >> t;
	std::cout << "Profile loaded from " << filename << std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "You need to either specify an existing file path or name a new one to be created.\n";
		return 1;
	}

	std::string profilePath (argv[1]);
	std::ifstream f;
	Target profile;
	bool quit = false;
	
	f.open(profilePath.c_str(), std::ios::binary);
	f.seekg(0, std::ios::end);
	int length = f.tellg();
	f.close();
	if (length != 0)
	{
		load_profile(profile, profilePath);
		std::cout << "TestVal: " << profile.getTestVal() << std::endl;
	}
	while(!quit)
	{
		//std::cout << "\n______________\n\nTo edit or add to profile data, press \"e\"\nTo generate a wordlist from this profile, press \"g\"\nTo quit, press \"q\"\n";
		char input = getchar();
		if (input == 'e')
		{
			profile.enterData();
			save_profile(profile, profilePath);
		}
		else if(input == 'g')
		{
			profile.generateList();
		}
		else if(input == 'q')
		{
			quit = true;
		}
		/*else
		{
			std::cout << "That wasn't one of your choices... try again?\n";
		}*/
	}

}
