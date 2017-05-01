/*
** bar_full.c for bar_full in /home/nicolas94200/CGRAPH/tekadventure/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Sat Apr 15 17:05:57 2017 goedert nicolas
** Last update Sat Apr 15 17:05:57 2017 goedert nicolas
*/

#include "my.h"

t_param_sprite	init_pos_bar_full(t_param_sprite pos_bar_full,
				  t_param_tekadventure param,
				  char *str)
{
  pos_bar_full.texture = sfTexture_createFromFile(str, NULL);
  pos_bar_full.sprite = sfSprite_create();
  sfSprite_setTexture(pos_bar_full.sprite, pos_bar_full.texture, sfTrue);
  sfTexture_updateFromPixels(pos_bar_full.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_bar_full.pos.x = 79.0f;
  pos_bar_full.pos.y = 56.0f;
  pos_bar_full.scale.x = 0.9999f;
  pos_bar_full.scale.y = 0.9992f;
  pos_bar_full.rectangle.left = 0.0f;
  pos_bar_full.rectangle.top = 0.0f;
  pos_bar_full.rectangle.width = 725;
  pos_bar_full.rectangle.height = 25;
  return (pos_bar_full);
}

int			timer_bar_full()
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

t_param_sprite	draw_bar_full(t_param_tekadventure param,
			      t_param_sprite pos_bar_full)
{
  if (timer_bar_full() == 1)
    {
      pos_bar_full.rectangle.width = pos_bar_full.rectangle.width - 0.0001f;
    }
  sfSprite_setPosition(pos_bar_full.sprite, pos_bar_full.pos);
  sfSprite_setTextureRect(pos_bar_full.sprite, pos_bar_full.rectangle);
  sfSprite_setScale(pos_bar_full.sprite, pos_bar_full.scale);
  sfRenderWindow_drawSprite(param.window, pos_bar_full.sprite, NULL);
  return (pos_bar_full);
}
