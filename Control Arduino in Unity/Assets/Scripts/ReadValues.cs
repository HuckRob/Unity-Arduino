using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports; // To get this to work you need to go into Edit -> Project Settings -> Player -> Other Settings -> Configuration -> Scripting Runtime Version -> .NET 4.x Equivalent (if that is not availible it could be because of the version of unity you are using) (this was built with Unity 2020.3.38f1)
using System.Diagnostics.Eventing.Reader;
using UnityEditor.VersionControl;

public class ReadValues : MonoBehaviour
{
    public Transform ObjectA;
    public Transform ObjectB;
    public float log;
    private int intLog;

    public bool redLedIsOn = false;
    public bool yellowLedIsOn = false;
    public bool blueLedIsOn = false;
    public bool greenLedIsOn = false;

    //public string portName = "COM5";
    //public int baudRate = 9600;
    SerialPort port = new SerialPort("COM5", 9600);


    // Start is called before the first frame update
    void Start()
    {
        port.Open();
    }

    private void Update()
    {
        if (redLedIsOn)
        {
            port.Write("R");
            //port.Write("5");
        }
        else
        {
            port.Write("0");
        }

        if (yellowLedIsOn == true)
        {
            port.Write("2");
        }
        else
        {
            port.Write("0");
        }

        if (blueLedIsOn == true)
        {
            port.Write("5");
        }
        else
        {
            port.Write("0");
        }

        if (greenLedIsOn == true)
        {
            port.Write("15");
        }
        else
        {
            port.Write("0");
        }
    }

    private void LateUpdate()
    {
        log = Vector3.Distance(ObjectA.position, ObjectB.position);
        //Debug.Log(log);

        if(log <= 5)
        {
            port.Write("2");
        }
        else
        {
            port.Write("0");
        }
    }
}
