/*
** main.c for main in /home/nicolas94200/CGRAPH/tekadventure
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Thu Apr 13 14:17:21 2017 goedert nicolas
** Last update Sun Apr 30 11:33:31 2017 goedert nicolas
*/

#include "my.h"

sfRenderWindow*		create_window(char *name, sfVector2i screen_size)
{
  sfRenderWindow*	window;
  sfVideoMode		mode;

  mode.width = screen_size.x;
  mode.height = screen_size.y;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit(EXIT_FAILURE);
  return (window);
}

sfUint8*	create_pixel_buffer(sfVector2i screen_size)
{
  int		i;
  sfUint8*	pixels;

  pixels = malloc(screen_size.x * screen_size.y * 4 * sizeof(*pixels));
  if (pixels == NULL)
    {
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (i < screen_size.x * screen_size.y * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return pixels;
}

void			windows(t_param_tekadventure param,
				t_tab_sprite sprites)
{
  sfVector2i		mouse;
  sfWindow		*win;

  win = param.window;
  while (sfRenderWindow_isOpen(param.window))
    {
      mouse = sfMouse_getPosition(win);
      if ((mouse.x >= 410 && mouse.y >= 300)
      && (mouse.x <= 430 && mouse.y <= 360))
	if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	  {
	    sprites.pos_bottle.pos.x = 1615;
	    sprites.pos_bottle.pos.y = 40;
	  }
      while (sfRenderWindow_pollEvent(param.window, &param.event))
	{
	  if (param.event.type == sfEvtClosed)
	    sfRenderWindow_close(param.window);
	}
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	exit(0);
      sprites_draw(param, &sprites);
    }
}

int			main(int argc, char **argv)
{
  t_param_tekadventure	param;
  t_tab_sprite		sprites;

  if (argc != 1)
    return (0);
  (void)(argv);
  param.screen_size.x = 1920;
  param.screen_size.y = 1080;
  param.window = create_window("Tekadventure", param.screen_size);
  tracker(1);
  param.pixels = create_pixel_buffer(param.screen_size);
  if (sprites_init(param, &sprites) == 1)
    return (1);
  windows(param, sprites);
  sfRenderWindow_destroy(param.window);
  tracker(-1);
  return (EXIT_SUCCESS);
}
