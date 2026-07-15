import requests;
import time;
import datetime;
import serial
arduino = serial.Serial('/dev/cu.usbserial-130',115200)
time.sleep(2)
url="https://worldcup26.ir/get/games";
match_id="73";
oldScore = 0;
try:
    while True:
        data = requests.get(url).json()
        games = data["games"]

        curTime = datetime.datetime.now();

        for game in games:
            if game["id"] == match_id:
                home_team = game["home_team_name_en"]
                away_team = game["away_team_name_en"]
                home_score = int(game["home_score"])
                away_score = int(game["away_score"])
                print(f"{curTime.strftime("%H")}:{curTime.strftime("%M")}:{curTime.strftime("%S")}")
                print(f"{home_team} {home_score} - {away_score} {away_team}")

                curScore = away_score
                if curScore > oldScore:
                    print(f"CANADA GOAL")
                    arduino.write(b'CANADA\n')
                    oldScore = curScore

        time.sleep(2)
except KeyboardInterrupt:
    print("Stopping")
finally:
    arduino.close()