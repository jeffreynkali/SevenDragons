/*
Mpoyo Nkali Glen Jeffrey 7977228
Mohamadou Ly 7974677
*/

#include "AnimalCardFactory.h"

AnimalCardFactory* AnimalCardFactory::factory = nullptr;

AnimalCardFactory::AnimalCardFactory(){
	std::shared_ptr<Joker> joker(new Joker());
	std::shared_ptr<BearAction> bearAction1(new BearAction());
	std::shared_ptr<BearAction> bearAction2(new BearAction());
	std::shared_ptr<BearAction> bearAction3(new BearAction());
	std::shared_ptr<DeerAction> deerAction1(new DeerAction());
	std::shared_ptr<DeerAction> deerAction2(new DeerAction());
	std::shared_ptr<DeerAction> deerAction3(new DeerAction());
	std::shared_ptr<HareAction> hareAction1(new HareAction());
	std::shared_ptr<HareAction> hareAction2(new HareAction());
	std::shared_ptr<HareAction> hareAction3(new HareAction());
	std::shared_ptr<MooseAction> mooseAction1(new MooseAction());
	std::shared_ptr<MooseAction> mooseAction2(new MooseAction());
	std::shared_ptr<MooseAction> mooseAction3(new MooseAction());
	std::shared_ptr<WolfAction> wolfAction1(new WolfAction());
	std::shared_ptr<WolfAction> wolfAction2(new WolfAction());
	std::shared_ptr<WolfAction> wolfAction3(new WolfAction());

	//NoSplit cards
	std::shared_ptr<NoSplit> noSplit1(new NoSplit('b'));
	std::shared_ptr<NoSplit> noSplit2(new NoSplit('d'));
	std::shared_ptr<NoSplit> noSplit3(new NoSplit('h')); 
	std::shared_ptr<NoSplit> noSplit4(new NoSplit('m'));
	std::shared_ptr<NoSplit> noSplit5(new NoSplit('w'));

	//cards splitted in two horizontally (format = 1)
	std::shared_ptr<SplitTwo> splitTwo1H(new SplitTwo('b', 'd', 1));
	std::shared_ptr<SplitTwo> splitTwo2H(new SplitTwo('d', 'h', 1));
	std::shared_ptr<SplitTwo> splitTwo3H(new SplitTwo('h', 'm', 1));
	std::shared_ptr<SplitTwo> splitTwo4H(new SplitTwo('m', 'w', 1));
	std::shared_ptr<SplitTwo> splitTwo5H(new SplitTwo('w', 'b', 1));

	//cards splitted in two vertically (format = 0)
	std::shared_ptr<SplitTwo> splitTwo1V(new SplitTwo('b', 'd', 0));
	std::shared_ptr<SplitTwo> splitTwo2V(new SplitTwo('d', 'h', 0));
	std::shared_ptr<SplitTwo> splitTwo3V(new SplitTwo('h', 'm', 0));
	std::shared_ptr<SplitTwo> splitTwo4V(new SplitTwo('m', 'w', 0));
	std::shared_ptr<SplitTwo> splitTwo5V(new SplitTwo('w', 'b', 0));

	//cards splitted in three horizontally (format = 1)
	std::shared_ptr<SplitThree> splitThree1H(new SplitThree('b', 'd', 'h', 1));
	std::shared_ptr<SplitThree> splitThree2H(new SplitThree('b', 'm', 'w', 1));
	std::shared_ptr<SplitThree> splitThree3H(new SplitThree('d', 'h', 'm', 1));
	std::shared_ptr<SplitThree> splitThree4H(new SplitThree('d', 'w', 'b', 1));
	std::shared_ptr<SplitThree> splitThree5H(new SplitThree('h', 'm', 'w', 1));
	std::shared_ptr<SplitThree> splitThree6H(new SplitThree('h', 'b', 'd', 1));
	std::shared_ptr<SplitThree> splitThree7H(new SplitThree('m', 'w', 'b', 1));
	std::shared_ptr<SplitThree> splitThree8H(new SplitThree('m', 'd', 'h', 1));
	std::shared_ptr<SplitThree> splitThree9H(new SplitThree('w', 'b', 'd', 1));
	std::shared_ptr<SplitThree> splitThree10H(new SplitThree('w', 'h', 'm', 1));

	//cards splitted in three vertically (format = 0)
	std::shared_ptr<SplitThree> splitThree1V(new SplitThree('b', 'd', 'h', 0));
	std::shared_ptr<SplitThree> splitThree2V(new SplitThree('b', 'm', 'w', 0));
	std::shared_ptr<SplitThree> splitThree3V(new SplitThree('d', 'h', 'm', 0));
	std::shared_ptr<SplitThree> splitThree4V(new SplitThree('d', 'w', 'b', 0));
	std::shared_ptr<SplitThree> splitThree5V(new SplitThree('h', 'm', 'w', 0));
	std::shared_ptr<SplitThree> splitThree6V(new SplitThree('h', 'b', 'd', 0));
	std::shared_ptr<SplitThree> splitThree7V(new SplitThree('m', 'w', 'b', 0));
	std::shared_ptr<SplitThree> splitThree8V(new SplitThree('m', 'd', 'h', 0));
	std::shared_ptr<SplitThree> splitThree9V(new SplitThree('w', 'b', 'd', 0));
	std::shared_ptr<SplitThree> splitThree10V(new SplitThree('w', 'h', 'm', 0));

	//card splited in four with b as the common animal
	std::shared_ptr<SplitFour> splitFourB1(new SplitFour('b', 'd', 'h', 'm'));
	std::shared_ptr<SplitFour> splitFourB2(new SplitFour('b', 'h', 'm', 'w'));
	std::shared_ptr<SplitFour> splitFourB3(new SplitFour('b', 'm', 'w', 'd'));

	//card splitted in four with d as the common animal
	std::shared_ptr<SplitFour> splitFourD1(new SplitFour('d', 'h', 'm', 'w'));
	std::shared_ptr<SplitFour> splitFourD2(new SplitFour('d', 'm', 'w', 'b'));
	std::shared_ptr<SplitFour> splitFourD3(new SplitFour('d', 'w', 'b', 'h'));

	//card splitted in four with h as the common animal
	std::shared_ptr<SplitFour> splitFourH1(new SplitFour('h', 'm', 'w', 'b'));
	std::shared_ptr<SplitFour> splitFourH2(new SplitFour('h', 'w', 'b', 'd'));
	std::shared_ptr<SplitFour> splitFourH3(new SplitFour('h', 'b', 'd', 'm'));

	//card splitted in four with m as the common animal
	std::shared_ptr<SplitFour> splitFourM1(new SplitFour('m', 'w', 'b', 'd'));
	std::shared_ptr<SplitFour> splitFourM2(new SplitFour('m', 'b', 'd', 'h'));
	std::shared_ptr<SplitFour> splitFourM3(new SplitFour('m', 'd', 'h', 'w'));

	//card splitted in four with w as the common animal
	std::shared_ptr<SplitFour> splitFourW1(new SplitFour('w', 'b', 'd', 'h'));
	std::shared_ptr<SplitFour> splitFourW2(new SplitFour('w', 'd', 'h', 'm'));
	std::shared_ptr<SplitFour> splitFourW3(new SplitFour('w', 'h', 'm', 'b'));

	deck.push_back(joker);
	deck.push_back(bearAction1);
	deck.push_back(bearAction2);
	deck.push_back(bearAction3);
	deck.push_back(deerAction1);
	deck.push_back(deerAction2);
	deck.push_back(deerAction3);
	deck.push_back(hareAction1);
	deck.push_back(hareAction2);
	deck.push_back(hareAction3);
	deck.push_back(mooseAction1);
	deck.push_back(mooseAction2);
	deck.push_back(mooseAction3);
	deck.push_back(wolfAction1);
	deck.push_back(wolfAction2);
	deck.push_back(wolfAction3);
	deck.push_back(noSplit1);
	deck.push_back(noSplit2);
	deck.push_back(noSplit3);
	deck.push_back(noSplit4);
	deck.push_back(noSplit5);
	deck.push_back(splitTwo1H);
	deck.push_back(splitTwo2H);
	deck.push_back(splitTwo3H);
	deck.push_back(splitTwo4H);
	deck.push_back(splitTwo5H);
	deck.push_back(splitTwo1V);
	deck.push_back(splitTwo2V);
	deck.push_back(splitTwo3V);
	deck.push_back(splitTwo4V);
	deck.push_back(splitTwo5V);
	deck.push_back(splitThree1H);
	deck.push_back(splitThree2H);
	deck.push_back(splitThree3H);
	deck.push_back(splitThree4H);
	deck.push_back(splitThree5H);
	deck.push_back(splitThree6H);
	deck.push_back(splitThree7H);
	deck.push_back(splitThree8H);
	deck.push_back(splitThree9H);
	deck.push_back(splitThree10H);
	deck.push_back(splitThree1V);
	deck.push_back(splitThree2V);
	deck.push_back(splitThree3V);
	deck.push_back(splitThree4V);
	deck.push_back(splitThree5V);
	deck.push_back(splitThree6V);
	deck.push_back(splitThree7V);
	deck.push_back(splitThree8V);
	deck.push_back(splitThree9V);
	deck.push_back(splitThree10V);
	deck.push_back(splitFourB1);
	deck.push_back(splitFourB2);
	deck.push_back(splitFourB3);
	deck.push_back(splitFourD1);
	deck.push_back(splitFourD2);
	deck.push_back(splitFourD3);
	deck.push_back(splitFourH1);
	deck.push_back(splitFourH2);
	deck.push_back(splitFourH3);
	deck.push_back(splitFourM1);
	deck.push_back(splitFourM2);
	deck.push_back(splitFourM3);
	deck.push_back(splitFourW1);
	deck.push_back(splitFourW2);
	deck.push_back(splitFourW3);
	
	

}

AnimalCardFactory* AnimalCardFactory::getFactory(){
	if (!factory) factory = new AnimalCardFactory();
	return factory;
}

AnimalCardFactory::~AnimalCardFactory(){
	delete factory;
}

Deck<std::shared_ptr<AnimalCard>> AnimalCardFactory::getDeck(){
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);
	return deck;
}