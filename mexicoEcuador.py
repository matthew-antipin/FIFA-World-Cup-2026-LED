from playwright.sync_api import sync_playwright
import time
import serial

arduino = serial.Serial('/dev/cu.usbserial-110',115200)
time.sleep(2)
url = "https://www.google.com/search?q=mexico+vs+ecuador"
scoreDiv = "div.imso_mh__scr-it"
penalDiv = "div.imso_mh_s__pen-scr-it"
with sync_playwright() as p:
    browser = p.chromium.launch(headless=False)
    page = browser.new_page()
    page.goto(url)

    page.wait_for_selector(scoreDiv)
    print(f"Program started!")
    print(f"Current score: ")
    score = page.locator(scoreDiv).all_inner_texts()
    print(score)
    print(f"Current penalty score: ")
    #penalScore = page.locator(penalDiv).all_inner_texts()
    #print(penalScore)

    curScore = score[0]
    #curPenalScore = penalScore[0]
    try:
        while True:
            score = page.locator(scoreDiv).all_inner_texts()
            newScore = score[0]
            #penalScore = page.locator(penalDiv).all_inner_texts()
            #newPenalScore = penalScore[0]
            if newScore != curScore:
                print(f"GOAL!")
                time.sleep(5)
                arduino.write(b"MEXICO")
                curScore = newScore
            #if newPenalScore != curPenalScore:
             #   print(f"PENALTY SHOT GOAL!")
             #   time.sleep(5)
             #   arduino.write(b"penMEXICO")
             #   curPenalScore = newPenalScore
            time.sleep(1)
    except KeyboardInterrupt:
        print(f"Stopping program...")
        time.sleep(1)
    finally:
        browser.close()
        p.stop()
        print(f"Program closed.")