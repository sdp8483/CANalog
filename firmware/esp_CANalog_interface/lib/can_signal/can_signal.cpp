#include "can_signal.h"

void printData(Signal_Handle_t *pData) {
 Serial.print("Struct Size: ");
  Serial.println(sizeof(Signal_Handle_t));

  Serial.print("SN: 0x");
  Serial.println(pData->sn, HEX);

  Serial.print("Frame: [");
  for (uint8_t i=0; i<sizeof(pData->frame); i++) {
    Serial.print("0x");
    Serial.print(pData->frame[i], HEX);
    Serial.print(" ");
  }
  Serial.println("]");

  Serial.print("Baud: ");
  Serial.println(pData->can_baud);

  Serial.print("Type: ");
  Serial.println(pData->can_type);

  Serial.print("ID: 0x");
  Serial.println(pData->can_id, HEX);

  Serial.print("Start Bit: ");
  Serial.println(pData->start_bit);

  Serial.print("Bit Len: ");
  Serial.println(pData->bit_len);

  Serial.print("Endianness: ");
  Serial.println(pData->endianness);

  Serial.print("Max: ");
  Serial.println(pData->max);

  Serial.print("Min: ");
  Serial.println(pData->min);

  Serial.print("Value: ");
  Serial.println(pData->value);

  uint32_t hBytes = pData->mask >> 32;
  uint32_t lBytes = (pData->mask & 0xFFFFFFFF);
  Serial.print("Mask: ");
  Serial.print(hBytes, HEX);
  Serial.println(lBytes, HEX);

  Serial.print("Dac: ");
  Serial.println(pData->dac_out);

  Serial.println();
}

uint8_t signal_struct_cmp(Signal_Handle_t *pData1, Signal_Handle_t *pData2) {
  uint8_t errors = 0;

  if (pData1->can_baud != pData2->can_baud) errors++;

  if (pData1->can_type != pData2->can_type) errors++;

  if (pData1->can_id != pData2->can_id) errors++;

  if (pData1->start_bit != pData2->start_bit) errors++;

  if (pData1->bit_len != pData2->bit_len) errors++;

  if (pData1->endianness != pData2->endianness) errors++;

  if (pData1->max != pData2->max) errors++;

  if (pData1->min != pData2->min) errors++;

  return errors;
}