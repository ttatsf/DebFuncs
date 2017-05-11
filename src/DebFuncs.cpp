#include "DebFuncs.h"

DF::Debounce::Debounce()
                      : RATE( 25 )
                        , THRESHOLD_L( 10 )
                        , THRESHOLD_H( 90 )
                        , recentValueMul100( 100 )
                        , debouncedValue( true )
                      {
}
DF::Debounce::Debounce( long rate )
                      : RATE(rate)
                        , THRESHOLD_L(10)
                        , THRESHOLD_H(90)
                        , recentValueMul100(100)
                        , debouncedValue(true)
                      {
}
DF::Debounce::Debounce( long rate
                        , long thresholdL
                        , long thresholdH
                      )
                      : RATE( rate )
                        , THRESHOLD_L( thresholdL )
                        , THRESHOLD_H( thresholdH )
                        , recentValueMul100( 100 )
                        , debouncedValue( true )
                      {
}
bool DF::Debounce::operator()( const bool& currentValue ){
  const long SMOOTHED_VALUE_MUL100 (  RATE * currentValue
                                    + (100 - RATE) * recentValueMul100 / 100
                                    );
  recentValueMul100 = SMOOTHED_VALUE_MUL100;

  if ( debouncedValue ){
      if( SMOOTHED_VALUE_MUL100 < THRESHOLD_L ){
        return debouncedValue = false;
      }
  } else if( SMOOTHED_VALUE_MUL100 > THRESHOLD_H ){
        return debouncedValue = true;
  }
  return debouncedValue;
}

DF::IsDROPPED::IsDROPPED():recentValue( false ){
}
bool DF::IsDROPPED::operator()( const bool& currentValue ){
  const bool RESULT ( recentValue && !currentValue );
  recentValue = currentValue;
  return RESULT;
}

DF::IsRAISED::IsRAISED():recentValue( false ){
}
bool DF::IsRAISED::operator()( const bool& currentValue ){
  const bool RESULT ( !recentValue && currentValue );
  recentValue = currentValue;
  return RESULT;
}

DF::IsCHANGED::IsCHANGED():recentValue( false ){
}
bool DF::IsCHANGED::operator()( const bool& currentValue ){
  const bool RESULT ( recentValue != currentValue );
  recentValue = currentValue;
  return RESULT;
}
