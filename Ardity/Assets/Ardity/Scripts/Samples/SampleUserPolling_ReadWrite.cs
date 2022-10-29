/**
 * Ardity (Serial Communication for Arduino + Unity)
 * Author: Daniel Wilches <dwilches@gmail.com>
 *
 * This work is released under the Creative Commons Attributions license.
 * https://creativecommons.org/licenses/by/2.0/
 */

using UnityEngine;
using System.Collections;

/**
 * Sample for reading using polling by yourself, and writing too.
 */
public class SampleUserPolling_ReadWrite : MonoBehaviour
{
    public SerialController serialController;

    // Initialization
    void Start()
    {
        serialController = GameObject.Find("SerialController").GetComponent<SerialController>();

        Debug.Log("Press A or Z to execute some actions");
    }

    // Executed each frame
    void Update()
    {
        //---------------------------------------------------------------------
        // Send data
        //---------------------------------------------------------------------

        // If you press one of these keys send it to the serial device. A
        // sample serial device that accepts this input is given in the README.

        //RED led On - Off Start
        if (Input.GetKeyDown(KeyCode.Q))
        {
            Debug.Log("Sending Q -- RED LED ON");
            serialController.SendSerialMessage("Q");
        }

        if (Input.GetKeyDown(KeyCode.A))
        {
            Debug.Log("Sending A -- RED LED OFF");
            serialController.SendSerialMessage("A");
        }
        //RED led On - Off End

        //YELLOW Led on - off Start
        if (Input.GetKeyDown(KeyCode.W))
        {
            Debug.Log("Sending W -- YELLOW LED ON");
            serialController.SendSerialMessage("W");
        }

        if (Input.GetKeyDown(KeyCode.S))
        {
            Debug.Log("Sending S -- YELLOW LED OFF");
            serialController.SendSerialMessage("S");
        }
        //Yellow Led on - off End
        //Blue Led on - off Start
        if (Input.GetKeyDown(KeyCode.E))
        {
            Debug.Log("Sending E -- BLUE LED ON");
            serialController.SendSerialMessage("E");
        }
        if (Input.GetKeyDown(KeyCode.D))
        {
            Debug.Log("Sending D -- BLUE LED OFF");
            serialController.SendSerialMessage("D");
        }
        //Blue Led on - off End
        //Green Led on - off Start
        if (Input.GetKeyDown(KeyCode.R))
        {
            Debug.Log("Sending R -- GREEN LED ON");
            serialController.SendSerialMessage("R");
        }
        if (Input.GetKeyDown(KeyCode.F))
        {
            Debug.Log("Sending F -- GREEN LED OFF");
            serialController.SendSerialMessage("F");
        }
        //Green Led on - off End

        //---------------------------------------------------------------------
        // Receive data
        //---------------------------------------------------------------------

        string message = serialController.ReadSerialMessage();

        if (message == null)
            return;

        // Check if the message is plain data or a connect/disconnect event.
        if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_CONNECTED))
            Debug.Log("Connection established");
        else if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_DISCONNECTED))
            Debug.Log("Connection attempt failed or disconnection detected");
        else
            Debug.Log("Message arrived: " + message);
    }
}
