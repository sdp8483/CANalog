#!/usr/bin/python

import websocket

ws = websocket.WebSocket()
ws.connect("ws://192.168.1.1/ws")

result = ws.recv()
print(result)
 
ws.close()
