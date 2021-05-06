////GSM module specification
#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h> //https://github.com/vshymanskyy/TinyGSM

// TTGO T-Call pin definitions
#define MODEM_RST                5
#define MODEM_PWRKEY            4
#define MODEM_POWER_ON          23
#define MODEM_TX                27
#define MODEM_RX                26
#define I2C_SDA                 21
#define I2C_SCL                 22
#define MODEM_BAUD_RATE         115200  //115.2 Kb/s baud rate

// GPRS init states
#define GPRS_RESET              0
#define GPRS_START_SERIAL       1
#define GPRS_INIT_MODULE        2
#define GPRS_INIT_MODEM         3
#define GPRS_CONNECT            4
#define GPRS_READY_             5

// GPRS data
#define GPRS_USER               ""
#define GPRS_PASS               ""
#define APN                     ""      // APN (google the apn of your network provider in your country)
#define SIM_PIN                 ""      // If SIM is locked, provide the PUK code

// Timeout connection before automatically restarting
#define GPRS_CONN_TIMEOUT       10000UL // 10 seconds

// Hardware Serial for builtin GSM Module
#define SerialAT Serial1 //I'm using an esp32, which have 3 hardware serial ports, i'm using the 2nd for the modem !

void setup_modem();
void GPRS_init();
void GPRS_wake_up();
void GPRS_put_to_sleep();
bool GPRS_connectivity_status();
