#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain{
public:
	std::string ideas[100];
	Brain(void);
	Brain(const Brain& obj);
	Brain& operator= (const Brain& obj);
	~Brain(void);
	const std::string* getIdeas(void) const;
	void setIdeas(std::string idea);
};

#endif