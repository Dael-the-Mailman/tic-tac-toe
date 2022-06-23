'''
Derived from Code Monkey King

https://www.youtube.com/playlist?list=PLLfIBXQeu3aanwI5pYz6QyzYtnBEgcsZ8
'''
from copy import deepcopy

class Board():
    def __init__(self, board=None):
        self.player_1 = 'x'
        self.player_2 = 'o'
        self.empty_square = '.'

        self.position = {}

        self.init_board()

        if board is not None:
            self.__dict__ = deepcopy(board.__dict__)
    
    def init_board(self):
        for row in range(3):
            for col in range(3):
                self.position[row, col] = self.empty_square

    def make_move(self, row, col):
        board = Board()
        board.position[row, col] = self.player_1

        (board.player_1, board.player_2) = (board.player_2, board.player_1) 

        return board

    def __str__(self):
        board_string = ''

        for row in range(3):
            for col in range(3):
                board_string += ' %s' % self.position[row, col]

            board_string += "\n"
        
        if self.player_1 == 'x':
            board_string = '\n-------------\n"x" to move:\n-------------\n\n' + board_string
        elif self.player_1 == 'o':
            board_string = '\n-------------\n"o" to move:\n-------------\n\n' + board_string

        return board_string

if __name__ == '__main__':
    board = Board()

    print(board)

    board = board.make_move(0,0)

    board_1 = Board(board)

    print(board_1)