# Tic Tac Toe

> Author: Kaleb Ugalde

The goal of this project is to gain understanding and experience implementing the minimax and monte carlo tree search algorithms to be used in my [chess project](https://github.com/Dael-the-Mailman/chess-project)

## Minimax

The minimax algorithm finds the optimal move given a given state by using a game tree. One agent attempts to maximize their score on the game tree while the other attempts to minimize their score. The vanilla minimax algorithm simulates all possible future states of the board and finds the optimal move for the agent to take.
![Game Tree Diagram](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/GeeksForGeeks-Alpha-Beta-Pruning-4.png)

### Alpha-Beta Pruning
One problem with the vanilla minimax algorithm is that it can be very computationally expensive. Some more complex games can have way too many board states to be reasonably computed in a given amount of time. Alpha-Beta Pruning solves this by eliminating certain moves beforehand which can significantly reduce the search space of the tree.
![Alpha-Beta Pruning Diagram](https://i.ytimg.com/vi/xBXHtz4Gbdo/maxresdefault.jpg)
```
//pseudo-code
function Max-Value(state, alpha, beta){
    if terminal(state) return score(state)
    v = -inf
    for s in next-states(state){
        v' = Min-Value(s, alpha, beta)
        if v' > v
            v = v'
        if v' >= beta
            return v
        if v' > alpha
            alpha = v'
    }
    return v
}

function Min-Value(state, alpha, beta){
    if terminal(state) return score(state)
    v = +inf
    for s in next-states(state){
        v' = Max-Value(s, alpha, beta)
        if v' < v
            v = v'
        if v' <= alpha
            return v
        if v' < alpha
            beta = v'
    }
    return v
}
```

## Monte Carlo Tree Search

### Select

### Expand

### Rollout

### Backpropagate
