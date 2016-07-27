#ifndef __SERIAL_H
#define __SERIAL_H

/* Debug printf option */
#define ENABLE_DEBUG_PRINT 0
#if ENABLE_DEBUG_PRINT == 1
  #define DEBUG_PRINTF my_printf
#else
  #define DEBUG_PRINTF(...)
#endif

/* Bluetooth command register macro */
#define REGISTER_NEW_CMD_START(header, msg_size, func)  if(command == header) { \
                                                              if(serial_read(buff, msg_size)) {return;} \
                                                              func(buff);
#define REGISTER_NEW_CMD(header, msg_size, func)        } else if(command == header) { \
                                                              if(serial_read(buff, msg_size)) {return;} \
                                                              func(buff);
#define REGISTER_NEW_CMD_END()                          }

void my_printf(const char *fmt, ...);

#endif
