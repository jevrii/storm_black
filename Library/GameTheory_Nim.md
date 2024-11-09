## Combinatorial Game Theory
Topics: ST Function, xor sum, Nim

**If all else fails, draw the NP/SG table / Decision Tree!**

- Two players
- They take turn to change the game state with a move
- Perfect information; no chance/guesswork involved
- Progressively finite: the game must end after a finite sequence of moves
- **Impartial combinatorial game: at a particular position, both players have the same set of available moves**

### N/P

- If initial position is N, P1 wins.
- If initial position is P, P2 wins.
  - Ending position is a P position (Player 1 loses).
- **Iff all positions X<sub>i</sub> we can reach from X<sub>cur</sub> are N positions, then X<sub>cur</sub> is P position.**
  - Intuition: Can P1 change to a game state where P2 must win? (P1/P2 relative position swap after moving)

### SG Function

- MEX of a set: Smallest non-negative integers _not_ in the set. (MEX(empty set) = 0)
- Graph: Topological sort (with reverse graph)!
- For multiple games run "simultaneously" (multiple nim pilies), **SG(all games combined) = SG(Game 1) xor SG(Game 2) ... xor SG(Game k)**
- Suppose we can reach X<sub>1</sub>, X<sub>2</sub>, ... , X<sub>k</sub> from current position X<sub>cur</sub>. **Then SG(X<sub>cur</sub>) = MEX (SG(X<sub>1</sub>), SG(X<sub>2</sub>), ... , SG(X<sub>k</sub>))**
- **P1 Wins (N position) iff SG value > 0**
- **P2 Wins (P position) iff SG value == 0**
  - Ending position has SG value == 0
  
### Nim

#### Rules
- There are N stone piles.
- In each move, you must remove some positive (>0) number of stones from exactly 1 pile.
- The first to not have an available move (when the board is clear) loses.

#### Solution
If there is 1 pile,
- From X<sub>K</sub> we can reach (X<sub>0</sub>, X<sub>1</sub>, ..., X<sub>K-1</sub>). 
- **Thus, SG(X<sub>K</sub>) = MEX (SG(X<sub>0</sub>), SG(X<sub>1</sub>), ..., SG(X<sub>K-1</sub>)) = K**
- General solution: If A<sub>1</sub> ^ A<sub>2</sub> ^ … ^ A<sub>N</sub> = 0 (xor sum), P2 wins. Otherwise, P1 wins
- Winning strategy: If possible, you should make a move that makes xor-sum = 0. Otherwise, you lose.

#### Misere Nim

> Misère Nim is exactly like the standard Nim game, except for one critical difference. If the size of every pile is 1, then we need to treat it as a special case where we count the number of piles. If the count is even, then the first player will win; if the count is odd, then the first player will lose.
> 
> If the size of every pile is not 1, then you can use XOR sum to determine who will win the game. If the XOR sum is zero the first player picks the last stone from the last pile hence looses, else the first player wins.

1) The last losing position of every game will have exactly one stone and one active pile. Ignoring the piles with zero, we can represent the basic losing position like this: [1].

2) There are exactly two ways to put your opponent in this losing position:

You have exactly one remaining pile, and the number of stones > 1 (e.g., [8]), or
You have exactly two remaining piles, one of which has only one stone (e.g., [1,8]).
3) The only "winning position" from (2) that has an xor value of 0 is [1,1].

4) If player 1 starts with an xor value of zero, player 1 loses unless the piles are: [1,1], [1,1,1,1], etc.

5) If player 1 starts with an xor value other than zero, player 1 wins unless the piles are: [1], [1,1,1], etc.

Oberservations (4) and (5) are enough to come up with an algorithm. You can see my solution here. But why do (4) and (5) hold?

I'll ignore the cases where each pile has one stone, since those cases are easy.

Let's suppose player p has an xor value of zero.

a) Every time p makes a move, their opponent can counter to put them back into an xor position of zero.

b) The opponent will never put p in [1,1], [1,1,1,1], etc., because that would require the opponent to pass up a winning position (such as [1,8], [1,1,1,8],etc.)

c) So these two things together mean that the opponent will never put p in a winning position, which establishes (4).

Now let's suppose player p has an xor value other than zero.

d) As long as at least one pile has more than 1 stone, p can give their opponent an xor value of 0, which establishes (5).



