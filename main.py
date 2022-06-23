'''
Derived from Code Monkey King

https://www.youtube.com/playlist?list=PLLfIBXQeu3aanwI5pYz6QyzYtnBEgcsZ8
'''
from copy import deepcopy

class Board():
    def __init__(self, board=None):
        self.player_x = 'x'
        self.player_o = 'o'
        self.empty_square = '.'

        self.position = {}

        self.init_board()

        if board is not None:
            self.__dict__ = deepcopy(board.__dict__)
    
    def init_board(self):
        for row in range(3):
            for col in range(3):
                self.position[row, col] = self.empty_square

    def __str__(self):
        board_string = ''

        for row in range(3):
            for col in range(3):
                board_string += ' %s' % self.position[row, col]

            board_string += "\n"
        return board_string

if __name__ == '__main__':
    board = Board()
    print(board)