/*
** carac_moves.c for carac_moves.c in /home/Romingo/CGraph/tekadventure/srcs
** 
** Made by romain rousseau
** Login   <Romingo@epitech.net>
** 
** Started on  Wed Apr 26 20:08:51 2017 romain rousseau
** Last update Fri Apr 28 22:42:42 2017 goedert nicolas
*/

#include "my.h"

t_param_sprite	carac_move_jump_scale(t_param_sprite pos_carac,
				      float *save_x, float *save_y)
{
  if (*save_y == 0.0f && *save_x == 0.0f)
    {
      *save_y = pos_carac.pos.y;
      *save_x = pos_carac.pos.x;
    }
  if (pos_carac.pos.x > *save_x
      && pos_carac.pos.x >= 1150 && pos_carac.pos.x <= 1450)
    {
      *save_y -= 0.55;
      *save_x = pos_carac.pos.x;
    }
  if (pos_carac.pos.x < *save_x
      && pos_carac.pos.x >= 1150 && pos_carac.pos.x <= 1450)
    {
      *save_y += 0.55;
      *save_x = pos_carac.pos.x;
    }
  return (pos_carac);
}

t_param_sprite	carac_move_jump(t_param_sprite pos_carac, int *clems)
{
  static float	save_y = 0.0f;
  static float	save_x = 0.0f;
  static int	dodo = 0;

  pos_carac = carac_move_jump_scale(pos_carac, &save_x, &save_y);
  if (pos_carac.pos.y >= save_y - 90.0f && dodo == 0)
    {
      pos_carac.pos.y = pos_carac.pos.y - 1;
      if (pos_carac.pos.y == save_y - 90.0f)
	dodo = 1;
    }
  else if (pos_carac.pos.y <= save_y && dodo == 1)
    {
      pos_carac.pos.y = pos_carac.pos.y + 1;
      if (pos_carac.pos.y == save_y)
	{
	  *clems = 0;
	  dodo = 0;
	  save_y = 0.0f;
	  save_x = 0.0f;
	}
    }
  return (pos_carac);
}

t_param_sprite	carac_move_right(t_param_sprite pos_carac)
{
  if (timer_carac() == 1)
    pos_carac.rectangle.left = pos_carac.rectangle.left + 50;
  pos_carac.pos.x = pos_carac.pos.x - 1;
  if (pos_carac.rectangle.left >= 150)
    {
      pos_carac.rectangle.left = 0;
      pos_carac.rectangle.top = 50;
    }
  if (pos_carac.pos.x >= 1150 && pos_carac.pos.x <= 1450)
    pos_carac.pos.y = pos_carac.pos.y + 0.55;
  return (pos_carac);
}

t_param_sprite	carac_move_left(t_param_sprite pos_carac)
{
  pos_carac.rectangle.top = 0;
  pos_carac.rectangle.width = 50;
  pos_carac.rectangle.height = 50;
  if (timer_carac() == 1)
    pos_carac.rectangle.left = pos_carac.rectangle.left + 50;
  pos_carac.pos.x = pos_carac.pos.x + 1;
  if (pos_carac.rectangle.left >= 150)
    {
      pos_carac.rectangle.left = 0;
      pos_carac.rectangle.top = 0;
    }
  if (pos_carac.pos.x >= 1150 && pos_carac.pos.x <= 1450)
    pos_carac.pos.y = pos_carac.pos.y - 0.55;
  return (pos_carac);
}
