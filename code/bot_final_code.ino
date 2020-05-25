 #include <QList.h>
struct directions {
    int right;
    int left;
    int up;
    int down;
  };
struct Name_Index_Edge {
  String Name; int Index;
};

//pins on arduino

    //Ultrasonic
  int trig=3,echopin=4;
  
    //IR color sensor
//A0 input
//A1 output
  

    //motors pins
//motor A
int EnA=5;
int in1A=6;
int in2A=7;
//motor B
int in1B=9;
int in2B=8;
int EnB=10;


  //RGB led self container
  
class collectorBot{
  public:
  int x;
  int y;
  int dir;
  QList<String> list_names_of_edges_bot_can_choose;
  QList<int> list_index_of_names_of_edges_bot_can_choose;
  QList<float> list_of_Weight_index_of_names_of_edges_bot_can_choose;
  directions directions_bot;//Directions of bot can choose 
  String String_of_indexs_list;
  int value_of_self_container;
  int container_weight;
  //String names_of_edges_bot_can_choose[4];  //ساويها بترتبهم حسب الأولوية
  // Edge end_edge_bot_choosed();
  //collectorBot();
  //void moveUp();
  //void moveDown();
  //void moveRight();
  //void moveLeft();
  //void botWays();
  //String create_name_of_edge_from_direction(int direc);//This function for next function"create_names_of_edges_from_botWays()"
  //void create_NamesAndIndex_of_edges_from_botWays();//set "String_of_indexs_list" from botWays() to sent it to server
  //int calculate_index_from_edge_name(String Edge_name);call botWays() AND set list_names_of_edges_bot_can_choose AND set list_index_of_names_of_edges_bot_can_choose
  
  
  collectorBot(){
   x=0;
   y=0;
   dir=90; 
   directions_bot.right=90;
   directions_bot.left=-1;
   directions_bot.up=0;
   directions_bot.down=-1; 
   value_of_self_container=0;
   container_weight=0;
   // end_edge_bot_choosed.name_edge="xxxx";
   
}
void moveUp(){
  if (y <4){
    dir=0;
    //digitalWrite();turn statment and condition to stop robot ,write it later...
    y++;}
    else
    y=4;
  }
  void moveDown(){
  if (y>0){
    dir=180;
    //digitalWrite();turn statment and condition to stop robot ,write it later...
    y--;}
    else
    y=0;
  }
  void moveRight(){
  if (x<4){
    dir=90;
    //digitalWrite();turn statment and condition to stop robot ,write it later...
    x++;}
    else
    x=4;
  }
  void moveLeft(){
  if (x>0){
    dir=-90;
    //digitalWrite();turn statment and condition to stop robot ,write it later...
    x--;}
    else
    x=0;
  }

 
  
