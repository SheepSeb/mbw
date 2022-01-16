#include <ble.h>
#include <gap.h>
#include <stdbool.h>
#include <stdio.h>
#include <tock.h>
#include <temperature.h>
#include <time.h>
#include <encrytion.h>
// Sizes in bytes
#define DEVICE_NAME_SIZE 6

/*******************************************************************************
 * MAIN
 ******************************************************************************/

int main(void)
{
  // declarations of variables to be used in this BLE example application
  uint16_t advertising_interval_ms = 100;

  int i, j, k;

  // TODO: uncomment production and comment testing when deployed
  /**
   *  PRODUCTION CODE
  while (1)
  {
    int temperature = 0;
    temperature_read_sync(&temperature);
    temperature = temperature/100;

    uint8_t data[DEVICE_NAME_SIZE];

    char text[10];

    // TODO: change k to temperature

    sprintf(text, "%d", temperature);

    char idMicrobit[2] = "MB";

    for (i = 0; i < 2; i++)
    {
      data[i] = idMicrobit[i];
    }

    for (i = 2, j = 0; i < DEVICE_NAME_SIZE; i++, j++)
    {
      data[i] = text[j];
    }

    static uint8_t adv_data_buf[ADV_DATA_MAX_SIZE];

    printf(" - Initializing BLE... %s\n", data);
    AdvData_t adv_data = gap_adv_data_new(adv_data_buf, sizeof(adv_data_buf));

    gap_add_flags(&adv_data, LE_GENERAL_DISCOVERABLE | BREDR_NOT_SUPPORTED);

    gap_add_device_name(&adv_data, data, DEVICE_NAME_SIZE);
    ble_start_advertising(ADV_NONCONN_IND, adv_data.buf, adv_data.offset, advertising_interval_ms);

    // TODO : add sleep for interval_ms
    delay_ms(advertising_interval_ms * 100);

    ble_stop_advertising();
  }
  **/

  // TESTING

  for (k = 0; k < 9; k++)
  {

    // TODO: uncomment those lines

    // int temperature = 0;
    // temperature_read_sync(&temperature);
    // temperature = temperature/100;

    uint8_t data[DEVICE_NAME_SIZE];

    char text[DEVICE_NAME_SIZE];

    // TODO: change k to temperature

    sprintf(text, "%d", k);

    char idMicrobit[2] = "MB";

    for (i = 0; i < 2; i++)
    {
      data[i] = idMicrobit[i];
    }

    for (i = 2, j = 0; i < DEVICE_NAME_SIZE; i++, j++)
    {
      data[i] = text[j];
    }
    char* encrypted_data =  encryptRot13(char* data);
    //TODO change data to encrypted data (including temperature)
    static uint8_t adv_data_buf[ADV_DATA_MAX_SIZE];

    printf(" - Initializing BLE... %s\n", data);
    AdvData_t adv_data = gap_adv_data_new(adv_data_buf, sizeof(adv_data_buf));

    gap_add_flags(&adv_data, LE_GENERAL_DISCOVERABLE | BREDR_NOT_SUPPORTED);

    gap_add_device_name(&adv_data, data, DEVICE_NAME_SIZE);
    ble_start_advertising(ADV_NONCONN_IND, adv_data.buf, adv_data.offset, advertising_interval_ms);

    // TODO : add sleep for interval_ms
    delay_ms(advertising_interval_ms * 100);

    ble_stop_advertising();
  }
  return 0;
}
