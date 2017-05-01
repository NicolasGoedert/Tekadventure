/*
** music.c for music in /home/nicolas94200/CGRAPH/tekadventure/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Sun Apr 16 13:29:42 2017 goedert nicolas
** Last update Sun Apr 16 13:29:42 2017 goedert nicolas
*/

#include "my.h"
#include "adds.h"

static sfMusic	*found_track(int nb, int *play)
{
  sfMusic	*song;

  song = sfMusic_createFromFile(TRACKLIST[nb - 1]);
  sfMusic_play(song);
  *play = 1;
  return (song);
}

void			tracker(int nb)
{
  static sfMusic	*song = NULL;
  static int		play = 0;

  if (nb == 0 && play == 0)
    {
      play = 1;
      sfMusic_pause(song);
    }
  else if (nb == 0 && play == 1)
    {
      play = 0;
      sfMusic_pause(song);
    }
  else if (nb == -1 || (nb <= NB_TRACKS && nb > 0 && song != NULL))
    {
      sfMusic_pause(song);
      sfMusic_destroy(song);
    }
  if (nb <= NB_TRACKS && nb > 0)
    song = found_track(nb, &play);
}
