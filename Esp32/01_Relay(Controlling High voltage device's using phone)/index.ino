#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "OPPOA17";
const char *password = "Manoj@123";

const int RELAY_PIN = 25;
bool relayState = false;

// Initialize the AsyncWebServer on port 80
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Relay Control</title>
  <style>
    :root {
      --bg: #0f172a;
      --card-bg: #1e293b;
      --text: #f8fafc;
      --primary: #3b82f6;
      --danger: #ef4444;
      --success: #22c55e;
    }
    body {
      font-family: system-ui, -apple-system, sans-serif;
      background: var(--bg);
      color: var(--text);
      display: flex;
      justify-content: center;
      align-items: center;
      min-height: 100vh;
      margin: 0;
    }
    .card {
      background: var(--card-bg);
      padding: 2rem;
      border-radius: 1rem;
      box-shadow: 0 20px 25px -5px rgba(0,0,0,0.5);
      text-align: center;
      width: 90%;
      max-width: 360px;
    }
    h2 { margin-top: 0; font-weight: 600; }
    .status-badge {
      display: inline-block;
      padding: 0.25rem 0.75rem;
      border-radius: 9999px;
      font-size: 0.875rem;
      font-weight: 600;
      margin-bottom: 1.5rem;
      background: var(--danger);
      transition: background 0.3s;
    }
    .status-badge.active { background: var(--success); }
    .btn {
      width: 100%;
      padding: 0.875rem;
      border: none;
      border-radius: 0.5rem;
      background: var(--primary);
      color: white;
      font-size: 1rem;
      font-weight: 600;
      cursor: pointer;
      transition: opacity 0.2s, transform 0.1s;
    }
    .btn:active { transform: scale(0.98); }
    .btn:disabled { opacity: 0.5; cursor: not-allowed; }
  </style>
</head>
<body>
  <div class="card">
    <h2>Relay 1 Switch</h2>
    <div id="status" class="status-badge">STATE: OFF</div>
    <button id="toggleBtn" class="btn" onclick="toggleRelay()">Turn ON</button>
  </div>

  <script>
    async function toggleRelay() {
      const btn = document.getElementById('toggleBtn');
      btn.disabled = true;
      try {
        const res = await fetch('/toggle');
        const state = await res.text();
        updateUI(state === 'HIGH');
      } catch (err) {
        console.error('Failed to toggle:', err);
      } finally {
        btn.disabled = false;
      }
    }

    function updateUI(isOn) {
      const status = document.getElementById('status');
      const btn = document.getElementById('toggleBtn');
      if (isOn) {
        status.textContent = 'STATE: ON';
        status.classList.add('active');
        btn.textContent = 'Turn OFF';
      } else {
        status.textContent = 'STATE: OFF';
        status.classList.remove('active');
        btn.textContent = 'Turn ON';
      }
    }
  </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Serve HTML UI
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", index_html);
  });

  // REST Endpoint for toggle action
  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest *request) {
    relayState = !relayState;
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);
    request->send(200, "text/plain", relayState ? "HIGH" : "LOW");
  });

  server.begin();
}

void loop() {
  // ESPAsyncWebServer handles incoming requests asynchronously in the background.
  // loop() is left empty so your CPU is free for other tasks.
}