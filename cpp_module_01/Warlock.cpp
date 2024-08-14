#include "Warlock.hpp"

Warlock::Warlock()
{}

Warlock::Warlock(std::string name, std::string title)
{
	_name = name;
	_title = title;
	std::cout << _name << ": This looks like another boring day!" << std::endl;
}

Warlock::Warlock(Warlock const& src)
{
	*this = src;
}

Warlock& Warlock::operator=(Warlock const& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return *this;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const& Warlock::getName() const
{
	return _name;
}

std::string const& Warlock::getTitle() const
{
	return _title;
}
                                         
void Warlock::setTitle(std::string const& title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


void Warlock::learnSpell(ASpell* spell)
{
	if (spell && _spellbook.find(spell->getName()) == _spellbook.end())
		_spellbook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string name)
{
	if (_spellbook.find(name) != _spellbook.end())
		_spellbook.erase(_spellbook.find(name));
}

void Warlock::launchSpell(std::string name, ATarget& target)
{
	if (_spellbook.find(name) != _spellbook.end())
		_spellbook[name]->launch(target);
}
