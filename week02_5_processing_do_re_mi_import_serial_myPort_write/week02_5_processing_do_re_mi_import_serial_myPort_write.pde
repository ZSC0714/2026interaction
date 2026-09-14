// week02_5_processing_do_re_mi_import_serial_myPort_write
// 我想要把 Arduino 跟 Processing 結合
// 在 Processing 按下 key 1 2 3 對應 Arduino 的 Do Re Mi 使用 USB Serial
import processing.serial.*; // 使用 USB Serial 外掛
Serial myPort; // 將用 myPort 來傳 USB Serial 資料
void setup() {
  size(300, 200); // 隨便的視窗
  myPort = new Serial(this, "COM3", 9600); // 中間 "COM4" or "COM3" 自己查
}

void draw() {

}
void keyPressed() {
  if (key=='1') myPort.write('1');
  if (key=='2') myPort.write('2');
  if (key=='3') myPort.write('3');
}
