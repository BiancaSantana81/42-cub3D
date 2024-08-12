#include "../includes/cub.h"

void draw_perpendicular_line(t_cub *game, int length) {
    // Calcula o ponto final da linha de direção do jogador
    int end_x = game->player->x + cos(game->player->pa) * length;
    int end_y = game->player->y + sin(game->player->pa) * length;

    // Calcula o vetor perpendicular
    float perp_dx = -sin(game->player->pa) * length;
    float perp_dy = cos(game->player->pa) * length;

    // Salva a posição original do jogador
    float original_px = game->player->px;
    float original_py = game->player->py;
    float original_pa = game->player->pa;

    // Desenha a primeira linha perpendicular
    game->player->px = end_x;
    game->player->py = end_y;
    game->player->pa = atan2(perp_dy, perp_dx);
    draw_line(game, 20);

    // Desenha a segunda linha perpendicular
    game->player->px = end_x;
    game->player->py = end_y;
    game->player->pa = atan2(-perp_dy, -perp_dx);
    draw_line(game, 20);

    // Restaura a posição original do jogador
    game->player->px = original_px;
    game->player->py = original_py;
    game->player->pa = original_pa;
}
