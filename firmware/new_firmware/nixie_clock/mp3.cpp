#include <DFPlayer.h>
#include <Time.h>

#include "pindef.h"
#include "serial.h"
#include "clock.h"
#include "alarm.h"
#include "mp3.h" 

DFPlayer *dfplayer;

int music_count = 0;
int volume = 30;

void mp3_init()
{
  dfplayer = new DFPlayer(SM_Software, mp3_rx, mp3_tx);
  delay(1);

  dfplayer->stop();
  delay(1);

  music_count = dfplayer->get_tracks();
  delay(1);

  dfplayer->set_volume(volume);
  delay(1);
  
  my_printf("MP3 songs:%d\n", music_count);
}

void play_alarm_music(int volume, int song)
{
  dfplayer->set_volume(volume);
  delay(1);
  
  dfplayer->play_root(song);
}

int volume_inc()
{
  if(volume <= 25) {
    volume += 5;
    dfplayer->set_volume(volume);
    save_music_volume_setting(volume);
  }

  return volume;
}

int volume_dec()
{
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
  delay(1);
  
  dfplayer->play_root(song);
  delay(1);
}

void stop_music()
{
  dfplayer->stop();
  delay(1);
}

void pause_music()
{
  dfplayer->pause();
  delay(1);
}

void unpause_music()
{
  dfplayer->unpause();
  delay(1);
}

void play_radom_music()
{
  if(music_count >= 1) {
    int random_number = year()  + month() * music_count + day() * music_count  + hour() + minute() + second();
    int random_song = random_number % music_count + 1;
        
    dfplayer->play_root(random_song);
    delay(1);
  }
}

