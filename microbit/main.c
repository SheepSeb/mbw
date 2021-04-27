#include <ble.h>
#include <gap.h>
#include <stdbool.h>
#include <stdio.h>
#include <tock.h>
#include <temperature.h>

// Sizes in bytes

/*******************************************************************************
 * MAIN
 ******************************************************************************/
#define UUIDS_SIZE 2
#define TEMPERATURE_SIZE 1

int main(void) {
  printf("[Project] MBW\n");

  int specialID1 = 1;
  int specialID2 = 2;

  uint16_t interval_ms = 100;
  uint8_t device_name[] = "MBW1";
  uint16_t uuids[] = {specialID1, specialID2};

  int temperature = 0;

  temperature_read_sync(&temperature);

  temperature = temperature/100;

  uint8_t dataSend[] = {temperature};

  static uint8_t adv_data_buf[ADV_DATA_MAX_SIZE];

  printf("- Starting Device ... %s\n",device_name);
  AdvData_t adv_data = gap_adv_data_new(adv_data_buf,sizeof(adv_data_buf));

  gap_add_flags(&adv_data, LE_GENERAL_DISCOVERABLE | BREDR_NOT_SUPPORTED);

  printf(" - Set device name..%s\n",device_name);

  gap_add_service_uuid16(&adv_data, uuids, UUIDS_SIZE);

  printf("- Setting data temperature %d.. \n",temperature);

  gap_add_service_data(&adv_data,uuids[1],dataSend,TEMPERATURE_SIZE);

  printf(" -Begin advertising! %s\n", device_name);
  ble_start_advertising(ADV_NONCONN_IND, adv_data.buf, adv_data.offset, interval_ms);

  printf(" -Now working evert %d\n",interval_ms);

  return 0;
}