 void botWays(){
  
if (x==0){
    if (y==0){
    directions_bot.up =0;
    directions_bot.down =-1;
    directions_bot.right =90;
    directions_bot.left =-1;
    }
    else if(y==4){
    directions_bot.up =-1;
    directions_bot.down =180;
    directions_bot.right =90;
    directions_bot.left =-1;
    }
    else if(y<4 &&y>0){
    directions_bot.up =0;
    directions_bot.down =180;
    directions_bot.right =90;
    directions_bot.left =-1;  
    }
    else {
    //print (error 1:y is out of range);
    }
  }
else if(x==4){
    if (y==0){
    directions_bot.up =0;
    directions_bot.down =-1;
    directions_bot.right =-1;
    directions_bot.left =-90;
    }
    else if(y==4){
    directions_bot.up =-1;
    directions_bot.down =180;
    directions_bot.right =-1;
    directions_bot.left =-90;
    }
    else if(y<4 &&y>0){
    directions_bot.up =0;
    directions_bot.down =180;
    directions_bot.right =-1;
    directions_bot.left =-90;  
    }
    else {
    //print (error 2:y is out of range);
  }
}
else if (x>0 && x<4){
   if (y==0){
    directions_bot.up =0;
    directions_bot.down =-1;
    directions_bot.right =90;
    directions_bot.left =-90;
    }
    else if(y==4){
    directions_bot.up =-1;
    directions_bot.down =180;
    directions_bot.right =90;
    directions_bot.left =-90;
    }
    else if(y<4 &&y>0){
    directions_bot.up =0;
    directions_bot.down =180;
    directions_bot.right =90;
    directions_bot.left =-90;  
    }
    else {
    //print (error 3:y is out of range);
  }
}
else{
//print (error 4:x is out of range)  
}
//don't return anything couse you edited direction_bot
  }

  
String create_name_of_edge_from_direction(int direc){
  String Edge_name;
  if (direc==0||direc==360){//up_edge
    Edge_name=String(String(x)+String(y)+String(x)+int(y+1));
    return Edge_name;
  }
  else if(direc==180){//down_edge
    Edge_name=String(String(x)+String(y)+String(x)+int(y-1));
    return Edge_name; 
  }
  else if(direc==90){//right_edge
     Edge_name=String(String(x)+String(y)+int(x+1)+String(y));
    return Edge_name;
  }
  else if(direc==-90||direc==270){//left_edge
     Edge_name=String(String(x)+String(y)+int(x-1)+String(y));
    return Edge_name;
  }
  else{
     Edge_name="Error 5";
    return Edge_name;
    //print (error 5:bad direction)
  }
}

int create_direction_from_name_of_edge(String Edge_name){
  int x1,x2,y1,y2;
  x1=Edge_name[0];
  y1=Edge_name[1];
  x2=Edge_name[2];
  y2=Edge_name[3];

  if(x1==x2){
    if (y2>y1)
    return 0;
    else
    return 180;
  }
  else if(y1==y2){
   if (x2>x1)
    return 90;
    else
    return -90; 
  }
}


void create_NamesAndIndex_of_edges_from_botWays(){
  int up,down,left,right;
  int dir_choosed;//dir_to_last_edge_bot_choosed;
  //reset list of names
  list_names_of_edges_bot_can_choose.clear();
 //names_of_edges_bot_can_choose[0]="";
 //names_of_edges_bot_can_choose[1]="";
 //names_of_edges_bot_can_choose[2]="";
 //names_of_edges_bot_can_choose[3]="";
 String_of_indexs_list="";//clear String_of_indexs_list
 botWays();//set direction in struct directions_bot
up= directions_bot.up;
down= directions_bot.down;
right= directions_bot.right;
left= directions_bot.left;
/*Serial.print("//up=");
Serial.println(up);
Serial.print("//down=");
Serial.println(down);
Serial.print("//right=");
Serial.println(right);
Serial.print("//left=");
Serial.println(left);
Serial.print("//dir=");
Serial.println(dir);*/
dir_choosed=dir+180;//Dir_of_last(End)_edge_bot_choosed
/*Serial.print("//dir_choosed=");
Serial.println(dir_choosed);*/
if (dir_choosed==360)//to Consider cases 0 = 360 and 270 = -90  and keep 90 =dir(-90)+180   and 180=dir(0)+180
dir_choosed=0;
else if(dir_choosed==270)
dir_choosed=-90;
/*Serial.print("//dir_choosed_after_edit=");
Serial.println(dir_choosed);*/


//void create_list_names_of_edges_from_botWays();
//set list_names_of_edges_bot_can_choose;
if (up!=-1){
 if( up!=dir_choosed){
  list_names_of_edges_bot_can_choose.push_front(create_name_of_edge_from_direction(up));//push front 
 }
 else 
 list_names_of_edges_bot_can_choose.push_back(create_name_of_edge_from_direction(up));//push back for choice at the end
}

if (down!=-1){
 if( down!=dir_choosed){
  list_names_of_edges_bot_can_choose.push_front(create_name_of_edge_from_direction(down));
 }
 else 
 list_names_of_edges_bot_can_choose.push_back(create_name_of_edge_from_direction(down));
}

if (right!=-1){
 if( right!=dir_choosed){
  list_names_of_edges_bot_can_choose.push_front(create_name_of_edge_from_direction(right));
 }
 else 
 list_names_of_edges_bot_can_choose.push_back(create_name_of_edge_from_direction(right));
}

if (left!=-1){
 if( left!=dir_choosed){
  list_names_of_edges_bot_can_choose.push_front(create_name_of_edge_from_direction(left));
 }
 else 
 list_names_of_edges_bot_can_choose.push_back(create_name_of_edge_from_direction(left));
}

//void create_list_index_of_names_of_edges_bot_can_choose();//I don't want to make special function for this process  so i did it here
//set list_index_of_names_of_edges_bot_can_choose
list_index_of_names_of_edges_bot_can_choose.clear();
for(int i=0;i<list_names_of_edges_bot_can_choose.length();i++){
 list_index_of_names_of_edges_bot_can_choose.push_back(calculate_index_from_edge_name(list_names_of_edges_bot_can_choose[i]));}

 //set String_of_indexs_list to sent it to server
for(int i=0;i<list_index_of_names_of_edges_bot_can_choose.length();i++){
 String_of_indexs_list=String(String_of_indexs_list + String(list_index_of_names_of_edges_bot_can_choose[i]));
 if((i+1)!=list_index_of_names_of_edges_bot_can_choose.length()){
  String_of_indexs_list = String_of_indexs_list + ",";
 }
 
}
}


int calculate_index_from_edge_name(String Edge_name){
String x1s,y1s,x2s,y2s;
int x1,x2,y1,y2;
 x1s=Edge_name[0]; 
 y1s=Edge_name[1];
 x2s=Edge_name[2];
 y2s=Edge_name[3];
 x1= x1s.toInt();
 y1= y1s.toInt();
 x2= x2s.toInt();
 y2= y2s.toInt();

 if (y1==y2){
   if (x1>x2){
    return (x1+y1*4); 
   }
   else{
     return (x2+y1*4); 
   }
  }
  
  else if (x1==x2){
    if (y1>y2){
  return (y1+x1*4+20); 
    }
    else{
    return(y2+x1*4+20);   
    }
   }
   else{//عالج المشكلة هنا وادرس الحالات اكثر وحط حدود للx,y مثل سكراتش
    //print (Error 6: not Edge);
    //Serial.println ("Error 6: not Edge"); //solve problem of conditions range and if and else if 
   }

}
//send_string_of_indexs_And_receive_weights and make list_of_Weight_index_of_names_of_edges_bot_can_choose
void send_string_of_indexs_And_receive_weights(){
  String String_weights="",tmp="";
  int i;
  //repeat_process://to goto here if message is bad and repeat_process of sending
 create_NamesAndIndex_of_edges_from_botWays() ; 
  Serial.println(String_of_indexs_list);
  list_of_Weight_index_of_names_of_edges_bot_can_choose.clear();
  while(!Serial.available());
  //String_weights="";
  String_weights=Serial.readString();
  //if(String_weights.substring(0,1).equals("W")){
  for(i=0;i<=String_weights.length();i++){
    if( String_weights[i] != ','  &&  i < String_weights.length()){
      tmp=tmp+String_weights[i];
      
    }
    else{
      //Serial.println(tmp);
      list_of_Weight_index_of_names_of_edges_bot_can_choose.push_back(tmp.toFloat());
      tmp="";
    }
  
  }
 /* }
  else{
    goto repeat_process;
  }*/
}

void test_print_bot_namesAndIndex_of_edges_bot_can_choose(){
  int i;
String print_xy,print_edgename,print_indexedge;
  create_NamesAndIndex_of_edges_from_botWays() ;
 print_xy=String("(x,y):"+String(x)+","+String(y));
 for(i=0;i<list_names_of_edges_bot_can_choose.length();i++){
 
  print_edgename=String(String(" Edge ")+ int(i) + String(" is:") +String(list_names_of_edges_bot_can_choose[i]));
  print_indexedge=String(String(" Edge_index ") + int(i) + String(" is:") +String(list_index_of_names_of_edges_bot_can_choose[i]));
  Serial.println(print_xy);
  Serial.println(print_edgename);
  Serial.println(print_indexedge);
  }
  Serial.println(String_of_indexs_list);
}

//just test motion
void test_motion_and_print_details_on_by_serial(){
  test_print_bot_namesAndIndex_of_edges_bot_can_choose();

  Serial.println("******************************MoveRight************************************");
  moveRight();
  
  test_print_bot_namesAndIndex_of_edges_bot_can_choose();
 
  Serial.println("******************************MoveUp************************************");
  moveUp();

  test_print_bot_namesAndIndex_of_edges_bot_can_choose();
  
  Serial.println("******************************MoveUp************************************");
  moveUp();


  test_print_bot_namesAndIndex_of_edges_bot_can_choose();
   
  Serial.println("******************************MoveRight************************************");
  moveRight();
  
  test_print_bot_namesAndIndex_of_edges_bot_can_choose();

 
 Serial.println("******************************MoveDown************************************");
  moveDown();

  test_print_bot_namesAndIndex_of_edges_bot_can_choose();
   
  
}




//test sending indexs and receving weights and print details on serial monitor
void test_send_string_of_indexs_And_receive_weights(){
  send_string_of_indexs_And_receive_weights();
   for(int i=0;i<list_of_Weight_index_of_names_of_edges_bot_can_choose.length();i++){
    Serial.println(list_of_Weight_index_of_names_of_edges_bot_can_choose[i]);
   }
}
int get_best_Index_for_best_motion(){
  int maxIndex=0,i;
  test_send_string_of_indexs_And_receive_weights();

//return index of max number of list
  if (list_of_Weight_index_of_names_of_edges_bot_can_choose.length()>0){
   for(i=1;i<list_of_Weight_index_of_names_of_edges_bot_can_choose.length();i++){
   if (list_of_Weight_index_of_names_of_edges_bot_can_choose[i]>list_of_Weight_index_of_names_of_edges_bot_can_choose[i-1]){
     maxIndex=i;}}
 }
  else{
    Serial.println("Error:44");
  
   }
  
 
   return maxIndex;
}

// return struct "best_index_of_edges" And "best_name_of_edges" 
 Name_Index_Edge   create_best_index_of_edges_And_best_name_of_edges(){
  int maxIndex;
  maxIndex= get_best_Index_for_best_motion();//get index of max weight
  Name_Index_Edge edge;
  edge.Name=list_names_of_edges_bot_can_choose[maxIndex];
  edge.Index=list_index_of_names_of_edges_bot_can_choose[maxIndex];
  return edge;
}

//choice best way for best motion
void bestMotion(){
   int bestDirection;
   Name_Index_Edge edge;
   edge=create_best_index_of_edges_And_best_name_of_edges();
   Serial.println(edge.Name);
   Serial.println(edge.Index);
   bestDirection=create_direction_from_name_of_edge(edge.Name);
   if (bestDirection==90){
    moveRight();}
   else if(bestDirection==-90){
    moveLeft();}
   else if(bestDirection==0){
    moveUp();}
   else if(bestDirection==180){
    moveDown();}   
    else {
     Serial.println("Error 55");    
    }
}

void go_to_start(){
  //get container weight and عدل عالكود منشان يصير يفرق بين الحاويات والعقد بالرجعة
  while(x>0){
    moveLeft();
  }
  while(y>0){
    moveDown();
  }
  value_of_self_container=0;
  //Serial.println(x+y);
}
void testMotion(){
 while(!Serial.available());
  value_of_self_container=Serial.readString().toInt();
  if (value_of_self_container<20){
  bestMotion();}
  else{
  go_to_start() ;}
}
 void move1(){
   /* int dur,dis,ir_sensor;
    //analogWrite motors 
  digitalWrite(in1A,HIGH);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,HIGH);
  digitalWrite(in2B,LOW);

    HH:
    digitalWrite(trig,LOW);
    delayMicroseconds(3);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echopin,HIGH);
    dis=(dur*0.034529)/2;
    Serial.println(dis);
    if (dis<=5){
       //stop Motors
  digitalWrite(in1A,LOW);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,LOW);
  digitalWrite(in2B,LOW);
  delay(200);
       goto HH;           
    }
   
 else{
  //analogWrite motors 
  digitalWrite(in1A,HIGH);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,HIGH);
  digitalWrite(in2B,LOW);
      
     if (analogRead(ir_sensor)>300 ){
      //stop Motors
  digitalWrite(in1A,LOW);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,LOW);
  digitalWrite(in2B,LOW);
  delay(200);
     
      if(container_weight==0){
     //bestMotion
     }
     else{
      
      container_weight=0;
   
     }
      goto HH; 
      
     }
     else{
      goto HH;
     }
 }*/
 int dur,dis,ir_sensor;
    //analogWrite motors 
analogWrite (EnA,250);
analogWrite (EnB,250);


  digitalWrite(in1A,HIGH);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,HIGH);
  digitalWrite(in2B,LOW);

