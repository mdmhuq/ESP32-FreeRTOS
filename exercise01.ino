#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else 
static const BaseType_t app_cpu = 1;
#endif

static const int led_pin = 2;
int changeTimeVal=500;



void toggleLEDExcercise(void *parameter){

  while(1){
    digitalWrite(led_pin, HIGH);
    if (changeTimeVal == 0){
      changeTimeVal+=500;
    }else{
      changeTimeVal-=100;
    }

    vTaskDelay(changeTimeVal/portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(changeTimeVal/portTICK_PERIOD_MS);


    
  }
}

void setup() {
  pinMode(led_pin, OUTPUT);
  xTaskCreatePinnedToCore(
  toggleLEDExcercise, 
  "Toggle LED", 
  1024, 
  NULL, 
  1, 
  NULL, 
  app_cpu);
}

void loop() {

}
