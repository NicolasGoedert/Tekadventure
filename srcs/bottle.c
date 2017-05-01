/*
** bottle.c for bottle in /home/nicolas94200/CGRAPH/tekadventure/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Sat Apr 15 17:05:57 2017 goedert nicolas
** Last update Sun Apr 30 11:39:57 2017 goedert nicolas
*/

#include "my.h"

t_param_sprite	init_pos_bottle(t_param_sprite pos_bottle,
			      t_param_tekadventure param,
			      char *str)
{
  pos_bottle.texture = sfTexture_createFromFile(str, NULL);
  pos_bottle.sprite = sfSprite_create();
  sfSprite_setTexture(pos_bottle.sprite, pos_bottle.texture, sfTrue);
  sfTexture_updateFromPixels(pos_bottle.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_bottle.pos.x = 400.0f;
  pos_bottle.pos.y = 300.0f;
  pos_bottle.scale.x = 0.15f;
  pos_bottle.scale.y = 0.15f;
  pos_bottle.rectangle.left = 0;
  pos_bottle.rectangle.top = 0;
  pos_bottle.rectangle.width = 280;
  pos_bottle.rectangle.height = 400;
  return (pos_bottle);
}

int			timer_bottle()
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

t_param_sprite	draw_bottle(t_param_tekadventure param,
			    t_param_sprite pos_bottle)
{
  if (timer_bottle() == 1)
    {
      pos_bottle.rectangle.left = pos_bottle.rectangle.left;
      pos_bottle.pos.x = pos_bottle.pos.x;
    }
  sfSprite_setPosition(pos_bottle.sprite, pos_bottle.pos);
  sfSprite_setTextureRect(pos_bottle.sprite, pos_bottle.rectangle);
  sfSprite_setScale(pos_bottle.sprite, pos_bottle.scale);
  sfRenderWindow_drawSprite(param.window, pos_bottle.sprite, NULL);
  return (pos_bottle);
}
