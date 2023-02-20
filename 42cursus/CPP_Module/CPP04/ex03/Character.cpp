#include <iostream>
#include "Character.hpp"

// Static variable initialize
int const	Character::S_MAX = 4;


// Constructor & Destructor
Character::Character(void)
:name("defalut_name"),
s_cnt(0)
{
	for (int i = 0; i < S_MAX; i++)
		this->slot[i] = NULL;
}

Character::Character(std::string const& name)
:name(name),
s_cnt(0)
{
	for (int i = 0; i < S_MAX; i++)
		this->slot[i] = NULL;
}

Character::Character(Character const& character)
:name(character.getName()),
s_cnt(character.s_cnt)
{
	for (int i = 0; i < S_MAX; i++) {
		if (character.slot[i])
			this->slot[i] = character.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
}

Character::~Character(void) {
	for (int i = 0; i < S_MAX; i++) {
		if (this->slot[i]) {
			delete this->slot[i];
			this->slot[i] = NULL;
		}
	}
}


// Operator overload
Character&	Character::operator=(Character const& character) {
	for (int i = 0; i < S_MAX; i++) {
		if (this->slot[i]) {
			delete this->slot[i];
			this->slot[i] = NULL;
		}
	}

	this->name = character.getName();
	this->s_cnt = character.s_cnt;
	for (int i = 0; i < S_MAX; i++) {
		if (character.slot[i])
			this->slot[i] = character.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
	return *this;
}


// Getter
std::string const&	Character::getName() const {
	return this->name;
}


// Member function
void	Character::equip(AMateria* m) {
	if (this->s_cnt >= S_MAX) {
		std::cout << name << ": My slot is FULL!!" << std::endl;
		return;
	}

	for (int i = 0; i < S_MAX; i++) {
		if (slot[i] == NULL) {
			slot[i] = m;
			break;
		}
	}
	s_cnt++;
}

void	Character::unequip(int idx) {
	if (idx < 0 or idx >= 4) {
		std::cout << name << ": Invalid slot index" << std::endl;
		return;
	}
	else if (slot[idx] == NULL) {
		std::cout << name << ": There is no Materia" << std::endl;
		return;
	}

	slot[idx] = NULL;
	s_cnt--;
}

void	Character::use(int idx, ICharacter& target) {
	if (slot[idx] == NULL) {
		std::cout << name << ": There is no Materia" << std::endl;
		return;
	}

	slot[idx]->use(target);
}
