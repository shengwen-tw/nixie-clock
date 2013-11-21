#ifndef __EVENT_H__
#define __EVENT_H__

/* Button base class */
class buttonBase {
  protected:
      int button_pin;
      int hold_time;
      clock_time *clock;
      
  public:
      /* Class constructor */
      buttonBase(int button_pin, clock_time *clock);
      /* Button event handler */
      virtual void button_click() = 0;
};

/* Implementations of the button */
class searchButton : public buttonBase {
  public:
      /* Class constructor */
      searchButton(int button_pin, clock_time *clock) : buttonBase(button_pin, clock) {}
      /* Button event handler */
      void button_click();
};

class adjustButton : public buttonBase {
  public:
      /* Class constructor */
      adjustButton(int button_pin, clock_time *clock) : buttonBase(button_pin, clock) {}
      /* Button event handler */
      void button_click();
};

class modeButton : public buttonBase {
  public:
      /* Class constructor */
      modeButton(int button_pin, clock_time *clock) : buttonBase(button_pin, clock) {}
      /* Button event handler */
      void button_click();
};

#endif
