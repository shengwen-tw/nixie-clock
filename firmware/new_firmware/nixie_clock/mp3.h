#ifndef __MP3_H
#define __MP3_H

#define DFPLAYER_DELAY_TIME 20

extern int music_current_select;
extern int music_count;

void check_mp3_state();
void set_mp3_loop_play_state(bool state);
int get_mp3_loop_play_state();
void set_alarm_loop_play_state(bool state);

void mp3_init();
void play_alarm_music(int volume, int song);
void play_music(int song);
void stop_music();
void pause_music();
void unpause_music();
void play_radom_music(int volume);
void next_music();
void previous_music();


int get_mp3_volume();
void apply_alarm_volume(int volume);
void load_music_volume_from_eeprom(int _volume);
void set_music_volume(int _volume);

#endif
