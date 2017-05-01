/*
** pikachu.c for pikachu in /home/nicolas94200/CGRAPH/tekadventure/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Sat Apr 15 14:28:37 2017 goedert nicolas
** Last update Sat Apr 29 18:22:43 2017 goedert nicolas
*/

#include "my.h"

int			timer_pika()
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

t_param_sprite	init_pos_pika(t_param_sprite pos_pika,
			      t_param_tekadventure param,
			      char *str)
{
  pos_pika.texture = sfTexture_createFromFile(str, NULL);
  pos_pika.sprite = sfSprite_create();
  sfSprite_setTexture(pos_pika.sprite, pos_pika.texture, sfTrue);
  sfTexture_updateFromPixels(pos_pika.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_pika.pos.x = 400.0f;
  pos_pika.pos.y = 630.0f;
  pos_pika.scale.x = 2.0f;
  pos_pika.scale.y = 2.0f;
  pos_pika.rectangle.left = 0;
  pos_pika.rectangle.top = 64;
  pos_pika.rectangle.width = 64;
  pos_pika.rectangle.height = 64;
  return (pos_pika);
}

t_param_sprite	draw_pika(t_param_tekadventure param,
			  t_param_sprite pos_pika)
{
  if (sfKeyboard_isKeyPressed(sfKeyD))
    pos_pika = pika_move_right(pos_pika);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    pos_pika = pika_move_left(pos_pika);
  if (pos_pika.pos.x >= 1149)
    pos_pika.pos.x = 1149;
  if (pos_pika.pos.x <= -40)
    pos_pika.pos.x = -40;
  sfSprite_setTextureRect(pos_pika.sprite, pos_pika.rectangle);
  sfSprite_setPosition(pos_pika.sprite, pos_pika.pos);
  sfSprite_setScale(pos_pika.sprite, pos_pika.scale);
  sfRenderWindow_drawSprite(param.window, pos_pika.sprite, NULL);
  return (pos_pika);
}
