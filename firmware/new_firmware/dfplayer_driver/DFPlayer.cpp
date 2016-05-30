
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFPlayer.h>

////////////////////////////
// Public Methods
////////////////////////////


DFPlayer::DFPlayer() {
  initialized_ = false;
}


DFPlayer::DFPlayer(SerialMode mode, int rxPin, int txPin) {
  initialized_ = false;
  initialize(mode, rxPin, txPin);
}


DFPlayer::~DFPlayer() {
  delete software_serial_;
}


void DFPlayer::initialize(SerialMode mode, int rxPin, int txPin) {
  //Serial.println("Initializing");
  serial_mode_ = mode;
  if(serial_mode_ == SM_Software) {
    // Software Serial
    //Serial.println("SoftwareSerial");
    software_serial_ = new SoftwareSerial(rxPin, txPin);
    //Serial.println("Begin");
    software_serial_->begin(9600);
  } else {
    // Use the Hardware Serial
    Serial.begin(9600);
  }
  
  delay(DFPLAYER_INIT_DELAY);
  initialized_ = true;
  //Serial.println("Initialize Complete");
}


void DFPlayer::reset() {
  execute_cmd(DFPLAYER_RESET, 0 ,0);
}


void DFPlayer::standby() {
  execute_cmd(DFPLAYER_STANDBY);
}


void DFPlayer::increase_volume() {
  execute_cmd(DFPLAYER_INCREASE_VOLUME);
}


void DFPlayer::decrease_volume() {
  execute_cmd(DFPLAYER_INCREASE_VOLUME);
}


void DFPlayer::set_volume(int volume) {
  execute_cmd(DFPLAYER_SPECIFY_VOLUME, 0, volume);
}


int DFPlayer::get_volume() {
  return read_cmd(DFPLAYER_QUERY_VOLUME);
}


void DFPlayer::set_eq(Equalizer eq) {
  execute_cmd(DFPLAYER_SPECIFY_EQ, 0, eq);
}


Equalizer DFPlayer::get_eq() {
  return (Equalizer)read_cmd(DFPLAYER_QUERY_EQ);
}


void DFPlayer::stop() {
  execute_cmd(DFPLAYER_STOP);
}


void DFPlayer::pause() {
  execute_cmd(DFPLAYER_PAUSE);
}


void DFPlayer::unpause() {
  execute_cmd(DFPLAYER_UNPAUSE);
}


void DFPlayer::play() {
  execute_cmd(DFPLAYER_UNPAUSE);
}


void DFPlayer::play_next() {
  execute_cmd(DFPLAYER_PLAY_NEXT);
}


void DFPlayer::play_previous() {
  execute_cmd(DFPLAYER_PLAY_PREVIOUS);
}


void DFPlayer::play_root(int track) {
  play_root(track, false);
}
void DFPlayer::play_root(int track, bool bRepeat) {
  execute_cmd(DFPLAYER_PLAY_ROOT, 0, track);
  
  if(bRepeat) {
    delay(DFPLAYER_CMD_DELAY);
    repeat(true);
  }
}


void DFPlayer::play_folder(int folder, int track) {
  play_folder(folder, track, false);
}
void DFPlayer::play_folder(int folder, int track, bool bRepeat) {
  execute_cmd(DFPLAYER_PLAY_FOLDER, folder, track);
  
  if(bRepeat) {
    delay(DFPLAYER_CMD_DELAY);
    repeat(true);
  }
}


void DFPlayer::play_mp3(int track) {
  play_mp3(track, false);
}
void DFPlayer::play_mp3(int track, bool bRepeat) {
  execute_cmd(DFPLAYER_PLAY_MP3, 0, track);
  
  if(bRepeat) {
    delay(DFPLAYER_CMD_DELAY);
    repeat(true);
  }
}


void DFPlayer::play_ad(int track) {
  execute_cmd(DFPLAYER_PLAY_AD, 0, track);
}


void DFPlayer::stop_ad() {
  execute_cmd(DFPLAYER_STOP_AD);
}


void DFPlayer::repeat(bool bRepeat) {
  execute_cmd(DFPLAYER_REPEAT_CURRENT, 0, !bRepeat);
}


int DFPlayer::get_folders() {
  return read_cmd(DFPLAYER_QUERY_FOLDERS);
}


int DFPlayer::get_tracks() {
  return read_cmd(DFPLAYER_QUERY_SD_FILES);
}
int DFPlayer::get_tracks(int folder) {
  return read_cmd(DFPLAYER_QUERY_FOLDER_FILES, 0, folder);
}


int DFPlayer::get_playing() {
  return read_cmd(DFPLAYER_QUERY_SD_TRACK);
}



////////////////////////////
// Private Methods
////////////////////////////

void DFPlayer::execute_cmd(byte command) {
  execute_cmd(command, 0, 0);
}
void DFPlayer::execute_cmd(byte command, byte param1, byte param2) {
  // Calculate the command checksum
  word checksum = -(
    DFPLAYER_VERSION_BYTE +
    DFPLAYER_CMD_LEN_BYTE +
    command +
    DFPLAYER_NO_ACK_BYTE +
    param1 +
    param2
  );
  
  // Build the command
  byte cmd[10] = {
    DFPLAYER_START_BYTE,
    DFPLAYER_VERSION_BYTE,
    DFPLAYER_CMD_LEN_BYTE,
    command,
    DFPLAYER_NO_ACK_BYTE,
    param1,
    param2,
    highByte(checksum),
    lowByte(checksum),
    DFPLAYER_END_BYTE
  };
  
  // Send the Command
  for(int i=0; i < 10; i++) {
    serial_write(cmd[i]);
    Serial.print(cmd[i], HEX); Serial.print(" ");
  }
  //Serial.println("");
}

int DFPlayer::read_cmd(byte command) {
  return read_cmd(command, 0, 0);
}
int DFPlayer::read_cmd(byte command, byte param1, byte param2) {
  int result = 0;
  int timeout = DFPLAYER_READ_TIMEOUT;
  int i = 0;
  
  if(serial_mode_ == SM_Software) {
    software_serial_->listen();
  }
  
  execute_cmd(command, param1, param2);
  
  while(timeout-- > 0 && i < 10) {
    if(serial_available() > 0) {
      byte b = serial_read();
      i++;
      
      if (i == 7) {
        result = b;
      }
    } else {
      delay(1);
    }
  }
  
  return result;
}


int DFPlayer::serial_available() {
  if(serial_mode_ == SM_Software) {
    return software_serial_->available();
  } else {
    return Serial.available();
  }
}


int DFPlayer::serial_read() {
  if(serial_mode_ == SM_Software) {
    return software_serial_->read();
  } else {
    return Serial.read();
  }
}


void DFPlayer::serial_write(byte b) {
  if(serial_mode_ == SM_Software) {
    software_serial_->write(b);
  } else {
    Serial.write(b);
  }
}
