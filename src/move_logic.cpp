#include "../include/move_logic.h"
#include <cstdint>
#include <raylib.h>
#include <vector>

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

void handleCapture(board_t* board, Vector2 final_position) {
    piece_type_t piece = getPieceAt(final_position.x, final_position.y, board);

    std::uint64_t mask = static_cast<std::uint64_t>(1) << (static_cast<int>(COMPRESS(final_position.x, final_position.y)));

    switch (piece) {
        case WHITE_PAWN:
            board->white_pawns ^= mask;
            break;
        case WHITE_KNIGHT:
            board->white_knights ^= mask;
            break;
        case WHITE_BISHOP:
            board->white_bishops ^= mask;
            break;
        case WHITE_ROOK:
            board->white_rooks ^= mask;
            break;
        case WHITE_QUEEN:
            board->white_queens ^= mask;
            break;
        case WHITE_KING:
            board->white_kings ^= mask;
            break;

        case BLACK_PAWN:
            board->black_pawns ^= mask;
            break;
        case BLACK_KNIGHT:
            board->black_knights ^= mask;
            break;
        case BLACK_BISHOP:
            board->black_bishops ^= mask;
            break;
        case BLACK_ROOK:
            board->black_rooks ^= mask;
            break;
        case BLACK_QUEEN:
            board->black_queens ^= mask;
            break;
        case BLACK_KING:
            board->black_kings ^= mask;
            break;

        default:
            break; // No piece to capture
    }
}


void setFinalPosition(board_t* board, std::vector<std::uint64_t> possible_moves, Vector2 final_position) {
    std::uint64_t final_position_mask =
            static_cast<std::uint64_t>(1) << (static_cast<int>(COMPRESS(final_position.x, final_position.y)));
        
        auto it = std::find(
            possible_moves.begin(), 
            possible_moves.end(), 
            final_position_mask
        );

        handleCapture(board, final_position);
        if (it != possible_moves.end()) {
            std::printf("Move is valid!\n");
            board->white_pawns |= possible_moves.at(
                std::distance(possible_moves.begin(), it));
        }

}


void makeMove(game_state_t* game_state) {
    board_t* board = game_state->board;
    Vector2 initial_position = game_state->initial_position;
    Vector2 final_position = game_state->final_position;
    bool white_turn = game_state->white_turn;

    piece_type_t piece = getPieceAt(initial_position.x, initial_position.y, board);

    if (piece == WHITE_PAWN && white_turn) {
        std::vector<std::uint64_t> possible_moves = getPawnMoves(
            board->white_pawns,
            initial_position, 
            white_turn
        );
        
        board->white_pawns ^= 
            static_cast<uint64_t>(1) << static_cast<uint64_t>(COMPRESS(initial_position.x, initial_position.y));
        
        setFinalPosition(board, possible_moves, final_position);

    }
}