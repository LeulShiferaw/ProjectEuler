#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

vector<int> additionChain(int n) {
    // Queue for BFS, each element is a chain (vector of numbers)
    queue<vector<int>> q;
    
    // Start with the chain [1]
    q.push({1});
    
    // Set to keep track of visited numbers to avoid repetition
    set<int> visited;
    visited.insert(1);

    while (!q.empty()) {
        // Get the current chain
        vector<int> chain = q.front();
        q.pop();

        // Get the last number in the current chain
        int lastNumber = chain.back();

        // If the last number equals n, we have found the chain
        if (lastNumber == n) {
            return chain;
        }

        // Try to add any number in the chain to the last number
        for (int i = 0; i < (int)chain.size(); ++i) {
            int newNumber = lastNumber + chain[i];

            // If the new number is <= n and hasn't been visited yet, extend the chain
            if (newNumber <= n) {
                vector<int> newChain = chain;
                newChain.push_back(newNumber);
                q.push(newChain);
            }
        }
    }

    // If we reach here, no chain was found, return an empty vector (this shouldn't happen for valid n)
    return {};
}

// a single addition chain
typedef std::vector<unsigned int> Chain;

// iterative depth-first search of Brauer sequence
bool search(Chain& chain, unsigned int exponent, unsigned int maxDepth)
{
  // too deep ?
  if (chain.size() > maxDepth)
    return false;

  auto last = chain.back();
  for (size_t i = 0; i < chain.size(); i++)
  {
    //auto sum = chain[i] + last;
    auto sum = chain[chain.size() - 1 - i] + last; // try high exponents first => about twice as fast
    if (sum == exponent)
      return true;

    chain.push_back(sum);
    if (search(chain, exponent, maxDepth))
      return true;

    chain.pop_back();
  }

  return false;
}

// increase depth until a solution is found
Chain findChain(unsigned int exponent)
{
  // cached ? (needed for Hackerrank only)
  static std::map<unsigned int, Chain> cache;
  auto lookup = cache.find(exponent);
  if (lookup != cache.end())
    return lookup->second;

  // start iterative search
  Chain chain;
  unsigned int depth = 1;
  while (true)
  {
    // reset chain
    chain = { 1 };
    // a start search
    if (search(chain, exponent, depth))
      break;

    // failed, allow to go one step deeper
    depth++;
  }

  cache[exponent] = chain;
  return chain;
}

int main() {
    unsigned int res = 0;
    for(unsigned int i=2; i<=200; ++i) {
        auto chain = additionChain(i);
        res += chain.size() - 1;
        for(auto &x : chain) {
            cout << x << " ";
        }
        cout << endl;
        
    }
    cout << res << endl;

    return 0;
}
