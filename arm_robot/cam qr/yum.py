import numpy as np
import cv2
import serial
import re
import pyzbar.pyzbar as pyzbar

x1, y1 = 100, 100  # Top-left corner
x2, y2 = 400, 400  # Bottom-right corner

x3, y3 = 200, 250  # Top-left corner
x4, y4 = 320, 300  # Bottom-right corner

# Capturing video through webcam
webcam = cv2.VideoCapture(0)
arduino = serial.Serial('COM10', 9600)  # Change 'COM10' to your Arduino's COM port
font = cv2.FONT_HERSHEY_PLAIN

# Start a while loop
while True:
    # Reading the video from the webcam in image frames
    _, imageFrame = webcam.read()
    imageFrame = imageFrame[y3:y4, x3:x4]

    # Convert the imageFrame from BGR (RGB color space) to HSV (hue-saturation-value) color space
    hsvFrame = cv2.cvtColor(imageFrame, cv2.COLOR_BGR2HSV)

    # Set range for red color and define a mask
    white_lower = np.array([0, 0, 141], np.uint8)
    white_upper = np.array([85, 66, 255], np.uint8)
    white_mask = cv2.inRange(hsvFrame, white_lower, white_upper)

    # Set range for green color and define a mask
    black_lower = np.array([0, 0, 0], np.uint8)
    black_upper = np.array([179, 255, 19], np.uint8)
    black_mask = cv2.inRange(hsvFrame, black_lower, black_upper)

    # Set range for blue color and define a mask
    blue_lower = np.array([88, 176, 70], np.uint8)
    blue_upper = np.array([133, 255, 255], np.uint8)
    blue_mask = cv2.inRange(hsvFrame, blue_lower, blue_upper)

    # Morphological Transform, Dilation for each color and bitwise_and operator
    # between imageFrame and mask to detect only that particular color
    kernel = np.ones((5, 5), "uint8")

    # For red color
    white_mask = cv2.dilate(white_mask, kernel)
    res_white = cv2.bitwise_and(imageFrame, imageFrame, mask=white_mask)

    # For green color
    black_mask = cv2.dilate(black_mask, kernel)
    res_black = cv2.bitwise_and(imageFrame, imageFrame, mask=black_mask)

    # For blue color
    blue_mask = cv2.dilate(blue_mask, kernel)
    res_blue = cv2.bitwise_and(imageFrame, imageFrame, mask=blue_mask)

    # Creating contours to track red, green, and blue colors
    contours, hierarchy = cv2.findContours(white_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for pic, contour in enumerate(contours):
        area = cv2.contourArea(contour)
        if area > 300:
            x, y, w, h = cv2.boundingRect(contour)
            imageFrame = cv2.rectangle(imageFrame, (x, y), (x + w, y + h), (28, 0, 200), 2)
            cv2.putText(imageFrame, "White Colour", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (28, 0, 200))
            arduino.write(b'W')  # Send 'W' for white
            print("sent White")

    # Creating contour to track green color
    contours, hierarchy = cv2.findContours(black_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for pic, contour in enumerate(contours):
        area = cv2.contourArea(contour)
        if area > 300:
            x, y, w, h = cv2.boundingRect(contour)
            imageFrame = cv2.rectangle(imageFrame, (x, y), (x + w, y + h), (0, 255, 0), 2)
            cv2.putText(imageFrame, "Black Colour", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (0, 255, 0))
            arduino.write(b'L')  # Send 'B' for black
            print("sent Black")


    # Creating contour to track blue color
    contours, hierarchy = cv2.findContours(blue_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for pic, contour in enumerate(contours):
        area = cv2.contourArea(contour)
        if area > 300:
            x, y, w, h = cv2.boundingRect(contour)
            imageFrame = cv2.rectangle(imageFrame, (x, y), (x + w, y + h), (255, 0, 0), 2)
            cv2.putText(imageFrame, "Blue Colour", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, (255, 0, 0))
            arduino.write(b'B')  # Send 'L' for blue
            print("sent Blue")

    # QR code detection
    check, frame = webcam.read()
    decodedObjects = pyzbar.decode(frame)

    # Crop the frame to the defined ROI
    frame = frame[y1:y2, x1:x2]

    for obj in decodedObjects:
        DATA = obj.data
        # Display the QR code data on the video frame at position (50, 50)
        cv2.putText(frame, str(DATA), (50, 50), font, 2, (255, 0, 0), 3)

        # Checking the ID
        # Replace the "ID == 2" with your ID so that the LED chaser can start working
        if re.search(b'1', DATA):
            # Send '1' to the serial port
            arduino.write(b'1')
            print("sent 1")

        elif re.search(b'2', DATA):
            arduino.write(b'2')
            print("sent 2")

    # Display the video frame
    cv2.imshow("Multiple Color Detection in Real-Time", imageFrame)
    cv2.imshow("QR", frame)

    if cv2.waitKey(10) & 0xFF == ord('q'):
        webcam.release()
        cv2.destroyAllWindows()
        break

# Close the serial connection when done
arduino.close()
