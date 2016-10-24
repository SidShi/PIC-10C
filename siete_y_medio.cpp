#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	int startMoney(100);
	Player MyMoney(startMoney);
	

	do {
		Hand MyHand, DealerHand;
		cout << "You have $" << MyMoney.get_money() << ". Enter bet: ";
		int bet;
		cin >> bet;
		cout << "Your cards: \n";
		for (int i = 0; i < MyHand.cards().size(); ++i) {
			cout << "\t\t" << MyHand.cards()[i].get_spanish_rank() << " de " << MyHand.cards()[i].get_spanish_suit() << "\t(" << MyHand.cards()[i].get_english_rank() << " of " << MyHand.cards()[i].get_english_suit() << ").\n";
		}
		double handvalue = MyHand.HandValue();
		cout << "Your total is " << handvalue << ". ";
		if (handvalue > 7.5) {
			cout << "You bust!\n";
		}
		else {
			char choice;
			cout << "Do you want another card? ";
			cin >> choice;
			while (choice == 'y') {
				Card nCard;
				cout << "New Card:\n";
				cout << "\t\t" << nCard.get_spanish_rank() << " de " << nCard.get_spanish_suit() << "\t(" << nCard.get_english_rank() << " of " << nCard.get_english_suit() << ").\n\n";
				MyHand.addCard(nCard);
				cout << "Your cards:\n";
				for (int i = 0; i < MyHand.cards().size(); ++i) {
					cout << "\t\t" << MyHand.cards()[i].get_spanish_rank() << " de " << MyHand.cards()[i].get_spanish_suit() << "\t(" << MyHand.cards()[i].get_english_rank() << " of " << MyHand.cards()[i].get_english_suit() << ").\n";
				}
				double handvaluem = MyHand.HandValue();
				cout << "Your total is " << handvaluem << ". ";
				if (handvaluem > 7.5) {
					cout << "You bust!\n";
					break;
				}
				else {
					cout << "Do you want another card? ";
					cin >> choice;
				}
			}
		}

		cout << "Dealer's cards:\n";
		for (int i = 0; i < DealerHand.cards().size(); ++i) {
			cout << "\t\t" << DealerHand.cards()[i].get_spanish_rank() << " de " << DealerHand.cards()[i].get_spanish_suit() << "\t(" << DealerHand.cards()[i].get_english_rank() << " of " << DealerHand.cards()[i].get_english_suit() << ").\n";
		}
		double dealervalue = DealerHand.HandValue();
		cout << "The dealer's total is " << dealervalue << ".\n";
		if (dealervalue > 7.5) {
			cout << "Dealer busts!\n";
		}
		else {
			while (dealervalue < 5.5) {
				Card nCard;
				cout << "New Card:\n\n";
				cout << "\t\t" << nCard.get_spanish_rank() << " de " << nCard.get_spanish_suit() << "\t(" << nCard.get_english_rank() << " of " << nCard.get_english_suit() << ").\n\n";
				DealerHand.addCard(nCard);
				cout << "Dealer's cards:\n";
				for (int i = 0; i < DealerHand.cards().size(); ++i) {
					cout << "\t\t" << DealerHand.cards()[i].get_spanish_rank() << " de " << DealerHand.cards()[i].get_spanish_suit() << "\t(" << DealerHand.cards()[i].get_english_rank() << " of " << DealerHand.cards()[i].get_english_suit() << ").\n";
				}
				double dealervaluem = DealerHand.HandValue();
				dealervalue = dealervaluem;
				cout << "Dealer's total is " << dealervaluem << ".\n";
				if (dealervaluem > 7.5) {
					cout << "Dealer busts!\n";
					break;
				}
			}
		}

		double handvaluef = MyHand.HandValue();
		double dealervaluef = DealerHand.HandValue();
		if (handvaluef > 7.5 && dealervaluef > 7.5) {
			cout << "House advantage. You lose " << bet << ".\n";
			MyMoney.moneyLoss(bet);
		}
		else if (handvaluef > 7.5 && dealervaluef <= 7.5) {
			cout << "Too bad. You lose " << bet << ".\n";
			MyMoney.moneyLoss(bet);
		}
		else if (handvaluef <= 7.5 && dealervaluef > 7.5) {
			cout << "You win " << bet << ".\n";
			MyMoney.moneyWin(bet);
		}
		else if (handvaluef < dealervaluef) {
			cout << "Too bad. You lose" << bet << ".\n";
			MyMoney.moneyLoss(bet);
		}
		else if (handvaluef == dealervaluef) {
			cout << "Nobody wins!\n";
		}
		else {
			cout << "You win " << bet << ".\n";
			MyMoney.moneyWin(bet);
		}


	} while (MyMoney.get_money() > 0);

	cout << "You have $0. GAME OVER!\n" << "Come back when you have more money.\n" << "Bye!\n";

	return 0;
}
