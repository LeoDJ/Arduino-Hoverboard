# Arduino Hoverboard Speed Control
All credits for reverse engineering the gyro communication protocol go to [Drew](http://drewspewsmuse.blogspot.de/2016/06/how-i-hacked-self-balancing-scooter.html).

More information and documentation can be found over on the [wiki](https://github.com/LeoDJ/Arduino-Hoverboard/wiki) (work in progress)

## Current state
It seems like the mainboard always wants to self-stabilize and the value sent from the Gyros truly only send the angle and don't directly control the motor speed.

Therefore the only real option to control the motors individually, aside from trying to counteract the PID loop, is to rewrite the mainboard firmware, as is done by Niklas Fauth in his [hoverboard-firmware-hack](https://github.com/NiklasFauth/hoverboard-firmware-hack).

This is also the path I will follow. Either by building my own firmware or by expanding his.
