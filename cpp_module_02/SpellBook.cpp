#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::SpellBook(SpellBook const& src)
{
	*this = src;
}

SpellBook& SpellBook::operator=(SpellBook const& rhs)
{
	if (this != &rhs)
	{
		_spells = rhs._spells;
	}
	return *this;
}

SpellBook::~SpellBook()
{
	for(std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); it++)
		delete it->second;
	_spells.clear();
}


void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
		_spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const& name)
{
	std::map<std::string, ASpell*>::iterator it = _spells.find(name);

	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const& name)
{
	ASpell* tmp = NULL;

	if (_spells.find(name) != _spells.end())
		tmp = _spells[name];
	return tmp;
}
