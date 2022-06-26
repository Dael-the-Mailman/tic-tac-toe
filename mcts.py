import math
import random

class TreeNode():
    def __init__(self, board, parent):
        self.board = board
        
        if self.board.is_win() or self.board.is_draw():
            self.is_terminal = True
        else:
            self.is_terminal = False

        self.is_fully_expanded = self.is_terminal

        self.parent = parent

        self.visits = 0

        self.score = 0

        self.children = {}

class MCTS():
    def search(self, initial_state):
        self.root = TreeNode(initial_state, None)

        for iteration in range(1000):
            node = self.select(self.root)

            score = self.rollout(node.board)

            self.backpropagate(node, score)
        
        try:
            return self.get_best_move(self.root, 0)

        except:
            pass

    def select(self, node):
        pass

    def rollout(self, board):
        pass

    def backpropagate(self, node, score):
        pass

    def get_best_move(self, node, exploration_constant):
        pass

