// GY-61 Channel Calibrator
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


#define COUNT 10

void setup()
{
  // Not used
}

void loop()
{
  int loop;
  double sum;
  int accValADC[COUNT];
  double accVal[COUNT];

  Serial.begin(57600);

  do
  {
    for (loop = 0; loop < COUNT; loop++)
    {
      // Read Values
      accValADC[loop] = analogRead(2);  // Change channel to the appropraite line being calibrated

      // Convert to volatage
      accVal[loop] = (double)accValADC[loop] / 1023.0 * 5.0;

      // Display results
      Serial.print(accVal[loop]);
      Serial.print(" ");

      // Wait a while
      delay(10);
    }

    sum = 0;
    for (loop = 0; loop < COUNT; loop++)
    {
      sum = sum + accVal[loop];
    }
    sum = sum / (double)COUNT;
    Serial.print("Average  ");
    Serial.print(sum);
    Serial.println(" ");
  }
  while (true);
}
