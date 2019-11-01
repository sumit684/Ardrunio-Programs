#include <Stepper.h>

#include <ESP8266WiFi.h>

const char* ssid = "sumit"; // SSID i.e. Service Set Identifier is the name of your WIFI
const char* password = "12341234"; // Your Wifi password, in case you have open network comment the whole statement.

int ledPin = LED_BUILTIN; // GPIO13 or for NodeMCU you can directly write D7
const int Relay1 = D1;
const int Relay2 = D2;
const int Relay3 = D3;
const int Relay4 = D4;
const int Relay5 = D5;
const int Relay6 = D6;
const int Relay7 = D7;
const int Relay8 = D0;
WiFiServer server(80); // Creates a server that listens for incoming connections on the specified port, here in this case port is 80.

void setup() {
  Serial.begin(9600);
  delay(10);
  setAllPin();//seting D0 to D7 & LedPin as OUTPUT
  digitalWrite(ledPin, LOW);
  connectWiFi(ssid, password); //connect to WiFi Network
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request
  if (request.indexOf("/?req=ON") != -1) {
    digitalWrite(LED_BUILTIN, LOW); //Turns ON
  }
  if (request.indexOf("/?req=OFF") != -1) {
    digitalWrite(LED_BUILTIN, HIGH); //Turns OFF
  }
  if (request.indexOf("/?req=ON1") != -1) {
    turnOffAll();
    digitalWrite(Relay1, HIGH);
  }
  if (request.indexOf("/?req=OFF1") != -1) {
    digitalWrite(Relay1, LOW);
  }
  if (request.indexOf("/?req=ON2") != -1) {
    turnOffAll();
    digitalWrite(Relay2, HIGH);
  }
  if (request.indexOf("/?req=OFF2") != -1) {
    digitalWrite(Relay2, LOW);
  }
  if (request.indexOf("/?req=ON3") != -1) {
    turnOffAll();
    digitalWrite(Relay3, HIGH);
  }
  if (request.indexOf("/?req=OFF3") != -1) {
    digitalWrite(Relay3, LOW);
  }
  if (request.indexOf("/?req=ON4") != -1) {
    turnOffAll();
    digitalWrite(Relay4, HIGH);
  }
  if (request.indexOf("/?req=OFF4") != -1) {
    digitalWrite(Relay4, LOW);
  }
  if (request.indexOf("/?req=ON5") != -1) {
    turnOffAll();
    digitalWrite(Relay5, HIGH);
  }
  if (request.indexOf("/?req=OFF5") != -1) {
    digitalWrite(Relay5, LOW);
  }
  if (request.indexOf("/?req=ON6") != -1) {
    turnOffAll();
    digitalWrite(Relay6, HIGH);
  }
  if (request.indexOf("/?req=OFF6") != -1) {
    digitalWrite(Relay6, LOW);
  }
  if (request.indexOf("/?req=ON7") != -1) {
    turnOffAll();
    digitalWrite(Relay7, HIGH);
  }
  if (request.indexOf("/?req=OFF7") != -1) {
    digitalWrite(Relay7, LOW);
  }
  if (request.indexOf("/?req=ON8") != -1) {
    turnOffAll();
    digitalWrite(Relay8, HIGH);
  }
  if (request.indexOf("/?req=OFF8") != -1) {
    digitalWrite(Relay8, LOW);
  }
  if (request.indexOf("/?req=OFFALL") != -1) {
    turnOffAll();
  }
  if (request.indexOf("/?req=ONALL") != -1) {
    turnOnAll();
  }

  // Set ledPin according to the request
  //digitalWrite(ledPin, value);

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>ESP8266 Controller</title>");
  client.println("<meta charset=\"utf-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">");
  client.println("<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js\"></script>");
  client.println("<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\"></script>");
  client.println("</head>");
  client.print("Led pin is now: ");

  //  if (value == HIGH) {
  //    client.print("On");
  //  } else {
  //    client.print("Off");
  //  }
  client.println("<br><br>");
  client.println("<a href=\"/?req=ON1\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 1 </button></a>");
  client.println("<a href=\"/?req=OFF1\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 1 </button></a><br />");
  client.println("<a href=\"/?req=ON2\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 2 </button></a>");
  client.println("<a href=\"/?req=OFF2\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 2 </button></a><br />");
  client.println("<a href=\"/?req=ON3\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 3 </button></a>");
  client.println("<a href=\"/?req=OFF3\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 3 </button></a><br />");
  client.println("<a href=\"/?req=ON4\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 4 </button></a>");
  client.println("<a href=\"/?req=OFF4\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 4 </button></a><br />");
  client.println("<a href=\"/?req=ON5\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 5 </button></a>");
  client.println("<a href=\"/?req=OFF5\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 5 </button></a><br />");
  client.println("<a href=\"/?req=ON6\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 6 </button></a>");
  client.println("<a href=\"/?req=OFF6\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 6 </button></a><br />");
  client.println("<a href=\"/?req=ON7\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 7 </button></a>");
  client.println("<a href=\"/?req=OFF7\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 7 </button></a><br />");
  client.println("<a href=\"/?req=ON8\"\"><button class=\"btn btn-primary m-2\">Turn ON Relay 8 </button></a>");
  client.println("<a href=\"/?req=OFF8\"\"><button class=\"btn btn-primary m-2\">Turn Off Relay 8 </button></a><br />");
  client.println("<a href=\"/?req=OFFALL\"\"><button class=\"btn btn-primary m-2\">Turn Off All </button></a><br />");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}

void connectWiFi(const char* ssid, const char* password) {
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP()); //Gets the WiFi shield's IP address and Print the IP address of serial monitor
  Serial.println("/");

  digitalWrite(ledPin, HIGH);
}

void setAllPin() {

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(ledPin, OUTPUT);
}
void turnOffAll() {
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
}
void turnOnAll() {
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);

}
