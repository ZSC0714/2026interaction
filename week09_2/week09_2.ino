// week09_2: 精彩、好聽、有變化且音量大的音效與旋律實作
// 板載 Pin 8 蜂鳴器專用

const int BUZZER_PIN = 8;
const int BUTTON_PIN = 2; // Maker UNO 板載按鈕

// 音符頻率定義 (Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_A5  880

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // 開機先播放一組「升頻開機音效」（高音域響度最大）
  playPowerUpSound();
}

void loop() {
  // 檢測是否按下 Maker UNO 板載按鈕 (Pin 2)
  if (digitalRead(BUTTON_PIN) == LOW) {
    playMarioTheme(); // 按下按鈕播放精彩樂曲
    delay(500);
  }
}

// 1. 動態滑音音效 (音量感強、頻率變化豐富)
void playPowerUpSound() {
  for (int hz = 400; hz <= 1500; hz += 30) {
    tone(BUZZER_PIN, hz);
    delay(5);
  }
  for (int hz = 1500; hz >= 600; hz -= 20) {
    tone(BUZZER_PIN, hz);
    delay(5);
  }
  noTone(BUZZER_PIN);
}

// 2. 經典遊戲旋律 (音階高低與節奏變化精彩)
void playMarioTheme() {
  int melody[] = {
    NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, 0,
    NOTE_G5, 0, 0, 0, NOTE_G4, 0, 0, 0
  };
  
  int noteDurations[] = {
    150, 150, 150, 150, 150, 150, 150, 150,
    150, 150, 150, 150, 150, 150, 150, 150
  };

  for (int i = 0; i < 16; i++) {
    int duration = noteDurations[i];
    if (melody[i] == 0) {
      delay(duration);
    } else {
      tone(BUZZER_PIN, melody[i], duration);
      delay(duration * 1.3); // 音符間微小停頓，增強節奏感
    }
  }
  noTone(BUZZER_PIN);
}
