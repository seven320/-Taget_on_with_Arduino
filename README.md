# Remote Target with arduino uno

## About
this code is written for Air soft gun target with arduino.
I hope you will enjoy it!!


## Getting Started
buy arduino UNO R3 starter kit [amazon link](https://www.amazon.co.jp/s?k=arduiono&__mk_ja_JP=%E3%82%AB%E3%82%BF%E3%82%AB%E3%83%8A&ref=nb_sb_noss_1)

then download aruduino IDE [link](https://www.arduino.cc/en/Main/Software)

git clone this repository and write target/target.ino to your arduino!!

install libraries by arduino IDE
```
Servo.h
IRremoteInt.h
IRremote
```
set pin and servo moter

change IR sensor signal which is depend on your remote controller(you can see it by arduino IDE)

## Usage
connect your arduino to power

push power button in your controller


there are 2 modes!

mode1 : when you push button, servo moter will work and target will be ready
mode2 : every 10 sec servo moter work automatically!
mode3 : almost done not yet
mode4 : coming soon...
