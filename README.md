# DebFuncs for Arduino
Functions for debouncing data, especially good for digitalRead().
## Description
DebFuncs has 4 simple function objects.

+ "Debounce" : returns debounced data from incoming data.
+ "IsDROPPED" : returns whether incoming debounced data is dropped from previous data.
+ "IsRAISED" : returns whether incoming debounced data is raised from previous data.
+ "IsCHANGED" : returns whether incoming debounced data is changed from previous data.

# DebFuncs VS. [DebounceFunc](https://github.com/ttatsf/DebounceFunc)

Uses the Schmitt trigger emulation to let it work faster and more stably.

## Installation
[Download ZIP](https://github.com/ttatsf/DebFuncs/archive/master.zip) and [follow instructions here.](https://www.arduino.cc/en/Guide/Libraries)

## Typical usage
As these are "function" objects, you can(and have to) handle each instance as  "function" directly.


```cpp

#include <DebFuncs.h>

//  Instantiate a set of function objects.
DF::Debounce debounceOne;
  //  or "DF::Debounce debounceOne(20)",for example.
  //  You can set value to the reaction rate from 0(no reaction) up to 100(no debouncing).
  //  The default value is 25.
DF::IsDROPPED isDroppedOne;

//  Instantiate a set of arrays.
DF::Debounce debounceArray[4];  
  //  or "DF::Debounce  debounceArray[4]={20,20,20,20}",for example.
  //  You can set value to each reaction rate from 0(no reaction) up to 100(no debouncing).
  //  The default value is 25.
DF::IsDROPPED isDroppedArray[4];

const int PIN_ONE = 2;
const int PIN_ARRAY[4] = {3,4,5,6};

void setup() {
  pinMode( PIN_ONE, INPUT_PULLUP );

  for (int i = 0; i < 4; i++){
    pinMode( PIN_ARRAY[i], INPUT_PULLUP );
  }
}

void loop() {
  // regular pattern :
  const bool DEBOUNCED_DATA = debounceOne( digitalRead( PIN_ONE ) );
  if ( isDroppedOne( DEBOUNCED_DATA ) ){
    //  Do anything you want only when the debounced data is dropped.
  }

  // regular pattern for array :
  for (int i = 0; i < 4; i++){
    const bool DEBOUNCED_DATA = debounceArray[i]( digitalRead( PIN_ARRAY[i] ) );
    if ( isDroppedArray[i]( DEBOUNCED_DATA ) ){
      //  Do anything you want only when the debounced data is dropped.
    }
  }
  delay(1);
}

```
For more advanced usage, you can set values to reaction rate(0 ~ 100), lower threshold(0 ~50) and higher threshold(50 ~ 100).

For example:

```
DF:Debounce debounceOne(25, 5, 95);
```
or:
```
DF::Debounce debounceArray[ 4 ] = { DF::Debounce(25, 5, 95)
                                    , DF::Debounce(25, 5, 95)
                                    , DF::Debounce(25, 5, 95)
                                    , DF::Debounce(25, 5, 95)
                                  };
```

# License
This code is available under the [MIT License](http://opensource.org/licenses/mit-license.php).
