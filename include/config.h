#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"
#define BLYNK_TOKEN "your_blynk_token"

// Define sensor and relay pins
#define MOISTURE_SENSOR_PIN1 D3
#define MOISTURE_SENSOR_PIN2 D4
#define MOISTURE_SENSOR_PIN3 D8

#define PUMP1_RELAY_PIN D0
#define PUMP2_RELAY_PIN D1
#define PUMP3_RELAY_PIN D2

#define BLYNK_TEMPLATE_ID "TMPL4CoI56fBA"
#define BLYNK_TEMPLATE_NAME "Vannerud"
#define BLYNK_AUTH_TOKEN "OlBzAErMRox-DX7jQNKKd_ILJluz5ARP"

#define BLYNK_PRINT Serial

enum Status {
    Offline,
    Online,
    MoistureWarning,
    Error,
    Watering
};