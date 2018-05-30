#define ledctl 13

String BoardModel = " UNO";
String Owner = " Owner";
String AsciiArt = " duino ~>";
String OwnerPasswd = "passwd";
bool ledstatus = 0;
bool asRoot = false;

void setup() {
pinMode(ledctl, OUTPUT); 

Serial.begin(9600);
Serial.println("Consoleduino v.1.3.1");
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
  else if(query == "pinctl" || query == "pinctl 1" || query == "pinctl 0"){f_pinctl(f_pinctlCheck(query));}
  else if(query == "hollywood"){hollywood();}
  else if(query == "su"){asRoot = permissionCheck();}
  else if(query == "exit"){exitRoot(query);}
  else{
  Serial.println(query+": no such command; try help");}

  }
}

void helpmsg(){
  Serial.println("Consoleduino help");
  Serial.println("help    print this msg");
  Serial.println("fetch   show system info");
  Serial.println("pinctl (1/2)   control led on pin 13; usage pinctl 1 or pinctl 0 ");
  Serial.println();
  Serial.println("For feedback use Telegram(@dwarq7), Instagram(@ilya_quicksort) or melonssh.at.pc@gmail.com;");
}
void fetchmsg(){
  Serial.println("Consoleduino");
  Serial.println("Board:" + BoardModel);
  Serial.println("Owner:" + Owner);
  Serial.println(AsciiArt);
}
void f_pinctl(bool status){
  
  ledstatus = status;
  digitalWrite(ledctl, ledstatus);
}
bool f_pinctlCheck(String fquery){
  if (fquery == "pinctl 1"){return true;}
  else if (fquery == "pinctl 0"){return false;}
  else if (fquery == "pinctl"){Serial.println("Not enough args; try help;"); 
}
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


bool permissionCheck(){
  String passwdToCheck;
  bool accept;
    Serial.print("Password for"+Owner+": ");
    if(Serial.available() > 0){
    passwdToCheck = Serial.readString();
    Serial.setTimeout(20000);
    accept = passwdCheck(passwdToCheck);
    }
    if(accept == true) return true;
    else return false;
}

bool passwdCheck(String passwd) {
  if (passwd == OwnerPasswd) return true;
  else {Serial.println("wrong password");return false;}
  } 

void exitRoot(String fquery){
  if (asRoot == true && fquery == "exit"){asRoot == false;}
}

