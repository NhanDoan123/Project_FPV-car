#include <WiFi.h>
#include <WiFiUdp.h>


const char* ssid = "Keily";
const char* password = "phomaiduong1604!";

WiFiUDP udp;
unsigned int localport = 4210;

char packet[16];



void setup() {
  Serial.begin(115200);
  set_pin();

  // WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  while (WiFi.localIP() == INADDR_NONE) {
    Serial.println("Waiting for IP...");
    delay(500);
  }

  Serial.println("\nConnected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // UDP
  udp.begin(localport);
  Serial.print("Listening to port");
  Serial.println(localport);

}

void loop() {
  int size = udp.parsePacket();
  if (size){
    int len = udp.read(packet, sizeof(packet) - 1);
    if (len>0) packet[len] = 0;

    String cmd = String(packet);

    if (cmd =="NW") NW();
    else if (cmd == "N") Forward();
    else if (cmd == "NE") NE();
    else if (cmd == "W") Left();
    else if (cmd == "B") Stop();
    else if (cmd == "E") Right();
    else if (cmd == "SW") SW();
    else if (cmd == "S") Backward();
    else if (cmd == "SE") SE();
    else if (cmd == "Rotate_left") Rotate_left();
    else if (cmd == "Rotate_right") Rotate_right();
  }
}

