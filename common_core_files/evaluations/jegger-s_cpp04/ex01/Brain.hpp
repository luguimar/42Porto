#ifndef	BRAIN_HPP
#define	BRAIN_HPP

#include <iostream>

class Brain {

	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain&);
	Brain&	operator=(Brain const &rhs);
	~Brain();

	std::string	getIdea(unsigned int n);
	void		setIdea(std::string str, unsigned int n);
};

#endif