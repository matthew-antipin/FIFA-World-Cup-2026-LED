# FIFA-World-Cup-2026-LED

## UPDATE ##
  I ended up using a webscraper instead, as that is much faster than the API I was using before. Since we're watching live broadcasts, speed      matters more, and curiously, sometimes the webscraper was faster than the broadcasted signal on the TV.
  ## ##

Simple API-driven program in Python, turning on an LED sequence via Arduino when a certain team scores. Written for Canada and Mexico.

I was initially inspired by an old project that I wanted to create years ago for the Toronto Maple Leafs, a sort of DIY Budweiser Goal Light/Horn.

While I don't have any speakers that can be plugged directly into an Arduino, I had 12V RGB LED strips leftover from a very old project, and I
had a spare Arduino Uno. With some simple soldering and using some basic MOSFETS to control the 12V rail using PWM digital pins on the Arduino,
I made a simple program that receives a serial command and runs a function that has a celebration sequence, using 2 individual strips.

From the Python side, I used a free and public API (https://worldcup26.ir/get/games) to check the score of a given match every 2 seconds, and
using extremely simple logic to compare the old recorded score (from 2 seconds ago) to the current recorded score (from "now"), if the score
has increased, then a command is sent to the Arduino over a serial USB connection to activate the celebration sequence (in this code, either
Mexico (green, white and red) or Canada (red and white)).

Special thanks to the public API that really made this possible! Available at:
https://github.com/rezarahiminia/worldcup2026?utm_source=chatgpt.com
