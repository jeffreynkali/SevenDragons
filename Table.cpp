/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include "Table.h"
#include "StartCard.h"
#include "MyException.h"

Table::Table(){
	//we initialize the table with nullptr
	table = std::vector< std::vector<std::shared_ptr<AnimalCard>>>(103, std::vector<std::shared_ptr<AnimalCard>>(103, nullptr));
	//The startCard is created by the class Table
	std::shared_ptr<StartCard> start(new StartCard());
	table[52][52] = start;
}

int Table::addAt(std::shared_ptr<AnimalCard> _card, int _row, int _col)
{
	//if the spot is already occupied the placement should be illegal
	if (this->get(_row, _col) != nullptr) throw MyException("IllegalPlacement");
	int result = countMatches(_card, _row, _col);
	if (result == 0 && _card->getAnimalChar(0) != 'j' )throw MyException("IllegalPlacement");
	else this->set(_card, _row, _col);
	return result;
}

std::shared_ptr<AnimalCard> Table::pickAt(int _row, int _col)
{
	if (this->get(_row, _col) == nullptr) return nullptr;
	std::shared_ptr<AnimalCard> result = this->get(_row, _col);
	table[_row][_col] = nullptr;
	return result;
}

std::shared_ptr<AnimalCard> Table::get(int _row, int _col)
{
	return this->table[_row][_col];
}

void Table::set(std::shared_ptr<AnimalCard> _card, int _row, int _col){
	this->table[_row][_col] = _card;
}

bool Table::win(std::string& animal)
{
	//as of now haven't yet figured out the most efficient way to go through the matrix
	int count = 0;
	for (int i = 0; i < 103; i++){

		for (int j = 0; j < 103; j++){

			if (this->get(i, j) != nullptr) {

				for (int k = 0; k < 4; k++){
					if ((*this->get(i, j)).getAnimalChar(k) == animal.at(0)){
						count++;
						if (count == 12)return true;
						break;
					}
				}
			}
		}

	}
	return false;
}

