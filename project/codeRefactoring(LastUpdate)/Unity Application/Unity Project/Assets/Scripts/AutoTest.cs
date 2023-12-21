using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.IO.Ports;
using TMPro;
using UnityEngine.UI;
using System;

public class AutoTest : MonoBehaviour
{
    [SerializeField] TMP_InputField COM_PORT;
    [SerializeField] TMP_InputField BaudRate;
    [SerializeField] TMP_InputField USART_DataJSON;
    [SerializeField] TMP_InputField USART_ResultsJSON;
    [SerializeField] TMP_Text status;
    [SerializeField] Image seatBelt;
    [SerializeField] Image LED_Front;
    [SerializeField] Image LED_Back;
    [SerializeField] Image LED_Right;
    [SerializeField] Image LED_Left;
    [SerializeField] Image motorNeedle;
    [SerializeField] TMP_Text motorSpeed;
    SerialPort stream;

    [SerializeField] private USART_MSG msg = new USART_MSG();
    Dictionary<string, string> dataDict = new Dictionary<string, string>();
    char rec;
    char terminationChar = '/';
    char resetChar = '.';
    float delayTime = 0.4f;
    bool streamOpen = false;

    // Start is called before the first frame update
    void Start()
    {
        USART_DataJSON.text = Application.persistentDataPath + "/USART_Data.json";
        USART_ResultsJSON.text = Application.persistentDataPath + "/USART_Results.json";
        dataDict.Add("FRONT","0");
        dataDict.Add("BACK","1");
        dataDict.Add("RIGHT","4");
        dataDict.Add("LEFT","5");
        dataDict.Add("MOTOR","3");
        dataDict.Add("BELT","2");
        dataDict.Add("WRITE", "0");
        dataDict.Add("READ", "1");
    }

    public void SaveIntoJson()
    {
        foreach (Nodes node in msg.nodes)
        {
            foreach (Tests test in node.tests)
            {
                test.status = (test.actual.ToUpper() == test.expected.ToUpper()) ? "Successful" : "Failed";
            }
        }

        string data = JsonUtility.ToJson(msg,true);
        //Debug.Log(Application.persistentDataPath);
        File.WriteAllText(USART_ResultsJSON.text, data);
        status.text = "File Saved Successfully";
        //Debug.Log("File Saved Successfully");
    }

    public void StartTests()
    {
        OpenStream();
        if(streamOpen)
            StartCoroutine("StartTestsCoroutine");
    }

    IEnumerator StartTestsCoroutine()
    {
        ReadFromJSON();

        foreach (Nodes node in msg.nodes)
        {
            status.text = "Sending 0x" + node.identifier;
            //Debug.Log("Sending 0x" + node.identifier);
            for(int i = 0; i < node.identifier.Length; i++)
            {
                stream.Write(node.identifier[i].ToString());
                yield return new WaitForSeconds(delayTime);
            }
            stream.Write(terminationChar.ToString());
            yield return new WaitForSeconds(delayTime);

            status.text = "Sending " + node.dataLengthCode;
            //Debug.Log("Sending " + node.dataLengthCode);
            stream.Write(node.dataLengthCode[0].ToString());
            yield return new WaitForSeconds(delayTime);
            stream.Write(terminationChar.ToString());
            yield return new WaitForSeconds(delayTime);
            foreach (Tests test in node.tests)
            {
                status.text = "Sending " + test.ID;
                //Debug.Log("Sending " + test.ID);
                for (int i = 0; i < dataDict[test.ID].Length; i++)
                {
                    stream.Write(dataDict[test.ID][i].ToString());
                    yield return new WaitForSeconds(delayTime);
                }
                stream.Write(terminationChar.ToString());
                yield return new WaitForSeconds(delayTime);

                status.text = "Sending " + test.command;
                //Debug.Log("Sending " + test.command);
                stream.Write(dataDict[test.command.ToUpper()][0].ToString());
                yield return new WaitForSeconds(delayTime);
                stream.Write(terminationChar.ToString());
                yield return new WaitForSeconds(delayTime);
                if (test.command.ToUpper() == "WRITE")
                {
                    status.text = "Sending " + test.data;
                    stream.Write(test.data[0].ToString());
                    yield return new WaitForSeconds(delayTime);
                    stream.Write(terminationChar.ToString());
                    yield return new WaitForSeconds(delayTime);
                }
                test.actual = "";
                status.text = "Reading...";
                yield return new WaitForSeconds(1);

                while (stream.BytesToRead > 0 || test.actual == "")
                {
                    try
                    {
                        rec = (char)stream.BaseStream.ReadByte();
                        status.text += rec.ToString();
                        test.actual += rec.ToString();
                    }
                    catch (TimeoutException e)
                    {
                        status.text = e.Message;
                    }

                    yield return new WaitForSeconds(0.01f);
                }
                status.text = test.actual;
                if (test.ID == "BELT")
                {
                    HandleBeltState(test.actual.ToUpper());
                }
                else if (test.ID == "MOTOR")
                {
                    HandleMotorSpeed(test.actual);
                }
                else if (test.ID == "FRONT")
                {
                    HandleLEDFrontState(test.actual.ToUpper());
                }
                else if (test.ID == "BACK")
                {
                    HandleLEDBackState(test.actual.ToUpper());
                }
                else if (test.ID == "RIGHT")
                {
                    HandleLEDRightState(test.actual.ToUpper());
                }
                else if (test.ID == "LEFT")
                {
                    HandleLEDLeftState(test.actual.ToUpper());
                }
                yield return new WaitForSeconds(float.Parse(test.delay));
            }
			stream.Write(resetChar.ToString());
        }
        status.text = "Test Completed";
        //Debug.Log("Test Completed");
        streamOpen = false;
        stream.Close();
        StopCoroutine("StartTestsCoroutine");
    }

