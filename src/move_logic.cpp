#include "../include/move_logic.h"
#include <cstdint>

// move_t* getPossibleMoves(board_t* board, int x, int y) {
//     std::string piece = getPieceAt(x, y, board);

//     if piece
// }

std::vector<std::uint64_t> getPawnMoves(std::uint64_t pieces, Vector2 current_position, bool white_turn) {
    std::vector<std::uint64_t> moves_list;

    if (white_turn) {
        moves_list.push_back(static_cast<uint64_t>(1) << (static_cast<int>(COMPRESS(current_position.x, current_position.y + 1))));
        moves_list.push_back(static_cast<uint64_t>(1) << (static_cast<int>(COMPRESS(current_position.x, current_position.y + 2))));
    }

    else {
        moves_list.push_back( static_cast<uint64_t>(1) << (static_cast<int>(COMPRESS(current_position.x, current_position.y - 1))));
        moves_list.push_back( static_cast<uint64_t>(1) << (static_cast<int>(COMPRESS(current_position.x, current_position.y - 2))));
    }

    return moves_list;
}

void makeMove(board_t* board, Vector2 initial_screen_position, Vector2 final_screen_position, bool white_turn) {
    piece_type_t piece = getPieceAt(initial_screen_position.x, initial_screen_position.y, board);

    if (piece == WHITE_PAWN && white_turn) {
        std::vector<std::uint64_t> possible_moves = getPawnMoves(board->white_pawns, initial_screen_position, white_turn);
        board->white_pawns ^= static_cast<uint64_t>(1) << static_cast<uint64_t>(COMPRESS(initial_screen_position.x, initial_screen_position.y));
        
        std::uint64_t final_position_mask = static_cast<std::uint64_t>(1) << (static_cast<int>(COMPRESS(final_screen_position.x, final_screen_position.y)));
        
        auto it = std::find(possible_moves.begin(), possible_moves.end(), final_position_mask);

        if (it != possible_moves.end()) {
            std::printf("Move is valid!\n");
            board->white_pawns |= possible_moves.at(std::distance(possible_moves.begin(), it));
        }

    }
}