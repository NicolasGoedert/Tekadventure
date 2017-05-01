/*
** caracl.c for caracl.c in /home/nicolas94200/CGRAPH/tekadventure/src
**
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
**
** Started on  Sat Apr 15 15:42:07 2017 goedert nicolas
** Last update Sun Apr 30 11:34:12 2017 goedert nicolas
*/

#include "my.h"

int			timer_carac()
{
  static struct timeb	tim1;
  static int		nb = 0;
  struct timeb		tim3;

  ftime(&tim3);
  if (tim1.millitm != tim3.millitm)
    {
      tim1.millitm = tim3.millitm;
      nb += 1;
      if (nb == 32)
	{
	  nb = 0;
	  return (1);
	}
    }
  return (0);
}

t_param_sprite	init_pos_carac(t_param_sprite pos_carac,
			       t_param_tekadventure param, char *str)
{
  pos_carac.texture = sfTexture_createFromFile(str, NULL);
  pos_carac.sprite = sfSprite_create();
  sfSprite_setTexture(pos_carac.sprite, pos_carac.texture, sfTrue);
  sfTexture_updateFromPixels(pos_carac.texture, param.pixels,
                             param.screen_size.x, param.screen_size.y, 0, 0);
  pos_carac.pos.x = 600.0f;
  pos_carac.pos.y = 665.0f;
  pos_carac.scale.x = 2.0f;
  pos_carac.scale.y = 2.0f;
  pos_carac.rectangle.left = 0;
  pos_carac.rectangle.top = 50;
  pos_carac.rectangle.width = 50;
  pos_carac.rectangle.height = 50;
  return (pos_carac);
}

t_param_sprite	draw_carac(t_param_tekadventure param,
			   t_param_sprite pos_carac)
{
  static int	clems;

  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    pos_carac = carac_move_right(pos_carac);
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    pos_carac = carac_move_left(pos_carac);
  if ((sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) == 1 && clems != 1)
    clems = 1;
  if (clems == 1)
    pos_carac = carac_move_jump(pos_carac, &clems);
  if (pos_carac.pos.x >= 1840)
    pos_carac.pos.x = 1840;
  if (pos_carac.pos.x <= 0)
    pos_carac.pos.x = 0;
  sfSprite_setTextureRect(pos_carac.sprite, pos_carac.rectangle);
  sfSprite_setPosition(pos_carac.sprite, pos_carac.pos);
  sfSprite_setScale(pos_carac.sprite, pos_carac.scale);
  sfRenderWindow_drawSprite(param.window, pos_carac.sprite, NULL);
  return (pos_carac);
}
