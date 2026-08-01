#include "../include/moves.h"
#include <cstdint>
#include <cstdio>
#include <raylib.h>
#include <vector>

// std::vector<std::uint64> (*piece_moves[])(board_t*, Vector2, bool) = {
//     &awsh_cd,
//     &awsh_exit,
//     &awsh_help,
//     &awsh_math,
// };


void handleCapture(board_t* board, Square final_position) {
    int x, y;
    decompressCoordinates(final_position, x, y);

    piece_type_t piece = getPieceAt(x, y, board);

    std::uint64_t mask = static_cast<std::uint64_t>(1) << (static_cast<int>(final_position));

    switch (piece) {
        case WHITE_PAWN:
            board->white_pawns   ^= mask;
            break;
        
        case WHITE_KNIGHT:
            board->white_knights ^= mask;
            break;
    
        case WHITE_BISHOP:
            board->white_bishops ^= mask;
            break;
        
        case WHITE_ROOK:
            board->white_rooks   ^= mask;
            break;
        
        case WHITE_QUEEN:
            board->white_queens  ^= mask;
            break;
        
        case WHITE_KING:
            board->white_kings   ^= mask;
            break;

    
        case BLACK_PAWN:
            board->black_pawns   ^= mask;
            break;
        
        case BLACK_KNIGHT:
            board->black_knights ^= mask;
            break;
    
        case BLACK_BISHOP:
            board->black_bishops ^= mask;
            break;
        
        case BLACK_ROOK:
            board->black_rooks   ^= mask;
            break;
    
        case BLACK_QUEEN:
            board->black_queens  ^= mask;
            break;
        
        case BLACK_KING:
            board->black_kings   ^= mask;
            break;
        
        case PIECE_NONE:
            break; // No piece to capture

        default:
            break; // How do you even get here? This should never happen.
    }
}


void setFinalPosition(board_t* board, Square initial_position, Square final_position, piece_type_t piece) {

    std::uint64_t initial_mask = static_cast<std::uint64_t>(1) << (static_cast<int>(initial_position));
    std::uint64_t final_mask = static_cast<std::uint64_t>(1) << (static_cast<int>(final_position));

    switch (piece) {
        case WHITE_PAWN:
            board->white_pawns &= ~initial_mask;
            board->white_pawns |= final_mask;
            break;
        
        case WHITE_KNIGHT:
            board->white_knights &= ~initial_mask;
            board->white_knights |= final_mask;
            break;
    
        case WHITE_BISHOP:
            board->white_bishops &= ~initial_mask;
            board->white_bishops |= final_mask;
            break;
        
        case WHITE_ROOK:
            board->white_rooks &= ~initial_mask;
            board->white_rooks |= final_mask;
            break;
        
        case WHITE_QUEEN:
            board->white_queens &= ~initial_mask;
            board->white_queens |= final_mask;
            break;
        
        case WHITE_KING:
            board->white_kings &= ~initial_mask;
            board->white_kings |= final_mask;
            break;

    
        case BLACK_PAWN:
            board->black_pawns &= ~initial_mask;
            board->black_pawns |= final_mask;
            break;
        
        case BLACK_KNIGHT:
            board->black_knights &= ~initial_mask;
            board->black_knights |= final_mask;
            break;
    
        case BLACK_BISHOP:
            board->black_bishops &= ~initial_mask;
            board->black_bishops |= final_mask;
            break;
        
        case BLACK_ROOK:
            board->black_rooks &= ~initial_mask;
            board->black_rooks |= final_mask;
            break;
    
        case BLACK_QUEEN:
            board->black_queens &= ~initial_mask;
            board->black_queens |= final_mask;
            break;
        
        case BLACK_KING:
            board->black_kings &= ~initial_mask;
            board->black_kings |= final_mask;
            break;

        default:
            break; // How do you even get here? This should never happen.
    }
        
}

std::vector<move_t> getPossibleMoves(board_t* board, int initial_x, int initial_y, piece_type_t piece, bool white_turn) {
    std::vector<move_t> moves_list;

    switch (piece) {

    case PIECE_NONE:
        perror("Can't move an empty square!");
    break;

    case WHITE_PAWN:
    case BLACK_PAWN:
        moves_list = getPawnMoves(
            board,
            initial_x,
            initial_y,
            white_turn
        );
    break;
    
    case WHITE_KNIGHT:
    case WHITE_BISHOP:
    case WHITE_ROOK:
    case WHITE_QUEEN:
    case WHITE_KING:
    case BLACK_KNIGHT:
    case BLACK_BISHOP:
    case BLACK_ROOK:
    case BLACK_QUEEN:
    case BLACK_KING:
      break;
    }

    return moves_list;
}


void makeMove(game_state_t* game_state, std::vector<move_t> possible_moves, Square final_position) {
    
    auto it = std::find_if(
        possible_moves.begin(), 
        possible_moves.end(),               
        [final_position](const move_t& move) {
            return move.to == final_position;
        }
    );

    if (it != possible_moves.end()) {
        handleCapture(game_state->board, final_position);
        setFinalPosition(game_state->board, it->from, final_position, game_state->selected_piece);
        game_state->is_white_turn = !game_state->is_white_turn; // Switch turns
    }
    
}
