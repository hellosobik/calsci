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

const char big_text[] PROGMEM = "Mechanical engineering, one of the oldest and broadest engineering disciplines, plays a crucial role in our daily lives and the advancement of technology. It encompasses the design, analysis, and manufacturing of mechanical systems, which range from tiny microdevices to enormous power plants. The field combines principles of physics, mathematics, material science, and engineering to create efficient, reliable, and innovative solutions to complex problems. At its core, mechanical engineering is about understanding how things work and making them better. This discipline covers various subfields, including thermodynamics, fluid mechanics, materials science, structural analysis, and robotics. Each area requires a deep understanding of fundamental principles and the ability to apply this knowledge to design and build practical solutions. One of the primary tasks of mechanical engineers is to design machines and mechanical systems. This involves using computer-aided design (CAD) software to create detailed models and simulations. CAD tools enable engineers to visualize their designs, test their functionality, and make necessary adjustments before actual production. This process is critical in ensuring that the final products are efficient, safe, and cost-effective. Mechanical engineering also plays a significant role in the manufacturing industry. Engineers in this field develop and optimize production processes, ensuring that products are made efficiently and to high-quality standards. This can involve designing new manufacturing equipment, improving existing processes, or implementing automation and robotics to increase productivity and precision. Another essential aspect of mechanical engineering is the study of thermodynamics and heat transfer. Understanding how energy is converted and transferred is vital in designing engines, HVAC systems, and even renewable energy systems like solar panels and wind turbines. Mechanical engineers work to improve the efficiency of these systems, reducing energy consumption and minimizing environmental impact. Fluid mechanics, another critical area, involves the study of how fluids behave under various conditions. This knowledge is applied in numerous industries, from aerospace, where it is used to design aircraft and spacecraft, to civil engineering, where it helps in designing efficient water supply and drainage systems. Mechanical engineers use fluid dynamics to optimize the performance and efficiency of pumps, turbines, and other fluid-handling equipment. Materials science is another cornerstone of mechanical engineering. Understanding the properties and behaviors of different materials allows engineers to select the best materials for a given application. This can involve developing new alloys and composites with improved strength, durability, and resistance to environmental factors. Advanced materials are crucial in industries like aerospace, automotive, and electronics, where performance and reliability are paramount. Mechanical engineering is not just about technical skills; it also requires creativity, problem-solving abilities, and a keen understanding of economic and environmental factors. Engineers must consider the cost, sustainability, and societal impact of their designs. This holistic approach ensures that mechanical engineers contribute positively to society, creating solutions that are not only effective but also responsible and sustainable. The history of mechanical engineering is rich and diverse, dating back to ancient civilizations. The early engineers of Egypt, Greece, and Rome applied principles of mechanics to build monumental structures, aqueducts, and simple machines like the lever and pulley. The Industrial Revolution in the 18th and 19th centuries marked a significant turning point in the field, as the development of the steam engine and other machinery revolutionized manufacturing and transportation. The advances in thermodynamics, material science, and mechanics during this period laid the foundation for modern mechanical engineering. Today, mechanical engineering continues to evolve, driven by technological advancements and the need for sustainable solutions. The integration of computer technology has transformed the field, enabling precise simulations, real-time data analysis, and advanced manufacturing techniques like 3D printing. Mechanical engineers are now at the forefront of developing renewable energy systems, autonomous vehicles, and smart technologies that improve our quality of life. One of the most exciting areas in mechanical engineering today is robotics. The design and development of robots require a deep understanding of mechanics, electronics, and computer programming. Robots are used in various applications, from manufacturing and healthcare to exploration and entertainment. In manufacturing, robots perform tasks with precision and consistency, increasing efficiency and reducing human error. In healthcare, robotic systems assist in surgeries, rehabilitation, and patient care, enhancing medical outcomes and improving quality of life. The exploration of space and deep-sea environments relies heavily on robotic systems, which can operate in extreme conditions where humans cannot. As technology advances, the capabilities of robots continue to expand, offering new possibilities for innovation and problem-solving. Another significant development in mechanical engineering is the focus on sustainable and renewable energy sources. Engineers are working to design more efficient wind turbines, solar panels, and hydroelectric systems. These renewable energy systems aim to reduce our reliance on fossil fuels, decrease greenhouse gas emissions, and combat climate change. Mechanical engineers also play a crucial role in improving energy efficiency in buildings and industrial processes. By optimizing HVAC systems, developing energy-efficient appliances, and implementing sustainable manufacturing practices, they contribute to reducing energy consumption and environmental impact. The transportation sector is another area where mechanical engineering is making significant strides. The development of electric and hybrid vehicles, high-speed trains, and more efficient aircraft are transforming the way we travel. Mechanical engineers are at the forefront of designing these advanced transportation systems, focusing on improving performance, safety, and fuel efficiency. Autonomous vehicles, which rely on sophisticated mechanical and electronic systems, are poised to revolutionize transportation, offering increased safety and convenience. Mechanical engineering also intersects with biomedical engineering, where the design of medical devices, prosthetics, and implants is crucial. Engineers in this field work on developing advanced prosthetics that mimic the natural movement of limbs, creating implants that improve patient outcomes, and designing medical devices that enhance diagnostic and treatment capabilities. The advancements in materials science have enabled the creation of biocompatible materials that integrate seamlessly with the human body, reducing the risk of rejection and improving the quality of life for patients. Mechanical engineers also contribute to the development of wearable technologies, such as fitness trackers and health monitoring devices. These devices rely on precise mechanical and electronic components to measure various physiological parameters, providing valuable data for health management and medical research. In the realm of manufacturing, the adoption of Industry 4.0 technologies is transforming traditional production processes. Mechanical engineers are instrumental in implementing automation, robotics, and the Internet of Things (IoT) in manufacturing environments. These technologies enable real-time monitoring, predictive maintenance, and data-driven decision-making, enhancing productivity and reducing downtime. Additive manufacturing, or 3D printing, is another revolutionary technology that mechanical engineers are leveraging. This technique allows for the creation of complex, customized parts with high precision, reducing material waste and production time. The ability to quickly prototype and iterate designs accelerates the innovation process, bringing new products to market faster. Mechanical engineering is also playing a pivotal role in addressing global challenges such as climate change, resource depletion, and urbanization. Engineers are developing sustainable technologies and practices to mitigate environmental impact and promote resource conservation. This includes designing energy-efficient systems, developing alternative energy sources, and creating sustainable infrastructure for growing urban populations. The principles of mechanical engineering are applied to optimize water management systems, improve waste treatment processes, and develop sustainable agricultural practices. Mechanical engineering is an ever-evolving field that constantly adapts to new challenges and opportunities. The advent of digital technology has brought about a new era in mechanical engineering, characterized by the integration of digital tools and processes. Digital twins, for example, are virtual replicas of physical systems that allow engineers to simulate, analyze, and optimize performance in real-time. This technology is transforming industries by enabling more accurate predictions and more efficient operations. The Internet of Things (IoT) is another digital innovation that is revolutionizing mechanical engineering. IoT involves connecting physical devices to the internet, allowing them to collect and exchange data. This connectivity enables engineers to monitor and control systems remotely, leading to improved efficiency and reliability. IoT applications in mechanical engineering include smart manufacturing, predictive maintenance, and energy management. Artificial intelligence (AI) and machine learning are also making significant impacts on mechanical engineering. These technologies enable engineers to analyze large amounts of data, identify patterns, and make informed decisions. AI-driven design and optimization tools are helping engineers create more efficient and innovative solutions. Machine learning algorithms are also being used to predict equipment failures and optimize maintenance schedules, reducing downtime and improving reliability. The field of mechanical engineering is also being transformed by advancements in materials science. The development of new materials, such as nanomaterials and biomaterials, is opening up new possibilities for innovation. Nanomaterials, for example, have unique properties that can be exploited to create stronger, lighter, and more efficient components. Biomaterials, on the other hand, are being used to develop medical devices and implants that are more compatible with the human body. Sustainability is a key focus in modern mechanical engineering. Engineers are increasingly prioritizing the development of sustainable technologies and practices to address environmental challenges. This includes designing energy-efficient systems, developing renewable energy technologies, and promoting sustainable manufacturing practices. The concept of the circular economy, which involves designing products and systems to minimize waste and maximize resource efficiency, is also gaining traction in the field. Mechanical engineering education is evolving to keep pace with these advancements. Engineering programs are increasingly incorporating digital tools and technologies into their curricula, preparing students for the challenges of the modern workforce. Hands-on learning experiences, such as internships and cooperative education programs, are also being emphasized to provide students with practical skills and real-world experience. Professional development is also important for practicing mechanical engineers. Continuing education and professional certifications, such as the Professional Engineer (PE) license, are essential for staying current with the latest advancements and maintaining a high standard of practice. Professional organizations, such as the American Society of Mechanical Engineers (ASME), offer resources and networking opportunities to support the ongoing development of engineers. The future of mechanical engineering is bright, with numerous opportunities for innovation and impact. As technology continues to advance, mechanical engineers will play a crucial role in shaping the future. They will be at the forefront of developing new technologies, improving existing systems, and addressing global challenges. The demand for skilled mechanical engineers is expected to remain strong, driven by the need for innovation and the ongoing growth of various industries. In conclusion, mechanical engineering is a dynamic and multifaceted discipline that is integral to the advancement of technology and the betterment of society. From designing innovative machines and optimizing manufacturing processes to developing sustainable energy solutions and advancing medical technologies, mechanical engineers are at the forefront of solving complex problems and driving progress. Their work is grounded in a deep understanding of fundamental principles and enhanced by creativity, innovation, and a commitment to sustainability. As technology continues to evolve, the role of mechanical engineers will remain crucial in shaping a better future for all. Mechanical engineering is not only about understanding how things work but also about applying this knowledge to create practical and innovative solutions. The field requires a strong foundation in physics, mathematics, and material science, as well as the ability to think creatively and solve complex problems. Mechanical engineers must also have a keen understanding of economic and environmental factors, as their designs often have significant impacts on cost, sustainability, and societal well-being. One of the most exciting aspects of mechanical engineering is the diversity of applications and industries it encompasses. Mechanical engineers work in a wide range of fields, including automotive, aerospace, energy, manufacturing, healthcare, and robotics. In the automotive industry, for example, mechanical engineers design and develop engines, transmissions, and other critical components to improve performance, fuel efficiency, and safety. They also work on developing advanced driver-assistance systems (ADAS) and autonomous vehicles, which are poised to revolutionize transportation. In the aerospace industry, mechanical engineers are involved in designing and developing aircraft, spacecraft, and their associated systems. This includes everything from propulsion systems and structural components to avionics and control systems. The challenges of aerospace engineering are unique, as engineers must consider factors such as aerodynamics, weight, and extreme environmental conditions. The work of aerospace engineers has led to significant advancements in air travel and space exploration, enabling humans to reach new frontiers. The energy sector is another area where mechanical engineers make significant contributions. They work on designing and optimizing power generation systems, including traditional fossil fuel-based plants and renewable energy technologies such as wind, solar, and hydroelectric power. Mechanical engineers are also involved in the development of energy storage systems, which are critical for balancing supply and demand in renewable energy systems. Improving energy efficiency and reducing environmental impact are key goals in this sector. Manufacturing is a core area of mechanical engineering, and engineers in this field are focused on developing and improving production processes. This includes everything from designing manufacturing equipment and automation systems to implementing quality control measures and optimizing supply chains. The adoption of Industry 4.0 technologies, such as IoT, AI, and robotics, is transforming manufacturing, making it more efficient, flexible, and responsive to market demands. Mechanical engineering also plays a crucial role in healthcare. Engineers in this field develop medical devices, prosthetics, and implants that improve patient outcomes and quality of life. They work on designing advanced prosthetics that mimic natural limb movement, creating biocompatible implants that reduce the risk of rejection, and developing diagnostic and treatment devices that enhance medical care. The integration of robotics in healthcare is another exciting area, with applications ranging from surgical robots to rehabilitation devices. Robotics is a rapidly growing field within mechanical engineering, with applications in various industries. Robots are used in manufacturing for tasks such as assembly, welding, and material handling, where they increase efficiency and precision. In healthcare, robots assist in surgeries, rehabilitation, and patient care, improving outcomes and quality of life. The use of robots in exploration, such as space missions and deep-sea expeditions, enables humans to reach and study environments that are otherwise inaccessible. The advancements in AI and machine learning are further enhancing the capabilities of robots, allowing them to perform more complex tasks and make autonomous decisions. Another exciting development in mechanical engineering is the focus on sustainability and renewable energy. Engineers are working to design more efficient wind turbines, solar panels, and hydroelectric systems to reduce our reliance on fossil fuels and decrease greenhouse gas emissions. They are also developing energy-efficient buildings, appliances, and industrial processes to minimize energy consumption and environmental impact. The concept of the circular economy, which aims to design products and systems that minimize waste and maximize resource efficiency, is gaining traction in the field. Mechanical engineering education is evolving to keep pace with these advancements. Engineering programs are incorporating digital tools and technologies into their curricula, preparing students for the challenges of the modern workforce. Hands-on learning experiences, such as internships and cooperative education programs, are emphasized to provide students with practical skills and real-world experience. Professional development is also important for practicing mechanical engineers, with continuing education and certifications essential for staying current with the latest advancements. The future of mechanical engineering is bright, with numerous opportunities for innovation and impact. As technology continues to advance, mechanical engineers will play a crucial role in shaping the future. They will be at the forefront of developing new technologies, improving existing systems, and addressing global challenges. The demand for skilled mechanical engineers is expected to remain strong, driven by the need for innovation and the ongoing growth of various industries. In conclusion, mechanical engineering is a dynamic and multifaceted discipline that is integral to the advancement of technology and the betterment of society. From designing innovative machines and optimizing manufacturing processes to developing sustainable energy solutions and advancing medical technologies, mechanical engineers are at the forefront of solving complex problems and driving progress. Their work is grounded in a deep understanding of fundamental principles and enhanced by creativity, innovation, and a commitment to sustainability. As technology continues to evolve, the role of mechanical engineers will remain crucial in shaping a better future for all.";

