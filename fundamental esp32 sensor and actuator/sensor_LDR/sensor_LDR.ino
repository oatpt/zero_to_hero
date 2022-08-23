#define LDR_analog A14 //กำหนดให้ขาอนาล็อกของ LDR อยู่ที่ A14
#define LDR_digital 26 //กำหนดให้ขาดิจิตอลของ LDR อยู่ที่ 26
void setup() {
  Serial.begin(115200);           //ตั้งค่าความเร็วในการส่งข้อมูล
  pinMode(LDR_digital,INPUT);     //กำหนดให้ Pin LDR_digital เป็นโหมดรับค่า
}

int digital_valu;
int analog_valu;

void loop() {
  analog_valu=analogRead(LDR_analog);       //อ่านค่าอนาล็อกจากLED
  digital_valu=digitalRead(LDR_digital);    //อ่านค่าดิจิตอลจากLED
  Serial.print("analog_valu => ");
  Serial.println(analog_valu);
  Serial.print("digital_valu => ");
  Serial.println(digital_valu);
  delay(2000);                              //รอ 2 วินาที
} 
