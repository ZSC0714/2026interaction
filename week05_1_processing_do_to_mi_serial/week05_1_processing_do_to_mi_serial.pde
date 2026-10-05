// week05_1_processing_do_to_mi_serial
// 從 Arduino 收到資料後，再用 import serial 將資料傳回去
// 我想要 Arduino 跟 Processing 結合
// 在 Processing 按下 key 1 2 3 等 Arduino 的 Do Re Mi 使用 USB Serial
// 因為沒有 USB Serial 線，要選擇好「方法」並點選對應的埠

import processing.serial.*;  // 使用 USB Serial 外掛

Serial myPort;  // 叫 myPort 來傳 USB Serial 資料

void setup() {
  size(300,200);  // 視窗的寬高
  
  myPort = new Serial(this, "COM3", 9600);  // 中間 "COM4" or "COM3" 自己查
}

void draw() {

}

void keyPressed() {  // 按鍵之後，會利用 USB Serial 傳資料到電腦
  // 小寫：注意輸入法，包含字母的 '1' '2' '3'
  
  if (key=='1') myPort.write('1');
  if (key=='2') myPort.write('2');
  if (key=='3') myPort.write('3');
}
