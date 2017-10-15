// author: levitan

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <string>

#include "Problem.h"

struct NPuzzleState {
	std::vector<std::vector<int> > board;
	int emptyi, emptyj, size;
	std::vector<int> operator[](int i) { return board[i]; }

	NPuzzleState(const std::string& str) {
		// split string into vector by whitespace
		int n;
		std::vector<int> v;
		std::stringstream iss(str);
		while (iss >> n) { v.push_back(n); }

		size = sqrt(v.size());
		// error checking
		if (sqrt(v.size()) != size) {
			throw "Error: input puzzle length is not square.";
		}

		// populate board (vector of vectors)
		for(int i = 0; i < size; i++) {
			std::vector<int> vv;
			for (int j = 0; j < size; j++) {
				vv.push_back(v[i * size + j]);
			}
			board.push_back(vv);
		}

		// find and save blank space location
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j]==0) {
					emptyi = i; emptyj = j;
					return;
				}
			}
		} throw "Error: did not find 0 in input puzzle.";
	}

	// copy constructor
	NPuzzleState(const NPuzzleState& rhs) {
		board = rhs.board;
		emptyi = rhs.emptyi; //board[i]
		emptyj = rhs.emptyj;
		size = rhs.size;
	}

	// TODO: implement a heuristic estimate of cost to solve
	// (will be called by A*)
	int nMisplaced(){
		int count = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (board[i][j]!= i * size + j) {
					count++;
				}

			}
		}
		return count;
	}





	// operator overloads
	bool operator==(const NPuzzleState& rhs) const {
		return board==rhs.board;
	}
	friend std::ostream& operator<<(std::ostream& stream, const NPuzzleState& rhs) {
		int ndigits = ceil(log10(rhs.board.size()^2));
		for (int i = 0; i < rhs.board.size(); i++) {
			for (int j = 0; j < rhs.board[i].size(); j++) {
				stream << std::setw(ndigits) << rhs.board[i][j] << " ";
			}
			if (i < rhs.board.size()-1) stream << std::endl;
		}
		return stream;
	}
	bool operator<(const NPuzzleState& rhs) const { // must be overloaded so can put states in set.
		return board < rhs.board;
	}

};


class NPuzzle : public Problem<NPuzzleState> {
	public:
	NPuzzle(const std::string& str) :
			Problem<NPuzzleState>(NPuzzleState(str)) {}

	bool isGoalState(const NPuzzleState& s) const {
		// TODO: return true if state is a goal state (numbers are in order
		// with 0 at location 0, 0)
			for (int i = 0; i < s.size; i++) {
				for (int j = 0; j < s.size; j++) {
					if (s.board[i][j]!= i * s.size + j) {
						return false;
					}

				}
			}
			return true;
	}

	std::vector<std::pair<std::string, NPuzzleState> > expand(const NPuzzleState& s) const {
		// TODO: return vector of child states resulting from applying
		// all possible moves IN ORDER: left, right, up, down, paired with
		// the corresponding move
		// structure is { (move, state), (move, state), ... }
		std::vector<std::pair<std::string, NPuzzleState>> childrenState;
		int temp;





			NPuzzleState s1 = s;
			NPuzzleState s2 = s;  //  1 3
			NPuzzleState s3 = s;  //  2 0
			NPuzzleState s4 = s;
	  // move left

		if(s1.emptyi >= 0 && s1.emptyj - 1 >= 0 && s1.emptyi < s1.size && s1.emptyj - 1 < s1.size){
				temp = s1.board[s1.emptyi][s1.emptyj - 1];
				s1.board[s1.emptyi][s1.emptyj - 1] = s1.board[s1.emptyi][s1.emptyj];
				s1.board[s1.emptyi][s1.emptyj] = temp;
				s1.emptyj --;

				childrenState.push_back(std::make_pair("LEFT ", s1));

		}

		// move right

		if(s2.emptyi >= 0 && s2.emptyj + 1 >= 0 && s2.emptyi < s2.size && s2.emptyj + 1 < s2.size){
				temp = s2.board[s2.emptyi][s2.emptyj + 1];
				s2.board[s2.emptyi][s2.emptyj + 1] = s2.board[s2.emptyi][s2.emptyj];
				s2.board[s2.emptyi][s2.emptyj] = temp;
				s2.emptyj++;
				childrenState.push_back(std::make_pair("RIGHT ", s2));

		}

		//move up
		if(s3.emptyi - 1>= 0 && s3.emptyj>= 0 && s3.emptyi - 1 < s3.size && s3.emptyj < s3.size){
				temp = s3.board[s3.emptyi - 1][s3.emptyj];
				s3.board[s3.emptyi - 1][s3.emptyj] = s3.board[s3.emptyi][s3.emptyj];
				s3.board[s3.emptyi][s3.emptyj] = temp;
				s3.emptyi--;
				childrenState.push_back(std::make_pair("UP ", s3));

		}

		// move down

		if(s4.emptyi + 1 >= 0 && s4.emptyj >= 0 && s4.emptyi + 1 < s4.size && s4.emptyj < s4.size){
				temp = s4.board[s4.emptyi + 1][s4.emptyj];
				s4.board[s4.emptyi + 1][s4.emptyj] = s4.board[s4.emptyi][s4.emptyj];
				s4.board[s4.emptyi][s4.emptyj] = temp;
				s4.emptyi++;
				childrenState.push_back(std::make_pair("DOWN ", s4));
		}


	return childrenState;
}
};
