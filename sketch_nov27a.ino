float Vel;
float freq = 5 ;//Hz //1127做0.1, 1, 2, 3, 4, 5 Hz(六種)
const int amplitude = 255; // 正弦波振幅
const int numSamples = 1000;  // 采样点数  =實驗時間
const float sampleRate = 50.0;  // 采样频率（Hz） 如果數據量小於採樣點數 可以降低一點
const float minFreq = 0.1;  // 扫频信号的最小频率（Hz）  *這邊可以調高
const float maxFreq = 5.0;   // 扫频信号的最大频率（Hz）
int PIN_Pressure = A5;
int enb = 9;
int in1 = 10;
int in2 = 11;


void setup() {
  Serial.begin(9600); // 启动Arduino IDE串口监视器
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(PIN_Pressure,INPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < numSamples; i++) {
      int sensorValue = analogRead(PIN_Pressure);
      float t = i / sampleRate;  // 当前时间
      float sineValue = (amplitude * sin( 2 * PI * freq * t)+255)/2;
      
      analogWrite(enb, sineValue);// 在PWM引脚上写入PWM值

      Serial.print(sineValue);
      Serial.print(" ");
      Serial.println(sensorValue);
      //Vel = abs(integerSineValue);
      // 将整数值发送到串口

      delay(20); // 稍微延迟以控制数据发送频率

    if(i==numSamples-1){
      Serial.print("=====================================");

    }
    }

    delay(3000); // 在每个正弦波周期之间添加延迟
}