int Table::countMatches(std::shared_ptr<AnimalCard> _card, int _row, int _col)
{
	int result = 0; 

	//if the card to drop is a joker
	//which can be paired to any other card and also can be placed anywhere
	//on the table
	if (_card->getAnimalChar(0) == 'j'){
		if ((this->get(_row - 1, _col)) != nullptr)result++;
		if ((this->get(_row + 1, _col)) != nullptr)result++;
		if ((this->get(_row , _col-1)) != nullptr)result++;
		if ((this->get(_row , _col+1)) != nullptr)result++;
		return result;
	}


	//If the card is not a joker which means it cannot be placed anywhere on the table
	//we will first verify if all the 4 neighbouring slots are empty
	//if that is the case the placement is de facto illegal
	//if ((this->get(_row, _col - 1)) == nullptr && (this->get(_row, _col + 1)) == nullptr && (this->get(_row - 1, _col)) == nullptr && (this->get(_row + 1, _col)) == nullptr) return 0;

	if ((*_card).getOrientation() == Orientation::UP)
	{

		//1st comparison with the card above the card we are interrested with
		//we check if the current card is not on the first row
		if (_row > 0 && _row <= 102)
		{
			//we verify the orientation of the card above
			//if there is one at that position
			if (this->get(_row - 1, _col) != nullptr){
				if ((*this->get(_row - 1, _col)).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(2) == (*this->get(_row - 1, _col)).getAnimalChar(0)
						||
						(*_card).getAnimalChar(3) == (*this->get(_row - 1, _col)).getAnimalChar(1)
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(2) == (*this->get(_row - 1, _col)).getAnimalChar(3)
						||
						(*_card).getAnimalChar(3) == (*this->get(_row - 1, _col)).getAnimalChar(2)
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
			}
			
		}

		//2nd comparison with the card on the left
		//we make sure that the current card is not on in the first column
		if (_col > 0 && _col <= 102)
		{
			
			//we verify the orientation of the card to the left
			//if there is one at this position
			if (this->get(_row, _col - 1) != nullptr){
				if ((*this->get(_row, _col - 1)).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(2) == (*this->get(_row, _col - 1)).getAnimalChar(3)
						||
						(*_card).getAnimalChar(0) == (*this->get(_row, _col - 1)).getAnimalChar(1)
						||
						(*this->get(_row, _col - 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row, _col - 1)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(2) == (*this->get(_row, _col - 1)).getAnimalChar(0)
						||
						(*_card).getAnimalChar(0) == (*this->get(_row, _col - 1)).getAnimalChar(2)
						||
						(*this->get(_row, _col - 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row, _col-1)).getAnimalChar(0) == 'c'
						)result++;
				}
			}

			
		}

		//3rd comparison with the card under the card we are interrested with
		//we check if the current card is not on the last row
		if (_row < 102 && _row >= 0)
		{
			//we verify the orientation of the card below
			//if there's one at that position
			if (this->get(_row + 1, _col) != nullptr){
				if ((*(this->get(_row + 1, _col))).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(0) == (*this->get(_row + 1, _col)).getAnimalChar(2)
						||
						(*_card).getAnimalChar(1) == (*this->get(_row + 1, _col)).getAnimalChar(3)
						||
						(*this->get(_row + 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row +1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(0) == (*this->get(_row + 1, _col)).getAnimalChar(1)
						||
						(*_card).getAnimalChar(1) == (*this->get(_row + 1, _col)).getAnimalChar(0)
						||
						(*this->get(_row + 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row + 1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
			}
			
		}

		//4th comparison with the card on the right
		//we make sure that the current card is not in the last column
		if (_col < 102 && _col >= 0)
		{
			//we verify the orientation of the card to the right
			//if there's one at that position
			if (this->get(_row, _col + 1) != nullptr){
				if ((*this->get(_row, _col + 1)).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(3) == (*this->get(_row, _col + 1)).getAnimalChar(2)
						||
						(*_card).getAnimalChar(1) == (*this->get(_row, _col + 1)).getAnimalChar(0)
						||
						(*this->get(_row, _col + 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row, _col + 1)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(3) == (*this->get(_row, _col + 1)).getAnimalChar(1)
						||
						(*_card).getAnimalChar(1) == (*this->get(_row, _col + 1)).getAnimalChar(3)
						||
						(*this->get(_row, _col + 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row , _col + 1)).getAnimalChar(0) == 'c'
						)result++;
				}
			}
			
		}
		
	}

	else
	{
		//The card orientation is DOWN
		//1st comparison with the card above the card we are interrested with
		//we check if the current card is not on the first row
		if (_row > 0 && _row <= 102)
		{
			//we verify the orientation of the card above
			//if there's one at that position
			if (this->get(_row - 1, _col) != nullptr){
				if ((*(this->get(_row - 1, _col))).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(1) == (*this->get(_row - 1, _col)).getAnimalChar(0)
						||
						(*_card).getAnimalChar(0) == (*this->get(_row - 1, _col)).getAnimalChar(1)
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(1) == (*this->get(_row - 1, _col)).getAnimalChar(3)
						||
						(*_card).getAnimalChar(0) == (*this->get(_row - 1, _col)).getAnimalChar(2)
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row - 1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
			}
			
		}

		//2nd comparison with the card on the left
		//we make sure that the current card is not on in the first column
		if (_col > 0 && _col <= 102)
		{
			//we verify the orientation of the card to the left
			//if there's one there
			if (this->get(_row, _col - 1) != nullptr){
				if ((*this->get(_row, _col - 1)).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(1) == (*this->get(_row, _col - 1)).getAnimalChar(3)
						||
						(*_card).getAnimalChar(3) == (*this->get(_row, _col - 1)).getAnimalChar(1)
						||
						(*this->get(_row, _col - 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row, _col - 1)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(1) == (*this->get(_row, _col - 1)).getAnimalChar(0)
						||
						(*_card).getAnimalChar(3) == (*this->get(_row, _col - 1)).getAnimalChar(2)
						||
						(*this->get(_row, _col - 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row, _col - 1)).getAnimalChar(0) == 'c'
						)result++;
				}
			}
			
		}

		//3rd comparison with the card under the card we are interrested with
		//we check if the current card is not on the last row
		if (_row < 102 && _row >= 0)
		{
			//we verify the orientation of the card below
			//if there's one there
			if (this->get(_row + 1, _col) != nullptr){
				if ((*(this->get(_row + 1, _col))).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(3) == (*this->get(_row + 1, _col)).getAnimalChar(2)
						||
						(*_card).getAnimalChar(2) == (*this->get(_row + 1, _col)).getAnimalChar(3)
						||
						(*this->get(_row + 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row + 1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(3) == (*this->get(_row + 1, _col)).getAnimalChar(1)
						||
						(*_card).getAnimalChar(2) == (*this->get(_row + 1, _col)).getAnimalChar(0)
						||
						(*this->get(_row + 1, _col)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row + 1, _col)).getAnimalChar(0) == 'c'
						)result++;
				}
			}
			
		}

		//4th comparison with the card on the right
		//we make sure that the current card is not in the last column
		if (_col < 102 && _col >= 0)
		{
			//we verify the orientation of the card to the right
			//if there's one there
			if (this->get(_row, _col + 1) != nullptr){
				if ((*this->get(_row, _col + 1)).getOrientation() == Orientation::UP)
				{
					if (
						(*_card).getAnimalChar(0) == (*this->get(_row, _col + 1)).getAnimalChar(2)
						||
						(*_card).getAnimalChar(2) == (*this->get(_row, _col + 1)).getAnimalChar(0)
						||
						(*this->get(_row, _col + 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row, _col + 1)).getAnimalChar(0) == 'c'
						)result++;
				}
				else
				{
					if (
						(*_card).getAnimalChar(0) == (*this->get(_row, _col + 1)).getAnimalChar(1)
						||
						(*_card).getAnimalChar(2) == (*this->get(_row, _col + 1)).getAnimalChar(3)
						||
						(*this->get(_row, _col + 1)).getAnimalChar(0) == 'j'
						||
						(*this->get(_row, _col + 1)).getAnimalChar(0) == 'c'
						)result++;
				}
			}
			
		}
	}

	return result;
}


void Table::addPlayer(std::shared_ptr<Player> _player){
	this->players.push_back(_player);
}

std::vector<std::shared_ptr<Player>> Table::getPlayers(){
	return this->players;
}

bool isNotNull(std::shared_ptr<AnimalCard> _a){
	return (_a != nullptr);
}

int Table::firstPrintableColumn(){
	//each of the 103 std::vector contained in the table vector represents a line
	//so we will just apply the algorithm find_if on the 103 lines and get the smallest
	//non null first position within those lines
	//this position will represent the smallest column number that contains a non null element
	bool firstInitialization{ true };
	int index = -1;
	std::vector<std::shared_ptr<AnimalCard>>::iterator it;
	for (int i = 0; i < 103; i++){
		it = std::find_if(table.at(i).begin(), table.at(i).end(), isNotNull);
		//if the line does not have a non null element the last index will be returned
		if (it != table[i].end()){
			//we make sure the match is at a position lower than the current minIndex
			//we prefer to calculate the index this way rather than using distance
			//because we know our implementation of the table will not change to a list
			//and also the call to distance could make the whole method less efficient
			if (firstInitialization) {
				index = it - table[i].begin();
				firstInitialization = false;
			}
			else{
				//it is not the first initialization so we have to make sure the value
				//is less than the current index before considering it
				if (index > (it - table[i].begin()))index = it - table[i].begin();
			}
		}
	}

	return index;
}

int Table::lastPrintableColumn(){
	//each of the 103 std::vector contained in the table vector represents a line
	//so we will just apply the algorithm find_if on the 103 lines and get the biggest
	//non null last position within those lines
	//this position will represent the biggest column number that contains a non null element
	bool firstInitialization{ true };
	int index = -1;
	//we use a reverse_iterator  to find the first occurrence from the end of each vector
	//meaning we find the last non null occurence in each line
	std::vector<std::shared_ptr<AnimalCard>>::reverse_iterator rit;
	for (int i = 0; i < 103; i++){
		rit = std::find_if(table.at(i).rbegin(), table.at(i).rend(), isNotNull);
		//if the line does not have a non null element the last reversed_index will be returned
		// the last reversed_index is in fact the first index
		if (rit != table[i].rend()){
			//we make sure the match is at a position bigger than the current maxIndex
			//we prefer to calculate the index this way rather than using distance
			//because we know our implementation of the table will not change to a list
			//and also the call to distance could make the whole method less efficient
			if (firstInitialization) {
				index = rit - table[i].rbegin();
				firstInitialization = false;
			}
			else{
				//it is not the first initialization so we have to make sure the value
				//is greater than the current index before considering it
				//but since we are using reverse_iterator greater actually means a 
				//lower reverse_iterator index
				if (index > (rit - table[i].rbegin()))index = rit - table[i].rbegin();
			}
		}
	}

	//the value returned has to be adjusted to the actual representation of the table
	return 102-index;
}

int Table::firstPrintableLine(){
	//each of the 103 std::vector contained in the table vector represents a line
	//so we will just apply the algorithm find_if on the 103 lines and get the first
	//non null first line
	int index = -1;
	std::vector<std::shared_ptr<AnimalCard>>::iterator it;
	for (int i = 0; i < 103; i++){
		it = std::find_if(table.at(i).begin(), table.at(i).end(), isNotNull);
		//if the line does not have a non null element the last index will be returned
		if (it != table[i].end()){
			//the index of the first line that had a non null element and we break
			index = i;
			break;
		}
	}
	return index;
}

int Table::lastPrintableLine(){
	//each of the 103 std::vector contained in the table vector represents a line
	//so we will just apply the algorithm find_if on the 103 lines and get the last
	//non null line
	int index = -1;
	std::vector<std::shared_ptr<AnimalCard>>::iterator it;
	for (int i = 102; i > -1; i--){
		it = std::find_if(table.at(i).begin(), table.at(i).end(), isNotNull);
		//if the line does not have a non null element the last index will be returned
		if (it != table[i].end()){
			//the index of the first line that had a non null element and we break
			index = i;
			break;
		}
	}
	return index;
}

void Table::print(){

	std::cout << std::endl;
	std::cout << std::endl;

	if (firstPrintableLine() != -1){
		for (int i = firstPrintableLine(); i <= lastPrintableLine(); i++){
			//upper part of the line
			for (int j = firstPrintableColumn(); j <= lastPrintableColumn(); j++){
				if (table[i][j] != nullptr)table[i][j]->printRow(EvenOdd::ODD);
				else std::cout << "  ";
			}

			//print a line return before printing the lower part of the line
			std::cout << std::endl;

			//lower part of the line
			for (int j = firstPrintableColumn(); j <= lastPrintableColumn(); j++){
				if (table[i][j] != nullptr) table[i][j]->printRow(EvenOdd::EVEN);
				else std::cout << "  ";
			}

			//print a line return before printing a new line
			std::cout << std::endl;
		}

		//two line returns after printing out the whole table
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

//insertion operator
void Table::write(std::ostream& os){
	// write out individual members of t with an end of line between each one
	for (int i = 0; i < 103; i++){
		for (int j = 0; j < 103; j++){
			if (this->get(i,j) != nullptr){
				os << this->get(i, j).get()->getAnimalChar(2) << " ";
				os << this->get(i, j).get()->getAnimalChar(3) << " ";
				os << this->get(i, j).get()->getAnimalChar(0) << " ";
				os << this->get(i, j).get()->getAnimalChar(1) << " ";
				os << std::endl;
			}
			else os << std::endl;
		}
	}
	
}

void Table::read(std::istream& is){
	std::string s;
	int i = 0;
	char a2, a3, a0, a1;
	// read in individual members of t
	while (std::getline(is, s)){
		if (!s.empty()){
			is >> a2 >> a3 >> a0 >> a1;
			std::shared_ptr<SplitFour> splitFour(new SplitFour(a2, a3, a0, a1));
			this->addAt(splitFour, i / 102, i % 102);
		}
		i++;
	}
}