#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::TargetGenerator(TargetGenerator const& src)
{
	*this = src;
}

TargetGenerator& TargetGenerator::operator=(TargetGenerator const& rhs)
{
	if (this != &rhs)
	{
		_targets = rhs._targets;
	}
	return *this;
}

TargetGenerator::~TargetGenerator()
{
	for(std::map<std::string, ATarget*>::iterator it = _targets.begin(); it != _targets.end(); it++)
		delete it->second;
	_targets.clear();
}


void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		_targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const& type)
{
	std::map<std::string, ATarget*>::iterator it = _targets.find(type);

	if (it != _targets.end())
	{
		delete it->second;
		_targets.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(std::string const& type)
{
	ATarget* tmp = NULL;

	if (_targets.find(type) != _targets.end())
		tmp = _targets[type];
	return tmp;
}
