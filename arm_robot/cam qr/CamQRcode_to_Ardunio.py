import cv2
import serial
import re
import time
import pyzbar.pyzbar as pyzbar

Resetpose1 = 0
Resetpose2 = 0

# Setting serial port to COM10 at a baud rate of 9600
port = serial.Serial('COM10', 9600)

video = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_PLAIN

w = 640  # Set the width
h = 480  # Set the height

video.set(cv2.CAP_PROP_FRAME_WIDTH, w)
video.set(cv2.CAP_PROP_FRAME_HEIGHT, h)

while True:
    check, frame = video.read()
    decodedObjects = pyzbar.decode(frame)

    for obj in decodedObjects:
        DATA = obj.data
        # Display the QR code data on the video frame at position (50, 50)
        cv2.putText(frame, str(DATA), (50, 50), font, 2, (255, 0, 0), 3)

        # Checking the ID
        # Replace the "ID == 2" with your ID so that the LED chaser can start working
        if re.search(b'1', DATA) and Resetpose1 == 0:
            # Send '1' to the serial port
            port.write(b'1')
            Resetpose1 = 1
            print("sent 1")
            time.sleep(10)
            Resetpose1 = 0

        elif re.search(b'2', DATA) and Resetpose2 == 0:
            port.write(b'2')
            Resetpose2 = 1
            print("sent 2")
            time.sleep(10)
            Resetpose2 = 0

    cv2.imshow("Video", frame)
    key = cv2.waitKey(1)
    if key == ord('q'):
        break

video.release()
cv2.destroyAllWindows()

