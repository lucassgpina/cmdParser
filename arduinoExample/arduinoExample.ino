#include <cmdParser.h>


int setPin (int argc, char *argv[]){

  if(argc < 3){
    Serial.println("Wrong number of arguments");
    return -1;
  }
    
  int pin = atoi(argv[1]);
  int value = atoi(argv[2]);

  digitalWrite(pin,value);
  return 0;
}

int readAnalog (int argc, char *argv[]){

  int read = analogRead(0);
  
  Serial.write("Analog 0 read: ");
  Serial.println(read);

  return 0;
}

Command cmd_table [] = {
    {"setPin",setPin},
    {"r_analog",readAnalog}
};

void setup() {
  Serial.begin(9600);
  setCmdTable(cmd_table,sizeof(cmd_table)/sizeof(cmd_table[0]));

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  Serial.write("Begin\n");
}

void loop() {
  

  if(Serial.available() > 0){
    int num_bytes;
    char in_buffer[200];
    if((num_bytes = Serial.readBytesUntil(0,in_buffer,sizeof(in_buffer))) == 0) return;
    // set 0 terminator
    in_buffer[num_bytes] = 0;
    int ret = readCmd(in_buffer);

    Serial.write("Cmd returned: ");
    Serial.println(ret);

  }

}
