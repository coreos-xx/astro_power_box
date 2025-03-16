mmun#include <EEPROM.h>

#define OUT0 PC0
#define OUT1 PC1
#define OUT2 PC2
#define OUT3 PC3
#define OUT4 PC4
#define OUT5 PC5
#define OUT6 PC6
#define OUT7 PC7

#define EEPROM_MAGIC_BYTE 0x15  // A marker to check if EEPROM is initialized
#define EEPROM_ADDR_MAGIC 0      // EEPROM Address for magic byte
#define EEPROM_ADDR_STATES 1      // EEPROM Address where pin states start

int outArray[8] = {OUT0, OUT1, OUT2, OUT3, OUT4, OUT5, OUT6, OUT7};
boolean stateArray[8] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}; // Default states

void loadStateFromEEPROM() {
    EEPROM.begin(); // Initialize EEPROM

    byte magicByte = EEPROM.read(EEPROM_ADDR_MAGIC);
    if (magicByte == EEPROM_MAGIC_BYTE) {
        //Serial.println("Loading stored configuration...");
        for (int i = 0; i < 8; i++) {
            stateArray[i] = EEPROM.read(EEPROM_ADDR_STATES + i);
        }
    } else {
        //Serial.println("No valid config found. Using defaults.");
        saveStateToEEPROM();  // Save default states to EEPROM
    }
}

void saveStateToEEPROM() {
    EEPROM.begin();

    Serial.println("Saving configuration to EEPROM...");

    EEPROM.write(EEPROM_ADDR_MAGIC, EEPROM_MAGIC_BYTE);  // Write magic byte
    for (int i = 0; i < 8; i++) {
        EEPROM.write(EEPROM_ADDR_STATES + i, stateArray[i]);
    }
    EEPROM.commit();  // Save changes

    Serial.println("Configuration saved. Reboot required.");
}

void setup() {
    Serial.begin(9600);
    delay(1000);

    //Serial.println("CH32V003 EEPROM Debug Start");

    loadStateFromEEPROM();  // Load saved configuration or use default

    for (int i = 0; i < 8; i++) {
        pinMode(outArray[i], OUTPUT);
        digitalWrite(outArray[i], stateArray[i]);  // Apply stored states
    }
}

void loop() {
    if (Serial.available()) {
        char in = Serial.read(); // Read the first command character

        if (in == 's') {
            Serial.println(" ");
            int val = Serial.read();
            val = val - 48; // Convert ASCII to integer
            if (val >= 0 && val < 8) {
                stateArray[val] = !stateArray[val]; // Toggle state
                digitalWrite(outArray[val], stateArray[val]); // Update hardware
                Serial.println(!stateArray[val]); // Send new state
            } else {
                Serial.print("Invalid switch index ");
                Serial.println(val);
            }
        } else if (in == 'g') {
            Serial.println(" ");
            int val = Serial.read();
            val = val - 48;
            if (val >= 0 && val < 8) {
                Serial.println(!stateArray[val]); // Send current state
            } else {
                Serial.print("Invalid switch index ");
                Serial.println(val);
            }
        } else if (in == 'e') {
            Serial.println(" ");
            int val = Serial.read();
            val = val - 48;
            if (val >= 0 && val < 8) {
                stateArray[val] = !stateArray[val]; // Toggle stored boot state
                saveStateToEEPROM();  // Save new boot state to EEPROM
                Serial.println("Boot state updated. Reboot required.");
            } else {
                Serial.print("Invalid switch index ");
                Serial.println(val);
            }
        } else {
            Serial.flush(); // Clear invalid input
        }
    }
}
