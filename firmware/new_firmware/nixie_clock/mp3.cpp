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

/* variable for song looping */
bool playing = false;
bool loop_song = false;
bool go_to_next = false;

void mp3_init()
{
  dfplayer = new DFPlayer(SM_Software, mp3_rx, mp3_tx);
  delay(DFPLAYER_DELAY_TIME);

  music_count = dfplayer->get_tracks();
  delay(DFPLAYER_DELAY_TIME);

  dfplayer->stop();
  delay(DFPLAYER_DELAY_TIME);

  dfplayer->set_volume(music_volume);
  delay(DFPLAYER_DELAY_TIME);
  
  DEBUG_PRINTF("MP3 songs:%d\n", music_count);
}

void check_mp3_state()
{
  if(loop_song == false || playing != true) {
    return;
  }
  
  if(digitalRead(mp3_state) == HIGH) {
    if(go_to_next == true) {
      DEBUG_PRINTF("Play next music\n");
      next_music();

      go_to_next = false;
      playing = false;
    }
  } else {
    go_to_next = true;
    playing = true;
  }
}

void set_mp3_loop_play_state(bool state)
{
  loop_song = state;
  eeprom_save_mp3_loop_setting();
}

int get_mp3_loop_play_state()
{
  return loop_song ? 1 : 0;
}

//Do not mix this function with set_music_volume() !
void load_music_volume_from_eeprom(int _volume)
{
  if(_volume > 30 || _volume < 0) {
    return;
  }
  
  music_volume = _volume;
}

void set_music_volume(int _volume)
{
  if(_volume > 30 || _volume < 0) {
    return;
  }

  dfplayer->set_volume(_volume);
  delay(DFPLAYER_DELAY_TIME);
  
  music_volume = _volume;
}

void play_music(int song)
{ 
  dfplayer->play_root(song);
  delay(DFPLAYER_DELAY_TIME);
}

void stop_music()
{
  dfplayer->stop();
  delay(DFPLAYER_DELAY_TIME);

  playing = false;
  go_to_next = false;
}

void pause_music()
{
  dfplayer->pause();
  delay(DFPLAYER_DELAY_TIME);
}

void unpause_music()
{
  dfplayer->unpause();
  delay(DFPLAYER_DELAY_TIME);
}

void next_music()
{
  dfplayer->play_next();
  delay(DFPLAYER_DELAY_TIME);

  playing = true;
}

void previous_music()
{
  dfplayer->play_previous();
  delay(DFPLAYER_DELAY_TIME);

  playing = true;
}

int get_mp3_volume()
{
  return music_volume;
}

void play_radom_music(int _volume)
{
  if(music_count >= 1) {
    int random_number = year()  + month() * music_count + day() * music_count  + hour() + minute() + second();
    int random_song = random_number % music_count + 1;

    dfplayer->set_volume(_volume);
    delay(DFPLAYER_DELAY_TIME);

    dfplayer->play_root(random_song);
    delay(DFPLAYER_DELAY_TIME);

    playing = true;
  }
}

