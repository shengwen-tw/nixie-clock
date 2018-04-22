## Bluetooth serial command (ASCII format)

### 1. Time set command

| start byte | year | year | year | year | month | month | day | day | hour | hour | min | min | sec | sec |
|------------|-------|-------|-------|-------|--------|--------|------|------|-------|-------|---------|---------|---------|---------|
| @          | 1     | 9     | 9     | 7     | 0      | 8      | 1    | 2    | 1     | 9     | 4       | 4       | 0       | 0       |

which means 1997/8/12 19:44:00

### 2. Alarm  set command

| start byte | index | index | hour | hour | min | min |
|------------|-------|-------|------|------|-----|-----|
| $          | 0     | 0     | 1    | 2    | 0   | 8   |

which means set alarm(index 0) to 12:00

### 3. Alarm state set command

| start byte | index | state |
|------------|-------|-------|
| +          | 0     | 1     |

which means enable alarm index 0 (1 = ENABLED, 0 = DISABLED)

### 4. Alarm time request command

**Request for hour information**

| start byte |   |   |
|------------|---|---|
| *          | 1 | 9 |

clock will return message like : "12", which mean hour = 12

**Request for minute information**

| start byte |   |   |
|------------|---|---|
| *          | 4 | 4 |

clock will return message like : "33", which mean minute = 33

**Request for state information**

| start byte |   |   |
|------------|---|---|
| *          | 1 | 7 |

clock will return message like : "1", which mean state = ENABLED

### 5. MP3 volume set command

| start byte | volume | volume |
|------------|--------|--------|
| {          | 1      | 5      |

which means set MP3 player volume to 15 (Volume's range is from 0 to 30)

### 6. Alarm volume set command

| start byte | volume | volume |
|------------|--------|--------|
| }          | 1      | 5      |

which means set alarm volume to 15 (Volume's range is from 0 to 30)

### 7. Music command

**Enable Music loop play**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | l | o | o | p | - | o |

**Disable Music loop play**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | l | o | o | p | - | x |

**Play random music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | r | a | n | d | o | m |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

**Sop playing music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | s | t | o | p | - | - |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message 

**Play next music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | n | e | x | t | - | - |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

**Play last music**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | l | a | s | t | - | - |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

**Play music to demonstrate the alarm volume**

| start byte |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|
| ~          | a | l | - | t | r | y |

Clock will ignore command and return message "1" while playing alarm music, otherwise will return "0" message

### 8. Synchronization command

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | m | p | 3 | - | v | o | l | u | m | e | - |

clock will return the MP3 player volume like "08" which means volume = 8 (Rang is from 0 to 30)

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | m | u | s | i | c | - | l | o | o | p | - |

clock will return the alarm volume like "08" which means volume = 8 (Rang is from 0 to 30)

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | h | i | b | e | r | n | a | t | e | - | - |

clock will return the time like "013007301" which means hibernate from 1:30 to 7:30 and enabled mode is on

| start byte |   |   |   |   |   |   |   |   |   |   |   |
|------------|---|---|---|---|---|---|---|---|---|---|---|
| !          | h | i | b | - | e | n | a | b | l | e | d |

clock will return the hibernation state like "1" which means ENABLED

### 9. Hibernation set command

| start byte | start_hr | start_hr | start_min | start_min | end_hr | end_hr | end_min | end_min | state |
|------------|----------|----------|-----------|-----------|--------|--------|---------|---------|-------|
| %          | 0        | 1        | 3         | 0         | 0      | 7      | 3       | 0       | 1     |

which means set hibernation time from 1:30 to 7:30 and enabled mode is on

### 10. Hibernation state set command

| start byte | state |
|------------|-------|
| ^          | 1     |

which mean set hibernation mode to ENABLED
