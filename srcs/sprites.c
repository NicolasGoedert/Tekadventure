/*
** init_sprites.c for init_sprites.c in /home/Romingo/clones/tekadventure/srcs
** 
** Made by romain rousseau
** Login   <Romingo@epitech.net>
** 
** Started on  Sat Apr 29 22:58:48 2017 romain rousseau
** Last update Sat Apr 29 22:58:48 2017 romain rousseau
*/

#include "my.h"
#include "adds.h"

static int	sprites_verif(t_tab_sprite *sprites)
{
  if (!sprites->pos_back.texture || !sprites->pos_carac.texture
      || !sprites->pos_pika.texture || !sprites->pos_bottle.texture
      || !sprites->pos_bar_void.texture || !sprites->pos_bar_full.texture
      || !sprites->pos_tab.texture)
    return (1);
  return (0);
}

int	sprites_init(t_param_tekadventure param,
		     t_tab_sprite *sprites)
{
  sprites->pos_back = init_pos_back(sprites->pos_back, param, BACKGROUND);
  sprites->pos_carac = init_pos_carac(sprites->pos_carac, param, CHARACTER);
  sprites->pos_pika = init_pos_pika(sprites->pos_pika, param, PIKA);
  sprites->pos_bottle = init_pos_bottle(sprites->pos_bottle, param, BOTTLE);
  sprites->pos_bar_void = init_pos_bar_void(sprites->pos_bar_void,
					    param, TVOID);
  sprites->pos_bar_full = init_pos_bar_full(sprites->pos_bar_full,
					    param, TFULL);
  sprites->pos_tab = init_pos_tab(sprites->pos_tab, param, TAB);
  if (sprites_verif(sprites) == 1)
    return (1);
  return (0);
}

void	sprites_draw(t_param_tekadventure param,
		     t_tab_sprite *sprites)
{
  sfRenderWindow_clear(param.window, sfBlack);
  sprites->pos_back = draw_back(param, sprites->pos_back);
  sprites->pos_pika = draw_pika(param, sprites->pos_pika);
  sprites->pos_carac = draw_carac(param, sprites->pos_carac);
  sprites->pos_bar_full = draw_bar_full(param, sprites->pos_bar_full);
  sprites->pos_bar_void = draw_bar_void(param, sprites->pos_bar_void);
  sprites->pos_tab = draw_tab(param, sprites->pos_tab);
  sprites->pos_bottle = draw_bottle(param, sprites->pos_bottle);
  sfRenderWindow_display(param.window);
}
