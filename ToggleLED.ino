#include <WiFi.h>

const char* SSID1 = "Vodafone-FB72";
const char* PW1 = "QmDRgGpmgmM8h3hu";

const char* SSID2 = "neon1024";
const char* PW2 = "13371337";

// Select which network to use
const char* ssid = SSID1;
const char* password = PW1;

WiFiServer server(80);  // Create server on port 80

int ledPin = 5;         // LED connected to GPIO 5
bool ledState = false;  // Track LED state

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();  // Start the server
}

void loop() {
  WiFiClient client = server.accept(); // updated to avoid deprecation warning

  if (client) {
    Serial.println("New Client.");
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n' && request.endsWith("\r\n\r\n")) {
          break;  // End of headers
        }
      }
    }

    if (request.indexOf("GET /toggle") >= 0) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }

    // Send HTML response with styling
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<!DOCTYPE html><html>");
    client.println("<head>");
    client.println("<meta charset='UTF-8'>");
    client.println("<title>ESP32 LED Toggle</title>");
    client.println("<style>");
    client.println("body { font-family: Arial, sans-serif; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; margin: 0; background-color: #f0f0f0; }");
    client.println("h1 { color: #333; margin-bottom: 20px; }");
    client.println(".status { font-weight: bold; display: inline-block; width: 50px; text-align: center; }");
    client.println(".on { color: blue; }");
    client.println(".off { color: black; }");
    client.println("button { padding: 10px 20px; font-size: 16px; cursor: pointer; border: none; border-radius: 5px; background-color: #007BFF; color: white; }");
    client.println("button:hover { background-color: #0056b3; }");
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.print("<h1>LED is <span class=\"status ");
    client.print(!ledState ? "on" : "off");
    client.print("\">");
    client.print(!ledState ? "ON" : "OFF");
    client.println("</span></h1>");
    client.println("<form action=\"/toggle\" method=\"GET\">");
    client.println("<button type=\"submit\">Toggle LED</button>");
    client.println("</form>");
    client.println("</body></html>");

    client.println();
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
