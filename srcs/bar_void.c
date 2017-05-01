/*
** bar_void.c for bar_void in /home/nicolas94200/CGRAPH/tekadventure/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Sat Apr 15 17:05:57 2017 goedert nicolas
** Last update Sat Apr 15 17:05:57 2017 goedert nicolas
*/

#include "my.h"

t_param_sprite	init_pos_bar_void(t_param_sprite pos_bar_void,
			      t_param_tekadventure param,
			      char *str)
{
  pos_bar_void.texture = sfTexture_createFromFile(str, NULL);
  pos_bar_void.sprite = sfSprite_create();
  sfSprite_setTexture(pos_bar_void.sprite, pos_bar_void.texture, sfTrue);
  sfTexture_updateFromPixels(pos_bar_void.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_bar_void.pos.x = 36.0f;
  pos_bar_void.pos.y = 0.0f;
  pos_bar_void.scale.x = 0.9999f;
  pos_bar_void.scale.y = 0.9992f;
  pos_bar_void.rectangle.left = 0;
  pos_bar_void.rectangle.top = 0;
  pos_bar_void.rectangle.width = 800;
  pos_bar_void.rectangle.height = 400;
  return (pos_bar_void);
}

int			timer_bar_void()
{
  static struct timeb	tim1;
  static int		nb = 0;
  struct timeb		tim3;

  ftime(&tim3);
  if (tim1.millitm != tim3.millitm)
    {
      tim1.millitm = tim3.millitm;
      nb += 1;
      if (nb == 100)
	{
	  nb = 0;
	  return (1);
	}
    }
  return (0);
}

t_param_sprite	draw_bar_void(t_param_tekadventure param,
			      t_param_sprite pos_bar_void)
{
  if (timer_bar_void() == 1)
    {
      pos_bar_void.rectangle.left = pos_bar_void.rectangle.left;
      pos_bar_void.pos.x = pos_bar_void.pos.x;
    }
  sfSprite_setPosition(pos_bar_void.sprite, pos_bar_void.pos);
  sfSprite_setTextureRect(pos_bar_void.sprite, pos_bar_void.rectangle);
  sfSprite_setScale(pos_bar_void.sprite, pos_bar_void.scale);
  sfRenderWindow_drawSprite(param.window, pos_bar_void.sprite, NULL);
  return (pos_bar_void);
}
