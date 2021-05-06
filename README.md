# Connect your ESP32 WROVER-B (TTGO T-CALL) to the cellular network

The goal behind deviding the setup into multiple steps is multitasking in the setup of the whole project, hence speeding up the setup process.

But, it's not actually necessary to use the stepped setup process, since a simple call to ``` GPRS_wake_up() ``` will setup the Sim800L module and connect to the cellular network.

I provided a function to put the Sim800L module to sleep, unfortunately, having the Sim800L module soldered to the board, I couldn't wake up the module correctly since it requires a pin that's not accessible to be toggled BUT I'm successfully putting it to sleep, and restarting the whole module each time i'm waking it up. So if you're not connecting to the internet that frequently, this might actually be benefecial, but if you're sleeping and waking up each couple of seconds, this might not be the best option since the Sim800L needs around 6 seconds to wake up, which is alot!

---

Some useful findings about the TTGO T-CALL module (or the SIM800L):

- It's a 2G module, so only consider using it if you still have 2G cellular networking available in your country of operation.

- It's a power hungry module that in some situations, might consume up to 2A!

- Sometimes, it requires a better antenna than the one shipped with the card.
 
