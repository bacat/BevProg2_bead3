#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>


std::string itos(int x)
{
    std::stringstream ss;
    ss << x;
    return ss.str();
}


class GameState
{
    std::vector<std::vector<int>> game_board;
    std::vector<std::vector<int>> value_board;
    int winner{0}, value{0}, player{0}, board_x{0}, board_y{0};

public:
    GameState(uint32_t board_x, uint32_t board_y)
    {
        for(size_t i{0}; i < board_x; i++)
        {
            game_board.push_back(std::vector<int>(board_y, 1));
            value_board.push_back(std::vector<int>(board_y, 1));
        }
    }

    std::string getVerticalStar(int centre_x, int centre_y)
    {
        int begin_index{centre_x - 4};
        int end_index{centre_x + 4};

        if(begin_index < 0) begin_index = 0;
        if(end_index > game_board.size() - 1) end_index = game_board.size() - 1;

        std::stringstream ss;
        for(int i{begin_index}; i <= end_index; i++)
        {
            ss << game_board[i][centre_y];
        }

        return ss.str();
    }

    std::string getHorizontalStar(int centre_x, int centre_y)
    {
        int begin_index{centre_y - 4};
        int end_index{centre_y + 4};

        if(begin_index < 0) begin_index = 0;
        if(end_index > game_board[0].size() - 1) end_index = game_board[0].size() - 1;

        std::stringstream ss;
        for(int i{begin_index}; i <= end_index; i++)
        {
            ss << game_board[centre_x][i];
        }

        return ss.str();
    }

    std::string getMainDiagonalStar(int centre_x, int centre_y)
    {
        int begin_i{4};
        int end_i{4};

        if(begin_i > centre_x) begin_i = centre_x;
        if(begin_i > centre_y) begin_i = centre_y;

        while (centre_x + end_i > game_board.size() - 1 || centre_y + end_i > game_board[0].size() - 1) { end_i--; }

        std::stringstream ss;

        for(int i{-begin_i}; i <= end_i; i++)
        {
            ss << game_board[centre_x + i][centre_y + i];
        }

        return ss.str();
    }

    std::string getMinorDiagonalStar(int centre_x, int centre_y)
    {
        int begin_i{4};
        int end_i{4};

        if(begin_i > centre_x) begin_i = centre_x;
        while(centre_y + begin_i > game_board[0].size() - 1) { begin_i--; }

        if(end_i > centre_y) end_i = centre_y;
        while(centre_x + end_i > game_board[0].size() - 1) { end_i--; }

        std::stringstream ss;

        for(int i{-begin_i}; i <= end_i; i++)
        {
            ss << game_board[centre_x + i][centre_y - i];
        }

        return ss.str();
    }
};




class GameAnalyse
{
    std::map<std::string, int> player1;
    std::map<std::string, int> player2;

public:
    GameAnalyse()
    {
        player1.emplace("10000", 1);    player1.emplace("01000", 1);    player1.emplace("00100", 1);
        player1.emplace("00010", 1);    player1.emplace("00001", 1);

        player1.emplace("11000", 5);    player1.emplace("00101", 5);    player1.emplace("10001", 5);
        player1.emplace("10010", 5);    player1.emplace("10100", 5);    player1.emplace("00110", 5);
        player1.emplace("01100", 5);    player1.emplace("01010", 5);    player1.emplace("00011", 5);
        player1.emplace("01001", 5);

        player1.emplace("11100", 25);   player1.emplace("01011", 25);   player1.emplace("10011", 25);
        player1.emplace("11001", 25);   player1.emplace("11010", 25);   player1.emplace("01101", 25);
        player1.emplace("10101", 25);   player1.emplace("10110", 25);   player1.emplace("00111", 25);
        player1.emplace("01110", 25);

        player1.emplace("11110", 100); player1.emplace("11101", 100);   player1.emplace("10111", 100);
        player1.emplace("11011", 100); player1.emplace("01111", 100);

        player1.emplace("11111", 10000);


        player2.emplace("20000", 1);    player2.emplace("02000", 1);    player2.emplace("00200", 1);
        player2.emplace("00020", 1);    player2.emplace("00002", 1);

        player2.emplace("22000", 5);    player2.emplace("00202", 5);    player2.emplace("20002", 5);
        player2.emplace("20020", 5);    player2.emplace("20200", 5);    player2.emplace("00220", 5);
        player2.emplace("02200", 5);    player2.emplace("02020", 5);    player2.emplace("00022", 5);
        player2.emplace("02002", 5);

        player2.emplace("22200", 25);   player2.emplace("02022", 25);   player2.emplace("20022", 25);
        player2.emplace("22002", 25);   player2.emplace("22020", 25);   player2.emplace("02202", 25);
        player2.emplace("20202", 25);   player2.emplace("20220", 25);   player2.emplace("00222", 25);
        player2.emplace("02220", 25);

        player2.emplace("22220", 100); player2.emplace("22202", 100);   player2.emplace("20222", 100);
        player2.emplace("22022", 100); player2.emplace("02222", 100);

        player2.emplace("22222", 10000);
    }
};


int main()
{

    GameState gs(10, 10);
    GameAnalyse anal();
    std::cout << gs.getMainDiagonalStar(1, 1) << std::endl;

    return EXIT_SUCCESS;
}