    public void ReadFromJSON()
    {
        // Read the entire file and save its contents.
        string data = File.ReadAllText(USART_DataJSON.text);

        // Deserialize the JSON data 
        msg = JsonUtility.FromJson<USART_MSG>(data);
    }

    void OpenStream()
    {
        try
        {
            stream = new SerialPort(COM_PORT.text, int.Parse(BaudRate.text));
            stream.StopBits = StopBits.One;
            stream.Parity = Parity.None;
            stream.ReadTimeout = 5000;
            stream.WriteTimeout = 5000;
            stream.Open();
            status.text = "Connected";
            //Debug.Log("Connected");
            streamOpen = true;
        }
        catch (IOException e)
        {
            status.text = e.Message;
            //Debug.Log(e.Message);
            streamOpen = false;
        }
    }

    void HandleBeltState(string state)
    {
        if(state == "ON")
        {
            seatBelt.color = Color.white;
        }
        else
        {
            seatBelt.color = Color.black;
        }
    }
    void HandleLEDFrontState(string state)
    {
        if (state == "ON")
        {
            LED_Front.color = Color.white;
        }
        else
        {
            LED_Front.color = Color.black;
        }
    }
    void HandleLEDBackState(string state)
    {
        if (state == "ON")
        {
            LED_Back.color = Color.red;
        }
        else
        {
            LED_Back.color = Color.black;
        }
    }
    void HandleLEDRightState(string state)
    {
        if (state == "ON")
        {
            LED_Right.color = Color.red;
        }
        else
        {
            LED_Right.color = Color.black;
        }
    }
    void HandleLEDLeftState(string state)
    {
        if (state == "ON")
        {
            LED_Left.color = Color.red;
        }
        else
        {
            LED_Left.color = Color.black;
        }
    }

    void HandleMotorSpeed(string speed)
    {
        Quaternion rot = motorNeedle.transform.rotation;
        rot.eulerAngles = new Vector3(rot.eulerAngles.x, rot.eulerAngles.y,-int.Parse(speed));
        motorNeedle.transform.rotation = rot;
        motorSpeed.text = speed; 
    }
}

[System.Serializable]
public class USART_MSG
{
    public List<Nodes> nodes = new List<Nodes>();
}

[System.Serializable]
public class Nodes
{
    public string identifier;
    public string dataLengthCode;
    public List<Tests> tests = new List<Tests>();
}

[System.Serializable]
public class Tests
{
    public string ID;
    public string command;
    public string data;
    public string delay;
    public string expected;
    public string actual;
    [HideInInspector] public string status;
}