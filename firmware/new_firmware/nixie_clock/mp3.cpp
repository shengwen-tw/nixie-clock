#include <DFPlayer.h>
#include <Time.h>

#include "pindef.h"
#include "serial.h"
#include "clock.h"
#include "alarm.h"
#include "mp3.h" 

DFPlayer *dfplayer;

int music_count = 0;
int music_volume = 30;

void mp3_init()
{
  dfplayer = new DFPlayer(SM_Software, mp3_rx, mp3_tx);
  delay(20);

  music_count = dfplayer->get_tracks();
  delay(5);

  dfplayer->stop();
  delay(5);

  dfplayer->set_volume(music_volume);
  delay(5);
  
  my_printf("MP3 songs:%d\n", music_count);
}

int volume_inc()
{
  if(music_volume <= 25) {
    music_volume += 5;
    dfplayer->set_volume(music_volume);
    save_music_volume_setting(music_volume);
  }

  return music_volume;
}

int volume_dec()
{
  if(music_volume >= 5) {
    music_volume -= 5;
    dfplayer->set_volume(music_volume);
    save_music_volume_setting(music_volume);
  }

  return music_volume;
}

void set_music_volume(int _volume)
{
  if(_volume > 30 || _volume < 0) {
    return;
  }
  
  music_volume = _volume;

  save_music_volume_setting(music_volume);
}

void play_music(int song)
{ 
  dfplayer->play_root(song);
  delay(5);
}

void stop_music()
{
  dfplayer->stop();
  delay(5);
}

void pause_music()
{
  dfplayer->pause();
  delay(5);
}

void unpause_music()
{
  dfplayer->unpause();
  delay(5);
}

void play_radom_music(int _volume)
{
  if(music_count >= 1) {
    int random_number = year()  + month() * music_count + day() * music_count  + hour() + minute() + second();
    int random_song = random_number % music_count + 1;

    dfplayer->set_volume(_volume);
    delay(5);
        
    dfplayer->play_root(random_song);
    delay(5);
  }
}

