import socket
import pygame
import time
import cv2
import numpy as np
import threading

last_cmd = ""

direction = [['NW','N','NE'],
             ['W','B','E'],
             ['SW','S','SE']]


def rounding(x):
    if abs(x)<0.4:
        x = 0
    else:
        x = x*(1/abs(x))
    return x

def Controller():
    global last_cmd
    while True:
        pygame.event.pump()
        x = int(rounding(joy.get_axis(0)) + 1)
        y = int(rounding(joy.get_axis(1)) + 1)
        z = int(rounding(joy.get_axis(2)) + 1)

        # --- Creating message ---
        Orientation = ["Rotate_left",direction[y][x],"Rotate_right"]
        cmd = Orientation[z]

        # --- Sending message ---
        control_sock.sendto(cmd.encode(),(UDP_IP,UDP_port))
        time.sleep(0.1)


UDP_IP = "192.168.12.164"
UDP_port = 4210
control_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

Rasp_ip = "0.0.0.0"
Video_port = 5005
video_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
video_sock.bind((Rasp_ip,Video_port))

pygame.init()
pygame.joystick.init()

joy = pygame.joystick.Joystick(0)
joy.init()

last_cmd = ""

# --- Car control ---
Controller_t = threading.Thread(target=Controller, daemon=True)
Controller_t.start()

while True:
# --- Getting video ---
    packet, _ = video_sock.recvfrom(65536)
    frame = cv2.imdecode(np.frombuffer(packet, dtype=np.uint8), cv2.IMREAD_COLOR)
    frame = cv2.resize(frame,(1000,1000))
    cv2.imshow("Low Latency Stream", frame)

    if cv2.waitKey(1) == ord("q"):
        break





