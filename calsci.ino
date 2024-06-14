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

//position relation

int update_string_buffers(String new_text){
  text_pos = 0;
  cursor_pos = 0;
  lcd.clear();
  if (new_text=="") {
    text=text.substring(0, text.length()-1);
  }else{
    text+=new_text;
    // text_pos++;
  }
  // text+=new_text;
  if (text.length()<=16) {
    r1=text;
    lcd.setCursor(0, 0);
    lcd.print(r1);}
  // }else if (text.length()>16 && text.length()<32) {
  //   lcd.setCursor(uint8_t, uint8_t)
  else if (text.length()>16 && text.length()<=32) {
    r1=text.substring(0, 16);
    r2=text.substring(16);
    lcd.setCursor(0,0);
    lcd.print(r1);
    lcd.setCursor(0,1);
    lcd.print(r2);
  }else if (text.length()>32) {
    r1=text.substring(16*(text.length()/16-1), 16*(text.length()/16));
    r2=text.substring(16*(text.length()/16));
    lcd.setCursor(0,0);
    lcd.print(r1);
    lcd.setCursor(0,1);
    lcd.print(r2);
  }
  
  return 0;
}
// int x, p;
int navigation(int direction){ //left = 1; up=2; right=3; down=4

    if (direction==1) {

    text_pos++;
    int x = text.length()-text_pos;
    if (x==-1) {
      text_pos=0;
      x = text.length()-text_pos;
    }

    // int x = text.length()-text_pos;
    // if (x==0) {
    //   text_pos=0;

    // }
    if (x>=16) {
      r1=text.substring(16*(x/16-1), 16*(x/16));
      r2=text.substring(16*(x/16));
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(r2);
      if (r2.length()<16 && x==-1) {
      for (int i = 0; i<16-r2.length(); i++) {
        lcd.print(" ");
      }
      int y = text.length()%16-1;
      lcd.setCursor(y, 1);
      // break;
      }
      lcd.setCursor((x)%16, 1);
      }
      // lcd.setCursor((x)%16, 1);
    
    else {
      r1=text.substring(0, 16);
      r2=text.substring(16);
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print(r2);
      lcd.setCursor((x)%16, 0);
    }
    }else if (direction==3) {

    text_pos--;
    int p = text.length()-text_pos;
    if (p==text.length()+1) {
      text_pos=text.length();
      p = text.length()-text_pos;
    }
    // }else {
    // text_pos--;
    // }
    if (p>=16) {
      r1=text.substring(16*(p/16-1), 16*(p/16));
      r2=text.substring(16*(p/16));
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(r2);
      if (r2.length()<16 && p==-1) {
      for (int i = 0; i<16-r2.length(); i++) {
        lcd.print(" ");
      }
      int q = text.length()%16-1;
      lcd.setCursor(q, 1);
      // break;
      }
      lcd.setCursor((p)%16, 1);
      }
      
    
    else {
      r1=text.substring(0, 16);
      r2=text.substring(16);
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print(r2);
      lcd.setCursor((p)%16, 0);
    }
    }else if (direction==2) {
    
      text_pos+=16;
    int x = text.length()-text_pos;
    if (x<0) {
      text_pos=0;
      x = text.length()-text_pos;
    }

    // int x = text.length()-text_pos;
    // if (x==0) {
    //   text_pos=0;

    // }
    if (x>=16) {
      r1=text.substring(16*(x/16-1), 16*(x/16));
      r2=text.substring(16*(x/16));
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(r2);
      if (r2.length()<16 && x==-1) {
      for (int i = 0; i<16-r2.length(); i++) {
        lcd.print(" ");
      }
      int y = text.length()%16-1;
      lcd.setCursor(y, 1);
      // break;
      }
      lcd.setCursor((x)%16, 1);
      }
      // lcd.setCursor((x)%16, 1);
    
    else {
      r1=text.substring(0, 16);
      r2=text.substring(16);
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print(r2);
      lcd.setCursor((x)%16, 0);
    }

    }
    else if (direction == 4) {

    text_pos-=16;
    int p = text.length()-text_pos;
    if (p>text.length()) {
      text_pos=text.length();
      p = text.length()-text_pos;
    }
    // }else {
    // text_pos--;
    // }
    if (p>=16) {
      r1=text.substring(16*(p/16-1), 16*(p/16));
      r2=text.substring(16*(p/16));
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(r2);
      if (r2.length()<16 && p==-1) {
      for (int i = 0; i<16-r2.length(); i++) {
        lcd.print(" ");
      }
      int q = text.length()%16-1;
      lcd.setCursor(q, 1);
      // break;
      }
      lcd.setCursor((p)%16, 1);
      }
      
    
    else {
      r1=text.substring(0, 16);
      r2=text.substring(16);
      lcd.setCursor(0,0);
      lcd.print(r1);
      lcd.setCursor(0,1);
      lcd.print(r2);
      lcd.setCursor((p)%16, 0);
    }

    }


  return 0;
}

int backspace(){
  update_string_buffers("");
  text_pos=0;
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
          update_string_buffers("1");
        }
        else if (row==6 && col==1) {
          update_string_buffers("2");
        }
        else if (row==6 && col==2) {
          update_string_buffers("3");
        }
        else if (row==5 && col==0) {
          update_string_buffers("4");
        }
        else if (row==5 && col==1) {
          update_string_buffers("5");
        }
        else if (row==5 && col==2) {
          update_string_buffers("6");
        }
        else if (row==4 && col==0) {
          update_string_buffers("7");
        }
        else if (row==4 && col==1) {
          update_string_buffers("8");
        }
        else if (row==4 && col==2) {
          update_string_buffers("9");
        }
        else if (row==7 && col==1) {
          update_string_buffers("0");
        }
        else if (row==6 && col==3) {
          update_string_buffers("*");
        }
        else if (row==6 && col==4) {
          update_string_buffers("+");
        }
        else if (row==5 && col==3) {
          update_string_buffers("/");
        }
        else if (row==5 && col==4) {
          update_string_buffers("-");
        }
        else if (row==3 && col==0) {
          update_string_buffers("sin(");
        }
        else if (row==3 && col==1) {
          update_string_buffers("cos(");
        }
        else if (row==3 && col==2) {
          update_string_buffers("tan(");
        }
        else if (row==2 && col==3) {
          update_string_buffers("(");
        }
        else if (row==2 && col==4) {
          update_string_buffers(")");
        }
        else if (row==7 && col==2) {
          update_string_buffers(".");
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
          navigation(1);
        }
        else if (row==1 && col==3) {
          navigation(3);
        }
        else if (row==0 && col==2) {
          navigation(2);
        }
        else if (row==2 && col==2) {
          navigation(4);
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