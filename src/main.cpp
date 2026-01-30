#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2       // Chân Data nối vào GPIO 2
#define DHTTYPE DHT11  // Khai báo loại cảm biến là DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("--- Bat dau doc du lieu tu DHT11 ---");
  dht.begin(); // Khởi tạo cảm biến
}

void loop() {
  delay(2000); // DHT11 cần khoảng 2 giây giữa các lần đọc

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Kiểm tra xem việc đọc dữ liệu có thành công không
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Loi: Khong doc duoc du lieu tu cam bien!");
    return;
  }

  Serial.print("Do am: ");
  Serial.print(humidity);
  Serial.print("%  |  Nhiet do: ");
  Serial.print(temperature);
  Serial.println("°C");
}