/*
** chopped.c for chopped in /home/nicolas94200/CGRAPH/tekadventure/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Sat Apr 15 18:04:48 2017 goedert nicolas
** Last update Sat Apr 15 18:04:48 2017 goedert nicolas
*/
#include "my.h"

t_param_sprite	init_pos_chopped(t_param_sprite pos_chopped,
				 t_param_tekadventure param,
				 char *str)
{
  pos_chopped.texture = sfTexture_createFromFile(str, NULL);
  pos_chopped.sprite = sfSprite_create();
  sfSprite_setTexture(pos_chopped.sprite, pos_chopped.texture, sfTrue);
  sfTexture_updateFromPixels(pos_chopped.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_chopped.pos.x = 1250.0f;
  pos_chopped.pos.y = 350.0f;
  pos_chopped.scale.x = 0.2f;
  pos_chopped.scale.y = 0.2f;
  pos_chopped.rectangle.left = 0;
  pos_chopped.rectangle.top = 0;
  pos_chopped.rectangle.width = 1356;
  pos_chopped.rectangle.height = 783;
  return (pos_chopped);
}

int			timer_chopped()
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
t_param_sprite	draw_chopped(t_param_tekadventure param,
			     t_param_sprite pos_chopped)
{
  if (timer_chopped() == 1)
    {
      pos_chopped.rectangle.left = pos_chopped.rectangle.left;
      pos_chopped.pos.x = pos_chopped.pos.x;
    }
  sfSprite_setPosition(pos_chopped.sprite, pos_chopped.pos);
  sfSprite_setTextureRect(pos_chopped.sprite, pos_chopped.rectangle);
  sfSprite_setScale(pos_chopped.sprite, pos_chopped.scale);
  sfRenderWindow_drawSprite(param.window, pos_chopped.sprite, NULL);
  return (pos_chopped);
}
