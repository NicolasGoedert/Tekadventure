/*
** my.h for include in /home/nicolas94200/CGRAPH/tekadventure
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Thu Apr 13 14:16:51 2017 goedert nicolas
** Last update Sat Apr 29 18:25:08 2017 goedert nicolas
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Music.h>
#include <SFML/Window/Types.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

typedef	struct		s_param_tekadventure
{
  sfRenderWindow	*window;
  sfUint8		*pixels;
  sfEvent		event;
  sfVector2i		screen_size;
}			t_param_tekadventure;

typedef struct	s_param_sprite
{
  sfVector2f	pos;
  sfVector2f	scale;
  sfIntRect	rectangle;
  sfTexture	*texture;
  sfSprite	*sprite;
}		t_param_sprite;

typedef struct		s_tab_sprite
{
  t_param_sprite	pos_back;
  t_param_sprite	pos_carac;
  t_param_sprite	pos_pika;
  t_param_sprite	pos_bottle;
  t_param_sprite	pos_bar_void;
  t_param_sprite	pos_bar_full;
  t_param_sprite	pos_chopped;
  t_param_sprite	pos_tab;
}			t_tab_sprite;

void			tracker(int nb);
int			sprites_init(t_param_tekadventure param,
				     t_tab_sprite *sprites);
void			sprites_draw(t_param_tekadventure param,
				     t_tab_sprite *sprites);
/*
**
*/
t_param_sprite	init_pos_back(t_param_sprite pos_back,
			      t_param_tekadventure param,
			      char *str);
t_param_sprite	draw_back(t_param_tekadventure param,
			  t_param_sprite pos_back);
/*
**
*/
t_param_sprite	init_pos_carac(t_param_sprite pos_carac,
			       t_param_tekadventure param,
			       char *str);
t_param_sprite	draw_carac(t_param_tekadventure param,
			   t_param_sprite pos_carac);
t_param_sprite	carac_move_right(t_param_sprite pos_carac);
t_param_sprite	carac_move_left(t_param_sprite pos_carac);
t_param_sprite	carac_move_jump(t_param_sprite pos_carac, int *);
t_param_sprite	pika_move_left(t_param_sprite pos_pika);
t_param_sprite	pika_move_right(t_param_sprite pos_pika);
int		timer_carac();
int		timer_pika();
/*
**
*/
t_param_sprite	init_pos_pika(t_param_sprite pos_pika,
			      t_param_tekadventure param,
			      char *str);
t_param_sprite	draw_pika(t_param_tekadventure param,
			  t_param_sprite pos_pika);
/*
**
*/
t_param_sprite	init_pos_bottle(t_param_sprite pos_bottle,
				t_param_tekadventure param,
				char *str);
t_param_sprite	draw_bottle(t_param_tekadventure param,
			    t_param_sprite pos_bottle);
/*
**
*/
t_param_sprite	init_pos_bar_void(t_param_sprite pos_bar_void,
				  t_param_tekadventure param,
				  char *str);
t_param_sprite	draw_bar_void(t_param_tekadventure param,
			      t_param_sprite pos_bar_void);
t_param_sprite	init_pos_bar_full(t_param_sprite pos_bar_full,
				  t_param_tekadventure param,
				  char *str);
t_param_sprite	draw_bar_full(t_param_tekadventure param,
			      t_param_sprite pos_bar_void);
/*
**
*/
t_param_sprite	init_pos_chopped(t_param_sprite pos_chopped,
				 t_param_tekadventure param,
				 char *str);
t_param_sprite	draw_chopped(t_param_tekadventure param,
			     t_param_sprite pos_chopped);
/*
**
*/
t_param_sprite	init_pos_tab(t_param_sprite pos_tab,
			     t_param_tekadventure param,
			     char *str);
t_param_sprite	draw_tab(t_param_tekadventure param,
			 t_param_sprite pos_tab);

#endif /* !MY_H_ */
