#define ledctl 13

String BoardModel = " UNO";
String Owner = " Owner";
String AsciiArt = " duino ~>";
String OwnerPasswd = "passwd";
bool ledstatus = 0;

void setup() {
pinMode(ledctl, OUTPUT); 

Serial.begin(9600);
Serial.println("Consoleduino v.0.1.1");
Serial.println("(c) Ilya Bilyk 2018");
Serial.println();
}

void loop() {
//Serial.println("duino ~>");

if(Serial.available() > 0) {
  String query = Serial.readString();
  query.trim();
  if(query == "help"){helpmsg();}
  else if(query == "fetch"){fetchmsg();}
  else if(query == "pinctl"){f_pinctl();}
  else if(query == "hollywood"){hollywood();}
  else if(query == "clear"){Serial.println();}//not working!!!
  else if(query == "reboot"){}
  else{
  Serial.println(query+": no such command; try help");}

  }
}

void helpmsg(){
  Serial.println("Consoleduino help");
  Serial.println("help    print this msg");
  Serial.println("fetch   show system info");
  Serial.println("pinctl    control led on pin 13");
  Serial.println();
  Serial.println("For feedback use Telegram(@dwarq7), Instagram(@ilya_quicksort) or melonssh.at.pc@gmail.com;");
}
void fetchmsg(){
  Serial.println("Consoleduino");
  Serial.println("Board:" + BoardModel);
  Serial.println("Owner:" + Owner);
  Serial.println(AsciiArt);
}
void f_pinctl(){
  
  ledstatus = !ledstatus;
  digitalWrite(ledctl, ledstatus);
}
void hollywood(){
  String hwq;
  Serial.println("You have found Hollywood!");
  while(true){if(Serial.available() > 0) {
    hwq = Serial.readString();
    if (hwq == "exit"){break;}
    else{
    Serial.println(hwq);}
    }
    
  }
}

/*
bool permissionCheck(String fquery){
  String passwdToCheck;
  bool accept;
  if (fquery == "reboot"){
    Serial.print("Password for"+Owner+": ");
    if(Serial.available() > 0){
    passwdToCheck = Serial.readString();
    accept = passwdCheck(passwdToCheck);}
    if(accept == true) return true;
    else return false;
  }
  }

bool passwdCheck(String passwd) {
  if (passwd == OwnerPasswd) return true;
  else {Serial.println("wrong password");return false;}
  } 

void permissionRebootOutput(bool perm){
  if (perm == true){
    Serial.println("Rebooting...");
    resetFunc();
  }
}
*/

