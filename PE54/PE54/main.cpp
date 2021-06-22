#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

enum val { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K, A };
enum typ { H, C, S, D};
enum status {INIT_STAT, HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_KIND, STRA, FLUSH, FULL_HUS, FOUR_KIND, STRA_FLUSH, ROY_FLUSH};

class Card
{
public:
	val value;
	typ type;
};

bool compare_func(Card c1, Card c2)
{
	return c1.value < c2.value;
}

class Deck
{
public:
	Card card[5];
	Card h_card;
	status stat = INIT_STAT;

	void calc_stat();

	//Assumes a sorted order of cards
	//Also assume the order at which they are called in calc_stat
	//E.g  If it is not a royal flush try straight flush assuming it is not a royal flush
	bool is_royal_flush();
	bool is_stra_flush();
	bool is_four_kind();
	bool is_full_hus();
	bool is_flush();
	bool is_stra();
	bool is_three_kind();
	bool is_two_pair();
	bool is_one_pair();
	Card high_card();
};

void Deck::calc_stat()
{
	sort(card, card + 5, compare_func);
	if (is_royal_flush())
		stat = ROY_FLUSH;
	else if (is_stra_flush())
		stat = STRA_FLUSH;
	else if (is_four_kind())
		stat = FOUR_KIND;
	else if (is_full_hus())
		stat = FULL_HUS;
	else if (is_flush())
		stat = FLUSH;
	else if (is_stra())
		stat = STRA;
	else if (is_three_kind())
		stat = THREE_KIND;
	else if (is_two_pair())
		stat = TWO_PAIR;
	else if (is_one_pair())
		stat = ONE_PAIR;
	else
	{
		Card res = high_card();
		stat = HIGH_CARD;
		h_card = res;
	}
}

bool Deck::is_flush()
{
	if (card[0].type == card[1].type && card[0].type == card[2].type && card[0].type == card[3].type && card[0].type == card[4].type)
		return true;
	return false;
}

bool Deck::is_royal_flush()
{
	if (is_flush())
	{
		if (card[0].value == TEN && card[1].value == J && card[2].value == Q && card[3].value == K && card[4].value == A)
			return true;
		return false;
	}
	return false;
}

bool Deck::is_stra()
{
	for (int i = 1; i < 5; ++i)
	{
		if (card[i].value != card[i - 1].value + 1)
			return false;
	}
	return true;
}

bool Deck::is_stra_flush()
{
	if (is_flush() && is_stra())
		return true;
	return false;
}

bool Deck::is_three_kind()
{
	for (int i = 0; i < 3; ++i)
	{
		if (card[i].value == card[i + 1].value && card[i].value == card[i + 2].value)
			return true;
	}
	return false;
}

bool Deck::is_full_hus()
{
	if (card[0].value == card[1].value && card[0].value == card[2].value && card[3].value == card[4].value)
		return true;
	else if (card[0].value == card[1].value && card[2].value == card[3].value && card[2].value == card[4].value)
		return true;
	return false;
}

bool Deck::is_two_pair()
{
	if (card[0].value == card[1].value && card[2].value == card[3].value)
		return true;
	else if (card[0].value == card[1].value && card[3].value == card[4].value)
		return true;
	else if (card[1].value == card[2].value && card[3].value == card[4].value)
		return true;
	return false;
}

bool Deck::is_one_pair()
{
	for (int i = 1; i < 5; ++i)
	{
		if (card[i].value == card[i - 1].value)
			return true;
	}
	return false;
}

bool Deck::is_four_kind()
{
	for (int i = 0; i < 2; ++i)
	{
		if (card[i].value == card[i + 1].value && card[i].value == card[i + 2].value && card[i].value == card[i + 3].value)
			return true;
	}
	return false;
}

Card Deck::high_card()
{
	return card[4];
}

val char_val(char c)
{
	switch (c)
	{
	case '2':
		return TWO;
	case '3':
		return THREE;
	case '4':
		return FOUR;
	case '5':
		return FIVE;
	case '6':
		return SIX;
	case '7':
		return SEVEN;
	case '8':
		return EIGHT;
	case '9':
		return NINE;
	case 'T':
		return TEN;
	case 'J':
		return J;
	case 'Q':
		return Q;
	case 'K':
		return K;
	case 'A':
		return A;
	}
}

typ char_typ(char c)
{
	switch (c)
	{
	case 'H':
		return H;
	case 'C':
		return C;
	case 'S':
		return S;
	case 'D':
		return D;
	}
}