// const char big_text[] PROGMEM = "Creating a 10,000-word essay on mechanical engineering in a single paragraph is highly unconventional and impractical for readability and comprehension.";

//string buffer
String text="";
// String r1="";
// String r2="";

//position
int text_pos = 0;
int cursor_pos = 0;

int update_pos(String text_nav){
  if(cursor_pos<0 && text_pos==0){
      cursor_pos=text.length()%32;
      text_pos=(text.length()/32)*32;
  return 0;

    }
  if (text_nav=="text") {
  if (cursor_pos>32) {
    if (cursor_pos<(32+16)) {
    text_pos+=16;
    cursor_pos=cursor_pos-16;
    }else{
    text_pos=(text.length()/32)*32;
    cursor_pos=cursor_pos%32;
    }
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
    }
    else if(cursor_pos>=32 || cursor_pos<0){
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
  else if (data=="" && !(cursor_pos==0 && text_pos==0)) {
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

int backspace(){
  // new_tex
  new_text("");
  // text_pos=0;
  return 0;
}

int allclear(){
  text="";
  cursor_pos=0;
  text_pos=0;
  new_text("");
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
        else if (row==1 && col==0) {
          // new_tex
          // new_text("1");
          new_text(big_text);
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
          allclear();
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

        delay(200);  // Debounce delay
      }
    }
    
    // Deactivate the current column
    digitalWrite(colPins[col], HIGH);
  }
}