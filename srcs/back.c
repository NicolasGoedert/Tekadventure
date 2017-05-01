/*
** back.c for back in /home/nicolas94200/CGRAPH/tekadventure
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Thu Apr 13 14:14:21 2017 goedert nicolas
** Last update Thu Apr 13 14:14:21 2017 goedert nicolas
*/

#include "my.h"

t_param_sprite	init_pos_back(t_param_sprite pos_back,
			      t_param_tekadventure param,
			      char *str)
{
  pos_back.texture = sfTexture_createFromFile(str, NULL);
  pos_back.sprite = sfSprite_create();
  sfSprite_setTexture(pos_back.sprite, pos_back.texture, sfTrue);
  sfTexture_updateFromPixels(pos_back.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_back.pos.x = 0.0f;
  pos_back.pos.y = 0.0f;
  pos_back.scale.x = 1.0f;
  pos_back.scale.y = 1.0f;
  pos_back.rectangle.left = 0;
  pos_back.rectangle.top = 0;
  pos_back.rectangle.width = 1920;
  pos_back.rectangle.height = 1080;
  return (pos_back);
}

t_param_sprite	draw_back(t_param_tekadventure param,
			  t_param_sprite pos_back)
{
  pos_back.rectangle.left = pos_back.rectangle.left;
  if (pos_back.rectangle.left == param.screen_size.x)
    pos_back.rectangle.left = 340;
  sfSprite_setTextureRect(pos_back.sprite, pos_back.rectangle);
  sfSprite_setScale(pos_back.sprite, pos_back.scale);
  sfRenderWindow_drawSprite(param.window, pos_back.sprite, NULL);
  return (pos_back);
}