bool compare_deck(Deck d1, Deck d2)
{
	d1.calc_stat();
	d2.calc_stat();

	if (d1.stat > d2.stat)
		return true;
	else if (d1.stat < d2.stat)
		return false;
	else if (d1.stat == HIGH_CARD)
	{
		if (d1.h_card.value > d2.h_card.value)
			return true;
		else if (d1.h_card.value < d2.h_card.value)
			return false;
		else throw(exception("Equal decks high card error"));
	}
	//when they have equal status
	else if (d1.stat == ONE_PAIR)
	{
		//Calculate the indexes of the pair 
		int x1, x2;
		for (int i = 1; i < 5; ++i)
		{
			if (d1.card[i].value == d1.card[i - 1].value)
			{
				x1 = i - 1;
				x2 = i;
			}
		}

		int y1, y2;
		for (int i = 1; i < 5; ++i)
		{
			if (d2.card[i].value == d2.card[i - 1].value)
			{
				y1 = i - 1;
				y2 = i;
			}
		}

		//Compare the pairs
		if (d1.card[x1].value > d2.card[y1].value)
			return true;
		else if (d1.card[x1].value < d2.card[y1].value)
			return false;
		else //if they are equal calculate the kicker values
		{
			int k1 = -20;//Smaller than all possible vals
			for (int i = 0; i < 5; ++i)
			{
				if (i == x1 || i == x2)//Skip the pair
					continue;

				if (d1.card[i].value > k1)
					k1 = d1.card[i].value;
			}

			int k2 = -20;//Smaller than all possible vals
			for (int i = 0; i < 5; ++i)
			{
				if (i == y1 || i == y2)//Skip the pair
					continue;

				if (d2.card[i].value > k2)
					k2 = d2.card[i].value;
			}

			if (k1 > k2)
				return true;
			else if (k2 > k1)
				return false;
			else
				throw exception("Equal values");
		}
	}
	else if (d1.stat == TWO_PAIR)
	{
		int x1 = -1, x2 = -1;
		for (int i = 1; i < 5; ++i)
		{
			if (d1.card[i].value == d1.card[i - 1].value && x1 == -1)
				x1 = i - 1;
			else if (d1.card[i].value == d1.card[i - 1].value)
				x2 = i - 1;
		}

		int y1 = -1, y2 = -1;
		for (int i = 1; i < 5; ++i)
		{
			if (d2.card[i].value == d2.card[i - 1].value && y1 == -1)
				y1 = i - 1;
			else if (d2.card[i].value == d2.card[i - 1].value)
				y2 = i - 1;
		}

		if (d1.card[x2].value > d2.card[y2].value)
			return true;
		else if (d1.card[x2].value < d2.card[y2].value)
			return false;
		else if (d1.card[x1].value > d2.card[y1].value)
			return true;
		else if (d1.card[x1].value < d2.card[y1].value)
			return false;
		else//Assuming both the pairs are equal calculate the kickers
		{
			int k1;
			for (int i = 0; i < 5; ++i)
			{
				if (i == x1 || i == x1 + 1 || i == x2 || i == x2 + 1)
					continue;
				k1 = d1.card[i].value;
			}
			
			int k2;
			for (int i = 0; i < 5; ++i)
			{
				if (i == y1 || i == y1 + 1 || i == y2 || i == y2 + 1)
					continue;
				k2 = d2.card[i].value;
			}

			if (k1 > k2)
				return true;
			else if (k1 < k2)
				return false;
			else
				throw exception("Equal decks");
		}
	}
	else if (d1.stat == THREE_KIND)
	{
		int x1;//The first index of the the three similar cards
		for (int i = 0; i < 3; ++i)
		{
			if (d1.card[i].value == d1.card[i + 1].value && d1.card[i].value == d1.card[i + 2].value)
				x1 = i;
		}

		int y1;
		for (int i = 0; i < 3; ++i)
		{
			if (d2.card[i].value == d2.card[i + 1].value && d2.card[i].value == d2.card[i + 2].value)
			{
				y1 = i;
			}
		}

		if (d1.card[x1].value > d2.card[y1].value)
			return true;
		else if (d1.card[x1].value < d2.card[y1].value)
			return false;
		else
		{
			int k1 = -1;
			for (int i = 0; i < 5; ++i)
			{
				if (i == x1 || i == x1 + 1 || i == x1 + 2)
					continue;
				else if (d1.card[i].value > k1)
					k1 = d1.card[i].value;
			}

			int k2 = -1;
			for (int i = 0; i < 5; ++i)
			{
				if (i == y1 || i == y1 + 1 || i == y1 + 2)
					continue;
				else if (d2.card[i].value > k2)
					k2 = d2.card[i].value;
			}

			if (k1 > k2)
				return true;
			else if (k2 > k1)
				return false;
			else
				throw exception("Equal decks");
		}
	}
	else if (d1.stat == STRA)
	{
	if (d1.card[4].value > d2.card[4].value)
		return true;
	else if (d1.card[4].value < d2.card[4].value)
		return false;
	else
		throw exception("Equal decks");
	}
	else if (d1.stat == FLUSH)
	{
		if (d1.card[4].value > d2.card[4].value)
			return true;
		else if (d1.card[4].value < d2.card[4].value)
			return false;
		else
			throw exception("Equal decks");
	}
	else if (d1.stat == FULL_HUS)
	{
		int x1;
		for (int i = 0; i < 3; ++i)
		{
			if (d1.card[i].value == d1.card[i + 1].value && d1.card[i].value == d1.card[i + 2].value)
				x1 = i;
		}

		int x2;
		if (x1 == 0)
			x2 = 3;
		else if (x1 == 2)
			x2 = 0;
		else throw exception("FULL HOUSE ERROR");

		int y1;
		for (int i = 0; i < 3; ++i)
		{
			if (d2.card[i].value == d2.card[i + 1].value && d2.card[i].value == d2.card[i + 2].value)
				y1 = i;
		}

		int y2;
		if (y1 == 0)
			y2 = 3;
		else if (y1 == 2)
			y2 = 0;
		else throw exception("FULL HOUSE ERROR!");

		if (d1.card[x1].value > d2.card[y1].value)
			return true;
		else if (d1.card[x1].value < d2.card[y1].value)
			return false;
		else if (d1.card[x2].value > d2.card[y2].value)
			return true;
		else if (d1.card[x2].value < d2.card[y2].value)
			return false;
		else
			throw exception("Equal decks");
	}
	else if (d1.stat == FOUR_KIND)
	{
		int x1;
		for (int i = 0; i < 2; ++i)
		{
			if (d1.card[i].value == d1.card[i + 1].value && d1.card[i].value == d1.card[i + 2].value && d1.card[i].value == d1.card[i + 3].value)
				x1 = i;
		}

		int y1;
		for (int i = 0; i < 2; ++i)
		{
			if (d2.card[i].value == d2.card[i + 1].value && d2.card[i].value == d2.card[i + 2].value && d2.card[i].value == d2.card[i + 3].value)
				y1 = i;
		}

		if (d1.card[x1].value > d2.card[y1].value)
			return true;
		else if (d1.card[x1].value < d2.card[y1].value)
			return false;
		else
		{
			int x2;
			if (x1 == 0)
				x2 = 4;
			else if (x1 == 1)
				x2 = 0;
			else throw(exception("FOUR KIND ERROR"));

			int y2;
			if (y1 == 0)
				y2 = 4;
			else if (y1 == 1)
				y2 = 0;
			else throw(exception("FOUR KIND ERROR"));

			if (d1.card[x2].value > d2.card[y2].value)
				return true;
			else if (d1.card[x2].value < d2.card[y2].value)
				return false;
			else
				throw exception("Equal decks");
		}
	}
	else if (d1.stat == STRA_FLUSH)
	{
		if (d1.card[4].value > d2.card[4].value)
			return true;
		else if (d1.card[4].value < d2.card[4].value)
			return false;
		else
			throw exception("Equal decks");
	}
	else if (d1.stat == ROY_FLUSH)
	{
	throw exception("Equal decks");
	}
}

int main()
{
	try
	{
		int res = 0;
		Deck d1, d2;
		ifstream file("poker.txt");

		for (int i = 1; i <= 1000; ++i)
		{
			for (int i = 1; i <= 10; ++i)
			{
				string str;
				file >> str;
				if (i <= 5)
				{
					d1.card[i - 1].value = char_val(str[0]);
					d1.card[i - 1].type = char_typ(str[1]);
				}
				else
				{
					d2.card[i - 6].value = char_val(str[0]);
					d2.card[i - 6].type = char_typ(str[1]);
				}
			}

			//Compare the decks
			if (compare_deck(d1, d2))
				++res;
		}		
		cout << "Result: " << res << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}