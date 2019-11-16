# Remote Target with arduino uno

## About
this code is written for Air soft gun target with arduino.
I hope you will enjoy it!!


## Getting Started
buy arduino UNO R3 starter kit(amazon link)
[https://www.amazon.co.jp/ELEGOO-%E3%82%AD%E3%83%83%E3%83%88-%E3%83%AC%E3%83%99%E3%83%AB%E3%82%A2%E3%83%83%E3%83%97-%E3%83%81%E3%83%A5%E3%83%BC%E3%83%88%E3%83%AA%E3%82%A2%E3%83%AB%E4%BB%98-mega2560-Arduino%E7%94%A8/dp/B06XF2HZGT/ref=sr_1_26_sspa?adgrpid=56128882994&gclid=Cj0KCQiA2b7uBRDsARIsAEE9XpEHDR1yb-Yg3r5Ad2hqSpM7t4HeULn74XDLzSfxGTlzmYWL6PZBhuQaAtckEALw_wcB&hvadid=338574310769&hvdev=c&hvlocphy=1009507&hvnetw=g&hvpos=1t1&hvqmt=b&hvrand=13518035080276249748&hvtargid=aud-758806828496%3Akwd-333861585003&hydadcr=6765_10869946&jp-ad-ap=0&keywords=arduino%E3%82%92%E3%81%AF%E3%81%98%E3%82%81%E3%82%88%E3%81%86%E3%82%AD%E3%83%83%E3%83%88&qid=1573919560&sr=8-26-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzRFYzQlVWNEtXVUNFJmVuY3J5cHRlZElkPUEwMjgxNTQ4MzZSU1AwNVNVWE9LMiZlbmNyeXB0ZWRBZElkPUEzRDlEUTdQRFFXQ1dKJndpZGdldE5hbWU9c3BfbXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==]

then download aruduino IDE(link)
[https://www.arduino.cc/en/Main/Software]

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
