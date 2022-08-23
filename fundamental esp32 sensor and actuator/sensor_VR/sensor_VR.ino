#define VR_Y 2 //กำหนดให้ขา VR แกน Y อยู่ที่ Pin2
#define VR_X 4  //กำหนดให้ขา VR แกน x อยู่ที่ Pin4
#define VR_SW 5 //กำหนดให้ขาสวิตช์ VR อยู่ที่ Pin5
//Joystick ให้ใช้ vcc 3.3v
void setup() {
  Serial.begin(115200);         //ตั้งค่าความเร็วในการส่งข้อมูล
  pinMode(VR_SW,INPUT_PULLUP);  //กำหนดให้ Pin VR_SW เป็นโหมดรับค่าแบบPULLUP
}

int VR_Y_valu;
int VR_X_valu;
int VR_SW_valu;

void loop() {
  VR_Y_valu=analogRead(VR_Y);           //อ่านค่าอนาล็อกจากVR แกน Y
  VR_X_valu=analogRead(VR_X);           //อ่านค่าอนาล็อกจากVR แกน X
  VR_SW_valu=digitalRead(VR_SW);        //อ่านค่าดิจิตอลจากสวิตช์ VR
  Serial.print("X-Axis => ");
  Serial.print(VR_Y_valu);
  Serial.print("    Y-Axis => ");
  Serial.print(VR_X_valu);
  Serial.print("    switch => ");
  Serial.println(VR_SW_valu);
  delay(100);                              //รอ 2 วินาที
} 
