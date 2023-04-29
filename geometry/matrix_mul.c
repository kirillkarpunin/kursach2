#include "geometry.h"

void matrix_mul(Coords* p_coords, int angle){
    Coords coords = *p_coords;

    int rotate_matrix_90[2][2] = {0, -1, 1, 0};
    int rotate_matrix_180[2][2] = {-1, 0, 0, -1};
    int rotate_matrix_270[2][2] = {0, 1, -1, 0};

    switch (angle) {
        case (90): {
            p_coords->x = coords.x * rotate_matrix_90[0][0] + coords.y * rotate_matrix_90[1][0];
            p_coords->y = coords.x * rotate_matrix_90[0][1] + coords.y * rotate_matrix_90[1][1];
            break;
        }

        case (180): {
            p_coords->x = coords.x * rotate_matrix_180[0][0] + coords.y * rotate_matrix_180[1][0];
            p_coords->y = coords.x * rotate_matrix_180[0][1] + coords.y * rotate_matrix_180[1][1];
            break;
        }

        case (270): {
            p_coords->x = coords.x * rotate_matrix_270[0][0] + coords.y * rotate_matrix_270[1][0];
            p_coords->y = coords.x * rotate_matrix_270[0][1] + coords.y * rotate_matrix_270[1][1];
            break;
        }

        default:
            break;
    }
}