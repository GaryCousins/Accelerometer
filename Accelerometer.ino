// GY-61 Board monitor
//
// Author:  Gary Cousins
// Date: 09/10/16
// Platform: Arduniuo UNO

// This code can be used, modified and distributed without limitation
// but the author takes no responsibility of loss or damages incurred as
// a result.  The author offers no support or warranty of any kind.  It
// is the responsibility of the end user to ensure this code is fit
// for purpose.

// ---------------------------------------------------------------------
void setup()
{
  // Not used
}

void loop()
{
  int loop;
  double sum;
  int accValADC[3];
  double accVal[3];
  double accValBias[3] = {1.74, 1.71, 1.83};        // Bias values as derived for this board
  double accValSensitivity[3] = {0.36, 0.35, 0.36}; // Sensitivity values are derived for this board

  Serial.begin(57600);

  do
  {
    for (loop = 0; loop < 3; loop++)
    {
      // Read Values
      accValADC[loop] = analogRead(loop);

      // Convert to volatage
      accVal[loop] = (double)accValADC[loop] / 1023.0 * 5.0;

      // Adjust for bias
      accVal[loop] = accVal[loop] - accValBias[loop];

      // Scale to g
      accVal[loop] = accVal[loop] / accValSensitivity[loop];

      switch (loop)
      {
        case 0:
          Serial.print("X ");
          break;
        case 1:
          Serial.print("Y ");
          break;
        case 2:
          Serial.print("Z ");
          break;
      }

      // Display results
      Serial.print(accVal[loop]);

      // Calculate vector sum
      sum = sqrt((accVal[0] * accVal[0]) + (accVal[1] * accVal[1]) + (accVal[2] * accVal[2]));
      Serial.print(" Vector sum: ");
      Serial.println(sum);

      // Wait a while
      delay(100);
    }
  }
  while (true);
}
