#include <LiquidCrystal_I2C.h>
#include "tinyexpr.h"
LiquidCrystal_I2C lcd(0x27,16, 2);

const int numRows = 8;   // Number of rows
const int numCols = 5;   // Number of columns

// Define the pins for rows and columns
int rowPins[numRows] = {13, 12, 14, 26, 25, 5, 17, 15};
int colPins[numCols] = {23, 16, 4, 19, 18};

//backlight toggle
int on=-1;

//string buffer
String text="";
String r1="";
String r2="";

//position
int text_pos = 0;
int cursor_pos = 0;

int update_pos(String text_nav){
  if (text_nav=="text") {
  if (cursor_pos>32) {
    text_pos+=16;
    cursor_pos=cursor_pos-16;
  }else if (cursor_pos<0) {
    text_pos-=16;
    cursor_pos=cursor_pos+16;
  }else {
    text_pos=text_pos;
    cursor_pos=cursor_pos;
  }
  }else if(text_nav=="nav"){
    if((cursor_pos+text_pos)>text.length()){
      cursor_pos=0;
      text_pos=0;

    }else if(cursor_pos<=0 && text_pos==0){
      cursor_pos=text.length()%32;
      text_pos=(text.length()/32)*32;

    }else if(cursor_pos>=32 || cursor_pos<0){
      if (cursor_pos>=32) {
        cursor_pos-=16;
        text_pos+=16;
      }else {
        cursor_pos+=16;
        text_pos-=16;
      }
      
    }
  }
  return 0;
}

//position relation
int update_display(){
  lcd.clear();
  for (int i = 0; i<32; i++) {
    int char_index=text_pos+i;
    if (char_index<text.length()) {
    
    lcd.setCursor(i%16, i/16);
    lcd.print(text.charAt(char_index));
    }
  }
  if (cursor_pos>=0) {
  lcd.setCursor((cursor_pos)%16, (cursor_pos)/16);
  }
  return 0;
}

int new_text(String data){
  if (data.length()>0) {
    text=text.substring(0,text_pos+cursor_pos)+data+text.substring(text_pos+cursor_pos);
    cursor_pos+=data.length();
  }
  else if (data=="" && text_pos!=cursor_pos) {
    int rem=text_pos+cursor_pos-1;
    text.remove(rem, 1);
    cursor_pos--;
  }
  update_pos("text");
  update_display();
  Serial.printf("text_pos=%d and cursor_pos=%d\n", text_pos, cursor_pos);
  return 0;
}

int navigate(String dir){
  if(dir=="l"){
    cursor_pos--;
  }else if(dir=="r"){
    cursor_pos++;
  }else if(dir=="u"){
    cursor_pos-=16;
  }else if(dir=="d"){
    cursor_pos+=16;
  }
  update_pos("nav");
  update_display();
  Serial.printf("text_pos=%d and cursor_pos=%d\n", text_pos, cursor_pos);
  return 0;
}

//position relation

