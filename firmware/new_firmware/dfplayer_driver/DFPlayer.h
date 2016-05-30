#ifndef DFPlayer_h
#define DFPlayer_h

#include <Arduino.h>
#include <SoftwareSerial.h>

// DFPlayer Module Commands
#define DFPLAYER_PLAY_NEXT          0x01
#define DFPLAYER_PLAY_PREVIOUS      0x02
#define DFPLAYER_PLAY_ROOT          0x03  // 1-2999
#define DFPLAYER_INCREASE_VOLUME    0x04
#define DFPLAYER_DECREASE_VOLUME    0x05
#define DFPLAYER_SPECIFY_VOLUME     0x06
#define DFPLAYER_SPECIFY_EQ         0x07  // 0:Normal / 1:Pop / 2:Rock / 3:Jazz / 4:Classic / 5:Bass
#define DFPLAYER_SINGLE_REPEAT      0x08  // 1-2999
#define DFPLAYER_PLAYBACK_DEVICE    0x09  // 0:USB / 1:SD
#define DFPLAYER_STANDBY            0x0A
#define DFPLAYER_RESET              0x0C
#define DFPLAYER_UNPAUSE            0x0D
#define DFPLAYER_PAUSE              0x0E
#define DFPLAYER_PLAY_FOLDER        0x0F  // 01-99 folder and 1-255 track
#define DFPLAYER_ALL_REPEAT         0x11  // 0:Stop Repeat / 1:All Repeat
#define DFPLAYER_PLAY_MP3           0x12  // Play "/mp3" folder files
#define DFPLAYER_PLAY_AD            0x13  // Play "/advert" folder ads while saving current playback position
#define DFPLAYER_STOP_AD            0x15  // Stop playing ad and resume playback
#define DFPLAYER_STOP               0x16  // Stop Playback
#define DFPLAYER_FOLDER_REPEAT      0x17
#define DFPLAYER_PLAY_RANDOM        0x18
#define DFPLAYER_REPEAT_CURRENT     0x19
#define DFPLAYER_QUERY_STATUS       0x42
#define DFPLAYER_QUERY_VOLUME       0x43
#define DFPLAYER_QUERY_EQ           0x44
#define DFPLAYER_QUERY_USB_FILES    0x47
#define DFPLAYER_QUERY_SD_FILES     0x48
#define DFPLAYER_QUERY_USB_TRACK    0x4B
#define DFPLAYER_QUERY_SD_TRACK     0x4C
#define DFPLAYER_QUERY_FOLDER_FILES 0x4E
#define DFPLAYER_QUERY_FOLDERS      0x4F


enum SerialMode {
  SM_Hardware = 0,
  SM_Software = 1
};


enum Equalizer {
  EQ_Normal  = 0,
  EQ_Pop     = 1,
  EQ_Rock    = 2,
  EQ_Jazz    = 3,
  EQ_Classic = 4,
  EQ_Bass    = 5
};


class DFPlayer {
  
  public:
    // Initialize
    DFPlayer();
    DFPlayer(SerialMode mode, int rxPin, int txPin);
    ~DFPlayer();
    void initialize(SerialMode mode, int rxPin, int txPin);
    void reset();
    void standby();
    
    // Settings
    void increase_volume();
    void decrease_volume();
    void set_volume(int volume);
    int get_volume();
    void set_eq(Equalizer eq);
    Equalizer get_eq();
    
    // Playback
    void stop();
    void pause();
    void unpause();
    void play();
    void play_next();
    void play_previous();
    void play_root(int track);
    void play_root(int track, bool repeat);
    void play_folder(int folder, int track);
    void play_folder(int folder, int track, bool repeat);
    void play_mp3(int track);
    void play_mp3(int track, bool repeat);
    void play_ad(int track);
    void stop_ad();
    void repeat(bool repeat);
    
    // Folders/Tracks
    int get_folders();
    int get_tracks();
    int get_tracks(int folder);
    int get_playing();
    
  private:
    // Static Members
    static const byte DFPLAYER_START_BYTE   = 0x7E;
    static const byte DFPLAYER_VERSION_BYTE = 0xFF;
    static const byte DFPLAYER_CMD_LEN_BYTE = 0x06;
    static const byte DFPLAYER_NO_ACK_BYTE  = 0x00;
    static const byte DFPLAYER_ACK_BYTE     = 0x01;
    static const byte DFPLAYER_END_BYTE     = 0xEF;
    static const int  DFPLAYER_INIT_DELAY   = 250;
    static const int  DFPLAYER_CMD_DELAY    = 10;
    static const int  DFPLAYER_READ_TIMEOUT = 250;
    
    // Members
    bool initialized_;
    SerialMode serial_mode_;
    SoftwareSerial* software_serial_;
    
    // Methods
    void execute_cmd(byte command);
    void execute_cmd(byte command, byte param1, byte param2);
    int read_cmd(byte command);
    int read_cmd(byte command, byte param1, byte param2);
    int serial_available();
    int serial_read();
    void serial_write(byte b);
};


#endif
