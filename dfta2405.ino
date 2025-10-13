// Heure fictive en gros caractères avec annonce sonore de 1 heure à minuit
// Le 13/10/2025 : Bon fonctionnement.
#include <DFRobot_DF1201S.h>
#include <U8g2lib.h>

#define DF1201SSerial Serial1
#define DF_RX 20
#define DF_TX 21
#define BUZZER 8

#define SDA_PIN 5
#define SCL_PIN 6

// OLED 72x40, full frame, hardware I2C, reset none, pins SDA/SCL spécifiés
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, SCL_PIN, SDA_PIN);

DFRobot_DF1201S DF1201S;

// --------------------- Buzzer ---------------------

 void bipBuzzer (int TempsH, int TempsL, int nb)                            // TempsH => délai buzzer ON, TempsL => délai buzzer OFF, nb => nombre de bips
  {
  for (int x = 1; x <= nb; x++) // ************************************** // Boucle le nombre de fois voulu passé par l'argument "int nb"
  {
  digitalWrite(BUZZER, HIGH);                                       // Active le buzzer
  delay (TempsH);                                                   // Temporisation à l'état haut du buzzer pendant la durée passée par l'argument "int TempsH"
  digitalWrite(BUZZER, LOW);                                        // Désactive le buzzer
  delay (TempsL);                                                   // Temporisation à l'état bas du buzzer pendant la durée passée par l'argument "int TempsL"
  }
  }


// --------------------- Lecture audio ---------------------
void playAudio(const char *fichier, uint8_t volume, uint8_t heure) {
  // Affiche l'heure sur OLED
  u8g2.clearBuffer();
  char buf[10];
  snprintf(buf, sizeof(buf), "%02d:00", heure);


  //u8g2.setFont(u8g2_font_ncenB08_tr);
  //u8g2.drawStr(0, 20, buf);
 // u8g2.sendBuffer();

  //u8g2.setFont(u8g2_font_fub11_tr); // police plus grande adaptée à 72x40
    //u8g2.setFont(u8g2_font_fub17_tr); 
  //u8g2.setFont(u8g2_font_logisoso18_tr);

u8g2.setFont(u8g2_font_fur20_tr);

  //u8g2.drawStr(0, 30, buf);         // position verticale ajustée
  
  u8g2.drawStr(1, 40, buf); 
  u8g2.sendBuffer();



  // Lecture DFPlayer
  DF1201S.start();
  delay(50);
  DF1201S.setVol(volume);
  DF1201S.playSpecFile(fichier);
  delay(300);
}

// --------------------- Setup ---------------------
void setup() {
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  Serial.begin(115200);
  DF1201SSerial.begin(115200, SERIAL_8N1, DF_RX, DF_TX);

  while (!DF1201S.begin(DF1201SSerial)) {
    Serial.println("Connexion DFPlayer...");
    delay(1000);
  }

  DF1201S.switchFunction(DF1201S.MUSIC);
  DF1201S.setPrompt(false);
  DF1201S.setVol(22);
  delay(200);

  u8g2.begin(); // initialise l'écran OLED
}

// --------------------- Loop ---------------------
void loop() {
  
  int H = 70;
  int L = 70;
  int N = 3;
  
  bipBuzzer(H,L,N);  
  playAudio("/wife/001F.mp3", 30, 1);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();
  
  bipBuzzer(H,L,N); 
  playAudio("/wife/002F.mp3", 26, 2);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();
  
  bipBuzzer(H,L,N); 
  playAudio("/wife/003F.mp3", 26, 3);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();
  
  bipBuzzer(H,L,N);  
  playAudio("/wife/004F.mp3", 22, 4);// blanc de fin
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/005F.mp3", 26, 5);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();
  
  bipBuzzer(H,L,N);  
  playAudio("/wife/006F.mp3", 28, 6);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/007F.mp3", 26, 7);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N); 
  playAudio("/wife/008F.mp3", 22, 8);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/009F.mp3", 26, 9);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/010F.mp3", 26, 10);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/011F.mp3", 26, 11);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/012F.mp3", 26, 12);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/013F.mp3", 26, 13);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/014F.mp3", 30, 14);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();
  
  bipBuzzer(H,L,N);  
  playAudio("/wife/015F.mp3", 26, 15);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/016F.mp3", 28, 16);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/017F.mp3", 26, 17);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/018F.mp3", 26, 18);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/019F.mp3", 28, 19);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/020F.mp3", 24, 20);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/021F.mp3", 28, 21);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/022F.mp3", 28, 22);//
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N); 
  playAudio("/wife/023F.mp3", 26, 23);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();

  bipBuzzer(H,L,N);  
  playAudio("/wife/024F.mp3", 30, 24);
  delay(3000);  // Durée approximative du fichier
  DF1201S.pause();


  // Boucle infinie : recommence à 1
}
