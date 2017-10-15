// author: Gushu Qin

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>


template <class T>
const T& next(std::stack<T> s) { return s.top(); }
template <class T>
const T& next(std::queue<T> q) { return q.front(); }
template <class T, class Compare>
const T& next(std::priority_queue<T, std::vector<T>, Compare> pq) { return pq.top(); }

template <class State>
struct Node {
	Node<State>* parent;
	std::string action;
	int pathCost;
	State state;
	Node(Node<State>* p, const std::string& a, int c, State s) :
		parent(p), action(a), pathCost(c), state(s) {}
	friend std::ostream& operator<<(std::ostream& stream, Node<State>* n) {
		stream << n->state << std::endl << "action: " << n->action;
		if (n->parent) stream << ", parent action: " << n->parent->action;
		else stream << ", startState";
		stream << "\ncost: " << n->pathCost << ", heuristic: " << n->state.nMisplaced();
		stream << std::endl;
		return stream;
	}
};

template <class State>
struct AstarCompare {
	bool operator()(Node<State>* lhs, Node<State>* rhs) {
		// TODO Remember that the node with the LOWER cost should be
		// GREATER
		return (lhs->pathCost + lhs->state.nMisplaced() > rhs->pathCost + rhs->state.nMisplaced()) ? true:false;
	}
};



template <class State>
class Problem {
	State startState;

	public:
	Problem(State s) : startState(s) {}
	virtual bool isGoalState(const State& s) const =0;
	virtual std::vector<std::pair<std::string, State> > expand(const State& s) const =0;
	const State& getStartState() { return startState; }

	template <class C>
	std::string solve(C fringe) {
		Node<State>* n = new Node<State>(NULL, "START", 0, startState);
		// TODO

		std::set<State> visited;

		std::string solution;
		//std::string csolution;
		//std::vector<std::string> words;



		C copy;
		Node<State>* newNode;

		fringe.push(n);


		while(!fringe.empty()){
					n = ::next(fringe);
					fringe.pop();
					if(isGoalState(n->state)){
							while(n != NULL){
								solution += n->action;
								n = n->parent;
							}
							return solution;
					}
					else{
							visited.insert(n->state);


							std::vector<std::pair<std::string,State>> childrenState = expand(n->state);


					while(!childrenState.empty()){
						newNode = new Node<State>(n, childrenState.front().first , n->pathCost+1, childrenState.front().second);
						childrenState.erase(childrenState.begin());

					copy = fringe;

					bool m = false;
					while(!copy.empty()){
						if(newNode->state == ::next(copy)->state){
							m = true;
							copy.pop();
						}
						else
							copy.pop();
					}
					if(!(visited.count(newNode->state) || m))  {
						fringe.push(newNode);
					}

				}
}

	}
	if(isGoalState(n->state)){
			while(n != NULL){
				solution += n->action;
				n = n->parent;
			}
			return solution;
	}

		return "did not find path";


}




	std::string BFS() {
		// TODO
		return solve(std::queue<Node<State>*>());

	}

	std::string DFS() {
		return solve(std::stack<Node<State>*>());
	}

	std::string Astar() {
		return solve(std::priority_queue<Node<State>*, std::vector<Node<State>*>, AstarCompare<State>>());
	}

	std::string solve(char c) {
		switch (c) {
			case 'b': return BFS();
			case 'd': return DFS();
			case 'a': return Astar();
		}
	}
};
