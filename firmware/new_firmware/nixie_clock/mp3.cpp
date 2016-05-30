#include <DFPlayer.h>

#include "pindef.h"
#include "serial.h"
#include "clock.h"
#include "alarm.h"

DFPlayer *dfplayer;

int music_count = 0;
int music_current_select = 1;

int playing_song = 0;
int pause_song = 0;
int volume = 15;

void mp3_init()
{
  dfplayer = new DFPlayer(SM_Software, mp3_rx, mp3_tx);
  delay(10);

  dfplayer->stop();
  delay(10);

  music_count = dfplayer->get_tracks();
  delay(10);

  dfplayer->set_volume(volume);

  my_printf("MP3 songs:%d\n", music_count);
}

void play_alarm_music(int volume, int song)
{
  dfplayer->set_volume(volume);
  delay(10);
  
  dfplayer->play_root(song);
}

int volume_inc()
{
  if(playing_song == 0) {
    return volume;
  }
  
  if(volume <= 25) {
    volume += 5;
    dfplayer->set_volume(volume);
    save_music_volume_setting(volume);
  }

  return volume;
}

int volume_dec()
{
  if(playing_song == 0) {
    return volume;
  }
  
  if(volume >= 5) {
    volume -= 5;
    dfplayer->set_volume(volume);
    save_music_volume_setting(volume);
  }

  return volume;
}

void set_music_volume(int _volume)
{
  volume = _volume;
}

void play_music(int song)
{
  dfplayer->set_volume(volume);
  delay(10);
  
  dfplayer->play_root(song);
  
  playing_song = song;
}

void stop_music()
{
  dfplayer->stop();
}

void pause_music()
{
  dfplayer->pause();
  pause_song = playing_song;
  playing_song = 0;
}

void unpuase_music()
{
  dfplayer->unpause();
  playing_song = pause_song;
  pause_song = 0;
}

void display_next_select_music()
{
  if(music_current_select == music_count) {
   music_current_select = 1;
  } else {
   music_current_select++;
  }
}

void play_button_react()
{
  if(clock_mode != MP3_MODE) {
    return;
  }
  
  if(playing_song == music_current_select) {
    pause_music();
  } else if(pause_song == music_current_select) {
    unpuase_music();
  } else {
    play_music(music_current_select);
  }
}