int new_test_old(String new_text){
  // // text_pos = 0;
  // // cursor_pos = 0;
  // lcd.clear();
  // if (new_text=="") {
  //   text=text.substring(0, text.length()-1);
  //   // text=text.substring(0,text.length()-text_pos-1)+new_text+text.substring(text.length()-text_pos-1);
  //   // text_pos-=new_text.length();
  // }else{
  //   // text+=new_text;
  //   text=text.substring(0,text.length()-text_pos)+new_text+text.substring(text.length()-text_pos);
  //   text_pos-=new_text.length();
  // }
  // // text+=new_text;
  // // if (text.length()<=16) {
  // //   r1=text;
  // //   lcd.setCursor(0, 0);
  // //   lcd.print(r1);}

  // // else if (text.length()>16 && text.length()<=32) {
  // //   r1=text.substring(0, 16);
  // //   r2=text.substring(16);
  // //   lcd.setCursor(0,0);
  // //   lcd.print(r1);
  // //   lcd.setCursor(0,1);
  // //   lcd.print(r2);
  // // }else if (text.length()>32) {
  // //   r1=text.substring(16*(text.length()/16-1), 16*(text.length()/16));
  // //   r2=text.substring(16*(text.length()/16));
  // //   lcd.setCursor(0,0);
  // //   lcd.print(r1);
  // //   lcd.setCursor(0,1);
  // //   lcd.print(r2);
  // // }
  // int p = text.length()-text_pos;
  //   if (p>text.length()) {
  //     text_pos=0;
  //     p = text.length()-text_pos;
  //   }else{
  //     text_pos++;
  //     p = text.length()-text_pos;
  //   }
  //   // }else {
  //   // text_pos--;
  //   // }
  //   if (p>=16) {
  //     r1=text.substring(16*(p/16-1), 16*(p/16));
  //     r2=text.substring(16*(p/16));
  //     lcd.setCursor(0,0);
  //     lcd.print(r1);
  //     lcd.setCursor(0,1);
  //     lcd.print("                ");
  //     lcd.setCursor(0,1);
  //     lcd.print(r2);
  //     if (r2.length()<16 && p==-1) {
  //     for (int i = 0; i<16-r2.length(); i++) {
  //       lcd.print(" ");
  //     }
  //     int q = text.length()%16-1;
  //     lcd.setCursor(q, 1);
  //     // break;
  //     }
  //     lcd.setCursor((p)%16, 1);
  //     }
      
    
  //   else {
  //     r1=text.substring(0, 16);
  //     r2=text.substring(16);
  //     lcd.setCursor(0,0);
  //     lcd.print(r1);
  //     lcd.setCursor(0,1);
  //     lcd.print(r2);
  //     lcd.setCursor((p)%16, 0);
  //   }
  
  return 0;
}
// int x, p;
int navigation(int direction){ //left = 1; up=2; right=3; down=4

    // if (direction==1) {

    // text_pos++;
    // int x = text.length()-text_pos;
    // if (x==-1) {
    //   text_pos=0;
    //   x = text.length()-text_pos;
    // }

    // // int x = text.length()-text_pos;
    // // if (x==0) {
    // //   text_pos=0;

    // // }
    // if (x>=16) {
    //   r1=text.substring(16*(x/16-1), 16*(x/16));
    //   r2=text.substring(16*(x/16));
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print("                ");
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   if (r2.length()<16 && x==-1) {
    //   for (int i = 0; i<16-r2.length(); i++) {
    //     lcd.print(" ");
    //   }
    //   int y = text.length()%16-1;
    //   lcd.setCursor(y, 1);
    //   // break;
    //   }
    //   lcd.setCursor((x)%16, 1);
    //   }
    //   // lcd.setCursor((x)%16, 1);
    
    // else {
    //   r1=text.substring(0, 16);
    //   r2=text.substring(16);
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   lcd.setCursor((x)%16, 0);
    // }
    // }else if (direction==3) {

    // text_pos--;
    // int p = text.length()-text_pos;
    // if (p==text.length()+1) {
    //   text_pos=text.length();
    //   p = text.length()-text_pos;
    // }
    // // }else {
    // // text_pos--;
    // // }
    // if (p>=16) {
    //   r1=text.substring(16*(p/16-1), 16*(p/16));
    //   r2=text.substring(16*(p/16));
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print("                ");
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   if (r2.length()<16 && p==-1) {
    //   for (int i = 0; i<16-r2.length(); i++) {
    //     lcd.print(" ");
    //   }
    //   int q = text.length()%16-1;
    //   lcd.setCursor(q, 1);
    //   // break;
    //   }
    //   lcd.setCursor((p)%16, 1);
    //   }
      
    
    // else {
    //   r1=text.substring(0, 16);
    //   r2=text.substring(16);
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   lcd.setCursor((p)%16, 0);
    // }
    // }else if (direction==2) {
    
    //   text_pos+=16;
    // int x = text.length()-text_pos;
    // if (x<0) {
    //   text_pos=0;
    //   x = text.length()-text_pos;
    // }

    // // int x = text.length()-text_pos;
    // // if (x==0) {
    // //   text_pos=0;

    // // }
    // if (x>=16) {
    //   r1=text.substring(16*(x/16-1), 16*(x/16));
    //   r2=text.substring(16*(x/16));
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print("                ");
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   if (r2.length()<16 && x==-1) {
    //   for (int i = 0; i<16-r2.length(); i++) {
    //     lcd.print(" ");
    //   }
    //   int y = text.length()%16-1;
    //   lcd.setCursor(y, 1);
    //   // break;
    //   }
    //   lcd.setCursor((x)%16, 1);
    //   }
    //   // lcd.setCursor((x)%16, 1);
    
    // else {
    //   r1=text.substring(0, 16);
    //   r2=text.substring(16);
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   lcd.setCursor((x)%16, 0);
    // }

    // }
    // else if (direction == 4) {

    // text_pos-=16;
    // int p = text.length()-text_pos;
    // if (p>text.length()) {
    //   text_pos=text.length();
    //   p = text.length()-text_pos;
    // }
    // // }else {
    // // text_pos--;
    // // }
    // if (p>=16) {
    //   r1=text.substring(16*(p/16-1), 16*(p/16));
    //   r2=text.substring(16*(p/16));
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print("                ");
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   if (r2.length()<16 && p==-1) {
    //   for (int i = 0; i<16-r2.length(); i++) {
    //     lcd.print(" ");
    //   }
    //   int q = text.length()%16-1;
    //   lcd.setCursor(q, 1);
    //   // break;
    //   }
    //   lcd.setCursor((p)%16, 1);
    //   }
      
    
    // else {
    //   r1=text.substring(0, 16);
    //   r2=text.substring(16);
    //   lcd.setCursor(0,0);
    //   lcd.print(r1);
    //   lcd.setCursor(0,1);
    //   lcd.print(r2);
    //   lcd.setCursor((p)%16, 0);
    // }

    // }


  return 0;
}

int backspace(){
  // new_tex
  new_text("");
  // text_pos=0;
  return 0;
}

int backlight_toggle(int one = on){
  if (one<0) {
  lcd.noBacklight();
  }else{
    lcd.backlight();
  }
  return 0;
}

int switch_case_key(){
  return 0;
}

void setup() {
  Serial.begin(115200);
  // disableCore0WDT();
  // disableCore1WDT();
  
  lcd.init();                      // initialize the lcd
  lcd.begin(16, 2); 
  lcd.noBacklight();
  lcd.cursor();
  lcd.clear();
  
  // Set row pins as INPUT_PULLUP
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], INPUT_PULLUP);
  }

  // Set column pins as OUTPUT and HIGH
  for (int j = 0; j < numCols; j++) {
    pinMode(colPins[j], OUTPUT);
    digitalWrite(colPins[j], HIGH);
  }
}

void loop() {
  // Loop through each column
  for (int col = 0; col < numCols; col++) {
    // Activate the current column
    digitalWrite(colPins[col], LOW);
    
    // Check each row in the current column
    for (int row = 0; row < numRows; row++) {
      int buttonState = digitalRead(rowPins[row]);
      
      // If button is pressed (LOW), print the row and column
      if (buttonState == LOW) {
        if (row==0 && col==0) {
          on=-1*on;
        int x = backlight_toggle(on);
        }else if (row==6 && col==0) {
          // new_tex
          // new_text("1");
          new_text("1");
        }
        else if (row==6 && col==1) {
          // new_tex
          // new_text("2");
          new_text("2");
        }
        else if (row==6 && col==2) {
          //new_tex
          new_text("3");
        }
        else if (row==5 && col==0) {
          //new_tex
          new_text("4");
        }
        else if (row==5 && col==1) {
          //new_tex
          new_text("5");
        }
        else if (row==5 && col==2) {
          //new_tex
          new_text("6");
        }
        else if (row==4 && col==0) {
          //new_tex
          new_text("7");
        }
        else if (row==4 && col==1) {
          //new_tex
          new_text("8");
        }
        else if (row==4 && col==2) {
          //new_tex
          new_text("9");
        }
        else if (row==7 && col==1) {
          //new_tex
          new_text("0");
        }
        else if (row==6 && col==3) {
          // new_tex
          new_text("*");
        }
        else if (row==6 && col==4) {
          // new_tex
          new_text("+");
        }
        else if (row==5 && col==3) {
          // new_tex
          new_text("/");
        }
        else if (row==5 && col==4) {
          // new_tex
          new_text("-");
        }
        else if (row==3 && col==0) {
          // new_tex
          new_text("sin(");
        }
        else if (row==3 && col==1) {
          // new_tex
          new_text("cos(");
        }
        else if (row==3 && col==2) {
          // new_tex
          new_text("tan(");
        }
        else if (row==2 && col==3) {
          // new_tex
          new_text("(");
        }
        else if (row==2 && col==4) {
          // new_tex
          new_text(")");
        }
        else if (row==7 && col==2) {
          // new_tex
          new_text(".");
        }
        else if (row==7 && col==0) {
          // float result = te_interp(text.c_str(), 0);
          // lcd.clear();
          // lcd.print(result);
          // Example expression
  const char *expression = text.c_str();
  int err;
  te_expr *n = te_compile(expression, 0, 0, &err);

  if (n) {
    double result = te_eval(n);

    // Buffer to hold the formatted result
    char buffer[16];

    // Format the result to a string with 6 decimal places
    dtostrf(result, 1, 6, buffer);
    String buff=buffer;
    // Print the result to the LCD
    lcd.clear();
    lcd.print("Result:");
    lcd.setCursor(0, 1);
    lcd.print(buff.substring(0,15));

    te_free(n);
  } else {
    lcd.clear();
    lcd.print("Parse error at ");
    lcd.setCursor(0, 1);
    lcd.print(err);
  }
        }
        else if (row==7 && col==4) {
          text="";
          r1="";
          r2="";
          text_pos=0;
          lcd.clear();
          lcd.setCursor(0, 0);
        }
        else if (row==1 && col==1) {
          // navigation(1);
          navigate("l");
        }
        else if (row==1 && col==3) {
          // navigation(3);
          navigate("r");
        }
        else if (row==0 && col==2) {
          // navigation(2);
          navigate("u");
        }
        else if (row==2 && col==2) {
          // navigation(4);
          navigate("d");
        }
        else if (row==7 && col==3) {
          backspace();
        }
        // Serial.print("Button Pressed at Row ");
        // Serial.print(row+1);
        // Serial.print(", Column ");
        // Serial.println(col+1);
        // //text ="row=" + row + " " + "col=" + col;
        // lcd.clear();
        // lcd.print("row = ");
        // lcd.print(row+1);
        // lcd.print(", col =");
        // lcd.print(col+1);
        delay(200);  // Debounce delay
      }
    }
    
    // Deactivate the current column
    digitalWrite(colPins[col], HIGH);
  }
}