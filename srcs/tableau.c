/*
** tableau.c for tab in /home/nicolas94200/CGRAPH/tekadventure/srcs
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Wed Apr 26 21:16:34 2017 goedert nicolas
** Last update Wed Apr 26 22:45:48 2017 goedert nicolas
*/

#include "my.h"

t_param_sprite	init_pos_tab(t_param_sprite pos_tab,
				t_param_tekadventure param,
				char *str)
{
  pos_tab.texture = sfTexture_createFromFile(str, NULL);
  pos_tab.sprite = sfSprite_create();
  sfSprite_setTexture(pos_tab.sprite, pos_tab.texture, sfTrue);
  sfTexture_updateFromPixels(pos_tab.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_tab.pos.x = 1600.0f;
  pos_tab.pos.y = 35.0f;
  pos_tab.scale.x = 0.999f;
  pos_tab.scale.y = 0.999f;
  pos_tab.rectangle.left = 0;
  pos_tab.rectangle.top = 0;
  pos_tab.rectangle.width = 265;
  pos_tab.rectangle.height = 70;
  return (pos_tab);
}

int			timer_tab()
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

t_param_sprite	draw_tab(t_param_tekadventure param, t_param_sprite pos_tab)
{
  if (timer_tab() == 1)
    {
      pos_tab.rectangle.left = pos_tab.rectangle.left;
      pos_tab.pos.x = pos_tab.pos.x;
    }
  sfSprite_setPosition(pos_tab.sprite, pos_tab.pos);
  sfSprite_setTextureRect(pos_tab.sprite, pos_tab.rectangle);
  sfSprite_setScale(pos_tab.sprite, pos_tab.scale);
  sfRenderWindow_drawSprite(param.window, pos_tab.sprite, NULL);
  return (pos_tab);
}
