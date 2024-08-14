#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
private:
	std::string _name;
	std::string _effects;

public:
	ASpell(std::string name, std::string effects);
	ASpell(ASpell const& src);
	ASpell& operator=(ASpell const& rhs);
	~ASpell();

	std::string getName() const;
	std::string getEffects() const;

	virtual ASpell* clone() const = 0;
	void	launch(ATarget const& target) const;
};

#endif
