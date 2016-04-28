#ifndef DECK_H
#define DECK_H
#include <vector>
#include <memory>

template <class T>
class Deck : public std::vector<T>{
public:
	T draw(){
		T result = this->back();
		this->pop_back();
		return result;
	}

	void setDeck(std::vector<T> _v){ 
		deck1 = _v;
	}

	std::vector<T> getDeck(){
		return deck1;
	}

};
#endif //DECK_H