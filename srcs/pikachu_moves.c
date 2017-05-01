/*
** pikachu_moves.c for pikachumoves in /home/nicolas94200/CGRAPH/tekadventure/srcs
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Sat Apr 29 18:07:15 2017 goedert nicolas
** Last update Sat Apr 29 18:39:16 2017 goedert nicolas
*/

#include "./my.h"

t_param_sprite	pika_move_right(t_param_sprite pos_pika)
{
  pos_pika.rectangle.top = 128;
  pos_pika.rectangle.width = 64;
  pos_pika.rectangle.height = 64;
  if (timer_pika() == 1)
    pos_pika.rectangle.left = pos_pika.rectangle.left + 64;
  pos_pika.pos.x = pos_pika.pos.x + 1;
  if (pos_pika.rectangle.left >= 256)
    {
      pos_pika.rectangle.left = 0;
      pos_pika.rectangle.top = 128;
    }
  return (pos_pika);
}

t_param_sprite	pika_move_left(t_param_sprite pos_pika)
{
  if (timer_pika() == 1)
    pos_pika.rectangle.left = pos_pika.rectangle.left + 64;
  pos_pika.pos.x = pos_pika.pos.x - 1;
  if (pos_pika.rectangle.left >= 256)
    {
      pos_pika.rectangle.left = 0;
      pos_pika.rectangle.top = 64;
    }
  return (pos_pika);
}
