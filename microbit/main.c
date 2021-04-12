#include <ble.h>
#include <gap.h>
#include <stdbool.h>
#include <stdio.h>
#include <tock.h>

// Sizes in bytes
#define DEVICE_NAME_SIZE 6

int main(void)
{
    int err;

    uint16_t advertising_interval_ms = 300;
    uint8_t device_name[] = "MBW Seb";

    static uint8_t adv_data_buf[ADV_DATA_MAX_SIZE];

    printf(" - Initializing BLE... %s\n", device_name);
    AdvData_t adv_data = gap_adv_data_new(adv_data_buf, sizeof(adv_data_buf));

    gap_add_flags(&adv_data, LE_GENERAL_DISCOVERABLE | BREDR_NOT_SUPPORTED);

    printf(" - Setting the device name... %s\n", device_name);

    printf(" - Begin advertising! %s\n", device_name);
    err = ble_start_advertising(ADV_NONCONN_IND, adv_data.buf, adv_data.offset, advertising_interval_ms);
    if (err < TOCK_SUCCESS)
        printf("ble_start_advertising, error: %s\r\n", tock_strrcode(err));

    printf("Now advertising every %d ms as '%s'\n", advertising_interval_ms,
           device_name);
    return 0;
}
