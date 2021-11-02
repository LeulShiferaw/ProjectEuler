//Not accurate
//Answer is 101524, but the solution is not accurate for 15 and 24 it gets different results on different attempts
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int NUM_TRIES = 100000;

int rand_num(int l, int h)
{
	return rand() % (h - l + 1) + l;
}

int roll_dice()
{
	return rand_num(1, 6);
}

enum class CC {GO, G2J, STAY};
enum class CH { GO, G2J, C1, E3, H2, R1, RC1, RC2, UC, SQ3, STAY };

CC comm_cards[16];
CH chan_cards[16];
pair<int, int> num_visit[40];

void initialize_cards()
{
	for (int i = 0; i < 40; ++i)
	{
		num_visit[i].first = 0;
		num_visit[i].second = i;
	}

	comm_cards[0] = CC::GO;
	comm_cards[1] = CC::G2J;

	for (int i = 2; i < 16; ++i)
		comm_cards[i] = CC::STAY;

	chan_cards[0] = CH::GO;
	chan_cards[1] = CH::G2J;
	chan_cards[2] = CH::C1;
	chan_cards[3] = CH::E3;
	chan_cards[4] = CH::H2;
	chan_cards[5] = CH::R1;
	chan_cards[6] = CH::RC1;
	chan_cards[7] = CH::RC2;
	chan_cards[8] = CH::UC;
	chan_cards[9] = CH::SQ3;

	for (int i = 10; i < 16; ++i)
		chan_cards[i] = CH::STAY;
}

CC pop_cc()
{
	CC res = comm_cards[15];
	for (int i = 15; i >= 1; --i)
	{
		comm_cards[i] = comm_cards[i - 1];
	}
	comm_cards[0] = res;
	return res;
}

CH pop_ch()
{
	CH res = chan_cards[15];
	for (int i = 15; i >= 1; --i)
	{
		chan_cards[i] = chan_cards[i - 1];
	}
	chan_cards[0] = res;
	return res;
}

void shuffle()
{
	for (int i = 0; i < 16; ++i)
	{
		int cc_ind = rand_num(i, 15);
		swap(comm_cards[i], comm_cards[cc_ind]);

		int ch_ind = rand_num(i, 15);
		swap(chan_cards[i], chan_cards[ch_ind]);
	}
}

int main()
{
	srand(time(0));

	initialize_cards();
	shuffle();

	int curr_sq = 0;
	int num_doulbes = 0;
	for (int i = 0; i < NUM_TRIES; ++i)
	{
		int dice1 = roll_dice();
		int dice2 = roll_dice();

		if (dice1 == dice2)
			++num_doulbes;
		else num_doulbes = 0;

		if (num_doulbes == 3)
		{
			num_doulbes = 0;
			curr_sq = 10;
			++num_visit[curr_sq].first;
			continue;
		}

		curr_sq += dice1 + dice2;
		curr_sq %= 40;

		switch (curr_sq)
		{
		case 2: case 17: case 33: 
		{
			CC card = pop_cc();
			if (card == CC::G2J)
				curr_sq = 10;
			else if (card == CC::GO)
				curr_sq = 0;
			break;
		}
		case 7: case 22: case 36:
		{
			CH card = pop_ch();
			if (card == CH::C1)
				curr_sq = 11;
			else if (card == CH::E3)
				curr_sq = 24;
			else if (card == CH::G2J)
				curr_sq = 10;
			else if (card == CH::GO)
				curr_sq = 0;
			else if (card == CH::H2)
				curr_sq = 39;
			else if (card == CH::R1)
				curr_sq = 5;
			else if (card == CH::RC1 || card == CH::RC2)
			{
				if (curr_sq == 7)
					curr_sq = 15;
				else if (curr_sq == 22)
					curr_sq = 25;
				else if (curr_sq == 36)
					curr_sq = 5;
			}
			else if (card == CH::SQ3)
			{
				if (curr_sq == 0)
					curr_sq = 37;
				else if (curr_sq == 1)
					curr_sq = 38;
				else if (curr_sq == 2)
					curr_sq = 39;
				else curr_sq -= 3;
			}
			break;
		}
		}
		++num_visit[curr_sq].first;
	}

	for (int i = 0; i < 40; ++i)
		cout << num_visit[i].first << " " << num_visit[i].second << endl;
	sort(num_visit, num_visit + 40);

	cout << num_visit[39].first / (double)NUM_TRIES << " " << num_visit[39].second << endl;
	cout << num_visit[38].first / (double)NUM_TRIES << " " << num_visit[38].second << endl;
	cout << num_visit[37].first / (double)NUM_TRIES << " " << num_visit[37].second << endl;
	cout << num_visit[36].first / (double)NUM_TRIES << " " << num_visit[36].second << endl;
	cout << num_visit[35].first / (double)NUM_TRIES << " " << num_visit[35].second << endl;

	return 0;
}