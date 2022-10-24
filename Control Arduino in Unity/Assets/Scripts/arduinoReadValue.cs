using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports; // This allows you to connect to the computer's serial port that the Arduino is plugged into

public class arduinoReadValue : MonoBehaviour
{
    public Transform objectA;
    public Transform objectB;
    public float log;
    private int intLog;
    private string portName = "COM5"; // This is the port name that the Arduino is plugged into
    private int baudRate = 9600; // This is the baud rate that the Arduino is set to
    SerialPort port = new SerialPort(portName, baudRate); // This creates a new serial port
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