    HH:
    digitalWrite(trig,LOW);
    delayMicroseconds(3);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    dur=pulseIn(echopin,HIGH);
    dis=(dur*0.034529)/2;
    Serial.println(dis);
    if (dis<=5){
       //stop Motors
  digitalWrite(in1A,LOW);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,LOW);
  digitalWrite(in2B,LOW);
  delay(200);
       goto HH;           
    }
   
 else{
  //analogWrite motors 
  digitalWrite(in1A,HIGH);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,HIGH);
  digitalWrite(in2B,LOW);
      kk:
     if (analogRead(ir_sensor)>300 ){
      //stop Motors
  digitalWrite(in1A,LOW);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,LOW);
  digitalWrite(in2B,LOW);
  delay(200);
  
      if(container_weight==0){
     //bestMotion
     }
     else{
      
      container_weight=0;
    
     }
      //goto kk; 
      
     }
     else{
      goto HH;
     }
 }

 
  }
void moveLeft11(){
  analogWrite (EnA,100);
  analogWrite (EnB,100);

  digitalWrite(in1A,HIGH);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,HIGH);
  digitalWrite(in2B,LOW);
  delay(250);
  analogWrite (EnA,100);
  analogWrite (EnB,150);
  delay(1000);
  digitalWrite(in1A,LOW);
  digitalWrite(in2A,LOW);
  digitalWrite(in1B,LOW);
  digitalWrite(in2B,LOW);


  }
void Bot_Algorithm(){

  
}
};



//Start of code
collectorBot bot;

void setup() {
pinMode(A1,OUTPUT);
pinMode(A0,INPUT);
pinMode(4,INPUT);
pinMode(3,OUTPUT);
pinMode(EnA,OUTPUT);
pinMode(in1A,OUTPUT);
pinMode(in2A,OUTPUT);
pinMode(in1B,OUTPUT);
pinMode(in2B,OUTPUT);
pinMode(EnB,OUTPUT);

digitalWrite(A1,HIGH);
  //Motors speed
/*analogWrite (EnA,100);
analogWrite (EnB,100);
*/
Serial.begin(9600);
 
 
//bot.move1();
//bot.moveLeft11();
 
}


void loop() {
 bot.testMotion();

  }
  
 
 

