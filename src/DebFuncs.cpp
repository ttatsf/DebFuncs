#include <DebFuncs.h>

DF::Debounce::Debounce():RATE(5), recentValueMul100(100), debouncedValue(true){
}
DF::Debounce::Debounce(long rate):RATE(rate), recentValueMul100(100), debouncedValue(true){
}
bool DF::Debounce::operator()(bool currentValue){
  const long SMOOTHED_VALUE_MUL100 = RATE * currentValue + (100 - RATE) * recentValueMul100 / 100;
  recentValueMul100 = SMOOTHED_VALUE_MUL100;

  if(debouncedValue){
    if(SMOOTHED_VALUE_MUL100 < 25){
      debouncedValue = false;
    }
  } else if(SMOOTHED_VALUE_MUL100 > 75){
      debouncedValue = true;
    }
  return debouncedValue;
}

DF::IsDROPPED::IsDROPPED():recentValue(false){
}
bool DF::IsDROPPED::operator()(bool currentValue){
  const bool RESULT = recentValue && !currentValue ;
  recentValue = currentValue;
  return RESULT;
}

DF::IsRAISED::IsRAISED():recentValue(false){
}
bool DF::IsRAISED::operator()(bool currentValue){
  const bool RESULT = !recentValue && currentValue ;
  recentValue = currentValue;
  return RESULT;
}

DF::IsCHANGED::IsCHANGED():recentValue(false){
}
bool DF::IsCHANGED::operator()(bool currentValue){
  const bool RESULT = recentValue != currentValue ;
  recentValue = currentValue;
  return RESULT;
}
