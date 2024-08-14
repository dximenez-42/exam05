#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
private:
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell*> _spellbook; 	
	

	Warlock();
	Warlock(Warlock const& src);
	Warlock& operator=(Warlock const& rhs);


public:
	Warlock(std::string name, std::string title);
	~Warlock();

	std::string const& getName() const;
	std::string const& getTitle() const;

	void setTitle(std::string const& title);

	void introduce() const;
	
	void learnSpell(ASpell* spell);
	void forgetSpell(std::string name);
	void launchSpell(std::string name, ATarget& target);
};

#endif
