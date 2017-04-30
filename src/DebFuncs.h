#ifndef DEB_FUNCS_H
#define DEB_FUNCS_H
#include <Arduino.h>

namespace DF{
  class Debounce{
    private:
      const long RATE;
      const long THRESHOLD_L;
      const long THRESHOLD_H;
      long recentValueMul100;
      bool debouncedValue;
    public:
      Debounce();
      Debounce(long rate);
      Debounce(long rate, long thresholdL, long thresholdH);
      bool operator()(bool currentValue);
  };

  class IsDROPPED{
    private:
      bool recentValue;
    public:
      IsDROPPED();
      bool operator()(bool currentValue);
  };
  class IsRAISED{
    private:
      bool recentValue;
    public:
      IsRAISED();
      bool operator()(bool currentValue);
  };
  class IsCHANGED{
    private:
      bool recentValue;
    public:
      IsCHANGED();
      bool operator()(bool currentValue);
  };
}
#endif
