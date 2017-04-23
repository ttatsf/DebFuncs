#DebFuncs for Arduino
Functions for debouncing data, especially good for digitalRead().
##Description
DebFuncs has 4 simple function objects.

+ "Debounce" : returns debounced data from incoming data.
+ "IsDROPPED" : returns whether incoming debounced data is dropped from previous data.
+ "IsRAISED" : returns whether incoming debounced data is raised from previous data.
+ "IsCHANGED" : returns whether incoming debounced data is changed from previous data.

#DebFuncs VS. [DebounceFunc](https://github.com/ttatsf/DebounceFunc)

Uses the Schmitt trigger emulation to work faster and more stably.

##Installation
[Download ZIP](https://github.com/ttatsf/DebFuncs/archive/master.zip) and [follow instructions here.](https://www.arduino.cc/en/Guide/Libraries)

##Typical usage
As these are "function" objects, you can(and have to) handle each instance as  "function" directly.


```

```




#License
This code is available under the [MIT License](http://opensource.org/licenses/mit-license.php).
